// Code for interfacing of SD card module with arduino microcontroller:

// For reading the files that are saved in SD card

#include <SPI.h>
#include <SD.h>
File myFile;
void setup()
{
    Serial.begin(9600);
    while (!Serial)
    {
        ;
    }
    Serial.print("Initializing SD card...");
    if (!SD.begin(4))
    {
        Serial.println("initialization failed!");
        return;
    }

    Serial.println("initialization done.");
    if (SD.exists("example.txt"))
    {
        Serial.println("example.txt exists.");
    }
    else
    {
        Serial.println("example.txt doesn't exist.");
    }
    Serial.println("Creating example.txt...");
    myFile = SD.open("example.txt", FILE_WRITE);
    myFile.close();

    if (SD.exists("example.txt"))
    {
        Serial.println("example.txt exists.");
    }
    else
    {
        Serial.println("example.txt doesn't exist.");
    }
    Serial.println("Removing example.txt...");
    SD.remove("example.txt");

    if (SD.exists("example.txt"))
    {
        Serial.println("example.txt exists.");
    }
    else
    {
        Serial.println("example.txt doesn't exist.");
    }
}
void loop()
{
}
