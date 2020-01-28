#include <wiringPi.h>
#include <stdio.h>

int led = 1;

void loop();
void setup();

int main (void) {
  
  wiringPiSetup();
  setup();
  
  while (TRUE){
    loop();
  }
  return 0;
}

void setup() {
  printf("running pwm\n");
  pinMode(led, PWM_OUTPUT);
}

void loop() {
  for (int i = 0; i < 1024; i++) {
    pwmWrite(led, i);
    delay(10);
  } 
  for (int i = 1024; i >= 0; i--) {
    pwmWrite(led, i);
    delay(10);
  }
}
