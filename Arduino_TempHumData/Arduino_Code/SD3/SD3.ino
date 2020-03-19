//This file has code to log temperature and 
// Humidity data

#include <SD.h> //Load SD card library
#include<SPI.h> //Load SPI Library

#include <Adafruit_Si7021.h>  // import the sensor library
#include <Wire.h> //imports the wire library for talking over I2C
Adafruit_Si7021 Sensor; //create sensor object called Sensor

float tempC; //Variable for holding temp in C
float tempF; // Variable for holding temp in F
float humidity; //Variable for holding humidity reading

int chipSelect=4; //chipSelect pin for the SD card Reader
File SensorDataTemp; //Data object you will write your sensor data to
File SensorDataHum;
void setup() {
Serial.begin(9600); //turn on serial monitor
Sensor.begin();  //initialize pressure sensor mySensor

pinMode(10, OUTPUT); // Must declare 10 an output and reserve it
SD.begin(4); // Initialize the SD card reader


}

void loop() {
tempC=Sensor.readTemperature(); //Read Temperature from sensor
tempF=tempC*1.8+32.;// Cenvert degrees C to F
humidity=Sensor.readHumidity();//Read Humidity

SensorDataTemp=SD.open("TData.txt",FILE_WRITE);
SensorDataHum=SD.open("HData.txt",FILE_WRITE);
if (SensorDataTemp){
Serial.print("The Temp is: "); //Print your results
Serial.print(tempF);
Serial.println(" degrees F");
Serial.print("The Humidity is: ");
Serial.print(humidity);
Serial.println(" %.");
Serial.println("");
delay(250); //Pause between readings

SensorDataTemp.print(tempF);
SensorDataTemp.println("");
SensorDataHum.print(humidity);
SensorDataHum.println("");
SensorDataTemp.close();
SensorDataHum.close();

}
}
