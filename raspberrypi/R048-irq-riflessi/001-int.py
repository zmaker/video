import machine
import utime
import urandom

pressed = False

def btHandler(pin):
    global pressed
    if not pressed:
        pressed = True
        t_reazione = utime.ticks_ms() - t1
        print("tempo: " + str(t_reazione) + " ms")

led = machine.Pin(15, machine.Pin.OUT)
button = machine.Pin(14, machine.Pin.IN, machine.Pin.PULL_DOWN)

led.on()
utime.sleep(urandom.uniform(5, 10))
led.off()

t1 = utime.ticks_ms()
button.irq(trigger=machine.Pin.IRQ_RISING, handler=btHandler)