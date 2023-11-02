#define red 7
#define green 8
#define btn 2

void blinkled(byte pin, int ret);
// void ledgreen(int ret);

void setup() {

  Serial.begin(9600);


  //configure pin 2 as an input and enable the internal pull-up resistor

  pinMode(btn, INPUT_PULLUP);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);


}


void loop() {




  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
  delay(1000);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  delay(1000);
 

// ******
 //read the pushbutton value into a variable

  // int sensorVal = digitalRead(btn);

  // Serial.println(sensorVal);

  // if (sensorVal == HIGH) {


  //   digitalWrite(red, LOW);


  // } else {


  //   digitalWrite(red, HIGH);


  // }

//***********

  // blinkled(green, 1000);
  // blinkled(red, 1000);

}


void blinkled(byte pin, int ret)
{

  digitalWrite(pin, HIGH);
  delay(ret);
  digitalWrite(pin, LOW);
  delay(ret);

}












// void ledred(int ret)
// {

//   digitalWrite(green, HIGH);
//   delay(ret);
//   digitalWrite(green, LOW);
//   delay(ret);

// }

