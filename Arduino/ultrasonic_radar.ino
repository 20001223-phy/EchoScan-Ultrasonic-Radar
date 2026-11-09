
#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(A0, A1, A2, A3, 8, 9);
Servo scanner;

#define TRIG_PIN 5
#define ECHO_PIN 10

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  scanner.attach(6);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lcd.print("Scanner Ready");
  delay(1500);
  lcd.clear();

  Serial.println("Angle,Distance");
}

void loop() {
  for (int angle = 0; angle <= 180; angle += 10) {
    scanner.write(angle);
    delay(500);

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH, 30000);

    lcd.setCursor(0, 0);
    lcd.print("Angle: ");
    lcd.print(angle);
    lcd.print("       ");

    lcd.setCursor(0, 1);

    if (duration == 0) {
      lcd.print("Dist: No Echo   ");
      Serial.print(angle);
      Serial.println(",Out");
    } else {
      float distance = duration * 0.0343 / 2.0;

      lcd.print("Dist: ");
      lcd.print(distance, 1);
      lcd.print(" cm   ");

      Serial.print(angle);
      Serial.print(",");
      Serial.println(distance, 1);
    }
  }
}
