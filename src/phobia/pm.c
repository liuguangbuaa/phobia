#include "libm.h"
#include "pm.h"

void pm_default(pmc_t *pm)
{
	pm->dc_minimal = 0.25f;		/* (us) */
	pm->dc_clearance = 5.0f;	/* (us) */
	pm->dc_bootstrap = 10.f;	/* (ms) */

	pm->config_NOP = PM_NOP_THREE_PHASE;
	pm->config_TVM = PM_ENABLED;
	pm->config_IFB = PM_IFB_AB_INLINE;
	pm->config_VSI_SILENT = PM_DISABLED;
	pm->config_FORCED = PM_ENABLED;
	pm->config_QENC_FORCED_ALIGN = PM_DISABLED;
	pm->config_ESTIMATE = PM_ESTIMATE_FLUX;
	pm->config_HFI = PM_DISABLED;
	pm->config_SENSOR = PM_SENSOR_DISABLED;
	pm->config_WEAK = PM_DISABLED;
	pm->config_DRIVE = PM_DRIVE_SPEED;
	pm->config_SERVO = PM_DISABLED;
	pm->config_INFO	= PM_ENABLED;
	pm->config_BOOST = PM_DISABLED;

	pm->tm_transient_slow = 50.f;	/* (ms) */
	pm->tm_transient_fast = 2.f;	/* (ms) */
	pm->tm_voltage_hold = 100.f;	/* (ms) */
	pm->tm_current_hold = 500.f;	/* (ms) */
	pm->tm_instant_probe = 2.f;	/* (ms) */
	pm->tm_average_drift = 100.f;	/* (ms) */
	pm->tm_average_probe = 500.f;	/* (ms) */
	pm->tm_startup = 50.f;		/* (ms) */

	pm->ad_IA[0] = 0.f;
	pm->ad_IA[1] = 1.f;
	pm->ad_IB[0] = 0.f;
	pm->ad_IB[1] = 1.f;
	pm->ad_US[0] = 0.f;
	pm->ad_US[1] = 1.f;
	pm->ad_UA[0] = 0.f;
	pm->ad_UA[1] = 1.f;
	pm->ad_UB[0] = 0.f;
	pm->ad_UB[1] = 1.f;
	pm->ad_UC[0] = 0.f;
	pm->ad_UC[1] = 1.f;

	pm->probe_current_hold = 10.f;
	pm->probe_current_weak = 5.f;
	pm->probe_hold_angle = 0.f;
	pm->probe_current_sine = 2.f;
	pm->probe_freq_sine_hz = pm->freq_hz / 24.f;
	pm->probe_speed_hold = 700.f;
	pm->probe_speed_spinup = 1700.f;
	pm->probe_speed_detached = 50.f;
	pm->probe_gain_P = 1E-2f;
	pm->probe_gain_I = 1E-3f;

	pm->fault_voltage_tol = 2.f;
	pm->fault_current_tol = 2.f;
	pm->fault_accuracy_tol = 1E-1f;
	pm->fault_current_halt = 156.f;
	pm->fault_voltage_halt = 57.f;

	pm->tvm_READY = PM_DISABLED;
	pm->tvm_range_DC = .16f;
	pm->tvm_FIR_A[0] = 0.f;
	pm->tvm_FIR_A[1] = 0.f;
	pm->tvm_FIR_A[2] = 0.f;
	pm->tvm_FIR_B[0] = 0.f;
	pm->tvm_FIR_B[1] = 0.f;
	pm->tvm_FIR_B[2] = 0.f;
	pm->tvm_FIR_C[0] = 0.f;
	pm->tvm_FIR_C[1] = 0.f;
	pm->tvm_FIR_C[2] = 0.f;

	pm->lu_MPPE = 30.f;
	pm->lu_gain_TAKE = 4.f;
	pm->lu_gain_GIVE = 2.f;
	pm->lu_gain_LEVE = 2E-1f;
	pm->lu_gain_LP = 1E-1f;

	pm->forced_hold_D = 10.f;
	pm->forced_maximal = 200.f;
	pm->forced_reverse = pm->forced_maximal;
	pm->forced_accel = 500.f;

	pm->detach_take_U = .5f;
	pm->detach_gain_AD = 2E-1f;
	pm->detach_gain_SF = 5E-2f;

	pm->flux_gain_IN = 5E-4f;
	pm->flux_gain_LO = 2E-5f;
	pm->flux_gain_HI = 5E-5f;
	pm->flux_gain_AD = 2E-1f;
	pm->flux_gain_SF = 5E-2f;

	pm->hfi_DIV = 12;
	pm->hfi_SKIP = 1;
	pm->hfi_SUM = 5;
	pm->hfi_inject = 4.f;
	pm->hfi_gain_SF = 5E-3f;

	pm->hall_READY = PM_DISABLED;
	pm->hall_prol_T = 0.1f;
	pm->hall_gain_PF = 1E-0f;
	pm->hall_gain_SF = 1E-3f;
	pm->hall_gain_LP = 5E-2f;

	pm->qenc_PPR = 2600;
	pm->qenc_FILTER = 1;
	pm->qenc_Zq = 1.f;
	pm->qenc_gain_PF = 1E-0f;
	pm->qenc_gain_SF = 2E-2f;
	pm->qenc_gain_IF = 0E-1f;

	pm->const_E = 0.f;
	pm->const_R = 0.f;
	pm->const_L = 0.f;
	pm->const_Zp = 1;
	pm->const_Ja = 0.f;

	pm->const_im_K[0] = 1.f;
	pm->const_im_K[1] = 0.f;
	pm->const_im_K[2] = 1.f;

	pm->watt_wP_maximal = 4000.f;
	pm->watt_iDC_maximal = 80.f;
	pm->watt_wP_reverse = 4000.f;
	pm->watt_iDC_reverse = 80.f;
	pm->watt_dclink_HI = 56.f;
	pm->watt_dclink_LO = 7.f;
	pm->watt_gain_LP_F = 5E-2f;
	pm->watt_gain_LP_P = 5E-2f;

	pm->i_maximal = 120.f;
	pm->i_reverse = pm->i_maximal;
	pm->i_derated_HFI = 50.f;
	pm->i_tol_Z = 0.f;
	pm->i_gain_P = 2E-1f;
	pm->i_gain_I = 5E-3f;

	pm->inject_ratio_D = .5f;
	pm->inject_gain_AD = 1.f;

	pm->weak_maximal = 30.f;
	pm->weak_bias_U = 2.f;
	pm->weak_gain_EU = 7E-3f;

	pm->v_maximal = PM_UMAX(pm) * 60.f;
	pm->v_reverse = pm->v_maximal;

	pm->s_maximal = pm->freq_hz * (2.f * M_PI_F / 18.f);
	pm->s_reverse = pm->s_maximal;
	pm->s_accel = 2000.f;
	pm->s_gain_P = 2E-2f;
	pm->s_gain_I = 0E-3f;
	pm->s_gain_S = 1E-0f;

	pm->x_tol_N = 1.f;
	pm->x_tol_Z = 0.f;
	pm->x_gain_P = 35.f;
	pm->x_gain_N = 2E-1f;

	pm->boost_gain_P = 1E-2f;
	pm->boost_gain_I = 1E-3f;
}

void pm_build(pmc_t *pm)
{
	pm->ts_minimal = (int) (pm->dc_minimal * (1.f / 1000000.f)
			* pm->freq_hz * (float) pm->dc_resolution);
	pm->ts_clearance = (int) (pm->dc_clearance * (1.f / 1000000.f)
			* pm->freq_hz * (float) pm->dc_resolution);
	pm->ts_bootstrap = PM_TSMS(pm, pm->dc_bootstrap);
	pm->ts_inverted = 1.f / (float) pm->dc_resolution;

	if (pm->config_ESTIMATE == PM_ESTIMATE_FLUX) {

		pm->temp_const_iE = 1.f / pm->const_E;
	}

	if (pm->config_HFI == PM_ENABLED) {

		pm->temp_HFI_wS = 2.f * M_PI_F * pm->freq_hz / (float) pm->hfi_DIV;
		pm->temp_HFI_HT[0] = m_cosf(pm->temp_HFI_wS * pm->dT * .5f);
		pm->temp_HFI_HT[1] = m_sinf(pm->temp_HFI_wS * pm->dT * .5f);
	}

	if (pm->config_SENSOR == PM_SENSOR_QENC) {

		pm->temp_2PZiPPR = 2.f * M_PI_F * pm->const_Zp
			* pm->qenc_Zq / (float) pm->qenc_PPR;
	}
}

