#include "memory.h"

volatile uint64_t * get_bram_base() {
#ifdef BRAM_BASE
  return (uint64_t *)(BRAM_BASE);
#else
  return (uint64_t *)0;         /* boot ROM, raise error */
#endif
}

volatile uint64_t * get_ddr_base() {
  return (uint64_t *)(DDR_BASE);
}

volatile uint64_t * get_flash_base() {
#ifdef SDCARD_ADDR
  return (uint64_t *)(SDCARD_ADDR);
#else
  return (uint64_t *)0;         /* boot ROM, raise error */
#endif
}