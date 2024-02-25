
#include <Servo.h>

Servo base;
Servo arm;
// create servo object to control a servo
// twelve servo objects can be created on most boards

int pos_arm = 0;  // variable to store the servo position
int pos_base = 0;

void setup() {
  base.attach(9);  // attaches the servo on pin 9 to the servo object
  arm.attach(10);
}

int countCommas(String input) {
  int count = 0;
  for (int i = 0; i < input.length(); i++) {
    if (input.charAt(i) == ',') {
      count++;
    }
  }
  return count;
}

void get_command(String input) {

  int commaCount = countCommas(input);

  if (commaCount == 1) {
    int firstCommaIndex = input.indexOf(',');
    String set1 = input.substring(0, firstCommaIndex);  // Extract the first P value
    String set2 = input.substring(firstCommaIndex + 1);

    int set1_int = set1.toInt();
    int set2_int = set2.toInt();

    base.write(set1_int);
    arm.write(set2_int);
    Serial.print("Adjusted Servos");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // if (Serial.available() > 0) {
  //   String input = Serial.readStringUntil('\n');  // Read the data until a newline character is received
  //   get_command(input);
  // }
  // base.write(90);
  // delay(1000);
  // base.write(0);
  // delay(1000);
  base.write(90);
  arm.write(180);
}
