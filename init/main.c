
// {
// 	my_fs_init();
	
// 	device_init(); // initialize the devices
// 	//fs_init();  // initialize the file system
// 	SD_TEST();
//   	sys_init();	// initialize the OS
// 	_panic("?");
// 	return 0;
// }

#include <stdint.h>
#include <stddef.h>
#include "printf.h"
//#include "bits.h"
#include "..\drivers\diskio.h"
#include "..\drivers\ff.h"
#include "..\drivers\elf.h"
#include "..\drivers\memory.h"
#include "..\drivers\sd.h"
#include "..\drivers\console.h"

FATFS FatFs;   // Work area (file system object) for logical drive

// max size of file image is 16M
#define MAX_FILE_SIZE 0x1000000

// size of DDR RAM (256M for Minisys) 
#define DDR_SIZE 0x10000000

// 4K size read burst
#define SD_READ_SIZE 4096


int main (void)
{
  FIL fil;                // File object
  FRESULT fr;             // FatFs return code
  uint8_t *boot_file_buf = (uint8_t *)(get_ddr_base()) + DDR_SIZE - MAX_FILE_SIZE; // at the end of DDR space
  uint8_t *memory_base = (uint8_t *)(get_ddr_base());

  cons_init(); //initialize consele

  printf("=============== MIPSfpga ===============\n\r", 0);
  printf("=============== DDR TEST ===============\n\r", 0);
  printf("DDR BASE VALUE:%d \r\n", *boot_file_buf);
  *boot_file_buf = 47;
  printf("DDR BASE VALUE AFTER WRITE:%d \r\n", *boot_file_buf);
  printf("=============== DDR TEST PASSED ===============\n\r", 0);

  printf("=============== FSBL ===============\n\r", 0);

  // Register work area to the default drive

  ???
  
  // Open a file

  ???

  // Read file into memory

  ???

  printf("Load %d bytes to memory address ", fsize);
  printf("%h from vmlinux.elf \n\r", (uint32_t)boot_file_buf);

  // read elf

  ???
  // Close the file
 
  ???

  // unmount it
  
  ???

  spi_disable();
  printf("=========== Jump to DDR ============\n\r", 0);
  asm("li $4, 0xbfc00000");
  asm("jr $4");

  while(1){}
}

