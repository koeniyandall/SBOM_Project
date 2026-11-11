/* Fake ECU app: formats a RAM-backed littlefs volume and writes a log file. */
#include <stdint.h>
#include <string.h>
#include "lfs.h"

#define BLOCK_SIZE  256
#define BLOCK_COUNT 64
static uint8_t storage[BLOCK_SIZE * BLOCK_COUNT];

static int bd_read(const struct lfs_config *c, lfs_block_t b, lfs_off_t off, void *buf, lfs_size_t size)
{ (void)c; memcpy(buf, &storage[b * BLOCK_SIZE + off], size); return 0; }
static int bd_prog(const struct lfs_config *c, lfs_block_t b, lfs_off_t off, const void *buf, lfs_size_t size)
{ (void)c; memcpy(&storage[b * BLOCK_SIZE + off], buf, size); return 0; }
static int bd_erase(const struct lfs_config *c, lfs_block_t b)
{ (void)c; memset(&storage[b * BLOCK_SIZE], 0xff, BLOCK_SIZE); return 0; }
static int bd_sync(const struct lfs_config *c) { (void)c; return 0; }

static const struct lfs_config cfg = {
    .read = bd_read, .prog = bd_prog, .erase = bd_erase, .sync = bd_sync,
    .read_size = 16, .prog_size = 16, .block_size = BLOCK_SIZE,
    .block_count = BLOCK_COUNT, .cache_size = 64, .lookahead_size = 16,
    .block_cycles = 500,
};

static lfs_t lfs;
static lfs_file_t file;
volatile int result;

int main(void)
{
    lfs_format(&lfs, &cfg);
    lfs_mount(&lfs, &cfg);
    lfs_file_open(&lfs, &file, "fault.log", LFS_O_WRONLY | LFS_O_CREAT);
    lfs_file_write(&lfs, &file, "DTC P0A80", 9);
    lfs_file_close(&lfs, &file);
    result = lfs_unmount(&lfs) == 0;
    return 0;
}
