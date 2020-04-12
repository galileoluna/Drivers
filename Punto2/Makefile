obj-m = driverTest.o 

all: 
	make -C /lib/modules/$(shell uname -r)/build SUBDIRS=$(shell pwd) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build SUBDIRS=$(shell pwd) clean


test:test.c 
	cc -o test test.c