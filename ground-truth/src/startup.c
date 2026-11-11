/*
 * Shared Cortex-M startup code: vector table + reset handler.
 * Each app_<lib>.c provides main(); this file gets it running.
 */
#include <stdint.h>

extern uint32_t _estack, _sidata, _sdata, _edata, _sbss, _ebss;
int main(void);

void Reset_Handler(void)
{
    uint32_t *src = &_sidata, *dst = &_sdata;
    while (dst < &_edata) *dst++ = *src++;           /* copy .data */
    for (dst = &_sbss; dst < &_ebss; ) *dst++ = 0;   /* zero .bss  */
    main();
    while (1) { }
}

void Default_Handler(void) { while (1) { } }

__attribute__((section(".isr_vector"), used))
const void *vector_table[] = {
    &_estack,          /* initial stack pointer */
    Reset_Handler,     /* reset */
    Default_Handler,   /* NMI */
    Default_Handler,   /* HardFault */
};
