
#include <Servo.h>

// Global variables
Servo verticalServo;
Servo horizontalServo;

// Pins
int joystickVerticalPin = 0;                 // slider variable connecetd to analog pin 0
int joystickHorizonalPin = 1;

// Debug settings
bool debug = false;

// Setup
void setup()
{
  // Connect servos with gpio
  verticalServo.attach(8);
  horizontalServo.attach(9);

  // Setup debug system
  if (debug)
  {
    Serial.begin(9600);
  }

  // Set servos to neutral positions
  Neutral();
}

// Functions
void MoveHorizontal(int val, int delayVal)
{
  horizontalServo.write(val);
  delay(delayVal);
}

void MoveVertical(int val, int delayVal)
{
  verticalServo.write(val);
  delay(delayVal);
}

void Neutral()
{
  MoveVertical(179, 500);
  MoveHorizontal(93, 500);
  delay(2000);
}

void Play(int horizontal, int vertical)
{
  MoveHorizontal(horizontal, 100);
  MoveVertical(0, 100); // down
  MoveVertical(vertical, 100); //up
}

void PlayC4()
{
  Play(19, 15);
}

void PlayD4()
{
  Play(42, 15);
}

void PlayE4()
{
  Play(53, 15);
}

void PlayF4()
{
  Play(60, 15);
}

void PlayG4()
{
  Play(74, 15);
}

void PlayA4()
{
  Play(82, 15);
}

void PlayH4()
{
  Play(90, 15);
}

void PlayC5()
{
  Play(100, 15);
}

void PlayD5()
{
  Play(108, 15);
}

void PlayE5()
{
  Play(118, 15);
}

void PlayF5()
{
  Play(127, 15);
}

void PlayG5()
{
  Play(132, 15);
}

void PlayScale()
{
  PlayC4();
  PlayD4();
  PlayE4();
  PlayF4();
  PlayG4();
  PlayA4();
  PlayH4();
  PlayC5();
  PlayD5();
  PlayE5();
  PlayF5();
  PlayG5();
}

void PlayDuckling()
{
  PlayC4();
  PlayD4();
  PlayE4();
  PlayF4();
  PlayG4();
  PlayG4();
  
  PlayA4();
  PlayA4();
  PlayA4();
  PlayA4();
  PlayG4();
  
  PlayA4();
  PlayA4();
  PlayA4();
  PlayA4();
  PlayG4();
  
  PlayF4();
  PlayF4();
  PlayF4();
  PlayF4();
  PlayE4();
  PlayE4();
  
  PlayD4();
  PlayD4();
  PlayD4();
  PlayD4();
  PlayC4();
}

void PlayFastDeduction()
{
  PlayC4();
  PlayD4();
  PlayE4();
  
  PlayC4();
  PlayD4();
  PlayE4();
  
  PlayC4();
  PlayD4();
  PlayE4();
}

void PlayRandom()
{
  int a = random(0,11);
  switch(a) {
    case 0:
      PlayC4();
    case 1:
        PlayD4();
    case 2:
        PlayE4();
    case 3:
        PlayF4();
    case 4:
        PlayG4();
    case 5:
        PlayA4();
    case 6:
        PlayH4();
    case 7:
        PlayC5();
    case 8:
        PlayD5();
    case 9:
        PlayE5();
    case 10:
        PlayF5();
    case 11:
        PlayG5();
  }
}

void ManualMode()
{
  int verticalJoystickValue = analogRead(joystickVerticalPin);
  int horizontalJoystickValue = analogRead(joystickHorizonalPin);

  int mappedVerticalValue = map(verticalJoystickValue, 0, 1023, 0, 50);
  int mappendHorizontalValue = map(horizontalJoystickValue, 1023, 0, 15, 130);

  MoveVertical(mappedVerticalValue, 50);
  MoveHorizontal(mappendHorizontalValue, 50);
  
  if(mappedVerticalValue<20)
  {
     MoveVertical(15, 100);
     MoveVertical(0, 100);
  }

  // Test for button
  if (debug)
  {
    if (digitalRead(2) == HIGH)
    {
      Serial.print("Joystick button");
      Serial.println("HIGH");
    }
    else
    {
      Serial.print("Joystick button");
      Serial.println("LOW");
    }
  }

  Serial.println(mappendHorizontalValue);

  // Debug output
  if (debug)
  {
    Serial.println("Joystick output");
    Serial.println("Vertical joystick value:");
    Serial.println(verticalJoystickValue);
    Serial.println("Horizontal joystick value:");
    Serial.println(horizontalJoystickValue);
    Serial.println("Mapped Vertical joystick value:");
    Serial.println(mappedVerticalValue);
    Serial.println("Mapped Horizontal joystick value:");
    Serial.println(mappendHorizontalValue);
  }
}

// Loop
void loop()
{
  ManualMode();
  return;
  
  //PlayRandom();
  //return;
}
