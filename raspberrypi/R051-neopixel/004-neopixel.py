# libreria
# https://github.com/blaz-r/pi_pico_neopixel
from neopixel import Neopixel
import utime
import machine

lednum = 12
stateMachineId = 0
gpioPin = 0

lev = machine.ADC(26)

pixels = Neopixel(lednum, stateMachineId, gpioPin, "GRB")

for i in range(lednum):
    pixels.set_pixel(i, (10, 0, 0))
    pixels.show()
    utime.sleep(.2)

for i in range(lednum-1, -1, -1):
    pixels.set_pixel(i, (0, 0, 0))
    pixels.show()
    utime.sleep(.2)

rgb1 = (0, 0, 50, 0)
rgb2 = (50, 0, 0, 250)

while (True):
    n = lev.read_u16()
    i = int(((lednum-1) * n)/65535)
    print(n, " - ", i)
    pixels.fill((0, 0, 0))
    pixels.set_pixel_line_gradient(0, i, rgb1, rgb2)
    pixels.show()
    utime.sleep(.1)