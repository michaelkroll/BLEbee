/*
 * BLEbee Test Sketch for Arduino 1.0.5
 * v1.0.0 2013-06-05
 * 
 * Copyright (c) 2012-2013 Dr. Michael Kroll
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

void setup()   {
  // The BLE-Shield v1.0.0 is running at 14400 baud. 
  Serial.begin(14400);
  Serial.print("BLEbee v1.0.0 Sketch setup...");
 
  // set the data rate for the Serial1 where the BLEbee is connected to
  Serial1.begin(14400);
  // The BLE-Shield v1.0.0 is not only litting up the blue LED on connection, 
  Serial.println(" done.");
}

void loop() // run over and over
{
  // Wait for Data on the serial console and submit it to the
  // BLE-Shield byte per byte. there is no longer a buffer involved.
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
