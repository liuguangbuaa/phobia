#include "cmsis/stm32f4xx.h"
#include "hal.h"

void RNG_startup()
{
	/* Enable RNG clock.
	 * */
	RCC->AHB2ENR |= RCC_AHB2ENR_RNGEN;

	/* Enable RNG.
	 * */
	RNG->CR |= RNG_CR_RNGEN;
}

unsigned long RNG_urand()
{
	unsigned long 		urand = 0UL;
	int			N = 0;

	do {
		/* Check that no error occured.
		 * */
		if (RNG->SR & (RNG_SR_SEIS | RNG_SR_CEIS)) {

			RNG->SR &= ~(RNG_SR_SEIS | RNG_SR_CEIS);

			RNG->CR &= ~(RNG_CR_RNGEN);
			RNG->CR |= RNG_CR_RNGEN;
		}

		/* Wait till RNG is ready.
		 * */
		if (RNG->SR & RNG_SR_DRDY) {

			urand = RNG->DR;
			break;
		}

		N++; __NOP();
	}
	while (N < 700000UL);

	return urand;
}

