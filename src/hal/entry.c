#include "cmsis/stm32f4xx.h"
#include "hal/hal.h"

extern long ld_stack;
extern long ld_begin_vectors;
extern long ld_end_text;
extern long ld_begin_data;
extern long ld_end_data;
extern long ld_begin_bss;
extern long ld_end_bss;
extern long ld_begin_ccm;
extern long ld_end_ccm;
extern long ld_end_flash;

void irq_Reset();
void irq_NMI();
void irq_HardFault();
void irq_MemoryFault();
void irq_BusFault();
void irq_UsageFault();
void irq_Default();
void irq_SVCall();
void irq_PendSV();
void irq_SysTick();

void irq_EXTI0();
void irq_ADC();
void irq_CAN1_TX();
void irq_CAN1_RX0();
void irq_CAN1_RX1();
void irq_CAN1_SCE();
void irq_TIM1_UP_TIM10();
void irq_TIM4();
void irq_USART3();

__attribute__ (( section(".vectors"), used )) void * vectors[] = {

	(void *) &ld_stack,

	irq_Reset,
	irq_NMI,
	irq_HardFault,
	irq_MemoryFault,
	irq_BusFault,
	irq_UsageFault,
	(void *) &ld_begin_vectors,
	(void *) &ld_end_flash,
	irq_Default,
	irq_Default,
	irq_SVCall,
	irq_Default,
	irq_Default,
	irq_PendSV,
	irq_SysTick,

	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_EXTI0,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_ADC,
	irq_CAN1_TX,
	irq_CAN1_RX0,
	irq_CAN1_RX1,
	irq_CAN1_SCE,
	irq_Default,
	irq_Default,
	irq_TIM1_UP_TIM10,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_TIM4,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_USART3,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default,
	irq_Default
};

static void
init_data(const long *long_s, long *long_d, long *long_e)
{
	while (long_d < long_e) { *long_d++ = *long_s++; }
}

static void
init_bss(long *long_d, long *long_e)
{
	while (long_d < long_e) { *long_d++ = 0; }
}

void irq_Reset()
{
	hal_bootload();

	init_data(&ld_end_text, &ld_begin_data, &ld_end_data);
	init_bss(&ld_begin_bss, &ld_end_bss);
	init_bss(&ld_begin_ccm, &ld_end_ccm);

	hal_startup();
	app_MAIN();
	hal_system_reset();
}

