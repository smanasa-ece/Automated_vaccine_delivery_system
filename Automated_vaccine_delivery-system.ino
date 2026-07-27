#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// ---------------- TEMPERATURE SENSOR ----------------
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// ---------------- GPS ----------------
TinyGPSPlus gps;
SoftwareSerial gpsSerial(10, 9);   // GPS TX -> D10, GPS RX -> D9

// ---------------- OUTPUT PINS ----------------
const int greenLED = 6;
const int redLED = 5;
const int buzzer = 7;

void setup()
{
  Serial.begin(9600);
  gpsSerial.begin(9600);

  sensors.begin();

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.println("==================================");
  Serial.println(" AUTOMATED VACCINE DELIVERY SYSTEM");
  Serial.println("==================================");
}

void loop()
{
  // Read Temperature
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");

  // Vaccine Safe Range
  if (temp >= 2 && temp <= 8)
  {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);

    Serial.println("STATUS : SAFE");
  }
  else
  {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);

    Serial.println("STATUS : ALERT - UNSAFE TEMPERATURE");
  }

  // Read GPS
  while (gpsSerial.available())
  {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isValid())
  {
    Serial.print("Latitude : ");
    Serial.println(gps.location.lat(), 6);

    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
  }
  else
  {
    Serial.println("Waiting for GPS signal...");
  }

  Serial.println("----------------------------------");

  delay(2000);
}