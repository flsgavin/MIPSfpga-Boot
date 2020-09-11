drivers_dir	  := drivers
boot_dir	  := boot
init_dir	  := init
link_script   := scse0_3.lds

modules		  := boot drivers init  
objects		  := $(boot_dir)/*.o			  \
				 $(drivers_dir)/*.o	 		  \
				 $(init_dir)/*.o			  
				 
.PHONY: all $(modules) clean run

all: $(modules) bootloader

bootloader: $(modules)
	$(LD) -EL -nostartfiles -N -T scse0_3.lds -G0 -o bootloader.elf $(objects) 
	$(OC) --remove-section .MIPS.abiflags --remove-section .reginfo bootloader.elf
	$(SZ) bootloader.elf
	$(OD) -D -l -t bootloader.elf > bootloader.dis
	$(OD) -D bootloader.elf > bootloader.txt
	$(OC) bootloader.elf -O srec bootloader.rec

$(modules): 
	$(MAKE) --directory=$@

clean: 
	for d in $(modules);	\
		do					\
			$(MAKE) --directory=$$d clean; \
		done; \
	rm -rf *.o *~ $(bootloader_elf)  $(user_disk)


include include.mk
