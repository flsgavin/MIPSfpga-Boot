
INCLUDES	  := -I../inc/

%.o: %.S
	$(CC) $(CFLAGS) $(INCLUDES) -c $< 

.PHONY: clean

all: start.o boot.o

clean:
	rm -rf *~ *.o

include ../include.mk