static void
pm_forced(pmc_t *pm)
{
	float		wSP, dS;

	/* Get the setpoint of forced speed.
	 * */
	if (pm->config_DRIVE == PM_DRIVE_CURRENT) {

		wSP = (pm->i_setpoint_Q < - pm->fault_current_tol) ? - PM_MAX_F
			: (pm->i_setpoint_Q > pm->fault_current_tol) ? PM_MAX_F : 0.f;
	}
	else if (pm->config_DRIVE == PM_DRIVE_SPEED) {

		wSP = pm->s_setpoint;
	}
	else {
		wSP = 0.f;
	}

	/* Maximal forced speed constraint.
	 * */
	wSP = (wSP > pm->forced_maximal) ? pm->forced_maximal :
		(wSP < - pm->forced_reverse) ? - pm->forced_reverse : wSP;

	/* Update actual speed with specified acceleration.
	 * */
	dS = pm->forced_accel * pm->dT;
	pm->forced_wS = (pm->forced_wS < wSP - dS) ? pm->forced_wS + dS :
		(pm->forced_wS > wSP + dS) ? pm->forced_wS - dS : wSP;

	/* Update DQ frame.
	 * */
	m_rotf(pm->forced_F, pm->forced_wS * pm->dT, pm->forced_F);
}

static void
pm_detached_FLUX(pmc_t *pm)
{
	float		uA, uB, uC, uX, uY, U, EX, EY, E, S;

	/* Get BEMF voltage.
	 * */
	uA = pm->fb_uA;
	uB = pm->fb_uB;
	uC = pm->fb_uC;

	if (PM_CONFIG_NOP(pm) == PM_NOP_THREE_PHASE) {

		U = (1.f / 3.f) * (uA + uB + uC);
		uA = U - uA;
		uB = U - uB;

		uX = uA;
		uY = .57735027f * uA + 1.1547005f * uB;
	}
	else {
		uX = uC - uA;
		uY = uC - uB;
	}

	pm->detach_X = uX;
	pm->detach_Y = uY;

	/* Absolute BEMF voltage.
	 * */
	U = m_sqrtf(uX * uX + uY * uY);

	if (U > pm->detach_take_U) {

		E = 1.f / U;

		uX *= E;
		uY *= E;

		if (pm->detach_TIM != 0) {

			/* Speed estimation (PLL).
			 * */
			m_rotf(pm->detach_V, pm->flux_wS * pm->dT, pm->detach_V);

			EX = uX * pm->detach_V[0] + uY * pm->detach_V[1];
			EY = uY * pm->detach_V[0] - uX * pm->detach_V[1];

			if (EX > M_EPS_F) {

				E = EY / EX * pm->freq_hz;

				S = U * pm->detach_gain_AD;
				S = (S > 1.f) ? 1.f : S;

				pm->flux_wS += E * S * pm->detach_gain_SF;
			}

			pm->flux_E = U / m_fabsf(pm->flux_wS);

			E = (pm->flux_wS < 0.f) ? - 1.f : 1.f;

			pm->flux_F[0] = uY * E;
			pm->flux_F[1] = - uX * E;

			E = (pm->const_E > M_EPS_F) ? pm->const_E : pm->flux_E;

			pm->flux_X = E * pm->flux_F[0];
			pm->flux_Y = E * pm->flux_F[1];
		}

		pm->detach_V[0] = uX;
		pm->detach_V[1] = uY;

		pm->detach_TIM++;
	}
	else {
		pm->detach_TIM = 0;
		pm->flux_wS = 0.f;
	}
}

static void
pm_estimate_FLUX(pmc_t *pm)
{
	float		uX, uY, lX, lY, iEE, EX, EY, DX, DY, E, gain_F;

	/* Get the actual voltage.
	 * */
	uX = pm->vsi_X - pm->const_R * pm->lu_iX;
	uY = pm->vsi_Y - pm->const_R * pm->lu_iY;

	if (PM_CONFIG_TVM(pm) == PM_ENABLED) {

		uX += pm->tvm_DX - pm->vsi_DX;
		uY += pm->tvm_DY - pm->vsi_DY;
	}

	/* Stator FLUX linear model.
	 * */
	lX = pm->const_L * pm->lu_iX;
	lY = pm->const_L * pm->lu_iY;

	if (pm->const_E > M_EPS_F) {

		iEE = pm->temp_const_iE * pm->temp_const_iE;

		/* Adaptive GAIN.
		 * */
		E = m_fabsf(pm->flux_wS * pm->const_E) * pm->flux_gain_AD;
		E = (E > 1.f) ? 1.f : 0.f;

		gain_F = (pm->flux_gain_LO + E * pm->flux_gain_HI) * pm->temp_const_iE;

		/* FLUX observer equations.
		 * */
		pm->flux_X += uX * pm->dT;
		pm->flux_Y += uY * pm->dT;

		EX = pm->flux_X - lX;
		EY = pm->flux_Y - lY;

		gain_F *= 1.f - (EX * EX + EY * EY) * iEE;

		pm->flux_X += EX * gain_F;
		pm->flux_Y += EY * gain_F;
	}
	else {
		/* Startup estimation.
		 * */
		pm->flux_X += uX * pm->dT;
		pm->flux_Y += uY * pm->dT;

		EX = pm->flux_X - lX;
		EY = pm->flux_Y - lY;

		gain_F = - pm->flux_gain_IN;

		pm->flux_X += EX * gain_F;
		pm->flux_Y += EY * gain_F;
	}

	/* Extract rotor FLUX linkage.
	 * */
	EX = pm->flux_X - lX;
	EY = pm->flux_Y - lY;

	E = m_sqrtf(EX * EX + EY * EY);

	pm->flux_E = E;

	if (E > M_EPS_F) {

		E = 1.f / E;

		EX *= E;
		EY *= E;

		if (		pm->lu_mode == PM_LU_FORCED
				&& pm->const_E < M_EPS_F) {

			pm->flux_wS = pm->forced_wS;
		}
		else {
			/* Speed estimation (PLL).
			 * */
			m_rotf(pm->flux_F, pm->flux_wS * pm->dT, pm->flux_F);

			DX = EX * pm->flux_F[0] + EY * pm->flux_F[1];
			DY = EY * pm->flux_F[0] - EX * pm->flux_F[1];

			if (DX > M_EPS_F) {

				E = DY / DX * pm->freq_hz;
				pm->flux_wS += E * pm->flux_gain_SF;
			}
		}

		pm->flux_F[0] = EX;
		pm->flux_F[1] = EY;
	}
}

static void
pm_HFI_DFT(const float DFT[8], float EV[2])
{
	float		LSQ[9], B[4], IMP[3], R;

	LSQ[0] = DFT[1] * DFT[1] + DFT[0] * DFT[0];
	LSQ[1] = - DFT[1] * DFT[5] - DFT[0] * DFT[4];
	LSQ[5] = DFT[5] * DFT[5] + DFT[4] * DFT[4];
	LSQ[2] = LSQ[5] + LSQ[0];
	LSQ[3] = 0.f;
	LSQ[4] = LSQ[1];

	R = (DFT[2] * DFT[0] + DFT[3] * DFT[1] + DFT[6] * DFT[4] + DFT[7] * DFT[5]) / LSQ[2];

	B[0] = DFT[2] - DFT[0] * R;
	B[1] = DFT[3] - DFT[1] * R;
	B[2] = DFT[6] - DFT[4] * R;
	B[3] = DFT[7] - DFT[5] * R;

	LSQ[6] = DFT[1] * B[0] - DFT[0] * B[1];
	LSQ[7] = - DFT[5] * B[0] + DFT[4] * B[1] - DFT[1] * B[2] + DFT[0] * B[3];
	LSQ[8] = DFT[5] * B[2] - DFT[4] * B[3];

	m_la_LSQ_3(LSQ, IMP);
	m_la_EIV(IMP, EV);
}

