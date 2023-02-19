// C++ code
//

#include <Wire.h>
#include <IRremote.h> //including infrared remote header file
int RECV_PIN = 11; // the pin where you connect the output pin of IR sensor
IRrecv irrecv(RECV_PIN);
decode_results results;
int value = 0;
int mA;


void setup()
{
Wire.begin();
Serial.begin(9600);
irrecv.enableIRIn();
}

void loop()
{
  Wire.beginTransmission(1);
  Wire.write(mA);         
  Wire.endTransmission();
  
  
  if (irrecv.decode(&results)) {
    value = results.value;
    Serial.println(" ");
    Serial.print("Code: ");
    Serial.println(value); //prints the value a a button press
    Serial.println(" ");
    irrecv.resume(); // Receive the next value
    Serial.println("*****************"); 
  }
  
  
  
  if (value == -32641) {
    mA= 15 + mA; 
    
    if (mA>=61) {
      mA=0;   
    
    }
    value=0;
  }

  if (value == -32641) {
    mA= mA - 15;
    
   if (mA>=-1) {
   mA=45;
    
    }
    value=0;
  }
  
  
}
    
      
      
      
      
      