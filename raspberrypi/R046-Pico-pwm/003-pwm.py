# https://docs.micropython.org/en/latest/esp8266/tutorial/pwm.html

import time
from machine import Pin, PWM

pwm = PWM(Pin(16))
pwm.freq(1000)

while True:
    for duty in range(0, 65025, 5):
        pwm.duty_u16(duty)
        time.sleep(0.0001)
    for duty in range(65025, 0, -5):
        pwm.duty_u16(duty)
        time.sleep(0.0001)
