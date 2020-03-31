import adafruit_mcp4725
import time
import board
import busio

i2c = busio.I2C(board.SCL, board.SDA)

# Initialize MCP4725.
dac = adafruit_mcp4725.MCP4725(i2c, address=0x60)

# There are a three ways to set the DAC output, you can use any of these:
#dac.value = 65535  # Use the value property with a 16-bit number just like
#dac.raw_value = 4095  # Use the raw_value property to directly read and write
#dac.normalized_value = 1.0  # Use the normalized_value property to set the

# Main loop will go up and down through the range of DAC values forever.
while True:
    # Go up the 12-bit raw range.
    print("Going up 0-3.3V...")
    for i in range(0,4095):
        dac.raw_value = i
        print(i)
        time.sleep(0.002)
    # Go back down the 12-bit raw range.
    print("Going down 3.3-0V...")
    for i in range(4095, -1, -1):
        dac.raw_value = i
        print(i)
        time.sleep(0.002)