static void
pm_estimate_HFI(pmc_t *pm)
{
	float			iX, iY, iD, iQ, uD, uQ;
	float			EV[2], F[2], E;

	if (pm->hfi_DFT_N == pm->hfi_DIV * pm->hfi_SKIP) {

		pm->hfi_DFT[0] = 0.f;
		pm->hfi_DFT[1] = 0.f;
		pm->hfi_DFT[2] = 0.f;
		pm->hfi_DFT[3] = 0.f;
		pm->hfi_DFT[4] = 0.f;
		pm->hfi_DFT[5] = 0.f;
		pm->hfi_DFT[6] = 0.f;
		pm->hfi_DFT[7] = 0.f;

		pm->hfi_REM[0] = 0.f;
		pm->hfi_REM[1] = 0.f;
		pm->hfi_REM[2] = 0.f;
		pm->hfi_REM[3] = 0.f;
		pm->hfi_REM[4] = 0.f;
		pm->hfi_REM[5] = 0.f;
		pm->hfi_REM[6] = 0.f;
		pm->hfi_REM[7] = 0.f;
	}

	/* Inductance relative anisotropy (K) compensation.
	 * */
	iX = pm->const_im_K[0] * pm->REM[14] - pm->const_im_K[1] * pm->REM[15];
	iY = pm->const_im_K[2] * pm->REM[15] - pm->const_im_K[1] * pm->REM[14];

	iD = pm->lu_F[0] * iX + pm->lu_F[1] * iY;
	iQ = pm->lu_F[0] * iY - pm->lu_F[1] * iX;

	/* Get corrected frame (half-period shift).
	 * */
	F[0] = pm->lu_F[0] * pm->temp_HFI_HT[0] - pm->lu_F[1] * pm->temp_HFI_HT[1];
	F[1] = pm->lu_F[1] * pm->temp_HFI_HT[0] + pm->lu_F[0] * pm->temp_HFI_HT[1];

	/* Get VSI voltages on DQ-axes.
	 * */
	uD = F[0] * pm->tvm_DX + F[1] * pm->tvm_DY;
	uQ = F[0] * pm->tvm_DY - F[1] * pm->tvm_DX;

	/* Discrete Fourier Transform (DFT).
	 * */
	m_rsum(&pm->hfi_DFT[0], &pm->hfi_REM[0], iD * pm->hfi_wave[0]);
	m_rsum(&pm->hfi_DFT[1], &pm->hfi_REM[1], iD * pm->hfi_wave[1]);
	m_rsum(&pm->hfi_DFT[2], &pm->hfi_REM[2], uD * pm->hfi_wave[0]);
	m_rsum(&pm->hfi_DFT[3], &pm->hfi_REM[3], uD * pm->hfi_wave[1]);
	m_rsum(&pm->hfi_DFT[4], &pm->hfi_REM[4], iQ * pm->hfi_wave[0]);
	m_rsum(&pm->hfi_DFT[5], &pm->hfi_REM[5], iQ * pm->hfi_wave[1]);
	m_rsum(&pm->hfi_DFT[6], &pm->hfi_REM[6], uQ * pm->hfi_wave[0]);
	m_rsum(&pm->hfi_DFT[7], &pm->hfi_REM[7], uQ * pm->hfi_wave[1]);

	pm->REM[14] = pm->lu_iX;
	pm->REM[15] = pm->lu_iY;

	pm->hfi_DFT_N += 1;

	if (pm->hfi_DFT_N >= pm->hfi_DIV * (pm->hfi_SUM + pm->hfi_SKIP)) {

		pm_HFI_DFT(pm->hfi_DFT, EV);

		/* Speed estimation (PLL).
		 * */
		if (EV[0] > M_EPS_F) {

			E = EV[1] / EV[0] * pm->freq_hz;
			pm->hfi_wS += E * pm->hfi_gain_SF;
		}

		/* Get actual saliency frame.
		 * */
		F[0] = pm->lu_F[0] * EV[0] - pm->lu_F[1] * EV[1];
		F[1] = pm->lu_F[1] * EV[0] + pm->lu_F[0] * EV[1];

		E = (3.f - F[0] * F[0] - F[1] * F[1]) * .5f;

		pm->hfi_F[0] = F[0] * E;
		pm->hfi_F[1] = F[1] * E;

		pm->hfi_DFT_N = 0;
	}

	/* Extrapolate rotor position.
	 * */
	m_rotf(pm->hfi_F, pm->hfi_wS * pm->dT, pm->hfi_F);
}

static void
pm_sensor_HALL(pmc_t *pm)
{
	float		hF[2], A, B, E;
	int		HS;

	HS = pm->fb_HS;

	if (HS >= 1 && HS <= 6) {

		if (HS == pm->hall_HS) {

			if (pm->hall_DIRF * pm->hall_lpf_wS > M_EPS_F) {

				E = pm->hall_lpf_wS * pm->hall_gain_PF * pm->dT;
				B = PM_HALL_SPAN * pm->hall_gain_PF;

				if (		m_fabsf(E) > M_EPS_F
						&& m_fabsf(pm->hall_prolS) < B) {

					m_rotf(pm->hall_F, E, pm->hall_F);

					pm->hall_prolS += E;
				}
				else {
					E = 0.f;
				}

				if (pm->hall_prolTIM != 0) {

					pm->hall_prolTIM--;
				}
				else {
					pm->hall_DIRF = 0;
					pm->hall_F[0] = pm->hall_ST[HS].X;
					pm->hall_F[1] = pm->hall_ST[HS].Y;

					E = 0.f;
				}
			}
			else if (pm->hall_DIRF != 0) {

				pm->hall_DIRF = 0;
				pm->hall_F[0] = pm->hall_ST[HS].X;
				pm->hall_F[1] = pm->hall_ST[HS].Y;

				E = 0.f;
			}
			else {
				E = 0.f;
			}
		}
		else {
			hF[0] = pm->hall_ST[HS].X;
			hF[1] = pm->hall_ST[HS].Y;

			A = pm->hall_ST[pm->hall_HS].X;
			B = pm->hall_ST[pm->hall_HS].Y;

			E = hF[1] * A - hF[0] * B;
			pm->hall_DIRF = (E < 0.f) ? - 1 : 1;

			E = - pm->hall_DIRF * (PM_HALL_SPAN / 2.f);
			m_rotf(hF, E * pm->hall_gain_PF, hF);

			A = hF[0] * pm->hall_F[0] + hF[1] * pm->hall_F[1];
			B = hF[1] * pm->hall_F[0] - hF[0] * pm->hall_F[1];

			pm->hall_HS = HS;
			pm->hall_prolTIM = pm->freq_hz * pm->hall_prol_T;
			pm->hall_prolS = 0.f;
			pm->hall_F[0] = hF[0];
			pm->hall_F[1] = hF[1];

			E = m_atan2f(B, A);
		}

		pm->hall_wS += (E * pm->freq_hz - pm->hall_wS) * pm->hall_gain_SF;
		pm->hall_lpf_wS += (pm->hall_wS - pm->hall_lpf_wS) * pm->hall_gain_LP;
	}
	else {
		pm->hall_READY = PM_DISABLED;

		pm->fail_reason = PM_ERROR_SENSOR_HALL_FAULT;
		pm->lu_mode = PM_LU_ESTIMATE_FLUX;
	}
}

