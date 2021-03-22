
#include <RH_ASK.h>
#include <SPI.h> 

RH_ASK driver;

#define dataout 12
#define LED 7

void setup()
{

   pinMode(dataout, OUTPUT);     
   pinMode(LED, OUTPUT);   
   Serial.begin(9600);    // Debugging only
   if (!driver.init())
        Serial.println("init failed");
}

void loop()
{
    const char *msg = "Welcome to Design-3 Lab!";
    Serial.println("Sending MESSAGE...");
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();

 
    char *ON = "1";
    driver.send((uint8_t *)ON, strlen(ON));
    driver.waitPacketSent();
    Serial.println(*ON);
    digitalWrite(LED, HIGH);
    digitalWrite(dataout, HIGH);
    delay(1000);

    char *OFF = "0";
    driver.send((uint8_t *)OFF, strlen(OFF));
    driver.waitPacketSent();
    Serial.println(*OFF);
    digitalWrite(LED, LOW);
    digitalWrite(dataout, LOW);
    delay(1000);


 }


 
