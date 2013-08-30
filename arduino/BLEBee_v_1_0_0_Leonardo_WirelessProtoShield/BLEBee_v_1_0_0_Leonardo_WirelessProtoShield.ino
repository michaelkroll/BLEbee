/*
 * BLEbee Test Sketch for Arduino 1.0.5
 * v1.0.0 2013-08-30
 * 
 * This Sketch is used to test the BLEBees communication features
 * with a Fio v3 - ATmega32u4 from Sparkfun Electronics: https://www.sparkfun.com/products/11520
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

void setup()   {
  // Set the baudrate of the Arduino
  Serial.begin(9600);
  Serial.print("BLEbee v1.0.0 Sketch setup...");

  // Set the data rate for the Serial1 where the BLEbee is connected to
  // The BLEBee's baudrate can be controlled by characteristic: 
  // 2FBC0F31-726A-4014-B9FE-C8BE0652E982
  // 0x00 = 9600 (default)
  // 0x01 = 14400
  // 0x02 = 19200
  // 0x03 = 28800
  // 0x04 = 38400
  Serial1.begin(9600);
  Serial.println(" done.");
}

void loop() // run over and over
{
  // Wait for Data on the serial console and submit it to the
  // BLEBee byte per byte. there is no longer a buffer involved.
  if (Serial.available()) {
    int ch = Serial.read();
    Serial.print(ch);
    Serial1.write(ch);
  }

  // Wait for data send from the iPhone and print it to the serial console.
  // That's it. Quite simple.
  if (Serial1.available()) {
    Serial.write(Serial1.read());
  }
}

