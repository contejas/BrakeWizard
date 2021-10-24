// --------------------------------------------------
//
// Code for control of ESP32 through MIT inventor app (Bluetooth). 
// device used: ESP32-WROOM-32D

#include "BluetoothSerial.h" 

#define motor1Pin1 27
#define motor1Pin2 26
#define enable1Pin 14

const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;

// init Class:
BluetoothSerial ESP_BT; 

int incoming;

void setup() {
  Serial.begin(19200);
  ESP_BT.begin("ESP32_Brake_Controller"); //Name of your Bluetooth interface -> will show up on your phone
  
  ledcSetup(pwmChannel, freq, resolution);
  ledcAttachPin(enable1Pin, pwmChannel);
  
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
}

void loop() {
  
  if (ESP_BT.available()) 
  {
    incoming = ESP_BT.read(); //Read what we receive 

    int value = incoming % 10;
    Serial.print("Button 1:"); 
    Serial.println(value);
    if(value == 1) {
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
    } else if(value == 0) {
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
    } else {
      Serial.print("YOOO CHILLL");
    }
  }
}
