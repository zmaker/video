#include <wiringPi.h>

int led = 29;
int bt = 28;

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
  pinMode(led, OUTPUT);
  pinMode(bt, INPUT);  
}

void loop() {
  int v = digitalRead(bt);
  if (v == HIGH) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
