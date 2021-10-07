// Receiver code :

#include <RH_ASK.h>
#include <SPI.h>
#include <VirtualWire.h>
#include <LiquidCrystal.h>
#include <SD.h>
#define SD_ChipSelectPin 4
#include <TMRpcm.h>
TMRpcm tmrpcm;
const int rs = 8, en = 10, d4 = 6, d5 = 5, d6 = 7, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
boolean x = false;
RH_ASK driver;
void audio1()
{
    tmrpcm.play("11.wav");
    x = true;
}
void audio2()
{
    tmrpcm.play("22.wav");
    x = true;
}
void audio3()
{
    tmrpcm.play("33.wav");
    x = true;
}
void audio4()
{
    tmrpcm.play("44.wav");
    x = true;
}
void upward()
{
    lcd.setCursor(0, 0);
    lcd.print("  I AM HUNGRY   ");
    delay(500);
}
void downward()
{
    lcd.setCursor(0, 0);
    lcd.print("  I AM THIRSTY  ");
    delay(500);
}
void right()
{
    lcd.setCursor(0, 0);
    lcd.print("   NEED HELP    ");
    delay(500);
}
void left()
{
    lcd.setCursor(0, 0);
    lcd.print("NOT FEELING WELL");
    delay(500);
}
void clearLCD()
{
    lcd.clear();
}
void setup()
{
    Serial.begin(9600); // Debugging only
    tmrpcm.speakerPin = 9;
    lcd.begin(16, 2);

    if (!driver.init())
    {
        Serial.println("init failed");
    }
    if (!SD.begin(SD_ChipSelectPin))
    {
        Serial.println("SD fail");
        return; // don't do anything more if not
    }
    else
    {
        Serial.println("SD ok");
    }
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) // Non-blocking
    {
        int i;
        for (i = 0; i < buflen; i++)
        {
            if (buf[i] == '1')
            {
                upward();
                if (x == false)
                {
                    audio1();
                }
            }
            if (buf[i] == '2')
            {
                downward();
                if (x == false)
                {
                    audio2();
                }
            }
            if (buf[i] == '3')
            {
                right();
                if (x == false)
                {
                    audio3();
                }
            }
            if (buf[i] == '4')
            {
                left();
                if (x == false)
                {
                    audio4();
                }
            }
            if (buf[i] == '5')
            {
                clearLCD();
                x = false;
            }
        }
    }
}
