/*
 * Tiny fake "ECU firmware" for an ARM Cortex-M4 microcontroller.
 * It doesn't do anything useful - it exists so a real third-party
 * library (zlib) gets compiled into the binary, just like real
 * firmware pulls in libraries you later have to identify.
 */
#include <stdint.h>
#include <string.h>
#include "zlib.h"

/* Symbols provided by the linker script */
extern uint32_t _estack, _sidata, _sdata, _edata, _sbss, _ebss;

static uint8_t raw[256];
static uint8_t packed[512];
static uint8_t unpacked[256];
volatile int result;

int main(void)
{
    /* Pretend this is a block of sensor/calibration data */
    for (int i = 0; i < (int)sizeof(raw); i++)
        raw[i] = (uint8_t)(i % 16);

    uLongf plen = sizeof(packed);
    uLongf ulen = sizeof(unpacked);

    compress(packed, &plen, raw, sizeof(raw));
    uncompress(unpacked, &ulen, packed, plen);

    result = memcmp(raw, unpacked, sizeof(raw)) == 0;
    while (1) { }   /* firmware never returns */
}

/* Runs at power-on: set up memory, then jump to main */
void Reset_Handler(void)
{
    uint32_t *src = &_sidata, *dst = &_sdata;
    while (dst < &_edata) *dst++ = *src++;           /* copy .data */
    for (dst = &_sbss; dst < &_ebss; ) *dst++ = 0;   /* zero .bss  */
    main();
}

void Default_Handler(void) { while (1) { } }

/* The vector table: the CPU reads this at address 0 on boot */
__attribute__((section(".isr_vector"), used))
const void *vector_table[] = {
    &_estack,          /* initial stack pointer */
    Reset_Handler,     /* reset */
    Default_Handler,   /* NMI */
    Default_Handler,   /* HardFault */
};
