#include <Adafruit_NeoPixel.h>

// ---------- Ultrasonic Sensor ----------
const int trigPin = 11;
const int echoPin = 12;

// ---------- NeoPixel ----------
const int neoPixelPin = 6;
const int numPixels = 1;

Adafruit_NeoPixel pixel(numPixels, neoPixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  // Ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Serial Monitor
  Serial.begin(9600);

  // NeoPixel
  pixel.begin();
  pixel.clear();
  pixel.show();
}

void loop() {

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo time
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  float distance = duration * 0.0343 / 2;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");


  // ---------- NeoPixel Feedback ----------

  if (distance < 7) {
    // Less than 20 cm = RED
    pixel.setPixelColor(0, pixel.Color(0, 255, 0));
  } 
  else {
    // 7 cm or more = BLUE
    pixel.setPixelColor(0, pixel.Color(0, 0, 255));
  }

  pixel.show();
  delay(100);
}


