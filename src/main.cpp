#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

const int display_toggle_button_pin = 8;
const int water_pump_button_pin = 12;
const int 
 = 13;
const int potentiometer_pin = A4;
const int water_sensor_pin = A5;

int display_mode = 0;
int water_pump_mode = 0;
int potentiometer_reading = 0;
int water_sensor_reading = 0;

LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  pinMode(display_toggle_button_pin , INPUT);
  pinMode(potentiometer_pin , INPUT);
  pinMode(water_sensor_pin , INPUT);
  pinMode(water_pump_button_pin , INPUT);
  pinMode(water_pump_motor_pin , OUTPUT);
}

void loop() {
  // water pump
  water_pump_mode = digitalRead(water_pump_button_pin);
  if (water_pump_mode == HIGH) {
    digitalWrite(water_pump_motor_pin, HIGH);
  } else {
    digitalWrite(water_pump_motor_pin, LOW);
  }

  // water sensor
  water_sensor_reading = analogRead(water_sensor_pin);

  // potenchiometer value
  potentiometer_reading = analogRead(potentiometer_pin);

  // display control
  display_mode = digitalRead(display_toggle_button_pin);
  lcd.clear();
  if (display_mode == HIGH) {
    lcd.setCursor(0, 0);
    lcd.print("potench val:");
    lcd.setCursor(0, 1);
    lcd.print(String(potentiometer_reading));
  } else {
    // display water sensor reading
    lcd.setCursor(0, 0);
    lcd.print("water sensor:");
    lcd.setCursor(0, 1);
    lcd.print(String(water_sensor_reading));
  }

  // lcd.clear();
  // lcd.print("Monday");
  // delay(2000);
  // lcd.clear();
  // lcd.print("13:45");
  delay(300);

}