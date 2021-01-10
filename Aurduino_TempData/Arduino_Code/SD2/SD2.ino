#include <LiquidCrystal_I2C.h>


// Temperature Pressure sensor to an LCD screen

#include<SPI.h> //Load SPI Library
#include <Wire.h>   // imports the wire library for talking over I2C 
#include <Adafruit_BMP085.h>  // import the Pressure Sensor Library We are using Version one of Adafruit API for this sensor

Adafruit_BMP085 mySensor;  // create sensor object called mySensor
LiquidCrystal_I2C lcd=LiquidCrystal_I2C(0x27, 16, 2);

float tempC;  // Variable for holding temp in C
float tempF;  // Variable for holding temp in F
float pressure; //Variable for holding pressure reading



void setup(){
Serial.begin(9600); //turn on serial monitor
mySensor.begin();   //initialize pressure sensor mySensor
lcd.init();
lcd.backlight();
pinMode(10, OUTPUT); //Must declare 10 an output and reserve it

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
lcd.setCursor(0,0);
lcd.print("tempF");
//lcd.setCursor(2,0);
//lcd.print(pressure);
delay(250); //Pause between readings.



}
