// This program can control 2 LEDs arrays through the digital pins
// of the Arduino Nano

#define LEDArray1 3
#define LEDArray2 9
#define Button 2
#define Pot A0
int n=0;
int Values[2]={0,0};
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600); delay(500); Serial.println("Begin Setup"); //delay for serial begin

  pinMode(Button, INPUT_PULLUP);
  pinMode(Pot, INPUT);

  pinMode(LEDArray1, OUTPUT);
  pinMode(LEDArray2, OUTPUT);


  digitalWrite(LEDArray1, LOW);
  digitalWrite(LEDArray2, LOW);

}

void loop() {
 //Serial.print("Outside programming mode, duty cycle is: "); Serial.println((float(Values[1])/255.0)) * 100; //Used for debugging duty cycle

 analogWrite(LEDArray1,Values[0]);
 analogWrite(LEDArray2,Values[1]);
 Values[n]=(analogRead(Pot)/4);
 if(digitalRead(Button)==LOW){
  while(digitalRead(Button)==LOW){
  }
  ++n;
  if(n>1){
    n=0;
  }
 }
}
