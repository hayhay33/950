/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman
  modified 27 Aug 2023
  by Eric Andrechek

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/


// Change this variable to the pin you plug your LED circuit into:
#define LED_PIN 1
// set these to the next pins in your circuit. Make sure that the physical order of the LEDs
// on your board are in the order they are labelled here.

#define LED_PIN_2 2
#define LED_PIN_3 3
#define LED_PIN_4 4
#define LED_PIN_5 5
#define LED_PIN_6 6
#define LED_PIN_7 7
#define LED_PIN_8 8
#define LED_PIN_9 9

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  // initialize digital pin LED_PIN as an output.
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
  pinMode(LED_PIN_6, OUTPUT);
  pinMode(LED_PIN_7, OUTPUT);
  pinMode(LED_PIN_8, OUTPUT);
  pinMode(LED_PIN_9, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  for(int i = 0; i < 2; ++i){
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN_2, HIGH);
    delay(100);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN, LOW);
    delay(100);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_2, LOW);
    delay(100);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_3, LOW);
    delay(100);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_4, LOW);
    delay(100);
    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_5, LOW);
    delay(100);
    digitalWrite(LED_PIN_8, HIGH);
    digitalWrite(LED_PIN_6, LOW);
    delay(100);
    digitalWrite(LED_PIN_9, HIGH);
    digitalWrite(LED_PIN_7, LOW);
    delay(100);
    digitalWrite(LED_PIN_9, LOW);
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(100);
    digitalWrite(LED_PIN_9, HIGH);
    delay(100);
    digitalWrite(LED_PIN_8, HIGH);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_9, LOW);
    delay(100);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_8, LOW);
    delay(100);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_7, LOW);
    delay(100);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_6, LOW);
    delay(100);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_5, LOW);
    delay(100);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_4, LOW);
    delay(100);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN_3, LOW);
    delay(100);
    digitalWrite(LED_PIN_2, LOW);
    delay(100);
  }

  for(int i = 0; i < 10; ++i) {
    int batteryVoltage = analogRead(A6);
    if(batteryVoltage <= 1023 && batteryVoltage > 920){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if(batteryVoltage <= 920 && batteryVoltage > 817){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(batteryVoltage <= 817 && batteryVoltage > 714){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(batteryVoltage <= 714 && batteryVoltage > 611){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(batteryVoltage <= 611 && batteryVoltage > 508){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(batteryVoltage <= 508 && batteryVoltage > 405){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(batteryVoltage <= 405 && batteryVoltage > 302){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(batteryVoltage <= 302 && batteryVoltage > 199){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(batteryVoltage <= 199 && batteryVoltage > 96){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(batteryVoltage <= 96 && batteryVoltage > 0){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else {
      for(int i = 0; i < 5; ++i){
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(LED_PIN_2, HIGH);
        digitalWrite(LED_PIN_3, HIGH);
        digitalWrite(LED_PIN_4, HIGH);
        digitalWrite(LED_PIN_5, HIGH);
        digitalWrite(LED_PIN_6, HIGH);
        digitalWrite(LED_PIN_7, HIGH);
        digitalWrite(LED_PIN_8, HIGH);
        digitalWrite(LED_PIN_9, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        digitalWrite(LED_PIN, LOW);
        digitalWrite(LED_PIN_2, LOW);
        digitalWrite(LED_PIN_3, LOW);
        digitalWrite(LED_PIN_4, LOW);
        digitalWrite(LED_PIN_5, LOW);
        digitalWrite(LED_PIN_6, LOW);
        digitalWrite(LED_PIN_7, LOW);
        digitalWrite(LED_PIN_8, LOW);
        digitalWrite(LED_PIN_9, LOW);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
      }
      return;
    }
    delay(500);
  }
  for(int i = 0; i < 5; ++i){
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_8, HIGH);
    digitalWrite(LED_PIN_9, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, LOW);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW);
    digitalWrite(LED_PIN_9, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }

  for(int i = 0; i < 10; ++i) {
    int fiveVoltage = analogRead(A1);
    if(fiveVoltage <= 1023 && fiveVoltage > 920){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if(fiveVoltage <= 920 && fiveVoltage > 817){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(fiveVoltage <= 817 && fiveVoltage > 714){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(fiveVoltage <= 714 && fiveVoltage > 611){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(fiveVoltage <= 611 && fiveVoltage > 508){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(fiveVoltage <= 508 && fiveVoltage > 405){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(fiveVoltage <= 405 && fiveVoltage > 302){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(fiveVoltage <= 302 && fiveVoltage > 199){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(fiveVoltage <= 199 && fiveVoltage > 96){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(fiveVoltage <= 96 && fiveVoltage > 0){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else {
      for(int i = 0; i < 5; ++i){
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(LED_PIN_2, HIGH);
        digitalWrite(LED_PIN_3, HIGH);
        digitalWrite(LED_PIN_4, HIGH);
        digitalWrite(LED_PIN_5, HIGH);
        digitalWrite(LED_PIN_6, HIGH);
        digitalWrite(LED_PIN_7, HIGH);
        digitalWrite(LED_PIN_8, HIGH);
        digitalWrite(LED_PIN_9, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        digitalWrite(LED_PIN, LOW);
        digitalWrite(LED_PIN_2, LOW);
        digitalWrite(LED_PIN_3, LOW);
        digitalWrite(LED_PIN_4, LOW);
        digitalWrite(LED_PIN_5, LOW);
        digitalWrite(LED_PIN_6, LOW);
        digitalWrite(LED_PIN_7, LOW);
        digitalWrite(LED_PIN_8, LOW);
        digitalWrite(LED_PIN_9, LOW);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
      }
      return;
    }
    delay(500);
  }

  for(int i = 0; i < 2; ++i){
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_8, HIGH);
    digitalWrite(LED_PIN_9, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, LOW);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW);
    digitalWrite(LED_PIN_9, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }

  for(int i = 0; i < 10; ++i) {
    int twothreeVoltage = analogRead(A2);
    if(twothreeVoltage <= 1023 && twothreeVoltage > 920){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if(twothreeVoltage <= 920 && twothreeVoltage > 817){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(twothreeVoltage <= 817 && twothreeVoltage > 714){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(twothreeVoltage <= 714 && twothreeVoltage > 611){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(twothreeVoltage <= 611 && twothreeVoltage > 508){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(twothreeVoltage <= 508 && twothreeVoltage > 405){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(twothreeVoltage <= 405 && twothreeVoltage > 302){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(twothreeVoltage <= 302 && twothreeVoltage > 199){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(twothreeVoltage <= 199 && twothreeVoltage > 96){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(twothreeVoltage <= 96 && twothreeVoltage > 0){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else {
      for(int i = 0; i < 5; ++i){
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(LED_PIN_2, HIGH);
        digitalWrite(LED_PIN_3, HIGH);
        digitalWrite(LED_PIN_4, HIGH);
        digitalWrite(LED_PIN_5, HIGH);
        digitalWrite(LED_PIN_6, HIGH);
        digitalWrite(LED_PIN_7, HIGH);
        digitalWrite(LED_PIN_8, HIGH);
        digitalWrite(LED_PIN_9, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        digitalWrite(LED_PIN, LOW);
        digitalWrite(LED_PIN_2, LOW);
        digitalWrite(LED_PIN_3, LOW);
        digitalWrite(LED_PIN_4, LOW);
        digitalWrite(LED_PIN_5, LOW);
        digitalWrite(LED_PIN_6, LOW);
        digitalWrite(LED_PIN_7, LOW);
        digitalWrite(LED_PIN_8, LOW);
        digitalWrite(LED_PIN_9, LOW);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
      }
      return;
    }
    delay(500);
  }

  for(int i = 0; i < 2; ++i){
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_8, HIGH);
    digitalWrite(LED_PIN_9, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, LOW);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW);
    digitalWrite(LED_PIN_9, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }

  for(int i = 0; i < 10; ++i) {
    int onethreeVoltage = analogRead(A3);
    if(onethreeVoltage <= 1023 && onethreeVoltage > 920){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if(onethreeVoltage <= 920 && onethreeVoltage > 817){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(onethreeVoltage <= 817 && onethreeVoltage > 714){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(onethreeVoltage <= 714 && onethreeVoltage > 611){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(onethreeVoltage <= 611 && onethreeVoltage > 508){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(onethreeVoltage <= 508 && onethreeVoltage > 405){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(onethreeVoltage <= 405 && onethreeVoltage > 302){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(onethreeVoltage <= 302 && onethreeVoltage > 199){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(onethreeVoltage <= 199 && onethreeVoltage > 96){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(onethreeVoltage <= 96 && onethreeVoltage > 0){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else {
      for(int i = 0; i < 5; ++i){
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(LED_PIN_2, HIGH);
        digitalWrite(LED_PIN_3, HIGH);
        digitalWrite(LED_PIN_4, HIGH);
        digitalWrite(LED_PIN_5, HIGH);
        digitalWrite(LED_PIN_6, HIGH);
        digitalWrite(LED_PIN_7, HIGH);
        digitalWrite(LED_PIN_8, HIGH);
        digitalWrite(LED_PIN_9, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        digitalWrite(LED_PIN, LOW);
        digitalWrite(LED_PIN_2, LOW);
        digitalWrite(LED_PIN_3, LOW);
        digitalWrite(LED_PIN_4, LOW);
        digitalWrite(LED_PIN_5, LOW);
        digitalWrite(LED_PIN_6, LOW);
        digitalWrite(LED_PIN_7, LOW);
        digitalWrite(LED_PIN_8, LOW);
        digitalWrite(LED_PIN_9, LOW);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
      }
      return;
    }
    delay(500);
  }

  for(int i = 0; i < 3; ++i){
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_8, HIGH);
    digitalWrite(LED_PIN_9, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, LOW);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW);
    digitalWrite(LED_PIN_9, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }

  for(int i = 0; i < 10; ++i) {
    int threeVoltage = analogRead(A0);
    if(threeVoltage <= 1023 && threeVoltage > 920){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if(threeVoltage <= 920 && threeVoltage > 817){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(threeVoltage <= 817 && threeVoltage > 714){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(threeVoltage <= 714 && threeVoltage > 611){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(threeVoltage <= 611 && threeVoltage > 508){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(threeVoltage <= 508 && threeVoltage > 405){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(threeVoltage <= 405 && threeVoltage > 302){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(threeVoltage <= 302 && threeVoltage > 199){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(threeVoltage <= 199 && threeVoltage > 96){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else if(threeVoltage <= 96 && threeVoltage > 0){
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    else {
      for(int i = 0; i < 5; ++i){
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(LED_PIN_2, HIGH);
        digitalWrite(LED_PIN_3, HIGH);
        digitalWrite(LED_PIN_4, HIGH);
        digitalWrite(LED_PIN_5, HIGH);
        digitalWrite(LED_PIN_6, HIGH);
        digitalWrite(LED_PIN_7, HIGH);
        digitalWrite(LED_PIN_8, HIGH);
        digitalWrite(LED_PIN_9, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        digitalWrite(LED_PIN, LOW);
        digitalWrite(LED_PIN_2, LOW);
        digitalWrite(LED_PIN_3, LOW);
        digitalWrite(LED_PIN_4, LOW);
        digitalWrite(LED_PIN_5, LOW);
        digitalWrite(LED_PIN_6, LOW);
        digitalWrite(LED_PIN_7, LOW);
        digitalWrite(LED_PIN_8, LOW);
        digitalWrite(LED_PIN_9, LOW);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
      }
      return;
    }
    delay(500);
  }
}
