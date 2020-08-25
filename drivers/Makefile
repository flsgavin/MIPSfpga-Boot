INCLUDES	  := -I../inc/

all: diskio.o sd.o uart.o console.o elf.o ff.o memory.o printf.o print.o 

%.o: %.c %.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $*.o


clean:
	rm -rf *~ *.o

include ../include.mk
