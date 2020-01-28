#include <wiringPi.h>
#include <stdio.h>

int led = 29;
unsigned int t1, dt; //interi a 32 bit
unsigned int t2, dt2;

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
  int t = millis();
  printf("millis: %d \n", t);
  pinMode(led, OUTPUT);
  
  delay(1000);
  t = millis();
  printf("millis: %d \n", t);
  
  t1 = millis();
}


void loop() {
  dt = millis() - t1;
  if (dt >= 1000) {
     t1 = millis();
     printf("1\n");
  }
  
  dt2 = millis() - t2;
  if (dt2 >= 600) {
     t2 = millis();
     printf("2\n");
  }
}
