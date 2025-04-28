#include <LiquidCrystal_I2C.h>

// Pins
const int moisturePin = A0;       // Moisture sensor pin
const int relayPin = 7;           // Pin to control the relay
const int trigPin = 9;            // Ultrasonic sensor trig pin
const int echoPin = 10;           // Ultrasonic sensor echo pin

// Setup LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Address 0x27 for most 16x2 I2C LCDs

// Moisture thresholds
const int dryThreshold = 500;       // Moisture threshold (adjust as needed)

// Water level thresholds (in cm)
const int lowWaterThreshold = 5;    // Low water level threshold (in cm)
const int maxWaterHeight = 14;      // Max water height in the tank (in cm)
const int maxDistance = 22;         // Distance from the sensor to the bottom of the tank (in cm)

// Plant name
String plantName = "Basil";

void setup() {
  pinMode(moisturePin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  digitalWrite(relayPin, LOW);  // Ensure the pump is off initially
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Read soil moisture level
  int moistureValue = analogRead(moisturePin);
  bool isDry = moistureValue > dryThreshold;

  // Measure water level using ultrasonic sensor
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  // Convert duration to water level distance in cm
  int distanceCm = duration * 0.034 / 2;
  int waterLevelCm = maxDistance - distanceCm;  // Calculate the actual water level

  // Control pump based on moisture sensor
  if (isDry) {
    digitalWrite(relayPin, HIGH);  // Turn ON pump
  } else {
    digitalWrite(relayPin, LOW);   // Turn OFF pump
  }

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Smart " + plantName);

  // Display water level
  lcd.setCursor(0, 1);
  if (waterLevelCm >= 0 && waterLevelCm <= maxWaterHeight) {
    if (waterLevelCm < lowWaterThreshold) {
      lcd.print("Low Water: " + String(waterLevelCm) + " cm");
    } else {
      lcd.print("Water OK: " + String(waterLevelCm) + " cm");
    }
  } else {
    lcd.print("Check sensor");
  }

  delay(2000);  // Show water level for 2 seconds
  lcd.clear();

  // Show soil moisture status
  lcd.setCursor(0, 0);
  lcd.print(plantName + " soil:");

  lcd.setCursor(0, 1);
  if (isDry) {
    lcd.print("Needs water!");
  } else {
    lcd.print("Moist & happy :)");
  }

  delay(3000);  // Show soil moisture status for 3 seconds
}
