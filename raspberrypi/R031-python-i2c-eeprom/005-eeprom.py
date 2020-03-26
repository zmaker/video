import smbus
import time

bus = smbus.SMBus(1)    # 0 = /dev/i2c-0 (port I2C0), 1 = /dev/i2c-1 (port I2C1)
i2c_addr= 0x50     #7 bit address (will be left shifted to add the read write bit)

data=0x01
address=0x00

#Write Operation
for x in range (0,6):
    L_Byte_Data=[address,data] 
    #l'indirizzo è formatio da 2 byte: alto e basso. Quello alto l'ho messo fisso a 0x00
    bus.write_i2c_block_data(i2c_addr,0x00,L_Byte_Data)
    print("write at:" + str(address) + " val:" + str(data))
    data += 0x01
    address=address+1
    time.sleep(0.01)

#Read Operation
read_addr = 0x00
for i in range(0,6):
    bus.write_i2c_block_data(i2c_addr,0x00,[read_addr])
    value=bus.read_byte(i2c_addr)
    print("read:" + str(read_addr) + " val:" + str(value))
    read_addr += 1
    time.sleep(0.5)
    
