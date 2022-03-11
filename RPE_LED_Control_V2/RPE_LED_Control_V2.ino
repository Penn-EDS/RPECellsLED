// Purpose: This program can control 2 LEDs arrays through the digital pins
// of the Arduino Nano. The Potenciometer will set the value of intensity of the
// blue LEDS and the button will toggle between set and reset the intensity values.
//
// Author: Pedro Quijano
// Date : March 10, 2022
//
// Rev 1.2 Commenting out the debugging lines
// Rev 1.1 Initial revision
//

#define LEDArray1 3
#define LEDArray2 9
#define Button 2
#define Pot A0

int n=0;
int Values = 0; //default value
const int convert = 10; //Variable for bit conversion

void setup() {
// debugging only --   Serial.begin(9600); delay(500); Serial.println("Begin Setup"); //delay for serial begin
  pinMode(Button, INPUT_PULLUP);
  pinMode(Pot, INPUT);

  pinMode(LEDArray1, OUTPUT);
  pinMode(LEDArray2, OUTPUT);

  Values = analogRead(Pot);//Set initial values the current potentiometer position.
  Values /= convert;  //Originally convert 10bit value to 8bit value dividing by 4. Now divide by 10 for a 40% duty cycle.

  analogWrite(LEDArray1,Values);
  delay(10);
  analogWrite(LEDArray2,Values);

  digitalWrite(Button, HIGH); //Make sure button variable starts High.
  // delay(100);
}

void loop(){
// Debugging only  Serial.print("Outside programming mode, duty cycle is: "); Serial.println((float(Values)/255.0)) * 100; //Used for debugging duty cycle

//***************************************************************
//****** Below is a debouncing routine for the push-button ******
//***************************************************************
  if(digitalRead(Button)==LOW){ //If button is pressed LEDs intensity is controlled by the potentiometer
    while(digitalRead(Button)==LOW){} //Waits for the button to be released

    while(digitalRead(Button)==HIGH){ //Potentiometer controls the LED intensity until the button is pressed again
      Values = analogRead(Pot);
      Values /= convert;  //Convert 10bit value to 8bit value

      analogWrite(LEDArray1,Values);
      delay(10);  //small delay between readings
      analogWrite(LEDArray2,Values);

    // Debugging only:      Serial.print("Inside programming mode, duty cycle is: "); Serial.println((float(Values)/255.0)) * 100; //Used for debugging duty cycle
    }
    while(digitalRead(Button)==LOW){} //Waits for the button to be released
  }
}
