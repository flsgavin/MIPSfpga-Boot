#ifndef MEMORY_HEADER_H
#define MEMORY_HEADER_H

#include <stdint.h>
#include "mfp_io.h"

extern volatile uint64_t * get_bram_base();
extern volatile uint64_t * get_ddr_base();
extern volatile uint64_t * get_flash_base();

#endif