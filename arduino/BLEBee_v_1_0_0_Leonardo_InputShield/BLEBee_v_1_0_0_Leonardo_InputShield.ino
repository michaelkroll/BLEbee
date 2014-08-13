/*
 * BLEbee Test Sketch for Arduino 1.0.5
 * v1.0.0 2013-08-30
 * 
 * This Sketch was created to use the BLEBee as the communication gateway to build a
 * BLE joystick using DFRobots Input Shield V2 http://www.dfrobot.com/index.php?route=product/product&path=35_124&product_id=62
 * and an Arduino Leonardo
 *
 * Copyright (c) 2014 Dr. Michael Kroll
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

#define up_button	8
#define down_button	A1
#define left_button	9
#define right_button	12
#define stick_button	A0
#define joystick_x	A2
#define joystick_y	A3

int old_left_state = 0;
int old_right_state = 01;
int old_up_state = 0;
int old_down_state = 0;
int old_stick_state = 0;
int old_joystick_x_value = 524;
int old_joystick_y_value = 517;

int counter = 0;

void setup()   {
  // Set the baudrate of the Arduino
  Serial.begin(9600);
  Serial.print("BLEbee v1.0.0 Sketch setup...");

  pinMode (left_button,  INPUT);
  pinMode (right_button, INPUT);
  pinMode (up_button,    INPUT);
  pinMode (down_button,  INPUT);

  pinMode (stick_button, INPUT);
  pinMode (joystick_x,   INPUT);
  pinMode (joystick_y,   INPUT);

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
  int left_state = digitalRead (left_button);
  int right_state = digitalRead (right_button);
  int up_state = digitalRead (up_button);
  int down_state = digitalRead (down_button);
  int stick_state = digitalRead (stick_button);

  int joystick_x_value = analogRead (joystick_x);
  int joystick_y_value = analogRead (joystick_y);

  // check if states have changed
  if (old_left_state != left_state) {
    old_left_state = left_state;
    if (left_state == 0) {
      Serial1.print(counter++);
      Serial1.print(" - ");
      Serial1.println("LEFT_PRESSED");
    }
    else {
      Serial1.print(counter++);
      Serial1.print(" - ");
      Serial1.println("LEFT_RELEASED");    
    }
  }
  
  if (old_right_state != right_state) {
    old_right_state = right_state;
    if (right_state == 0) {
      Serial1.print(counter++);
      Serial1.print(" - ");
      Serial1.println("RIGHT_PRESSED");
    }
    else {
      Serial1.print(counter++);
      Serial1.print(" - ");
      Serial1.println("RIGHT_RELEASED");    
    }
  }
  
  if (old_up_state != up_state) {
    old_up_state = up_state;
    if (up_state == 0) {
      Serial1.print(counter++);
      Serial1.print(" - ");
      Serial1.println("UP_PRESSED");
    }
    else {
      Serial1.print(counter++);
      Serial1.print(" - ");
      Serial1.println("UP_RELEASED");    
    }  
  }
  
  if (old_down_state != down_state) {
    old_down_state = down_state;
    if (down_state == 0) {
      Serial1.print(counter++);
      Serial1.print(" - ");
      Serial1.println("DOWN_PRESSED");
    }
    else {
      Serial1.print(counter++);
      Serial1.print(" - ");
      Serial1.println("DOWN_RELEASED");    
    }  
  }
  
  if (old_stick_state != stick_state) {
    old_stick_state = stick_state;
    if (stick_state == 0) {
      Serial1.print(counter++);
      Serial1.print(" - ");
      Serial1.println("STICk_PRESSED");
    }
    else {
      Serial1.print(counter++);
      Serial1.print(" - ");
      Serial1.println("STICK_RELEASED");    
    }  
  }

  int treshhold_x = abs(old_joystick_x_value - joystick_x_value);  
  if (treshhold_x > 3) {
    old_joystick_x_value = joystick_x_value;
    Serial.print(counter++);
    Serial.print(" - ");
    Serial.print("JOYSTICK_X=");  
    Serial.println(joystick_x_value);    
  }
  
  int treshhold_y = abs(old_joystick_y_value - joystick_y_value);
  if (treshhold_y > 3) {
    old_joystick_y_value = joystick_y_value;
    Serial.print(counter++);
    Serial.print(" - ");
    Serial.print("JOYSTICK_Y=");  
    Serial.println(joystick_y_value);    
  }

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
  delay(50);
}

