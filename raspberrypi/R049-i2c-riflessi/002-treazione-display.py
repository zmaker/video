import machine
import utime
import urandom

sda = machine.Pin(0)
scl = machine.Pin(1)
i2c = machine.I2C(0, sda=sda, scl=scl, freq=400000)


pressed = False
t1 = 0

def btHandler(pin):
    global pressed, t1
    if not pressed:
        pressed = True
        t_reazione = utime.ticks_ms() - t1
        msg = "tempo: " + str(t_reazione) + " ms"
        print(msg)
        i2c.writeto(114, msg)

led = machine.Pin(15, machine.Pin.OUT)
button = machine.Pin(14, machine.Pin.IN, machine.Pin.PULL_DOWN)

i2c.writeto(114, '\x7C')
i2c.writeto(114, '\x2D')
i2c.writeto(114, 'premi per iniziare')
while (not button.value()):
    pass

i2c.writeto(114, '\x7C')
i2c.writeto(114, '\x2D')

led.on()
utime.sleep(urandom.uniform(5, 10))
led.off()

t1 = utime.ticks_ms()
button.irq(trigger=machine.Pin.IRQ_RISING, handler=btHandler)
