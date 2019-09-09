#include <Stepper.h>
//#include <ardumidi.h>
int ledPin = 13;

const int stepsPerRevolution = 400;//720도

Stepper stepper1(stepsPerRevolution, 10, 11, 12, 13);


void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    switch (Serial.read())
    {
      case '1'://도
        Serial.println("1");
        playNote(stepper1, 20, 100);
        digitalWrite(ledPin, HIGH);
        break;
      case '2'://레
        Serial.println("2");
        playNote(stepper1, 22, 100);
        break;
      case '3'://미
        Serial.println("3");
        playNote(stepper1, 25, 100);
        break;
      case '4'://파
        Serial.println("4");
        playNote(stepper1, 27, 100);
        break;
      case '5'://솔
        Serial.println("5");
        playNote(stepper1, 30, 100);
        break;
      case '6'://라
        Serial.println("6");
        playNote(stepper1, 34, 100);
        break;
      case '7'://시
        Serial.println("7");
        playNote(stepper1, 38, 100);
        break;
      case '8'://도
        Serial.println("8");
        playNote(stepper1, 40, 100);
        break;
      case '9'://2레
        Serial.println("9");
        playNote(stepper1, 45, 100);
        break;
      case '0'://2미
        Serial.println("0");
        playNote(stepper1, 50, 100);
        break;
      case ' '://쉬고
        Serial.println("_");
        delay(400);
        break;
    }
  }
}
void playNote(Stepper stepperName, int speedStep, int delayTime)
{
  stepperName.setSpeed(speedStep);
  stepperName.step(speedStep);
  delay(delayTime);
}
