  

// Infrared Module Sensors 
#define R !digitalRead(10) // Right sensor
#define M !digitalRead(4)  // Middle sensor
#define L !digitalRead(2)  // Left sensor
// Light is absorbed if the sensor is over a black line, value = LOW



// H-Bridge Pins
// ENA and ENB control the speed of right and left motor separately by PWM.
#define ENA 5
#define ENB 6

// Duty cycle: between 0 (always off) and 255 (always on)
#define carSpeed 150
 
// IN1 and IN2 are used to control motor A (left), IN3 and IN4 are used to control motor B (right)
#define IN1 7   
#define IN2 8
#define IN3 9
#define IN4 11






// Car turning right
void right(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  
  // Left motors spin forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Right motors spin backward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
} 



// Car going forward
void forward(){

  // Both motors turned on at speed 'carSpeed'
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);

  // Left moters spin forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  // Righ moters spin forward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}




// Car turning left
void left(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);

  // Left motors spin backwards
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Right motors spin forward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}



// Stops both motors
void stop(){
   digitalWrite(ENA, LOW);
   digitalWrite(ENB, LOW);
} 

// Setup pins as inputs
void setup(){
  pinMode(10,INPUT);
  pinMode(4,INPUT);
  pinMode(2,INPUT);
}

// Main loop
void loop() {
  if(R) { 
    // Execute function
    right();
    // while right sensor is sensing the track, keep executing the function
    while(R);                             
  }   
  else if(L) {
    left();
    // while left sensor is sensing the track, keep executing the function
    while(L);  
  }
  
  // if middle sensor detects a black line, M = HIGH
  else if(M){
    // Execute function
    forward();
  }

}
