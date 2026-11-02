#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <math.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
#define DHT_PIN A1
#define DHT_TYPE DHT11

const unsigned long DISPLAY_INTERVAL_MS = 4000UL;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHT dht(DHT_PIN, DHT_TYPE);

bool showTemperature = true;
unsigned long lastUpdate = 0;

void updateSensorDisplay() {
  const float humidity = dht.readHumidity();
  const float temperature = dht.readTemperature();

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);

  if (isnan(humidity) || isnan(temperature)) {
    display.println(F("Falha na leitura"));
    display.println(F("Verifique o DHT11"));
  } else {
    display.println(F("DHT11"));
    display.println();
    if (showTemperature) {
      display.println(F("Temperatura"));
      display.setTextSize(2);
      display.print(temperature, 1);
      display.println(F(" C"));
    } else {
      display.println(F("Umidade"));
      display.setTextSize(2);
      display.print(humidity, 1);
      display.println(F(" %"));
    }
  }

  display.display();
}

void setup() {
  Serial.begin(9600);
  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Falha ao inicializar o display SSD1306"));
    while (true) {
    }
  }

  display.setTextColor(SSD1306_WHITE);
  updateSensorDisplay();
  lastUpdate = millis();
}

void loop() {
  if (millis() - lastUpdate >= DISPLAY_INTERVAL_MS) {
    lastUpdate = millis();
    showTemperature = !showTemperature;
    updateSensorDisplay();
  }
}
