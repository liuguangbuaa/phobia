/*
   Phobia DC Motor Controller for RC and robotics.
   Copyright (C) 2013 Roman Belov <romblv@gmail.com>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <math.h>

#include "plant.h"
#include "lib.h"

#define PWM_FAST_SOLVER			1

plant_t			plant;

static double
plant_bemf_shape(double x)
{
	double		s1;

	/* Phase align.
	 * */
	x = -x;

	/* Sinusoidal shape.
	 * */
	s1 = sin(x);

	return s1;
}

void plant_enable()
{
	double		Kv;

	plant.tsim = 0.0; /* Simulation time (Second) */
        plant.tdel = 1.0 / 20e+3; /* Delta */
	plant.pwmf = 1000; /* PWM resolution */

        plant.x[0] = 0.0; /* Phase A current (Ampere) */
	plant.x[1] = 0.0; /* Phase B current (Ampere) */
        plant.x[2] = 0.0; /* Electrical Speed (Radian/Sec) */
        plant.x[3] = -1.0; /* Electrical Position (Radian) */
        plant.x[4] = 20.0; /* Temperature (Celsius) */
	plant.x[5] = 0.0; /* Consumed Energy (Joule) */
	plant.x[6] = 0.0; /* Produced Energy (Joule) */

	/* Winding resistance at 20 C. (Ohm)
         * */
	plant.const_R = 147e-3;

	/* Winding inductance. (Henry)
         * */
	plant.const_L = 44e-6;

	/* Source voltage. (Volt)
	 * */
	plant.const_U = 12.0;

	/* Source internal resistance. (Ohm)
	 * */
	plant.const_uR = 0e-3;

	/* Number of the rotor pole pairs.
	 * */
	plant.const_Z = 11.0;

	/* BEMF constant. (Volt/RadianPerSecond)
         * */
	Kv = 650; /* total RPM per volt */
        plant.const_E = 30.0 / (Kv * 2.0 * M_PI) / plant.const_Z;

	/* Moment of inertia. (Kg/m^2)
	 * */
	plant.const_J = 10e-5;

	/* Load torque constants.
	 * */
	plant.const_M[0] = 1e-3;
	plant.const_M[1] = 0e-0;
	plant.const_M[2] = 1e-5;
	plant.const_M[3] = 0e-0;
}

static void
plant_equation(double dx[7],
		const double x[7])
{
	double		R, L, E, U, Z, J;
	double		e[3], bemf[3], Uz, Mt, Ml, s, Is;

	R = plant.const_R * (1.0 + 4.28e-3 * (x[4] - 20.0));
	L = plant.const_L;
	E = plant.const_E;
	U = plant.const_U;
	Z = plant.const_Z;
	J = plant.const_J;

	e[0] = plant_bemf_shape(x[3]);
	e[1] = plant_bemf_shape(x[3] - 2.0 * M_PI / 3.0);
	e[2] = plant_bemf_shape(x[3] + 2.0 * M_PI / 3.0);

	bemf[0] = x[2] * E * e[0];
	bemf[1] = x[2] * E * e[1];
	bemf[2] = x[2] * E * e[2];

	Uz = (plant.i[0] + plant.i[1] + plant.i[2]) * U / 3.0
		- (bemf[0] + bemf[1] + bemf[2]) / 3.0;

	/* Electrical equations.
	 * */
	dx[0] = ((plant.i[0] * U - Uz) - x[0] * R - bemf[0]) / L;
	dx[1] = ((plant.i[1] * U - Uz) - x[1] * R - bemf[1]) / L;

	Mt = Z * E * (x[0] * e[0] + x[1] * e[1]
			- (x[0] + x[1]) * e[2]);

	s = fabs(x[2] / Z);
	Ml = plant.const_M[0]
		+ plant.const_M[1] * s
		+ plant.const_M[2] * s * s
		+ plant.const_M[3] * s * s * s;
	Ml = (x[2] < 0.0 ? Ml : -Ml);

	/* Mechanical equations.
	 * */
	dx[2] = Z * (Mt + Ml) / J;
	dx[3] = x[2];

	/* Thermal equation.
	 * */
	dx[4] = 0.0;

	/* Energy equations.
	 * */
	Is = plant.i[0] * x[0] + plant.i[1] * x[1]
		- plant.i[2] * (x[0] + x[1]);
	dx[5] = U * Is;
	dx[6] = Mt * (x[2] / Z);
}

static void
plant_solve(double dt)
{
	double		s1[7];
	double		s2[7];
	double		x2[7];
	int		j;

	/* Second-order ODE solver.
	 * */

	plant_equation(s1, plant.x);

	for (j = 0; j < 7; ++j)
		x2[j] = plant.x[j] + s1[j] * dt;

	plant_equation(s2, x2);

	for (j = 0; j < 7; ++j)
		plant.x[j] += (s1[j] + s2[j]) * dt / 2.0;

	/* Wrap the angular position.
	 * */
	plant.x[3] = (plant.x[3] < -M_PI)
		? plant.x[3] + 2.0 * M_PI : (plant.x[3] > M_PI)
		? plant.x[3] - 2.0 * M_PI : plant.x[3];
}

