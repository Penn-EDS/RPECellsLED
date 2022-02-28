// This program can control 2 LEDs arrays through the digital pins
// of the Arduino Nano

#define LEDArray1 3
#define LEDArray2 6
#define Button 2
#define Pot A0
int n=0;
int Values[2]={128,128};
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(Button, INPUT_PULLUP);
  pinMode(Pot, INPUT);

  pinMode(LEDArray1, OUTPUT);
  pinMode(LEDArray2, OUTPUT);


  digitalWrite(LEDArray1, LOW);
  digitalWrite(LEDArray2, LOW);

}
