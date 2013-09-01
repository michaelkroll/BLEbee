/*
 * BLEbee Test Sketch for Arduino 1.0.5
 * v1.0.0 2013-09-01
 * 
 * This Sketch is used to test the BLEBees communication features
 * with an Arduino FIO
 *
 * Copyright (c) 2013 Dr. Michael Kroll
 *
 * http://www.mkroll.mobi
 * http://forum.mkroll.mobi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this 
 * software and associated documentation files (the "Software"), to deal in the Software 
 * without restriction, including without limitation the rights to use, copy, modify, merge, 
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons 
 * to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or 
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE 
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

// Pin 13 has an LED connected on most Arduino boards.
int led = 13;

long previousMillis = 0; 
long interval = 1000; 

long cnt = 0;

void setup() {

  // Set the data rate for the Serial where the BLEbee is connected to
  // The BLEBee's baudrate can be controlled by characteristic: 
  // 2FBC0F31-726A-4014-B9FE-C8BE0652E982
  // 0x00 = 9600 (default)
  // 0x01 = 14400
  // 0x02 = 19200
  // 0x03 = 28800
  // 0x04 = 38400
  Serial.begin(9600);
  Serial.print("BLEbee v1.0.0 Sketch setup...");
}
 
void loop() { // run over and over
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;       
    Serial.print("Hello from Arduino FIO: ");      
    Serial.println(cnt++);
  }
  
  if (Serial.available()) {
    int data = Serial.read();
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  }
}