static void
pm_sensor_QENC(pmc_t *pm)
{
	float			relR, rotR, rotF[2], gain_SF;
	int			relEP, N;

	relEP = (short int) (pm->fb_EP - pm->qenc_baseEP);

	pm->qenc_baseEP = pm->fb_EP;
	pm->qenc_prolTIM++;

	if (pm->qenc_FILTER == 1) {

		N =  (relEP > 0 && pm->qenc_lastEP < 0) ? - 1 : 0;
		N += (relEP < 0 && pm->qenc_lastEP > 0) ?   1 : 0;

		pm->qenc_lastEP = (relEP != 0) ? relEP : pm->qenc_lastEP;

		relEP += N;
	}

	if (relEP == 0) {

		relR = pm->qenc_wS * pm->qenc_gain_PF * pm->dT;
		relR = (m_fabsf(pm->qenc_prolS) < pm->temp_2PZiPPR) ? relR : 0.f;
		pm->qenc_prolS += relR;

		rotR = pm->qenc_prolS + (float) pm->qenc_rotEP * pm->temp_2PZiPPR;
	}
	else {
		relR = (float) relEP * pm->temp_2PZiPPR - pm->qenc_prolS;
		pm->qenc_prolS = 0.f;

		pm->qenc_rotEP += relEP;
		pm->qenc_rotEP += (pm->qenc_rotEP < - pm->qenc_PPR) ? pm->qenc_PPR : 0;
		pm->qenc_rotEP += (pm->qenc_rotEP > pm->qenc_PPR) ? - pm->qenc_PPR : 0;

		rotR = (float) pm->qenc_rotEP * pm->temp_2PZiPPR;
	}

	N = (int) (rotR / (2.f * M_PI_F));
	rotR -= (float) (N * 2.f * M_PI_F);

	rotR += (rotR < - M_PI_F) ? 2.f * M_PI_F : 0.f;
	rotR += (rotR > M_PI_F) ? - 2.f * M_PI_F : 0.f;

	rotF[0] = m_cosf(rotR);
	rotF[1] = m_sinf(rotR);

	pm->qenc_F[0] = rotF[0] * pm->qenc_baseF[0] - rotF[1] * pm->qenc_baseF[1];
	pm->qenc_F[1] = rotF[1] * pm->qenc_baseF[0] + rotF[0] * pm->qenc_baseF[1];

	gain_SF = 1.f / (float) pm->qenc_prolTIM;
	gain_SF = (gain_SF < pm->qenc_gain_SF) ? gain_SF : pm->qenc_gain_SF;

	pm->qenc_wS += (relR * pm->freq_hz - pm->qenc_wS) * gain_SF;

	if (		pm->config_DRIVE == PM_DRIVE_SPEED
			&& pm->qenc_gain_IF > M_EPS_F
			&& pm->const_Ja > M_EPS_F
			&& m_fabsf(pm->qenc_prolS) < pm->temp_2PZiPPR) {

		pm->qenc_wS += (pm->lu_iQ - pm->s_integral)
			* pm->qenc_gain_IF * pm->dT / pm->const_Ja;
	}

	if (relEP != 0) {

		pm->qenc_prolTIM = 0;
	}
}

static void
pm_lu_flux_zone(pmc_t *pm)
{
	float			lev_wS, lev_E;
	int			lev_TIM;

	/* Smooth speed (LPF).
	 * */
	pm->lu_flux_lpf_wS += (pm->flux_wS - pm->lu_flux_lpf_wS) * pm->lu_gain_LP;

	if (pm->lu_flux_zone == PM_FLUX_UNCERTAIN) {

		lev_wS = pm->lu_gain_TAKE * pm->lu_MPPE;

		if (pm->lu_mode == PM_LU_DETACHED) {

			lev_TIM = PM_TSMS(pm, pm->tm_startup);

			if (		m_fabsf(pm->lu_flux_lpf_wS) > lev_wS
					&& pm->detach_TIM > lev_TIM) {

				pm->lu_flux_zone = PM_FLUX_HIGH;
				pm->lu_flux_locked = 1;
			}
		}
		else {
			lev_E = pm->lu_gain_LEVE * pm->const_E;

			if (m_fabsf(pm->flux_E - pm->const_E) < lev_E) {

				if (		pm->lu_flux_lpf_wS > lev_wS
						&& pm->lu_wS > lev_wS) {

					pm->lu_flux_zone = PM_FLUX_HIGH;
					pm->lu_flux_locked = 1;
				}
				else if (	pm->lu_flux_lpf_wS < - lev_wS
						&& pm->lu_wS < - lev_wS) {

					pm->lu_flux_zone = PM_FLUX_HIGH;
					pm->lu_flux_locked = 1;
				}
			}
		}
	}
	else if (pm->lu_flux_zone == PM_FLUX_HIGH) {

		lev_wS = pm->lu_gain_GIVE * pm->lu_MPPE;

		if (pm->lu_mode == PM_LU_DETACHED) {

			if (		m_fabsf(pm->lu_flux_lpf_wS) < lev_wS
					|| pm->detach_TIM == 0) {

				pm->lu_flux_zone = PM_FLUX_UNCERTAIN;
			}
		}
		else {
			if (m_fabsf(pm->lu_flux_lpf_wS) < lev_wS) {

				pm->lu_flux_zone = PM_FLUX_UNCERTAIN;
			}
		}
	}
}

