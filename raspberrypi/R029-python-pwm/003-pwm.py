import RPi.GPIO as GPIO
import time

freq = 100
pin = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(pin, GPIO.OUT)

p = GPIO.PWM(pin, freq)
p.start(0)
for n in range(0, 100, 5):
  p.ChangeDutyCycle(n)
  time.sleep(0.1)
for n in range(100, -1, -5):
  p.ChangeDutyCycle(n)
  time.sleep(0.1)
p.stop()
GPIO.cleanup()