static void
plant_bridge_sample()
{
	double		sa[2], u, uref, du;
	int		a;

	/* ADC reference voltage.
	 * */
	uref = 3.3;

	/* Current sampling.
	 * */
	sa[0] = plant.x[0];
	sa[1] = -(plant.x[0] + plant.x[1]);

	/* Output voltage of the current sensor A.
	 * */
	u = sa[0] * 55e-3 + uref / 2.0;
	du = gauss() * 3e-3 + 0e-3;
	//u += du;

	/* ADC conversion.
	 * */
	a = (int) (u / uref * 4096);
	a = a < 0 ? 0 : a > 4095 ? 4095 : a;
	plant.z[0] = a;

	/* Output voltage of the current sensor C.
	 * */
	u = sa[1] * 55e-3 + uref / 2.0;
	du = gauss() * 3e-3 - 0e-3;
	//u += du;

	/* ADC conversion.
	 * */
	a = (int) (u / uref * 4096);
	a = a < 0 ? 0 : a > 4095 ? 4095 : a;
	plant.z[1] = a;

	/* Voltage sampling.
	 * */
	sa[0] = plant.const_U;

	u = sa[0] / 9.0;
	du = gauss() * 3e-3 + 0e-3;
	//u += du;

	/* ADC conversion.
	 * */
	a = (int) (u / uref * 4096);
	a = a < 0 ? 0 : a > 4095 ? 4095 : a;
	plant.z[2] = a;
}

static void
plant_bridge_solve(double tdel)
{
	int		j, ton[3], pm[3];
	double		pwmdt, dt;

	/* Prepare variables.
	 * */
	pwmdt = tdel / plant.pwmf / 2.0;
	ton[0] = (int) (plant.u[0] * plant.pwmf);
	ton[1] = (int) (plant.u[1] * plant.pwmf);
	ton[2] = (int) (plant.u[2] * plant.pwmf);

	if (PWM_FAST_SOLVER) {

		/* Sort Ton values.
		 * */

		pm[0] = 0;
		pm[1] = 1;
		pm[2] = 2;

		if (ton[pm[0]] < ton[pm[2]]) {

			j = pm[2];
			pm[2] = pm[0];
			pm[0] = j;
		}

		if (ton[pm[0]] < ton[pm[1]]) {

			j = pm[1];
			pm[1] = pm[0];
			pm[0] = j;
		}

		if (ton[pm[1]] < ton[pm[2]]) {

			j = pm[2];
			pm[2] = pm[1];
			pm[1] = j;
		}

		/* Count Up.
		 * */
		plant.i[pm[0]] = 1;
		plant.i[pm[1]] = 1;
		plant.i[pm[2]] = 1;

		dt = pwmdt * (ton[pm[0]]);
		plant_solve(dt);

		plant.i[pm[0]] = 0;
		plant.i[pm[1]] = 1;
		plant.i[pm[2]] = 1;

		dt = pwmdt * (ton[pm[1]] - ton[pm[0]]);
		plant_solve(dt);

		plant.i[pm[0]] = 0;
		plant.i[pm[1]] = 0;
		plant.i[pm[2]] = 1;

		dt = pwmdt * (ton[pm[2]] - ton[pm[1]]);
		plant_solve(dt);

		plant.i[pm[0]] = 0;
		plant.i[pm[1]] = 0;
		plant.i[pm[2]] = 0;

		dt = pwmdt * (plant.pwmf - ton[pm[2]]);
		plant_solve(dt);

		/* Count Down.
		 * */
		dt = pwmdt * (plant.pwmf - ton[pm[2]]);
		plant_solve(dt);

		plant.i[pm[0]] = 0;
		plant.i[pm[1]] = 0;
		plant.i[pm[2]] = 1;

		dt = pwmdt * (ton[pm[2]] - ton[pm[1]]);
		plant_solve(dt);

		plant.i[pm[0]] = 0;
		plant.i[pm[1]] = 1;
		plant.i[pm[2]] = 1;

		dt = pwmdt * (ton[pm[1]] - ton[pm[0]]);
		plant_solve(dt);

		plant.i[pm[0]] = 1;
		plant.i[pm[1]] = 1;
		plant.i[pm[2]] = 1;

		dt = pwmdt * (ton[pm[0]]);
		plant_solve(dt);
	}
	else {
		/* Count Up.
		 * */
		for (j = 0; j < plant.pwmf; ++j) {

			plant.i[0] = j < ton[0] ? 1 : 0;
			plant.i[1] = j < ton[1] ? 1 : 0;
			plant.i[2] = j < ton[2] ? 1 : 0;

			plant_solve(pwmdt);
		}

		/* Count Down.
		 * */
		for (j = plant.pwmf; j > 0; --j) {

			plant.i[0] = j > ton[0] ? 0 : 1;
			plant.i[1] = j > ton[1] ? 0 : 1;
			plant.i[2] = j > ton[2] ? 0 : 1;

			plant_solve(pwmdt);
		}
	}
}

void plant_update()
{
	plant_bridge_sample();
	plant_bridge_solve(plant.tdel);
	plant.tsim += plant.tdel;
}
