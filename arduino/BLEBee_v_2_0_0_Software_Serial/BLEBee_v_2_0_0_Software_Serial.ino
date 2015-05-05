/*
 * BLEBee SoftSerial Test Sketch for Arduino 1.6.3
 * v2.0.0 2015-05-05
 * 
 * Copyright (c) 2012-2015 Dr. Michael Kroll
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
 *
 * http://www.mkroll.mobi
 * http://forum.mkroll.mobi
 */
#include <SoftwareSerial.h>

// In order to not interfear with the USB serial console
// we configure the BLEBees serial lines to be available
// through SoftwareSerial on pins D8 and D9. 
// Please set the jumpers
// to RX -> D8 and TX -> D9
SoftwareSerial bleShield(8,9);

void setup()   {

  // On the Arduino Uno, the Serial port is mapped to the USB Cable
  // and available in pins D0 D1.
  // We set it to 9600 baud.
  Serial.begin(9600);
  Serial.print("BLEBee v2.0.0 Sketch setup...");

  // Set the data rate for the SoftwareSerial port
  // The BLEBee v2.0.0 is running at 9600 since this
  // is the default baudrate for the BLEBee v2.0.0 
  bleShield.begin(9600);
  Serial.println(" done.");
}


void loop() // run over and over
{
  // Wait for Data on the serial console and submit it to the
  // BLEBee byte per byte. there is no longer a buffer involved.
  if (Serial.available()) {
    int ch = Serial.read();
    char c = char(ch);
    Serial.print(c);
    bleShield.print(c);
  }
  
  // Wait for data send from the iPhone and print it to the serial console.
  // That's it. Quite simple.
  if (bleShield.available()) {
    Serial.write(bleShield.read());
  }
}
