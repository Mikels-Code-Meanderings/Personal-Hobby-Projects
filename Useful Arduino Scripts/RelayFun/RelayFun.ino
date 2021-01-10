// This Sketch uses some outputs from the microcontroller to open and close dry relay contacts. The circuts attached to the contacts
// were a 120VAC for some heating elements, and 12VDC for a basic computer fan. The sensor reads temp, and if below a certain temp, the 
// "heater" kicks on. Anyway, the code is quite simple, and a space heater needs some serious precautions if I intend to use it as a 
// Final product at some point. Thanks, and have a nice day.


#include <Adafruit_Si7021.h>  // import the sensor library
#include <Wire.h> //imports the wire library for talking over I2C
#include <SD.h> //Load SD card library
#include<SPI.h> //Load SPI Library
Adafruit_Si7021 Sensor; //create sensor object called Sensor
float tempC; //Variable for holding temp in C
float tempF; // Variable for holding temp in F

int RelayDude = 7;
int RelayDude1 = 8;
//void takeReading();
void setup() {
  Serial.begin(9600);
  pinMode(RelayDude,OUTPUT);
  pinMode(RelayDude1,OUTPUT);
Sensor.begin();  
}

void loop() {
 // digitalWrite(RelayDude,HIGH);
 // delay(30000);
//  digitalWrite(RelayDude,LOW);
 // delay(30000);
 

//void takeReading() {

tempC=Sensor.readTemperature(); //Read Temperature from sensor
tempF=tempC*1.8+32.;// Cenvert degrees C to F


 if (tempF < 65){
digitalWrite(RelayDude,LOW);
digitalWrite(RelayDude1,LOW);
}
else  {
  digitalWrite(RelayDude,HIGH);
  digitalWrite(RelayDude1,HIGH);
}
Serial.print("The Temp is: "); //Print Temperature 
Serial.print(tempF);
Serial.println(" degrees F");
delay(1000);
}
