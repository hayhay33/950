---
layout: spec
latex: true
---

# Lab 3: Group B Portion

<div class="primer-spec-callout danger" markdown="1">
Oftentimes we will refer to "Common Practice", meaning the circuit will work if you don't follow this convention, but it may be harder to understand for an outsider, or in certain "edge cases" it might function differently than expected. A common practice we are requiring you to follow is color coding your jumper wires, as this makes debugging a complex circuit much easier. Power should be red, GND should be black, and any data/signal jumpers should be some other color. Additionally, supply 5v to one red power rail on the breadboard, 3.3v to the other red rail, and GND the remaining two blue rails. Then you can connect any sensors to those rails without tracing wires over and over back to the Arduino pins.
</div>

## Contents 

- [Lab 3: Group B Portion](#lab-3-group-b-portion)
  - [Contents](#contents)
  - [Materials](#materials)
  - [Procedure](#procedure)
    - [1. Adding the Temperature Sensors](#1-adding-the-temperature-sensors)
    - [2. Adding the Pressure Sensor](#2-adding-the-pressure-sensor)
    - [3. Adding the Humidity Sensor](#3-adding-the-humidity-sensor)
    - [4. Adding the Accelerometer](#4-adding-the-accelerometer)
  - [Submission](#submission)

## Materials

- [ ] 1 Arduino Nano
- [ ] 1 Breadboard
- [ ] 1 Programming Cable (and adapters if necessary)
- [ ] 2 TMP36 Temperature Sensors
- [ ] 1 Pressure Sensor
- [ ] 1 Humidity Sensor
- [ ] 1 Accelerometer
- [ ] A handful of jumper wires
- [ ] A computer with the Arduino IDE [installed](/tutorials#arduino-ide-install) and [setup](/tutorials#arduino-library).
- [ ] ENGR100-950 Arduino Library

## Procedure

### 1. Adding the Temperature Sensors

<div class="primer-spec-callout danger" markdown="1">
Whenever you perform a calibration curve, or want to read accurate values to the SD card, you should do so with the battery connected. Because of the differences in voltage applied by a computer through USB and the 9V batteries we are using, there is some variation in the voltage values read by the Arduino from each sensor. For this lab, since you don't have an SD logger connected (yet!) just calibrate using the serial monitor through USB. Keep this in mind for future labs!
</div>

- [Link to TMP36 Spec Sheet](https://drive.google.com/file/d/10Lu2-s9MYqh0s0O6Nkxy8E_LDwDpnZ7T/view?usp=sharing)

Just like we did in the last lab, we now need to plug in the TMP36 to an analog pin on the Arduino, and read it using `analogRead()` and `Serial.println()`. Go to File → Examples → Basics → AnalogReadSerial and change the code to read the pin for your temperature sensor. When adding the second temperature sensor, print to the serial monitor using comma-separated values. (Hint: You can use `Serial.print()` to print values without a newline character between them, which may help you print csv integers to the serial monitor for testing. Then you can just use `Serial.print(",");` to add a comma between the values. The last line you print, which will be the last sensor column of your csv matrix, should use `Serial.println()` in order to make a new line for the next data read). Convert these raw values to voltages using the equations used in previous labs, then print the voltages in the aforementioned format. **You should change the values to type `double` rather than type `int` and when applying any sort of calculations add .0 to the end of the number so the code knows you are looking for decimals!**

Here is the wiring diagram again for your reference:

[![TMP36 Pinout](https://cdn-learn.adafruit.com/assets/assets/000/000/471/large1024/temperature_tmp36pinout.gif?1447975787)](https://learn.adafruit.com/tmp36-temperature-sensor/overview)

<div class="primer-spec-callout warning" markdown="1">
Do this process twice to record data from two TMP36 sensors. When we launch our weather balloons we will want to measure the internal temperature of our payload and the external temperature of the atmosphere.
</div>

Once you have your temperature sensors connected, it's time to make a calibration curve (technically you should make two separate calibration curves for each TMP36 since they may have some variation, but they should be relatively similar). You can do this in the same manner as in the last lab using the cold chamber. Enter these calibration curves into your Arduino code by modifying the temperature variables with a slope-intercept equation, and verify that the serial monitor is producing realistic temperature values. Save these calibration curves somewhere for later use! **It may be less annoying to calibrate all of the sensors at the end once you have all the sensors connected but before you have the data logger plugged in. This is up to you!**

### 2. Adding the Pressure Sensor

- [Link to MPX4115 Spec Sheet](https://drive.google.com/file/d/1HvO6ww0i4jqZtf4NJvgjcQmIwZw6AqbE/view?usp=sharing)

<div class="primer-spec-callout info" markdown="1">
Pay attention to the required supply voltage for each of these components to prevent accidental damage. You can find these values in the provided spec sheets for each individual component. In the case of the pressure sensor it is 5v.
</div>

Begin by skimming over the provided spec sheet and become familiar with the pin layout. Connect the sensor to the Arduino, based on the pin-out provided. **You only need to connect the Vin (or VCC), GND, and Vout pins.** Print the data to the Serial Monitor to ensure it is working, using `analogRead()` like before with the temperature sensors, add this to the code with the battery voltage and temperature sensors so that you now have four comma-separated values printed in one line. It may be "Voltage,Temp1,Temp2,Pressure" for example, all in one line. Again, these raw values should be converted to voltages within the code, as before.

This data now needs to be calibrated in order to be useful! Take a measurement and create a calibration curve equation for this sensor, assuming that a measurement of 0V maps to 0 pressure for the other measurement. Again, save this calibration curve for later.

<div class="primer-spec-callout info" markdown="1">
Note: You may simply look up the local Ann Arbor pressure using a weather app for the calibration point.
</div>

Apply this calibration curve to the code as before with the temperature sensors, adding to the string of values printed to the serial monitor. The values shouldn't be changing much if at all, because pressure won't vary by large values while remaining at a steady altitude.

### 3. Adding the Humidity Sensor

- [Link to HIH-4030 Spec Sheet](https://drive.google.com/file/d/1AbuDJoNI-4D2zUW1M4IfG_zt5Is2a3Eh/view?usp=sharing)

Begin by skimming over the provided spec sheet and become familiar with the pin layout. Connect the sensor to the Arduino, based on the pin-out provided and using the **5V pin** as the power supply.

Add lines to the code from before to print the humidity data (voltages!) in the same comma-separated format.

Take measurement data indoors and while walking outside to see changes. Create a calibration curve equation for this sensor and apply it to the code to print a calibrated humidity value in the serial monitor. Save this calibration curve.

### 4. Adding the Accelerometer

- [Link to ADXL335 Spec Sheet](https://drive.google.com/file/d/1nYnJopSdXv7brn2TT8iLgIH01D7TD_NQ/view?usp=sharing)

Begin by skimming over the provided spec sheet and become familiar with the pin layout. Connect the sensor to the Arduino, based on the pin-out provided and using the **3.3V pin** as the power supply. Each of the axes (x, y, and z) will be connected to its own analog pin. You will not have anything connected to the ST pin.

Add code to the program you've been working with to read voltage values from each of the three axes. Then perform a two-point calibration for each axis individually, and update the code to print the new calibrated values in the same comma-delimited format as before. **Save these calibration curves! Take a screenshot of the serial monitor printing out a string of data from all of the sensors in the same line, every half second (or whatever the time delay is set to within the code).**

<div class="primer-spec-callout info" markdown="1">
To perform a calibration curve of the accelerometer, take note of the axes as labeled on the top of the sensor. Holding the sensor so that only one axis is experiencing acceleration due to gravity, record the output value as -1g (g being acceleration due to gravity). Then flip it over 180 degrees so that it is experiencing 1g, and record this value as your second point. Apply these calibration curves to the code from before in csv format.
</div>

<div class="primer-spec-callout warning" markdown="1">
When Group A is ready to move on, take both of your breadboards and move all the jumpers running from your Arduino into the same pins on their Arduino, so that everything is wired into one microcontroller (you need not physically move the components, but rather just your jumpers, leaving two breadboards side by side. They can lock together!). Once this is done, follow the link below to jump back into the normal lab manual together.
</div>

- [Groups A & B Lab Manual - Finishing Steps](/labs/lab-3#7-adding-the-microsd-card-adapter-module)