// This file has the pressure data suppressed in an effort to organize the data into a single column that is easily read by 
// by Octave, and transposed in a way that I can plot the temperature data vs. time. thanks for your time!
#include <SD.h> //Load SD card library
#include<SPI.h> //Load SPI Library
#include <LiquidCrystal_I2C.h> // Library for LCD
// Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,16,2) for 16x2 LCD.

#include <Wire.h>   // imports the wire library for talking over I2C 
#include <Adafruit_BMP085.h>  // import the Pressure Sensor Library We are using Version one of Adafruit API for this sensor
Adafruit_BMP085 mySensor;  // create sensor object called mySensor


float tempC;  // Variable for holding temp in C
float tempF;  // Variable for holding temp in F
float pressure; //Variable for holding pressure reading

int chipSelect = 4; //chipSelect pin for the SD card Reader
File mySensorData; //Data object you will write your sesnor data to

void setup(){
Serial.begin(9600); //turn on serial monitor
mySensor.begin();   //initialize pressure sensor mySensor
 // Initiate the LCD:
  lcd.init();
  lcd.backlight();
pinMode(10, OUTPUT); //Must declare 10 an output and reserve it
SD.begin(4); //Initialize the SD card reader
}

void loop() {
tempC = mySensor.readTemperature(); //  Read Temperature from BMP180
tempF = tempC*1.8 + 32.; // Convert degrees C to F
pressure=mySensor.readPressure(); //Read Pressure


Serial.print("The Temp is: "); //Print Your results
Serial.print(tempF);
Serial.println(" degrees F");
Serial.print("The Pressure is: ");
Serial.print(pressure);
Serial.println(" Pa.");
Serial.println("");
  lcd.setCursor(0, 0); // Set the cursor on the first column and first row.
  lcd.print(tempF); 
  lcd.print(" F "); 
  lcd.setCursor(0, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
  lcd.print(pressure);
  lcd.print(" Pa ");
  lcd.setCursor(9,0);
  lcd.print(tempC);
  lcd.print(" C ");
delay(250); //Pause between readings.


}
