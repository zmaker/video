'''
git clone https://github.com/adafruit/Adafruit_CircuitPython_NeoPixel.git
'''
# Simple test for NeoPixels on Raspberry Pi
import time
import board
import neopixel


# Choose an open pin connected to the Data In of the NeoPixel strip, i.e. board.D18
# NeoPixels must be connected to D10, D12, D18 or D21 to work.
pixel_pin = board.D18

# The number of NeoPixels
num_pixels = 16

# The order of the pixel colors - RGB or GRB. Some NeoPixels have red and green reversed!
# For RGBW NeoPixels, simply change the ORDER to RGBW or GRBW.
ORDER = neopixel.GRB

pixels = neopixel.NeoPixel(
    pixel_pin, num_pixels)

while True:
    for i in range(0, 16):
        pixels.fill((0,0,0))
        pixels[i] = (100, 0, 0)
        pixels.show()
        time.sleep(0.05)
      
