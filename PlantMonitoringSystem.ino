#include "U8glib.h"  // OLED display library
#include <DHT11.h>

// Pin Definitions
#define moisturePin A0  // Soil moisture sensor pin

const int switchLeftPin = 7;   // Pin connected to left position
const int switchRightPin = 6;  // Pin connected to right position

// Variables
int moisture = 0;  
int temperature = 0;
int humidity = 0;

const int numPlants = 3;  // Number of plants
int currentPlant = 0;  // Start with the first plant

// Plant names
String plantNames[numPlants] = {"Tomato", "Chili", "Spinach"};

// Moisture ranges
int moistureLow[numPlants] = {50, 40, 60};
int moistureHigh[numPlants] = {70, 60, 70};

// Temperature ranges
int tempLow[numPlants] = {20, 20, 10};
int tempHigh[numPlants] = {30, 30, 21};

// Humidity ranges
int humidityLow[numPlants] = {40, 60, 50};
int humidityHigh[numPlants] = {60, 70, 60};

// Initialize OLED display (SH1106 controller)
U8GLIB_SH1106_128X64 u8g(13, 11, 10, 9);

// Create an instance of the DHT11 class.
DHT11 dht11(2);

void setup() {
  pinMode(moisturePin, INPUT);  // Set soil moisture sensor pin as input
  pinMode(switchLeftPin, INPUT_PULLUP);   // Enable internal pull-up resistor
  pinMode(switchRightPin, INPUT_PULLUP);  // Enable internal pull-up resistor
  Serial.begin(9600); // Initialize Serial Monitor at 9600 baud
  dht11.setDelay(100); // Set this to the desired delay. Default is 500ms.
}

void draw(void) {
  // Check temperature against desired results
  String temperatureStatus = (temperature >= tempLow[currentPlant] && temperature <= tempHigh[currentPlant]) ? "o" : (temperature < tempLow[currentPlant]) ? "+" : "-";
  String moistureStatus = (moisture >= moistureLow[currentPlant] && moisture <= moistureHigh[currentPlant]) ? "o" : (moisture < moistureLow[currentPlant]) ? "+" : "-";
  String humidityStatus = (humidity >= humidityLow[currentPlant] && humidity <= humidityHigh[currentPlant]) ? "o" : (humidity < humidityLow[currentPlant]) ? "+" : "-";

  // Declare labels
  String moistureString = "Moisture: ";  
  String temperatureString = "Temperature: ";
  String humidityString = "Humidity: ";

  // Draw labels
  u8g.setFont(u8g_font_6x12); 
  u8g.drawStr(0, 22, moistureString.c_str()); // Moisture label
  u8g.drawStr(0, 35, temperatureString.c_str()); // Temperature label
  u8g.drawStr(0, 48, humidityString.c_str()); // Humidity label

  u8g.drawStr(30, 60, "-"); // Humidity unit
  u8g.drawStr(45, 60, plantNames[currentPlant].c_str()); // Plant name at the bottom
  u8g.drawStr(95, 60, "-"); // Humidity unit


  // Draw the values and status
  u8g.setFont(u8g_font_6x10); 

  u8g.drawStr(75, 22, String(moisture).c_str()); // Moisture value
  u8g.drawStr(110, 22, moistureStatus.c_str()); // Moisture status

  u8g.drawStr(75, 35, String(temperature).c_str()); // Temperature value
  u8g.drawStr(110, 35, temperatureStatus.c_str()); // Temperature status

  u8g.drawStr(75, 48, String(humidity).c_str()); // Humidity value
  u8g.drawStr(110, 48, humidityStatus.c_str()); // Humidity status

  // draw icons 
  u8g.setFont(u8g_font_5x8); 
  u8g.drawStr(90, 48, "%"); // Humidity unit
  u8g.drawStr(90, 35, "C"); // Temperature unit
  u8g.drawStr(90, 22, "%"); // Moisture unit

}

int readMoisture() {
  int sensorValue = analogRead(moisturePin);  // Read sensor input
  int moisturePercent = map(sensorValue, 0, 1023, 0, 100);  // Convert to percentage (0-100%)
  return moisturePercent;  // Return soil moisture level
}

void loop() {
  bool leftPressed = digitalRead(switchLeftPin) == LOW;  // Check if left position is pressed
  bool rightPressed = digitalRead(switchRightPin) == LOW; // Check if right position is pressed
  
  moisture = readMoisture();  // Update soil moisture level

  // Attempt to read the temperature and humidity values from the DHT11 sensor.
  int result = dht11.readTemperatureHumidity(temperature, humidity);

  if (leftPressed) {
    currentPlant = (currentPlant - 1 + numPlants) % numPlants;  // Cycle back to last plant
    delay(200);} 
  else if (rightPressed) {
    currentPlant = (currentPlant + 1) % numPlants;  // Cycle to next plant
    delay(200);}

  u8g.firstPage();  
  do {
    draw();  // Draw on OLED display
  } while (u8g.nextPage()); 
}
