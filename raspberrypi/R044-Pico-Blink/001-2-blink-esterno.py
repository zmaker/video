from machine import Pin, Timer

led = Pin(16, Pin.OUT)
tim = Timer()

def tick(timer):
    global led
    led.toggle()

tim.init(freq=2.0, mode=Timer.PERIODIC, callback=tick)
