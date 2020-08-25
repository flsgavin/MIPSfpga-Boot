OUTPUT_ARCH(mips)
__entry = DEFINED(__reset_vector) ? 0xbfc00000 : _start;
ENTRY(__entry)
PROVIDE (__flash_start = DEFINED(__reset_vector) ? 0xbfc00000 : __app_start);
PROVIDE (__tlb_stride_length = 1);
SECTIONS
{ 

    /* Start of bootrom */
  .bootrom 0xbfc00000 : 
  AT (__flash_start)
  {
    *(.reset)		/* Reset entry point. */
    *(.boot)		/* Boot code. */
    . = ALIGN(4k);
  } = 0
  
  . = 0x80000000;
 .except_vec3 : {
	*(.text.exc_vec3)
  . = ALIGN(4k);
    }

  . = 0x8A010000;
  .text : {
        *(.text)
        . = ALIGN(4k);
    }

  .data : {
	*(.data)
	}

  .sdata : {
    *(.sdata)
  }

  _fbss = .;
  .bss  : {
   *(.bss)
   }

   end = . ;
   _end = . ;
}
