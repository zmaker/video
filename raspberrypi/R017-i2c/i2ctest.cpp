#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <wiringPi.h>

#include "bcm2835.h"
#include "pca9685.h"

int main(int argc, char **argv) {
	if (getuid() != 0) {
		fprintf(stderr, "Program is not started as \'root\' (sudo)\n");
		return -1;
	}

	if (bcm2835_init() != 1) {
		fprintf(stderr, "bcm2835_init() failed\n");
		return -2;
	}
	
//	wiringPiSetup();

	//uint16_t OnValue, OffValue;
	PCA9685 pca9685;

	pca9685.Dump();

	pca9685.SetFrequency(100);
  
	for(;;) {
 for (int i = 0; i < 4096; i++) {
    pca9685.Write(CHANNEL(0), VALUE(i));
    delay(1);
    }
    for (int i = 4095; i >= 0; i--) {
    pca9685.Write(CHANNEL(0), VALUE(i));
    delay(1);
    } 
	}

	return 0;
}
