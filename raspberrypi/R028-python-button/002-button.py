import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(20, GPIO.IN)

count = 0

while True:
    bt = GPIO.input(20)
    if (bt):
        count = count + 1
        print(count)
    time.sleep(.1)