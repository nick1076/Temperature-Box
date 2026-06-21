#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels



//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(1, 10);
  // Display static text
  display.println("Nicholas");

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(1, 30);
  // Display static text
  display.println("Niles");
  display.display(); 
  delay(2000);
}

void loop()
{
    //Read data and store it to variables hum and temp
    
    display.clearDisplay();

    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.setCursor(40, 18);

    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(90, 14);

    display.println("o");
    display.display(); 
    delay(2000); //Delay 2 sec.
}

   
