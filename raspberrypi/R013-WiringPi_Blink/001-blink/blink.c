#include <wiringPi.h>

int main (void) {
  int pled = 29;

  wiringPiSetup();
  pinMode(pled, OUTPUT);
  while (TRUE){
    digitalWrite(pled, HIGH);
    delay(500);
    digitalWrite(pled, LOW);
    delay(500);
  }
  return 0;
}
