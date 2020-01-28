
PREFIX ?=

CC	= $(PREFIX)gcc
CPP	= $(PREFIX)g++
AS	= $(CC)
LD	= $(PREFIX)ld
AR	= $(PREFIX)ar

ROOT = ./

LIB := -L$(ROOT)/lib-pca9685/lib_linux
LDLIBS := -lpca9685 -lwiringPi
LIBDEP := $(ROOT)/lib-pca9685/lib_linux/libpca9685.a

INCLUDES := -I$(ROOT)/lib-pca9685/include

COPS := -Wall -Werror -O3 -fno-rtti -std=c++11 -DNDEBUG

BCM2835 = $(ROOT)/lib-bcm2835_raspbian

ifneq "$(wildcard $(BCM2835) )" ""
	LIB += -L$(BCM2835)/lib_linux
	LDLIBS += -lbcm2835_raspbian
	INCLUDES += -I$(BCM2835)/include
else
	LDLIBS += -lbcm2835
endif

all : i2ctest

clean :
	rm -f *.o
	rm -f *.lst
	rm -f i2ctest 
	cd $(ROOT)/lib-pca9685 && make -f Makefile.Linux clean
	
$(ROOT)/lib-pca9685/lib_linux/libpca9685.a :
	cd $(ROOT)/lib-pca9685 && make -f Makefile.Linux "DEF=-DRASPPI"
	
i2ctest : Makefile i2ctest.cpp $(ROOT)/lib-pca9685/lib_linux/libpca9685.a
	$(CPP) i2ctest.cpp $(INCLUDES) $(COPS) -o i2ctest $(LIB) $(LDLIBS)
	$(PREFIX)objdump -D i2ctest | $(PREFIX)c++filt > i2ctest.lst
