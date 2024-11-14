#include <img.h>
#include <DHT.h>

#define DHTPIN 13       // Pin connected to DHT11 data pin
#define DHTTYPE DHT11   // DHT 11

TFT_eSPI tft = TFT_eSPI(); // Initialize the TFT screen
unsigned long previousMillis = 0; // Variable to store the previous time
const long interval = 1000; // Interval for sensor reading (1 seconds)

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor

// Array of colors for text display
uint16_t colors[] = {TFT_RED, TFT_GREEN, TFT_BLUE, TFT_YELLOW, TFT_CYAN, TFT_MAGENTA, TFT_ORANGE, TFT_WHITE};

void setup() {
  dht.begin(); // Start DHT sensor
  
  tft.init();                // Start TFT screen
  tft.setRotation(1);        // Set display orientation (adjust if necessary)
  tft.fillScreen(TFT_BLACK); // Clear screen with black color

  // Display images on the TFT screen
  tft.pushImage(15, 20, 50, 50, temp);
  tft.pushImage(100, 20, 50, 50, humi);
  
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(1);
  tft.drawString("Temperature", 7, 72);
  tft.drawString("Humidity", 100, 72);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // Save the last time the sensor was updated
    previousMillis = currentMillis;

    // Read temperature and humidity from DHT11
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    // Check if any reads failed and exit early (to try again later)
    if (isnan(humidity) || isnan(temperature)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    // Clear previous temperature and humidity values
    tft.fillRect(15, 90, 50, 16, TFT_BLACK);   // Clear previous temperature display
    tft.fillRect(108, 90, 50, 16, TFT_BLACK); // Clear previous humidity display

    // Display updated temperature and humidity values
    tft.setTextColor(TFT_WHITE);
    tft.drawString(String(temperature) + " C", 15, 90);   // Show temperature
    tft.drawString(String(humidity) + " %", 105, 90);    // Show humidity
  }
}
