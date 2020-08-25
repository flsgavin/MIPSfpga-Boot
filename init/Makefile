INCLUDES := -I../inc 

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

.PHONY: clean

all:  main.o 

clean:
	rm -rf *~ *.o


include ../include.mk

