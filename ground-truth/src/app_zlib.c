/* Fake ECU app: compresses and decompresses a calibration block with zlib. */
#include <stdint.h>
#include <string.h>
#include "zlib.h"

static uint8_t raw[256], packed[512], unpacked[256];
volatile int result;

int main(void)
{
    for (int i = 0; i < (int)sizeof(raw); i++) raw[i] = (uint8_t)(i % 16);
    uLongf plen = sizeof(packed), ulen = sizeof(unpacked);
    compress(packed, &plen, raw, sizeof(raw));
    uncompress(unpacked, &ulen, packed, plen);
    result = memcmp(raw, unpacked, sizeof(raw)) == 0 && strlen(zlibVersion()) > 0;
    return 0;
}