static void
pm_lu_FSM(pmc_t *pm)
{
	int			lev_SKIP, lev_HOLD;

	if (pm->lu_mode == PM_LU_DETACHED) {

		if (pm->config_ESTIMATE == PM_ESTIMATE_FLUX) {

			if (pm->detach_SKIP > 0) {

				pm_detached_FLUX(pm);
			}

			pm_lu_flux_zone(pm);

			pm->lu_F[0] = pm->flux_F[0];
			pm->lu_F[1] = pm->flux_F[1];
			pm->lu_wS = pm->flux_wS;
		}

		pm->detach_SKIP++;

		if (pm->lu_flux_zone != PM_FLUX_DETACHED) {

			lev_SKIP = 2.f * PM_TSMS(pm, pm->tm_startup);

			if (pm->lu_flux_zone == PM_FLUX_HIGH) {

				pm->lu_mode = PM_LU_ESTIMATE_FLUX;

				pm->proc_set_Z(0);
			}
			else if (pm->detach_SKIP < lev_SKIP) {

				/* Not enough time passed to go into low speed
				 * mode. Shut up here.
				 * */
			}
			else if (	pm->config_SENSOR == PM_SENSOR_HALL
					&& pm->hall_READY == PM_ENABLED) {

				pm->lu_mode = PM_LU_SENSOR_HALL;

				pm->hall_HS = pm->fb_HS;
				pm->hall_DIRF = 0;

				pm->hall_F[0] = pm->lu_F[0];
				pm->hall_F[1] = pm->lu_F[1];
				pm->hall_wS = pm->lu_wS;
				pm->hall_lpf_wS = pm->lu_wS;

				pm->proc_set_Z(0);
			}
			else if (pm->config_HFI == PM_ENABLED) {

				pm->lu_mode = PM_LU_ESTIMATE_HFI;

				pm->hfi_DFT_N = 0;

				pm->hfi_F[0] = pm->lu_F[0];
				pm->hfi_F[1] = pm->lu_F[1];
				pm->hfi_wS = pm->lu_wS;

				pm->proc_set_Z(0);
			}
			else if (pm->config_FORCED == PM_ENABLED) {

				pm->lu_mode = PM_LU_FORCED;

				pm->forced_F[0] = pm->flux_F[0];
				pm->forced_F[1] = pm->flux_F[1];
				pm->forced_wS = pm->flux_wS;
				pm->forced_TIM = 0;

				pm->proc_set_Z(0);
			}
		}
	}
	else if (pm->lu_mode == PM_LU_FORCED) {

		pm_forced(pm);

		if (pm->config_ESTIMATE == PM_ESTIMATE_FLUX) {

			pm_estimate_FLUX(pm);
			pm_lu_flux_zone(pm);
		}

		pm->forced_TIM++;

		pm->lu_F[0] = pm->forced_F[0];
		pm->lu_F[1] = pm->forced_F[1];
		pm->lu_wS = pm->forced_wS;

		if (		pm->lu_flux_zone == PM_FLUX_HIGH
				&& pm->const_E > M_EPS_F) {

			pm->lu_mode = PM_LU_ESTIMATE_FLUX;
		}
		else {
			lev_HOLD = PM_TSMS(pm, pm->tm_current_hold);

			if (		pm->config_SENSOR == PM_SENSOR_QENC
					&& pm->config_QENC_FORCED_ALIGN == PM_ENABLED
					&& pm->forced_TIM > lev_HOLD) {

				pm->lu_mode = PM_LU_SENSOR_QENC;

				pm->qenc_baseEP = pm->fb_EP;
				pm->qenc_baseF[0] = pm->lu_F[0];
				pm->qenc_baseF[1] = pm->lu_F[1];
				pm->qenc_lastEP = 0;
				pm->qenc_rotEP = 0;
				pm->qenc_prolTIM = 0;
				pm->qenc_prolS = 0.f;

				pm->qenc_F[0] = pm->lu_F[0];
				pm->qenc_F[1] = pm->lu_F[1];
				pm->qenc_wS = pm->lu_wS;
			}
		}
	}
	else if (pm->lu_mode == PM_LU_ESTIMATE_FLUX) {

		if (pm->config_ESTIMATE == PM_ESTIMATE_FLUX) {

			pm_estimate_FLUX(pm);
			pm_lu_flux_zone(pm);

			pm->lu_F[0] = pm->flux_F[0];
			pm->lu_F[1] = pm->flux_F[1];
			pm->lu_wS = pm->flux_wS;
		}

		if (pm->lu_flux_zone == PM_FLUX_UNCERTAIN) {

			if (		pm->config_SENSOR == PM_SENSOR_HALL
					&& pm->hall_READY == PM_ENABLED) {

				pm->lu_mode = PM_LU_SENSOR_HALL;

				pm->hall_HS = pm->fb_HS;
				pm->hall_DIRF = 0;

				pm->hall_F[0] = pm->lu_F[0];
				pm->hall_F[1] = pm->lu_F[1];
				pm->hall_wS = pm->lu_wS;
				pm->hall_lpf_wS = pm->lu_wS;
			}
			else if (	pm->config_SENSOR == PM_SENSOR_QENC
					&& pm->lu_flux_locked == 1) {

				pm->lu_mode = PM_LU_SENSOR_QENC;

				pm->qenc_baseEP = pm->fb_EP;
				pm->qenc_baseF[0] = pm->lu_F[0];
				pm->qenc_baseF[1] = pm->lu_F[1];
				pm->qenc_lastEP = 0;
				pm->qenc_rotEP = 0;
				pm->qenc_prolTIM = 0;
				pm->qenc_prolS = 0.f;

				pm->qenc_F[0] = pm->lu_F[0];
				pm->qenc_F[1] = pm->lu_F[1];
				pm->qenc_wS = pm->lu_wS;
			}
			else if (pm->config_HFI == PM_ENABLED) {

				pm->lu_mode = PM_LU_ESTIMATE_HFI;

				pm->hfi_DFT_N = 0;

				pm->hfi_F[0] = pm->lu_F[0];
				pm->hfi_F[1] = pm->lu_F[1];
				pm->hfi_wS = pm->lu_wS;
			}
			else if (pm->config_FORCED == PM_ENABLED) {

				pm->lu_mode = PM_LU_FORCED;

				pm->forced_F[0] = pm->flux_F[0];
				pm->forced_F[1] = pm->flux_F[1];
				pm->forced_wS = pm->flux_wS;
				pm->forced_TIM = 0;
			}
			else if (PM_CONFIG_TVM(pm) == PM_ENABLED) {

				pm->lu_mode = PM_LU_DETACHED;

				pm->detach_TIM = 0;
				pm->detach_SKIP = - PM_TSMS(pm, pm->tm_transient_fast);

				pm->flux_F[0] = 1.f;
				pm->flux_F[1] = 0.f;
				pm->flux_wS = 0.f;

				pm->watt_lpf_D = 0.f;
				pm->watt_lpf_Q = 0.f;
				pm->watt_lpf_wP = 0.f;

				pm->proc_set_Z(7);
			}
		}
	}
	else if (pm->lu_mode == PM_LU_ESTIMATE_HFI) {

		pm_estimate_HFI(pm);

		if (pm->config_ESTIMATE == PM_ESTIMATE_FLUX) {

			pm_estimate_FLUX(pm);
			pm_lu_flux_zone(pm);
		}

		pm->lu_F[0] = pm->hfi_F[0];
		pm->lu_F[1] = pm->hfi_F[1];
		pm->lu_wS = pm->hfi_wS;

		if (pm->lu_flux_zone == PM_FLUX_HIGH) {

			pm->lu_mode = PM_LU_ESTIMATE_FLUX;
		}
	}
	else if (pm->lu_mode == PM_LU_SENSOR_HALL) {

		pm_sensor_HALL(pm);

		if (pm->config_ESTIMATE == PM_ESTIMATE_FLUX) {

			pm_estimate_FLUX(pm);
			pm_lu_flux_zone(pm);
		}

		pm->lu_F[0] = pm->hall_F[0];
		pm->lu_F[1] = pm->hall_F[1];
		pm->lu_wS = pm->hall_wS;

		if (pm->lu_flux_zone == PM_FLUX_HIGH) {

			pm->lu_mode = PM_LU_ESTIMATE_FLUX;
		}
	}
	else if (pm->lu_mode == PM_LU_SENSOR_QENC) {

		pm_sensor_QENC(pm);

		if (pm->config_ESTIMATE == PM_ESTIMATE_FLUX) {

			pm_estimate_FLUX(pm);
			pm_lu_flux_zone(pm);
		}

		pm->lu_F[0] = pm->qenc_F[0];
		pm->lu_F[1] = pm->qenc_F[1];
		pm->lu_wS = pm->qenc_wS;

		if (pm->lu_flux_zone == PM_FLUX_HIGH) {

			pm->lu_mode = PM_LU_ESTIMATE_FLUX;
		}
	}

	pm->lu_iD = pm->lu_F[0] * pm->lu_iX + pm->lu_F[1] * pm->lu_iY;
	pm->lu_iQ = pm->lu_F[0] * pm->lu_iY - pm->lu_F[1] * pm->lu_iX;
}

