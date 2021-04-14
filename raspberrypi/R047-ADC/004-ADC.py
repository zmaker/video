import machine
import time
from machine import Pin, PWM

pwm = PWM(Pin(16))
pwm.freq(1000)

sens = machine.ADC(26) #gp26 channel 0

while True:
    val = sens.read_u16()
    print(val)
    pwm.duty_u16(val)
    time.sleep(0.01)
