import time
# Import the ADS1x15 module.
import Adafruit_ADS1x15
# Create an ADS1115 ADC (16-bit) instance.
adc = Adafruit_ADS1x15.ADS1115()

GAIN = 1

while True:
    val = adc.read_adc(0, gain=GAIN)
    print(val)
    time.sleep(.5)