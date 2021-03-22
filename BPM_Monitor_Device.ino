#define USE_ARDUINO_INTERRUPTS true // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h> // Includes the PulseSensorPlayground Library.

//#include <Wire.h>
//#include <LCD.h>
//#include <LiquidCrystal_I2C.h>



// Variables
// declares the pins for the LCD screen
//#define I2C_ADDR          0x27        //Define I2C Address where the PCF8574A is
//#define BACKLIGHT_PIN      3
//#define En_pin             2
//#define Rw_pin             1
//#define Rs_pin             0
//#define D4_pin             4
//#define D5_pin             5
//#define D6_pin             6
//#define D7_pin             7
//
//LiquidCrystal_I2C      lcd(I2C_ADDR, En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

const int pulseWire = A0; // pulse sensor purple wire connected to analogue pin A0
const int buzzerPin = 9;  // buzzer connected to output pin 3
const int LED = 4 ;       // LED connected to output pin 5
int threshold = 500; // Signal that are read as an actual beat vs which signals to ignore



// Creates an instance of the PulseSensorPlayground object called "pulseSensor"
PulseSensorPlayground pulseSensor;

//


// code to be run once
void setup() {

  Serial.begin(115200); // For Serial Monitor

//  //Define the LCD as 16 column by 2 rows 
//    lcd.begin (16,2);
//    
//    //Switch on the backlight
//    lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
//    lcd.setBacklight(HIGH);
//    
//    //goto first column (column 0) and first line (Line 0)
//    lcd.setCursor(5,0);
//    
//    //Print at cursor Location
//    lcd.print("BPM");
//    
//    //goto first column (column 0) and second line (line 1)
//    lcd.setCursor(3,1);
//    lcd.print("Monitor");
//
//    delay(2000)
//    lcd.clear()



  // Configure the PulseSensor object, by assigning our variables to it.
  pulseSensor.analogInput(pulseWire);
  pulseSensor.setThreshold(threshold);

  // Double-check the "pulseSensor" object was created and "began" seeing a signal.
  if (pulseSensor.begin()) {
    Serial.println(" pulseSensor Object created "); //This prints one time at A power-up, or on Arduino reset.


  }
}

void loop() {


  int myBPM = pulseSensor.getBeatsPerMinute(); // Calls function on our pulseSensor object that returns BPM as an "int".
  // "myBPM" hold this BPM value now.
  if (pulseSensor.sawStartOfBeat()) { // Constantly test to see if "a beat happened".
    Serial.print("BPM: "); // Print phrase "BPM: "
    Serial.println(myBPM); // Print the value inside of myBPM.



if (myBPM > 100 ){
  digitalWrite(LED,HIGH);
  digitalWrite(buzzerPin,HIGH);
  delay(250);
  digitalWrite(LED,LOW);
  digitalWrite(buzzerPin,LOW);
 
  
}
else {
  digitalWrite(LED,LOW);
  digitalWrite(buzzerPin,LOW);
}

  }


//  // set the cursor to column 0, line 1
//  // (note: line 1 is the second row, since counting begins with 0):
//  lcd.setCursor(3, 1);
//  lcd.print(myBPM);








  delay(20); // delay the code by 20 ms
}
