#https://docs.micropython.org/en/latest/library/machine.Pin.html
from machine import Pin
import time

led = Pin(16, Pin.OUT)
button = Pin(15, Pin.IN, None)

while True:
    if button.value():
        led.toggle()
        time.sleep(0.5)