void pm_voltage(pmc_t *pm, float uX, float uY)
{
	float		uA, uB, uC, uMIN, uMAX, uDC;
	int		xA, xB, xC, xMIN, xMAX;

	uX *= pm->temp_const_ifbU;
	uY *= pm->temp_const_ifbU;

	if (PM_CONFIG_NOP(pm) == PM_NOP_THREE_PHASE) {

		uA = uX;
		uB = - .5f * uX + .8660254f * uY;
		uC = - .5f * uX - .8660254f * uY;
	}
	else {
		uA = uX;
		uB = uY;
		uC = 0.f;
	}

	if (uA < uB) {

		uMIN = uA;
		uMAX = uB;
	}
	else {
		uMIN = uB;
		uMAX = uA;
	}

	if (uC < uMIN) {

		uMIN = uC;
	}
	else if (uMAX < uC) {

		uMAX = uC;
	}

	uDC = uMAX - uMIN;

	pm->vsi_DC = uDC;

	if (uDC > 1.f) {

		uDC = 1.f / uDC;

		uA *= uDC;
		uB *= uDC;
		uC *= uDC;

		uMIN *= uDC;
		uMAX *= uDC;
	}

	if (pm->config_VSI_SILENT == PM_ENABLED) {

		uDC = (uMAX - uMIN < .5f) ? .5f - uMAX : 0.f - uMIN;
	}
	else {
		uDC = 0.f - uMIN;
	}

	uA += uDC;
	uB += uDC;
	uC += uDC;

	xA = (int) (pm->dc_resolution * uA);
	xB = (int) (pm->dc_resolution * uB);
	xC = (int) (pm->dc_resolution * uC);

	if (pm->lu_mode != PM_LU_DISABLED) {

		if (PM_CONFIG_IFB(pm) == PM_IFB_AB_INLINE) {

			xMAX = pm->dc_resolution - pm->ts_clearance;

			if (xA > xMAX || xB > xMAX) {

				xMAX = (xA < xB) ? xB : xA;
				xMAX = (xMAX < xC) ? xC : xMAX;
				xMIN = pm->dc_resolution - xMAX;

				xA += xMIN;
				xB += xMIN;
				xC += xMIN;
			}

			xMAX = pm->dc_resolution - pm->ts_minimal;

			xA = (xA < pm->ts_minimal) ? 0 : (xA > xMAX) ? pm->dc_resolution : xA;
			xB = (xB < pm->ts_minimal) ? 0 : (xB > xMAX) ? pm->dc_resolution : xB;
			xC = (xC < pm->ts_minimal) ? 0 : (xC > xMAX) ? pm->dc_resolution : xC;
		}
		else if (PM_CONFIG_IFB(pm) == PM_IFB_AB_LOW) {

			xMAX = pm->dc_resolution - pm->ts_clearance;

			xA = (xA < pm->ts_minimal) ? 0 : (xA > xMAX) ? xMAX : xA;
			xB = (xB < pm->ts_minimal) ? 0 : (xB > xMAX) ? xMAX : xB;
			xC = (xC < pm->ts_minimal) ? 0 : (xC > xMAX) ? xMAX : xC;
		}
	}
	else {
		xA += pm->ts_minimal;
		xB += pm->ts_minimal;
		xC += pm->ts_minimal;

		xMAX = pm->dc_resolution - pm->ts_clearance;

		xA = (xA > xMAX) ? xMAX : xA;
		xB = (xB > xMAX) ? xMAX : xB;
		xC = (xC > xMAX) ? xMAX : xC;
	}

	if (pm->ts_bootstrap != 0) {

		pm->vsi_SA = (xA == pm->dc_resolution) ? pm->vsi_SA + 1 : 0;
		pm->vsi_SB = (xB == pm->dc_resolution) ? pm->vsi_SB + 1 : 0;
		pm->vsi_SC = (xC == pm->dc_resolution) ? pm->vsi_SC + 1 : 0;

		if (		pm->vsi_SA > pm->ts_bootstrap
				|| pm->vsi_SB > pm->ts_bootstrap
				|| pm->vsi_SC > pm->ts_bootstrap) {

			pm->fail_reason = PM_ERROR_BOOTSTRAP_FAULT;
			pm->fsm_req = PM_STATE_HALT;
		}
	}

	pm->proc_set_DC(xA, xB, xC);

	xMIN = pm->dc_resolution - pm->ts_clearance;

	/* Check if there are PWM edges within clearance zone. The CURRENT
	 * measurement will be used or rejected based on this flag.
	 * */
	pm->vsi_IF = (pm->vsi_IF & 1) ? 2 : 0;
	pm->vsi_IF |= (xA > xMIN && xA < pm->dc_resolution) ? 1 : 0;
	pm->vsi_IF |= (xB > xMIN && xB < pm->dc_resolution) ? 1 : 0;

	if (PM_CONFIG_TVM(pm) == PM_ENABLED) {

		xMAX = (int) (pm->dc_resolution * pm->tvm_range_DC);

		/* Check if voltages are within acceptable zone. The VOLTAGE
		 * measurement will be used or rejected based on these flags.
		 * */
		pm->vsi_UF = (pm->vsi_UF & 1) ? 2 : 0;
		pm->vsi_UF |= (xA > xMAX || xB > xMAX || xC > xMAX) ? 1 : 0;

		/* Check if voltages are exactly zero to get more accuracy.
		 * */
		pm->vsi_AZ = (pm->vsi_AZ & 1) ? 2 : 0;
		pm->vsi_AZ |= (xA == 0) ? 1 : 0;
		pm->vsi_BZ = (pm->vsi_BZ & 1) ? 2 : 0;
		pm->vsi_BZ |= (xB == 0) ? 1 : 0;
		pm->vsi_CZ = (pm->vsi_CZ & 1) ? 2 : 0;
		pm->vsi_CZ |= (xC == 0) ? 1 : 0;
	}

	pm->vsi_DX = pm->vsi_X;
	pm->vsi_DY = pm->vsi_Y;

	if (PM_CONFIG_NOP(pm) == PM_NOP_THREE_PHASE) {

		uDC = (1.f / 3.f) * (xA + xB + xC);

		uA = (xA - uDC) * pm->const_fb_U * pm->ts_inverted;
		uB = (xB - uDC) * pm->const_fb_U * pm->ts_inverted;

		pm->vsi_X = uA;
		pm->vsi_Y = .57735027f * uA + 1.1547005f * uB;
	}
	else {
		uA = (xA - xC) * pm->const_fb_U * pm->ts_inverted;
		uB = (xB - xC) * pm->const_fb_U * pm->ts_inverted;

		pm->vsi_X = uA;
		pm->vsi_Y = uB;
	}
}

