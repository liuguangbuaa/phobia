## Overview

This page describes how to identify motor parameters by means of PMC. The
knowledge of parameters is necessary to control. Any new motor connected to the
PMC should be identified before run in closed control loop.

## Preparation

You may need to adjust some parameters in accordance with the capabilities of
the motor to not burn it. Default is acceptable for most RC motors but be
aware. These parameters are used to probe the motor.

	# reg pm.probe

There are a lot of parameters that can affect the motor identification. But we
believe that they will need a change only in a very complicated case.

Most likely you will change **pm.probe_speed_hold** parameter. The probe speed
should provide enough BEMF but not to exceed **pm.forced_hold_D** speed.

## Sensors adjustment

To achieve a good result adjust the voltage and current sensors. The automatic
self-adjustment that is necessary for matching the voltage measurement
channels. Also current sensors will be self-adjusted if motor is connected.

	# pm_self_adjust

This is enough to do it once and save the values in the flash. But we recommend
to do it again when you change supply voltage.

## Number of the rotor pole pairs

This number connects the electrical speed with the mechanical. We believe you
are able to identify Zp simply by counting the number of magnets on the rotor
then divide it by 2. This is the most famous method.

	# reg pm.const_Zp <N>

If access to the motor is restricted and to count the magnets is impossible
then just leave a value 1. Instead of mechanical speed you will see electrical
speed. By measuring the mechanical speed directly you can estimate Zp and set
it later.

## Impedance of stator windings

Resistance is measured by holding a constant current vector for some time.
Assuming that the rotor was fixed we can determine R as U/I. For greater
accuracy you need to increase the probe current or reduce the supply voltage.

We use a high frequency sinusoidal signal to measure the full impedance then we
calculate DQ inductance and rotation angle.

	# pm_probe_base

Normally it will print the values of the identified parameters. In case of
failure the error will be printed out. We recommend to do this procedure twice
to make sure of reliable estimates.

## Rotor flux linkage

This parameter also known as Kv rating. Internal representation is E that
linked with Kv by following equation.

	                 60
	E = ----------------------------
	     2 * PI * sqrt(3) * Kv * Zp

To identify E you have to run in closed loop. Also the rotor should rotate at
significant speed. We do a forced spinup to reach this condition.

	# pm_probe_spinup

To get more accurate estimate run the motor at high speed and request E probe
manually. Do not load the motor.

	# reg pm.s_setpoint_rpm <rpm>
	# pm_probe_const_E

## No forced spinup

If you failed to start the motor with **pm_probe_spinup** you have an option to
identify E in detached mode. You will have to rotate the motor manually in this
case.

	# pm_probe_detached

It waits for the motor to reach at least **pm.probe_speed_detached** speed.

## Mean Peak to Peak Error (MPPE)

Command **pm_probe_spinup** does many estimates after forced spinup. Look at
this time diagram.

	 | -- (speed)                                        _
	 |                                                  / \
	 |                                                 /   \
	 |                    _--_-_--_-__--_-_-_--__-_--_/     \
	 |                   /                                   \
	 |   _--_-_-_--_-_-_/                                     \
	 |  /                |         |            |              ~~~
	 | /        |        |         |            |            |
	-+----------+--------+---------+------------+------------+-------->
	   | forced |   E    |    E    |   MPPE     |  inertial  |

We estimate MPPE at constant speed condition to know the lower limit of FLUX
observer operation. You can get BEMF values of mode switching expressed
relative to MPPE.

	# reg pm.flux_gain_TAKE_E
	# reg pm.flux_gain_GIVE_E

## Moment of inertia

Final estimate is moment of inertia **pm.const_Ja**. To do this possible a
speed maneuver is performed. Note that this may result energy regeneration so
your power supply must tolerate this.

This constant is used to predict the speed changes from a known current.

## Hall sensors adjustment

**TODO**

