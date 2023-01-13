#include <Wire.h>
#include <BMx280I2C.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//#define I2C_SDA 14
//#define I2C_SCL 15

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//create a BMx280I2C object using the I2C interface with I2C Address 0x76
#define I2C_ADDRESS 0x76
BMx280I2C bmx280(I2C_ADDRESS);

void setup() {
  Wire.begin();
  
  Serial.begin(115200);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text  
  display.cp437(true);   
  display.display();
  
  if (!bmx280.begin())
  {
    Serial.println("begin() failed. check your BMx280 Interface and I2C Address.");
    while (1);
  }

  if (bmx280.isBME280())
    Serial.println("sensor is a BME280");
  else
    Serial.println("sensor is a BMP280");

  //reset sensor to default parameters.
  bmx280.resetToDefaults();

  //by default sensing is disabled and must be enabled by setting a non-zero
  //oversampling setting.
  //set an oversampling setting for pressure and temperature measurements. 
  bmx280.writeOversamplingPressure(BMx280MI::OSRS_P_x16);
  bmx280.writeOversamplingTemperature(BMx280MI::OSRS_T_x16);

  //if sensor is a BME280, set an oversampling setting for humidity measurements.
  if (bmx280.isBME280())
    bmx280.writeOversamplingHumidity(BMx280MI::OSRS_H_x16);

  bmx280.measure();
}

unsigned long t1;

void loop() {
  if ((millis() - t1) > 1000) {
    if (bmx280.hasValue()) {
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("P:");display.print(bmx280.getPressure());
      display.setCursor(0, 10);
      display.print("T:");display.print(bmx280.getTemperature());
      display.setCursor(0, 20);
      display.print("H:");display.print(bmx280.getHumidity());
      
      display.display();
      bmx280.measure();
    }
    t1 = millis(); 
  }  
}