static void
pm_loop_current(pmc_t *pm)
{
	float		sD, sQ, eD, eQ, uD, uQ, uX, uY, wP, hfi_U;
	float		iMAX, iREV, uMAX, wMAX, wREV, E;

	if (pm->lu_mode == PM_LU_FORCED) {

		sD = pm->forced_hold_D;
		sQ = 0.f;
	}
	else if (	pm->lu_mode == PM_LU_ESTIMATE_FLUX
			&& pm->lu_flux_zone != PM_FLUX_HIGH) {

		sD = 0.f;
		sQ = 0.f;
	}
	else {
		sD = pm->i_setpoint_D;
		sQ = pm->i_setpoint_Q;

		if (pm->inject_ratio_D > M_EPS_F) {

			E = m_fabsf(pm->lu_iQ) * pm->const_R * .5f
				- m_fabsf(pm->lu_wS) * pm->const_E;

			if (E > 0.f) {

				E *= pm->inject_gain_AD;
				E = (E > 1.f) ? 1.f : E;

				/* Inject D current to increase observability.
				 * */
				sD = E * pm->inject_ratio_D * m_fabsf(pm->lu_iQ);
			}
		}

		if (pm->config_WEAK == PM_ENABLED) {

			E = (1.f - pm->vsi_DC) * pm->const_fb_U - pm->weak_bias_U;

			pm->weak_D += E * pm->weak_gain_EU;
			pm->weak_D = (pm->weak_D < - pm->weak_maximal) ? - pm->weak_maximal :
				(pm->weak_D > 0.f) ? 0.f : pm->weak_D;

			if (pm->weak_D < - M_EPS_F) {

				/* Flux weakening control.
				 * */
				sD = pm->weak_D;
			}
		}
	}

	/* Get VSI voltages on DQ-axes.
	 * */
	uD = pm->lu_F[0] * pm->tvm_DX + pm->lu_F[1] * pm->tvm_DY;
	uQ = pm->lu_F[0] * pm->tvm_DY - pm->lu_F[1] * pm->tvm_DX;

	/* LPF is necessary to ensure the stability of POWER limiting loop.
	 * */
	pm->watt_lpf_D += (uD - pm->watt_lpf_D) * pm->watt_gain_LP_F;
	pm->watt_lpf_Q += (uQ - pm->watt_lpf_Q) * pm->watt_gain_LP_F;

	/* Operating POWER is a scalar product of voltage and current.
	 * */
	wP = PM_KWAT(pm) * (pm->lu_iD * pm->watt_lpf_D + pm->lu_iQ * pm->watt_lpf_Q);
	pm->watt_lpf_wP += (wP - pm->watt_lpf_wP) * pm->watt_gain_LP_P;

	/* Maximal CURRENT constraint.
	 * */
	iMAX = pm->i_maximal;
	iREV = - pm->i_reverse;

	iMAX = (iMAX < pm->i_derated_1) ? iMAX : pm->i_derated_1;
	iREV = (iREV > - pm->i_derated_1) ? iREV : - pm->i_derated_1;

	if (pm->lu_mode == PM_LU_ESTIMATE_HFI) {

		iMAX = (iMAX < pm->i_derated_HFI) ? iMAX : pm->i_derated_HFI;
		iREV = (iREV > - pm->i_derated_HFI) ? iREV : - pm->i_derated_HFI;
	}

	sD = (sD > iMAX) ? iMAX : (sD < - iMAX) ? - iMAX : sD;
	sQ = (sQ > iMAX) ? iMAX : (sQ < iREV) ? iREV : sQ;

	/* Maximal POWER constraint.
	 * */
	wMAX = pm->watt_wP_maximal;
	wREV = - pm->watt_wP_reverse;

	/* Maximal DC link CURRENT constraint.
	 * */
	wP = pm->watt_iDC_maximal * pm->const_fb_U;
	wMAX = (wP < wMAX) ? wP : wMAX;
	wP = - pm->watt_iDC_reverse * pm->const_fb_U;
	wREV = (wP > wREV) ? wP : wREV;

	/* Prevent DC link OVERVOLTAGE.
	 * */
	wREV = (pm->const_fb_U > pm->watt_dclink_HI) ? 0.f : wREV;
	wMAX = (pm->const_fb_U < pm->watt_dclink_LO) ? 0.f : wMAX;

	/* Apply POWER constraints (with D-axis priority).
	 * */
	wP = PM_KWAT(pm) * (sD * pm->watt_lpf_D + sQ * pm->watt_lpf_Q);

	if (wP > wMAX) {

		wP = PM_KWAT(pm) * sD * pm->watt_lpf_D;

		if (wP > wMAX) {

			sD *= wMAX / wP;
			sQ = 0.f;
		}
		else {
			wMAX -= wP;
			wP = PM_KWAT(pm) * sQ * pm->watt_lpf_Q;

			if (wP > M_EPS_F) {

				sQ *= wMAX / wP;
			}
		}
	}
	else if (wP < wREV) {

		wP = PM_KWAT(pm) * sD * pm->watt_lpf_D;

		if (wP < wREV) {

			sD *= wREV / wP;
			sQ = 0.f;
		}
		else {
			wREV -= wP;
			wP = PM_KWAT(pm) * sQ * pm->watt_lpf_Q;

			if (wP < - M_EPS_F) {

				sQ *= wREV / wP;
			}
		}
	}

	/* Obtain discrepancy.
	 * */
	eD = sD - pm->lu_iD;
	eQ = sQ - pm->lu_iQ;

	/* There is a DEAD zone.
	 * */
	eD = (m_fabsf(eD) > pm->i_tol_Z) ? eD : 0.f;
	eQ = (m_fabsf(eQ) > pm->i_tol_Z) ? eQ : 0.f;

	uD = pm->i_gain_P * eD;
	uQ = pm->i_gain_P * eQ;

	/* Feed forward compensation.
	 * */
	uD += - pm->lu_wS * pm->const_L * sQ;
	uQ += pm->lu_wS * pm->const_L * sD;

	uMAX = PM_UMAX(pm) * pm->const_fb_U;

	pm->i_integral_D += pm->i_gain_I * eD;
	pm->i_integral_D = (pm->i_integral_D > uMAX) ? uMAX :
		(pm->i_integral_D < - uMAX) ? - uMAX : pm->i_integral_D;
	uD += pm->i_integral_D;

	pm->i_integral_Q += pm->i_gain_I * eQ;
	pm->i_integral_Q = (pm->i_integral_Q > uMAX) ? uMAX :
		(pm->i_integral_Q < - uMAX) ? - uMAX : pm->i_integral_Q;
	uQ += pm->i_integral_Q;

	/* Output voltage CLAMP.
	 * */
	uD = (uD > pm->v_maximal) ? pm->v_maximal :
		(uD < - pm->v_maximal) ? - pm->v_maximal : uD;
	uQ = (uQ > pm->v_maximal) ? pm->v_maximal :
		(uQ < - pm->v_reverse) ? - pm->v_reverse : uQ;

	if (pm->lu_mode == PM_LU_ESTIMATE_HFI) {

		/* HF wave synthesis.
		 * */
		m_rotf(pm->hfi_wave, pm->temp_HFI_wS * pm->dT, pm->hfi_wave);

		/* HF injection.
		 * */
		hfi_U = pm->hfi_inject * pm->temp_HFI_wS * pm->const_L;

		uD += pm->hfi_wave[0] * hfi_U;
		uQ += pm->hfi_wave[1] * hfi_U;
	}

	/* Go to XY-axes.
	 * */
	uX = pm->lu_F[0] * uD - pm->lu_F[1] * uQ;
	uY = pm->lu_F[1] * uD + pm->lu_F[0] * uQ;

	pm_voltage(pm, uX, uY);
}

static void
pm_loop_speed(pmc_t *pm)
{
	float		iSP, iFD, wSP, gain_S, eS, dS;

	/* Maximal speed constraint.
	 * */
	wSP = pm->s_setpoint;
	wSP = (wSP > pm->s_maximal) ? pm->s_maximal :
		(wSP < - pm->s_reverse) ? - pm->s_reverse : wSP;

	if (pm->config_SERVO == PM_ENABLED) {

		/* No constraint required.
		 * */
		pm->s_track = wSP;
	}
	else {
		/* Maximal acceleration constraint.
		 * */
		dS = pm->s_accel * pm->dT;
		pm->s_track = (pm->s_track < wSP - dS) ? pm->s_track + dS
			: (pm->s_track > wSP + dS) ? pm->s_track - dS : wSP;
	}

	if (pm->lu_mode == PM_LU_FORCED) {

		pm->i_setpoint_Q = 0.f;
	}
	else {
		/* Get speed discrepancy.
		 * */
		eS = pm->s_track - pm->lu_wS;

		/* Slow down in case of weak speed estimate.
		 * */
		if (pm->lu_mode == PM_LU_ESTIMATE_HFI) {

			gain_S = pm->s_gain_S;
		}
		else if (pm->lu_mode == PM_LU_SENSOR_HALL) {

			gain_S = pm->s_gain_S;
		}
		else {
			gain_S = 1.f;
		}

		/* Here is PI regulator with load reconstruction.
		 * */
		iSP = pm->s_gain_P * gain_S * eS;

		iFD = pm->lu_iQ - (pm->lu_wS - pm->s_base_wS) * pm->freq_hz * pm->const_Ja;
		pm->s_base_wS = pm->lu_wS;

		pm->s_integral += (iFD - pm->s_integral) * pm->s_gain_I * gain_S;
		iSP += pm->s_integral;

		/* Output clamp.
		 * */
		iSP = (iSP > pm->i_maximal) ? pm->i_maximal :
			(iSP < - pm->i_reverse) ? - pm->i_reverse : iSP;

		/* Update current loop setpoint. It would be possible here to
		 * use MTPA or something else.
		 * */
		pm->i_setpoint_Q = iSP;
	}
}

static void
pm_loop_servo(pmc_t *pm)
{
	float		EX, EY, eP, eP_abs, wSP, lerp_S;

	/* Full revolution counter.
	 * */
	if (pm->lu_F[0] < 0.f) {

		if (pm->lu_F[1] < 0.f) {

			pm->x_lu_revol += (pm->x_lu_F1 >= 0.f) ? 1 : 0;
		}
		else {
			pm->x_lu_revol += (pm->x_lu_F1 < 0.f) ? - 1 : 0;
		}
	}

	pm->x_lu_F1 = pm->lu_F[1];

	/* Get position discrepancy.
	 * */
	EX = pm->x_setpoint_F[0] * pm->lu_F[0] + pm->x_setpoint_F[1] * pm->lu_F[1];
	EY = pm->x_setpoint_F[1] * pm->lu_F[0] - pm->x_setpoint_F[0] * pm->lu_F[1];

	eP = m_atan2f(EY, EX);

	if (EY < 0.f) {

		if (pm->lu_F[1] < 0.f && pm->x_setpoint_F[1] >= 0.f)
			eP += 2.f * M_PI_F;
	}
	else {
		if (pm->lu_F[1] >= 0.f && pm->x_setpoint_F[1] < 0.f)
			eP -= 2.f * M_PI_F;
	}

	eP += (pm->x_setpoint_revol - pm->x_lu_revol) * 2.f * M_PI_F;
	eP_abs = m_fabsf(eP);

	pm->x_residual = eP;

	/* Servo is based on constant acceleration formula.
	 * */
	eP = (eP < 0.f) ? - m_sqrtf(eP_abs) : m_sqrtf(eP_abs);

	/* There is a DEAD zone.
	 * */
	eP = (eP_abs > pm->x_tol_Z) ? eP : 0.f;

	/* Slow down in NEAR zone.
	 * */
	lerp_S = (eP_abs < pm->x_tol_N) ? eP_abs / pm->x_tol_N : 1.f;
	lerp_S = pm->x_gain_N + (1.f - pm->x_gain_N) * lerp_S;

	wSP = eP * pm->x_gain_P * lerp_S + pm->x_setpoint_wS;

	/* Update speed loop setpoint.
	 * */
	pm->s_setpoint = wSP;
}

