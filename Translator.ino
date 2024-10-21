#include <Wire.h>
#include <MPU6050.h>
#include <SoftwareSerial.h>
#include <I2Cdev.h>



MPU6050 mpu;
const int MPU_ADDRESS = 0x68; // I2C address of the MPU-6050

int16_t ax, ay, az, gx, gy, gz; // 16-bit integers
SoftwareSerial BTSerial(3, 2); // RX, TX pins of HC-05

struct MyData {
  byte X;
  byte Y;
  byte Z;
};

MyData data;




const int INDEX_PIN = A3;  
const int MIDDLE_PIN = A2;
const int RING_PIN = A1;
const int PINKY_PIN = A0;

void setup() {
  // Flex sensor pin setup
  pinMode(A0, INPUT); //PINKY
  pinMode(A1, INPUT); //RING
  pinMode(A2, INPUT); //MIDDLE
  pinMode(A3, INPUT); //INDEX
 
  Serial.begin(9600); // Initialize serial communication for debugging
  Wire.begin();
  mpu.initialize();
  BTSerial.begin(9600); // Initialize SoftwareSerial for Bluetooth communication


  // MPU6050 setup
  Wire.begin();
  mpu.initialize();

}

void loop() {
  // Flex sensor readings
  int index = analogRead(INDEX_PIN);
  int middle = analogRead(MIDDLE_PIN);
  int ring = analogRead(RING_PIN);
  int pinky = analogRead(PINKY_PIN);


  // MPU6050 data readings
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  data.X = map(ax, -17000, 17000, 0, 255 ); // X axis data
  data.Y = map(ay, -17000, 17000, 0, 255); 

  delay(500);


  //pinky a0 default 210 ; bent <210
  //ring a1
  // middle a2 default 280 ; bent <280
  // index a3
  
  // yaxis default 130  .. bend forward -> decrease
  // xaxis default 110  .. right -> decrease
  
  if (index >=0 && middle >= 260 && ring<210 && pinky <210 && data.Y>125) {
    BTSerial.write("peace\n"); // Send string over bluetooth
    Serial.println("peace");
    delay(500);
  } else if (index >=0 && middle >= 260 && ring >=210 && pinky <210 ) {
    BTSerial.write("i need help\n");
    Serial.println("i need help");
    delay(500);
  } /*else if (index >=0 && middle >= 260 && ring >= 210 && pinky >= 210 && data.Y >= 125) {
    BTSerial.write("okay\n");
    Serial.println("okay");
    delay(500);
  }*/ else if (index >=0 && middle <= 240 && ring <= 190 && pinky <= 190 && data.X <= 0 && data.Y >= 125) {
    BTSerial.write("come here\n");
    Serial.println("come here");
    delay(500);
  } else if (index >=0 && middle >= 260 && ring >=210 && pinky >= 210 && data.Y >= 125) {
    BTSerial.write("hello\n");
    Serial.println("hello");
    delay(500);
  } else if (index >=0 && middle <= 240 && ring <=210 && pinky <= 210) {
    BTSerial.write("fist bump\n");
    Serial.println("fist bump");
    delay(500);
  } else if (index >=0 && middle <= 240 && ring <=200 && pinky >= 210 && data.Y >= 130) {
    BTSerial.write("need to go washroom\n");
    Serial.println("need to go washroom");
    delay(500);
  } else if (index >=0 && middle >=260 && ring >=210 && pinky >= 210 && data.X <= 0 && data.Y >= 130) {
    BTSerial.write("thank you\n");
    Serial.println("thank you");
    delay(500);
  } /*else if (index >=0 && middle >=260 && ring >=210 && pinky >= 210 && data.X <= 0 && data.Y >= 130) {
    BTSerial.write("");
    Serial.println("");
    delay(500);
  }*/ else {
    //BTSerial.writen("No sign detected");
    Serial.println("No sign detected\n");
    delay(500);
  }
  delay(500); 
}