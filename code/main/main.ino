/*
* Custom Modular Joystick
* Modular Accessible Joystick. This version is for 3 interconnectable modules.
* Main Module has 1 2-axis Joystick, 3 Buttons.
* Secondary Module has 1 2-axis Joystick, 2 Buttons.
* Slider Module has 2 Sliders, 2 Buttons.
* Invert axes and modify deadzones if needed at lines 95-100.
* -----------------------
* Controller: Arduino Leonardo
* ----------------------------
* Author:  Ernestas G. (github.com/ernestasga)
* Date:    2023-10-22
* Version: 1.0.0
*/

#include <Joystick.h>

/*
* Analog Joystick class
* @param xPin - X axis pin
* @param yPin - Y axis pin
* @param deadzone - deadzone % for the joystick. 0.0 - 1.0
* @param invertXAxis - (Optional) Invert the X axis. Default is false.
* @param invertYAxis - (Optional) Invert the Y axis. Default is false.
*/
class AnalogJoystick {
  private:
    byte pinX, pinY;
    float deadzonePercentage;
    bool invertX, invertY;
    int applyDeadzone(int value) {
      int center = 512;  // Assuming the joystick centers around 512 (analog range: 0-1023)
      int range = 512;   // Max deviation from center
      int deadzone = static_cast<int>(range * deadzonePercentage);
      if (value > (center + deadzone) || value < (center - deadzone)) {
        return value;
      }
      return center;
    }
    int invertAxis(int value, bool invert) {
      return invert ? 1023 - value : value;
    }

  public:
    AnalogJoystick(byte xPin, byte yPin, float deadzone, bool invertXAxis = false, bool invertYAxis = false)
    : pinX(xPin), pinY(yPin), deadzonePercentage(deadzone), invertX(invertXAxis), invertY(invertYAxis) {}

    int readX() {
      return invertAxis(applyDeadzone(analogRead(pinX)), invertX);
    }
    int readY() {
      return invertAxis(applyDeadzone(analogRead(pinY)), invertY);
    }
};

/*
* Slider class
* @param pin - slider pin
* @param invertSlider - (Optional) Invert the slider value. Default is false.
*/
class Slider {
  private:
    byte pin;
    bool invert;

    int invertValue(int value) {
      return invert ? 1023 - value : value;
    }

  public:
    Slider(byte _pin, bool invertSlider = false) : pin(_pin), invert(invertSlider) {}
    int readValue() {
      return invertValue(analogRead(pin));
    }
};

/*
* Button class
* @param pin - button pin
*/
class Button {
  private:
    byte pin;
  public:
    Button(byte _pin) : pin(_pin) {
      pinMode(pin, INPUT_PULLUP);
    }
    bool isPressed() {
      return digitalRead(pin) == LOW;
    }
};

// Main Joystick
AnalogJoystick joystick1(A0, A1, 0.025, true, true); // 2.5% deadzone
// Secondary Joystick
AnalogJoystick joystick2(A3, A2, 0.025, true, false); // 2.5% deadzone
// Sliders
Slider slider1(A4, true);
Slider slider2(A5);
// Buttons
Button buttons[] = {Button(2), Button(3), Button(4), Button(5), Button(6), Button(7), Button(8), Button(9), Button(10)};

// Initialize Joystick
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID,   // HID Report ID
  JOYSTICK_TYPE_JOYSTICK,       // HID Type: Joystick
  9,      // Number of Buttons
  0,      // Number of Hat Switches
  true,   // X Axis
  true,   // Y Axis
  true,   // Z Axis. Used only for dummy center value
  true,   // Rx Axis
  true,   // Ry Axis
  true,   // Rz Axis. Used only for dummy center value
  false,  // Rudder
  true,   // Throttle
  true,   // Accelerator
  false,  // Brake
  false   // Steering
);

void setup() {
  Joystick.begin();
}

void loop() {
  // Main Joystick
  Joystick.setXAxis(joystick1.readX());
  Joystick.setYAxis(joystick1.readY());
  
  // Secondary Joystick
  Joystick.setRxAxis(joystick2.readX());
  Joystick.setRyAxis(joystick2.readY());

  // Sliders
  Joystick.setZAxis(slider1.readValue());
  Joystick.setRzAxis(slider2.readValue());

  // Buttons
  for (int i = 0; i < 9; i++) {
    Joystick.setButton(i, buttons[i].isPressed());
  }

  // Dummy Always Center Axes
  Joystick.setThrottle(512);

  delay(1);
}
