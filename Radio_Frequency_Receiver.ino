
#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

#define LED 12

unsigned int target = 0;
//const unsigned int upperThreshold = 1;
//const unsigned int lowerThreshold = 0;

void setup()
{
    pinMode(LED, OUTPUT);
    
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[24];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      //int i;
      // Message with a good checksum received, dump it.
      Serial.print("Message: ");
      Serial.println((char*)buf);
      Serial.println(buf[0]);        
    

   target=(buf[0]);
   
    if(target==49)
    {
     digitalWrite(LED, HIGH);
    }
   
   else
   {
     digitalWrite(LED, LOW);
   }
 }}
