// Code for interfacing of MPU6050 with arduino microcontroller:

// For reading the values of accelerometer 
 
#include <Wire.h>
long accelX, accelY, accelZ;
float gForceX, gForceY, gForceZ;
void setup() {
 Serial.begin(9600);
 Wire.begin();
 setupMPU();
}
void loop() {
 recordAccelRegisters();
 printData();
 delay(100);
}
void setupMPU(){
Wire.beginTransmission(0b1101000);
Wire.write(0x6B); 
 Wire.write(0b00000000); 
 Wire.endTransmission(); 
Wire.beginTransmission(0b1101000); 
 Wire.write(0x1B); 
 Wire.write(0x00000000); 
 Wire.endTransmission(); 
Wire.beginTransmission(0b1101000); 
 Wire.write(0x1C); 
 Wire.write(0b00000000); 
 Wire.endTransmission(); 
}
void recordAccelRegisters() {
Wire.beginTransmission(0b1101000); 
 Wire.write(0x3B); 
 Wire.endTransmission();
 Wire.requestFrom(0b1101000,6); 
 while(Wire.available() < 6);
 accelX = Wire.read()<<8|Wire.read(); 
 accelY = Wire.read()<<8|Wire.read(); 
 accelZ = Wire.read()<<8|Wire.read(); 
 processAccelData();
}
void processAccelData(){
 gForceX = accelX / 16384.0;
 gForceY = accelY / 16384.0; 
 gForceZ = accelZ / 16384.0;


}
void printData() {
 Serial.print(" Accel (g)");


 Serial.print(" X=");
 Serial.print(gForceX);
 Serial.print(" Y=");
 Serial.print(gForceY);
 Serial.print(" Z=");
 Serial.println(gForceZ);
}
