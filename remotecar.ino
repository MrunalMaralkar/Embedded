#define BLYNK_TEMPLATE_ID "TMPL3cj1UmpvF"
#define BLYNK_TEMPLATE_NAME "Remote Control CAR"
#define BLYNK_AUTH_TOKEN  "INvEapsoEGVaChKKvi-pykPFTO2XtaxX"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Motor pins
const int IN1 = 16;
const int IN2 = 17;
const int IN3 = 18;
const int IN4 = 19;

char ssid[] = "OPPO Reno7 5G";
char pass[] = "02260226";

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}

// Blynk virtual pin controls
BLYNK_WRITE(V1) { // Forward
  int btn = param.asInt();
  if (btn == 1) forward();
}

BLYNK_WRITE(V2) { // Backward
  if (param.asInt() == 1) backward();
}

BLYNK_WRITE(V3) { // Left
  if (param.asInt() == 1) left();
}

BLYNK_WRITE(V4) { // Right
  if (param.asInt() == 1) right();
}

BLYNK_WRITE(V5) { // Stop
  if (param.asInt() == 1) stopCar();
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
