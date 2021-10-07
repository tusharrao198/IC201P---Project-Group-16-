// Code for interfacing of Speaker with arduino microcontroller:

// To read the audio file from SD card and play it on speaker

#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup()
{
    tmrpcm.speakerPin = 9;
    Serial.begin(9600);
    if (!SD.begin(SD_ChipSelectPin))
    {
        Serial.println("SD fail");
        return;
    }

    tmrpcm.setVolume(6);
    tmrpcm.play("rain.wav");
}
