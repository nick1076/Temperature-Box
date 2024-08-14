#include <Adafruit_GFX.h>
#include <Adafruit_GC9A01A.h>

// Define the pins used for the display
#define TFT_CS   5
#define TFT_RST  4
#define TFT_DC   21
#define TFT_MOSI 23
#define TFT_SCK  18

#include "DHT.h"

#define DHTPIN 15

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

// Create an instance of the display
Adafruit_GC9A01A tft = Adafruit_GC9A01A(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  // Initialize the display
  Serial.begin(9600);
  dht.begin();
  tft.begin();
  tft.setRotation(1); // Optional: Rotate the display
  tft.fillScreen(GC9A01A_BLACK); // Clear the screen with black color

  // Set text color and size
  tft.setTextColor(GC9A01A_WHITE);
  tft.setTextSize(8);

  Serial.print("hello");
  
  // Print text
}

void loop() {
  float h = dht.readHumidity();
  float f = dht.readTemperature(true);

  Serial.print("hello2");

  if (isnan(h) || isnan(f)) {
    return;
  }

  Serial.print("hello3");
  
  tft.fillScreen(GC9A01A_BLACK);
  tft.setCursor(80, 50);
  tft.println((int)f);
  tft.setCursor(55, 140);
  tft.print((int)h);
  tft.println("%");

  Serial.print("hello4");
  delay(2000);
}