# Custom Arduino Leonardo Joystick
This is a custom Arduino Leonardo Joystick. It is based on the Arduino Leonardo and uses the Arduino Joystick library.

| | | |
|:-------------------------:|:-------------------------:|:-------------------------:|
|<img width="1604" alt="img 1" src="https://github.com/ernestasga/leonardo-joystick/blob/main/images/1.jpg?raw=true">  |  <img width="1604" alt="img2" src="https://github.com/ernestasga/leonardo-joystick/blob/main/images/2.jpg?raw=true">|<img width="1604" alt="img 3" src="https://github.com/ernestasga/leonardo-joystick/blob/main/images/3.jpg?raw=true">|
|<img width="1604" alt="img 4" src="https://github.com/ernestasga/leonardo-joystick/blob/main/images/4.jpg?raw=true">  |  <img width="1604" alt="img 5" src="https://github.com/ernestasga/leonardo-joystick/blob/main/images/5.jpg?raw=true">| <img width="1604" alt="img 6" src="https://github.com/ernestasga/leonardo-joystick/blob/main/images/6.jpg?raw=true"> |

## Overview
Joystick is built with accessibility and modularity in mind.

## Parts
- [Arduino Leonardo](https://store.arduino.cc/products/arduino-leonardo-without-headers)
- 2x [2-axis potentiometers](https://www.aliexpress.com/item/1005005203342038.html)
- 2x [slider potentiometers](https://www.aliexpress.com/item/1005005434366252.html)
- 6x [tactile arduino buttons with caps](https://www.aliexpress.com/item/1005005708818336.html)
- 1x [mini toggle switch](https://www.aliexpress.com/item/1005004692981776.html)
- [6 core cable](https://www.aliexpress.com/item/4000570401041.html) (for connecting the joystick and buttons, ~5M)
- [2 core cable](https://www.aliexpress.com/item/4000570401041.html) (for connecting the external buttons, ~5M)
- 5x [6-pin connectors](https://www.aliexpress.com/item/1005004615687476.html)
- 2x [2-pin connectors](https://www.aliexpress.com/item/1005004615687476.html)
- 16x M3 screws (12x for button plates, 4x for joystick raisers)
- 4x M3 nuts (for securing joystick raisers)
- Some super glue

## 3D Printed Parts
- **Main case**: Contains the controller board, a joystick and 3 buttons. There are also 2 additional ports for extra joysticks and 2 ports for external buttons.
    * Main Case.stl
    * Top Cover.stl
    * Buttons Plate.stl (Print in ABS. Screw threads don't work well in PLA)
    * Joystick Raiser.stl
    * 4x Arduino Pin Cap.stl (For pushing down the Arduino board)

- **Secondary case**: Contains a joystick and 2 buttons. Connected with one of 6-pin ports on main case.
    * Secondary Case.stl
    * Top Cover.stl
    * Buttons Plate.stl (Print in ABS. Screw threads don't work well in PLA)
    * Joystick Raiser.stl

- **Slider case**: Contains 2 slider potentiometers and 2 buttons. Connected with one of 6-pin ports on main case.
    * Slider Case.stl
    * Top Cover.stl
    * Buttons Plate.stl (Recommended to print in ABS)

## Assembly
1. Solder the wires to the Arduino Leonardo board. Wiring rules are in the `Arduino Leonardo Wiring.pdf` file.
2. Connect other ends of wires to 6-pin and 2-pin connectors on the main case. Lookup `Connector Color Coding.png` for the color coding.
3. Insert the Arduino Leonardo board into the main case. Use 4x Arduino Pin Caps to push the board down.
4. Prepare joystick raisers:
    1. Insert M3 nuts into the inside of the joystick raisers. Use super glue to secure them.
    2. Screw the joystick raisers to the main case.
5. Insert the joystick into and connect it to the ardunio board. When lined up with top cover, super guide the joystick raiser.
6. Connect the 6-pin connectors to the secondary and slider cases. (Optional) Connect the 2-pin connectors to the external buttons.

For secondary case and slider case, you can use the same steps as for the main case. The only difference is that you don't need to insert the Arduino board into the case and there are much less wires to connect.

## Flashing the Arduino
1. Download and install the Arduino IDE from https://www.arduino.cc/en/Main/Software
2. Install the Arduino Joystick library:
    1. Download the Arduino Joystick library from [Github Repo](https://github.com/MHeironimus/ArduinoJoystickLibrary/releases/)
    2. Extract the library to `~/Documents/Arduino/libraries/`
3. Open the `code/main/main.ino` file in the Arduino IDE
4. Select "Arduino Leonardo" from the Tools > Board menu
5. Select your Arduino Leonardo's serial port from the Tools > Port menu
6. Invert axes and modify deadzones if needed at lines 95-100.
7. Press the "Upload" button

## Customization
### Code
You can customize the joystick functionality by modifying the `code/main/main.ino` file. You can change the button mappings, invert axes, modify deadzones and more.

### 3D Models
You can modify the 3D models by opening the `3D/src/Joystick.3df` file in Autodesk [Fusion 360](https://www.autodesk.com/products/fusion-360/overview) or `3D/src/Joystick.step` file in any other 3D modeling software.

Specifically, you may want to modify case engravings. They can be found at the end of each component' timeline. SVG files for engravings can be found in the `3D/src/svg` folder.

## Usage
The joystick is recognized as a standard HID USB joystick. You can use it in any game or application that supports joysticks.

Here is a list of complimentary software that can be used with the joystick for accessibility purposes:
- [Xpadder](https://www.xpadder.com/) - Allows you to map keyboard keys and mouse button actions to your game controller buttons.
- [x360ce](https://www.x360ce.com/) - Allows you to emulate an Xbox controller with any controller.
- [JoyToKey](https://joytokey.net/en/) - Allows you to map keyboard keys and mouse button actions to your game controller buttons.