static void
pm_infometer(pmc_t *pm)
{
	float		Wh, Ah, fuel;

	/* Quantum.
	 * */
	const int	revqu = 3;

	/* Full revolution counter.
	 * */
	if (pm->lu_F[0] < 0.f) {

		if (pm->lu_F[1] < 0.f) {

			pm->im_revol_1 += (pm->im_lu_F1 >= 0.f) ? 1 : 0;
		}
		else {
			pm->im_revol_1 += (pm->im_lu_F1 < 0.f) ? - 1 : 0;
		}
	}

	pm->im_lu_F1 = pm->lu_F[1];

	if (pm->im_revol_1 < - revqu) {

		pm->im_revol_total += - pm->im_revol_1;
		pm->im_revol_1 = 0;
	}
	else if (pm->im_revol_1 > revqu) {

		pm->im_revol_total += pm->im_revol_1;
		pm->im_revol_1 = 0;
	}

	/* Traveled distance (m).
	 * */
	pm->im_distance = (float) pm->im_revol_total
		* pm->const_ld_S / (float) pm->const_Zp;

	/* Get WATT per HOUR.
	 * */
	Wh = pm->watt_lpf_wP * pm->dT * (1.f / 3600.f);
	Ah = Wh * pm->temp_const_ifbU;

	if (Wh > 0.f) {

		m_rsum(&pm->im_consumed_Wh, &pm->im_REM[0], Wh);
		m_rsum(&pm->im_consumed_Ah, &pm->im_REM[1], Ah);
	}
	else {
		m_rsum(&pm->im_reverted_Wh, &pm->im_REM[2], - Wh);
		m_rsum(&pm->im_reverted_Ah, &pm->im_REM[3], - Ah);
	}

	/* Fuel gauge.
	 * */
	if (pm->im_capacity_Ah > M_EPS_F) {

		fuel = (pm->im_capacity_Ah - pm->im_consumed_Ah
				+ pm->im_reverted_Ah) / pm->im_capacity_Ah;

		pm->im_fuel_pc = 100.f * fuel;
	}
}

void pm_feedback(pmc_t *pm, pmfb_t *fb)
{
	float		vA, vB, vC, Q;

	if ((pm->vsi_IF & 2) == 0) {

		/* Get inline currents.
		 * */
		pm->fb_iA = pm->ad_IA[1] * fb->current_A + pm->ad_IA[0];
		pm->fb_iB = pm->ad_IB[1] * fb->current_B + pm->ad_IB[0];

		if (		m_fabsf(pm->fb_iA) > pm->fault_current_halt
				|| m_fabsf(pm->fb_iB) > pm->fault_current_halt) {

			pm->fail_reason = PM_ERROR_INLINE_OVER_CURRENT;
			pm->fsm_req = PM_STATE_HALT;
		}

		if (PM_CONFIG_NOP(pm) == PM_NOP_THREE_PHASE) {

			pm->lu_iX = pm->fb_iA;
			pm->lu_iY = .57735027f * pm->fb_iA + 1.1547005f * pm->fb_iB;
		}
		else {
			pm->lu_iX = pm->fb_iA;
			pm->lu_iY = pm->fb_iB;
		}
	}
	else if (pm->lu_mode != PM_LU_DISABLED) {

		m_rotf(pm->lu_F, pm->lu_wS * pm->dT, pm->lu_F);

		pm->lu_iX = pm->lu_F[0] * pm->lu_iD - pm->lu_F[1] * pm->lu_iQ;
		pm->lu_iY = pm->lu_F[1] * pm->lu_iD + pm->lu_F[0] * pm->lu_iQ;
	}

	/* Get DC link voltage.
	 * */
	pm->const_fb_U = pm->ad_US[1] * fb->voltage_U + pm->ad_US[0];
	pm->temp_const_ifbU = 1.f / pm->const_fb_U;

	if (pm->const_fb_U > pm->fault_voltage_halt) {

		pm->fail_reason = PM_ERROR_DC_LINK_OVER_VOLTAGE;
		pm->fsm_req = PM_STATE_HALT;
	}

	pm->tvm_DX = pm->vsi_DX;
	pm->tvm_DY = pm->vsi_DY;

	if (PM_CONFIG_TVM(pm) == PM_ENABLED) {

		vA = pm->tvm_FIR_A[1] * pm->fb_uA;
		vB = pm->tvm_FIR_B[1] * pm->fb_uB;
		vC = pm->tvm_FIR_C[1] * pm->fb_uC;

		/* Get terminal voltages.
		 * */
		pm->fb_uA = pm->ad_UA[1] * fb->voltage_A + pm->ad_UA[0];
		pm->fb_uB = pm->ad_UB[1] * fb->voltage_B + pm->ad_UB[0];
		pm->fb_uC = pm->ad_UC[1] * fb->voltage_C + pm->ad_UC[0];

		if (		pm->lu_mode != PM_LU_DETACHED
				&& pm->tvm_READY == PM_ENABLED
				&& pm->vsi_UF == 0 ) {

			/* Extract actual terminal voltages using FIR filter.
			 * */

			if ((pm->vsi_AZ & 2) == 0) {

				vA += pm->tvm_FIR_A[0] * pm->fb_uA + pm->tvm_FIR_A[2];
			}
			else {
				vA = 0.f;
			}

			if ((pm->vsi_BZ & 2) == 0) {

				vB += pm->tvm_FIR_B[0] * pm->fb_uB + pm->tvm_FIR_B[2];
			}
			else {
				vB = 0.f;
			}

			if ((pm->vsi_CZ & 2) == 0) {

				vC += pm->tvm_FIR_C[0] * pm->fb_uC + pm->tvm_FIR_C[2];
			}
			else {
				vC = 0.f;
			}

			pm->tvm_A = vA;
			pm->tvm_B = vB;
			pm->tvm_C = vC;

			if (PM_CONFIG_NOP(pm) == PM_NOP_THREE_PHASE) {

				Q = (1.f / 3.f) * (vA + vB + vC);
				vA = vA - Q;
				vB = vB - Q;

				pm->tvm_DX = vA;
				pm->tvm_DY = .57735027f * vA + 1.1547005f * vB;
			}
			else {
				vA = vA - vC;
				vB = vB - vC;

				pm->tvm_DX = vA;
				pm->tvm_DY = vB;
			}
		}
	}

	/* Get SENSOR values.
	 * */
	pm->fb_HS = fb->pulse_HS;
	pm->fb_EP = fb->pulse_EP;

	/* Main FSM is used to execute external commands.
	 * */
	pm_FSM(pm);

	if (pm->lu_mode != PM_LU_DISABLED) {

		/* The observer FSM.
		 * */
		pm_lu_FSM(pm);

		if (pm->lu_mode == PM_LU_DETACHED) {

			pm_voltage(pm, pm->detach_X, pm->detach_Y);
		}
		else {
			if (pm->lu_flux_zone != PM_FLUX_DETACHED) {

				if (pm->config_SERVO == PM_ENABLED) {

					pm_loop_servo(pm);
				}

				if (pm->config_DRIVE == PM_DRIVE_SPEED) {

					pm_loop_speed(pm);
				}
			}

			/* Current loop is always enabled.
			 * */
			pm_loop_current(pm);
		}

		if (pm->config_INFO == PM_ENABLED) {

			/* To collect information.
			 * */
			pm_infometer(pm);
		}

		if (m_isfinitef(pm->lu_F[0]) == 0) {

			pm->fail_reason = PM_ERROR_INVALID_OPERATION;
			pm->fsm_state = PM_STATE_HALT;
		}
	}
}

