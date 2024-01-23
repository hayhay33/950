---
layout: spec
latex: true
---

# Lab 3: Creating a Standalone Arduino and Adding Sensors

<div class="primer-spec-callout danger" markdown="1">
This is the first lab completed as a team! As such, the amount of work needed to complete it is slightly higher than previous labs. The completion of this lab will be made MUCH easier if you carefully read through this manual and complete it in steps.
</div>

## Contents 

- [Lab 3: Creating a Standalone Arduino and Adding Sensors](#lab-3-creating-a-standalone-arduino-and-adding-sensors)
  - [Contents](#contents)
  - [Materials](#materials)
  - [Introduction](#introduction)
    - [Arduino Power Requirements](#arduino-power-requirements)
    - [Data Logging](#data-logging)
  - [Procedure](#procedure)
    - [1. Powering the Arduino](#1-powering-the-arduino)
    - [2. Measuring Battery Voltage](#2-measuring-battery-voltage)
    - [3. Adding the Temperature Sensors](#3-adding-the-temperature-sensors)
    - [4. Adding the Pressure Sensor](#4-adding-the-pressure-sensor)
    - [5. Adding the Humidity Sensor](#5-adding-the-humidity-sensor)
    - [6. Adding the Accelerometer](#6-adding-the-accelerometer)
    - [7. Adding the MicroSD Card Adapter Module](#7-adding-the-microsd-card-adapter-module)
    - [8. Collecting Data](#8-collecting-data)
    - [9. Analyzing the Data in MATLAB](#9-analyzing-the-data-in-matlab)
  - [Submission](#submission)

## Materials

- [ ] 1 Arduino Nano
- [ ] 1 Breadboard
- [ ] 1 Programming Cable (and adapters if necessary)
- [ ] 2 TMP36 Temperature Sensors
- [ ] 1 Pressure Sensor
- [ ] 1 Humidity Sensor
- [ ] 1 Accelerometer
- [ ] 1 MicroSD Card
- [ ] 1 Data Logger
- [ ] 1 MicroSD Card - USB Adapter
- [ ] 2 1k$$\Omega$$ resistors
- [ ] A handful of jumper wires
- [ ] 1 9V battery
- [ ] 1 9V battery connector
- [ ] A computer with the Arduino IDE [installed](/tutorials#arduino-ide-install) and [setup](/tutorials#arduino-library).

## Introduction

So far, every time we have used our Arduino to log data, we have read the data through Arduino's Serial monitor, and have powered the Arduino via our computer's USB port. While this has worked so far, our end goal is to send these Arduinos on weather ballons! We cannot use a computer for power and data logging for that!

This lab can be broken down into two main sections, one in which we learn to power the board via a battery and estimate the battery's capacity or charge, and one where we record Arduino sensor data onto a microSD card. At the end of this lab, you should have all the knowledge you need to make a fully portable temperature, pressure, humidity, and acceleration logger.

### Arduino Power Requirements

The Arduino Nanos that we use in this class operate at 5V logic. This means the pins coming off of it, like the digital pins, are all at 5Vs. The Arduino, however, has circuitry inside it that lets it take a range of voltages as input. This is called the Vin pin, and takes a voltage between 7-12V. The Arduino then internally converts that down to a safer 5V level for its own operations. For this lab, we will be powering our Arduino Nano with a 9V battery.

### Data Logging

Our Arduino has some memory on it, but reading and writing to this memory is a rather complicated procedure, which is why we need the Arduino IDE to handle writing the code to the Arduino's memory for us. Writing variables to the Arduino's memory is not user-friendly and is difficult to read back. Therefore, we elect to instead use a microSD card, which has a far higher data capacity and allows us to easily read data on our computer. This lab will use a pre-built data logging module to write data to the microSD card in a similar way you write data out to the Arduino's Serial monitor.

## Procedure

### 1. Powering the Arduino

To start, we want to power our Arduino with the 9V battery. Plug your Arduino into your breadboard, and plug the 9V into it's connection clip. It should only fit on one way, as the 9V's two terminals are different shapes.

Notice that one wire coming out of the battery is red, and one is black. Common practice says that red will be positive, in this case +9V, and the black will be what we connect to our Arduino's GND.

<div class="primer-spec-callout danger" markdown="1">
Oftentimes we will refer to "Common Practice", meaning the circuit will work if you don't follow this convention, but it may be harder to understand for an outsider, or in certain "edge cases" it might function differently than expected. A common practice we are requiring you to follow is color coding your jumper wires, as this makes debugging a complex circuit much easier. Power should be red, GND should be black, and any data/signal jumpers should be some other color. Additionally, supply 5v to one red power rail on the breadboard, 3.3v to the other red rail, and GND the remaining two blue rails. Then you can connect any sensors to those rails without tracing wires over and over back to the Arduino pins.
</div>

Take these wires and plug them into your Arduino via your breadboard. Red should go to the Arduino's Vin, and black should go to any GND pin.

Once you've plugged the 9V in, the Arduino should light up - even though it isn't plugged into your computer! If it does, congrats, your external power is working! If not, check your connections again.

As one last check that everything is working before we move on, upload the File → Examples → Basics → Blink code that the Arduino IDE comes with to your Arduino. After it finishes uploading, unplug your computer and verify that the onboard LED on the Arduino continues to blink on only the 9V's power.

<div class="primer-spec-callout info" markdown="1">
In the next lab we will go over creating a more reliable power source using a separate power circuit. For now, this will do, just take note that sensor readings may fluctuate based on whether the Arduino is powered by a battery or by your computer, and whether or not all of the sensors are plugged in and drawing power. More on this later!
</div>

### 2. Measuring Battery Voltage

Most modern electronics, from your smartphone to even rockets, have some way of reporting back the charge of any internal batteries. While we don't use the battery for very long at any one time in this lab, other people are using the same batteries, and so we do want to verify they are charged.

To measure battery voltage, we can use the analog pins on the Arduino, similar to how we did in lab 1. The caveat of this is, however, that the analog pins can **only take up to 5V!!** So, before reading the battery in, we need to build a voltage divider to step the battery voltage down to 5V max.

Using our voltage divider [(see the resources page for more)](/resources), we can take 2 1k$$\Omega$$ resistors and step 9V down to 4.5V max. Go ahead and build this voltage divider.

When you are done, your 9V battery should have the black wire going to GND, and the red wire going to **both** Vin on the Arduino **and** a voltage divider.

Now, let's test that the voltages look about right. Go to File → Examples → Basics → AnalogReadSerial and change the `analogRead()` function called in `loop()` to be the pin you plugged your voltage divider into. Run this code and make note of the values it returns.

You know on the Arduino Nano this value will be between 0-1024, and that your max voltage, as reported by the Arduino, is 5V. Convert your raw value to the voltage by dividing it by 1023 and multiplying it by 5V. This is the voltage your Arduino recorded.

Your battery, however, has a higher voltage than that. We now need to undo the effects of the voltage divider to determine the battery's original voltage. Since we used the same resistance on either side of the voltage divider, the voltage is being cut in half. Therefore, we can simply multiply the Arduino's recorded voltage by 2 to get the 9V battery's voltage. It should be somewhere between 8 and 10V.

<div class="primer-spec-callout info" markdown="1">
Note that the values displayed in the serial monitor are rounded, and don't show us as accurate of voltages as we would like. This is because the value is stored as an "int", or integer. To obtain decimal places, change this to a double.
</div>

### 3. Adding the Temperature Sensors

<div class="primer-spec-callout danger" markdown="1">
Whenever you perform a calibration curve, or want to read accurate values to the SD card, you should do so with the battery connected. Because of the differences in voltage applied by a computer through USB and the 9V batteries we are using, there is some variation in the voltage values read by the Arduino from each sensor. Keep this in mind!
</div>

- [Link to TMP36 Spec Sheet](https://drive.google.com/file/d/10Lu2-s9MYqh0s0O6Nkxy8E_LDwDpnZ7T/view?usp=sharing)

Just like we did in the last lab, we now need to plug in the TMP36 to an analog pin on the Arduino, and read it using `analogRead()` and `Serial.println()`. Add this to the code used for measuring the battery voltage with comma-separated values. (Hint: You can use `Serial.print()` to print values without a newline character between them, which may help you print csv integers to the serial monitor for testing. Then you can just use `Serial.print(",");` to add a comma between the values. The last line you print, which will be the last sensor column of your csv matrix, should use `Serial.println()` in order to make a new line for the next data read).

Here is the wiring diagram again for your reference:

[![TMP36 Pinout](https://cdn-learn.adafruit.com/assets/assets/000/000/471/large1024/temperature_tmp36pinout.gif?1447975787)](https://learn.adafruit.com/tmp36-temperature-sensor/overview)

<div class="primer-spec-callout warning" markdown="1">
Do this process twice to record data from two TMP36 sensors. When we launch our weather balloons we will want to measure the internal temperature of our payload and the external temperature of the atmosphere.
</div>

Once you have your temperature sensors connected, it's time to make a calibration curve (technically you should make two separate calibration curves for each TMP36 since they may have some variation, but they should be relatively similar). Enter these calibration curves into your Arduino code by modifying the temperature variables with a slope-intercept equation, and verify that the serial monitor is producing realistic temperature values.

### 4. Adding the Pressure Sensor

- [Link to MPX4115 Spec Sheet](https://drive.google.com/file/d/1HvO6ww0i4jqZtf4NJvgjcQmIwZw6AqbE/view?usp=sharing)

<div class="primer-spec-callout info" markdown="1">
Pay attention to the required supply voltage for each of these components to prevent accidental damage. You can find these values in the provided spec sheets for each individual component.
</div>

Begin by skimming over the provided spec sheet and become familiar with the pin layout. Connect the sensor to the Arduino, based on the pin-out provided. **You only need to connect the Vin, GND, and Vout pins.** Print the data to the Serial Monitor to ensure it is working, using `analogRead()` like before with the temperature sensors, add this to the code with the battery voltage and temperature sensors so that you now have four comma-separated values printed in one line. It may be "Voltage,Temp1,Temp2,Pressure" for example, all in one line.

The value we are printing to the serial monitor is raw, and needs calibrated. Take a measurement and create a calibration curve equation for this sensor, assuming that a measurement of 0V maps to 0 pressure for the other measurement.

<div class="primer-spec-callout info" markdown="1">
Note: You may simply look up the local Ann Arbor pressure using a weather app for the calibration point.
</div>

Apply this calibration curve to the code as before with the temperature sensors, adding to the string of values printed to the serial monitor. The values shouldn't be changing much, because pressure won't vary by large values while remaining at a steady altitude.

### 5. Adding the Humidity Sensor

- [Link to HIH-4030 Spec Sheet](https://drive.google.com/file/d/1AbuDJoNI-4D2zUW1M4IfG_zt5Is2a3Eh/view?usp=sharing)

Begin by skimming over the provided spec sheet and become familiar with the pin layout. Connect the sensor to the Arduino, based on the pin-out provided and using the **5V pin** as the power supply.

Add lines to the code from before to print the humidity data in the same comma-separated format.

Take measurement data indoors and while walking outside to see changes. Create a calibration curve equation for this sensor and apply it to the code to print a calibrated humidity value in the serial monitor.

### 6. Adding the Accelerometer

- [Link to ADXL335 Spec Sheet](https://drive.google.com/file/d/1nYnJopSdXv7brn2TT8iLgIH01D7TD_NQ/view?usp=sharing)

Begin by skimming over the provided spec sheet and become familiar with the pin layout. Connect the sensor to the Arduino, based on the pin-out provided and using the **3.3V pin** as the power supply.

Add code to the program you've been working with to read raw values from each of the three axes. Then perform a two-point calibration for each axis individually, and update the code to print the new calibrated values in the same comma-delimited format as before. Take a screenshot of the serial monitor printing out a string of data from all of the sensors in the same line, every half second.

<div class="primer-spec-callout info" markdown="1">
To perform a calibration curve of the accelerometer, take note of the axes as labeled on the top of the sensor. Holding the sensor so that only one axis is experiencing acceleration due to gravity, record the output value as -1g (g being acceleration due to gravity). Then flip it over 180 degrees so that it is experience 1g, and record this value as your second point. Apply these calibration curves to the code from before in csv format.
</div>

Now that you have a completed circuit, take a picture of your setup and save this for your submission file. **(Remember, wires and rails should follow "common practice" mentioned earlier.)**

### 7. Adding the MicroSD Card Adapter Module

Unlike the other sensors and modules we have used so far, the MicroSD module we are using uses the Arduino's digital pins. Luckily for us, there are libraries (that you should have installed when following the tutorial and initially setting up your Arduino IDE), that handle all the complicated digital interfacing for us. All we need to know is which pins to plug the adapter module into.

![MicroSD Adapter Module Wiring](../media/SD-Card-Wiring.png){: .invert-colors-in-dark-mode }

While your Arduino is powered off and disconnected from the 9V, plug your module in as shown above. The Arduino pins for this **DO** matter and cannot easily be changed, unlike the analog pins.

Once everything is wired up, put your microSD card into the adapter module and plug in your Arduino. At this point you should modify and upload the code found in File → Examples → ENGR100-950 → Lab3-SD.

Please read through the comments of this code file, as you will be adding additional sensors and modifying this file on your own. In this lab, you may also need to change the analog pins that are the defaults for all of your sensors.

There is a delay statement at the end of the loop.  Think about how many data points will be taken if you take data for 5 minutes.  Will you need data this often?  More often?  Less often?  Adjust the delay accordingly.

### 8. Collecting Data

With everything plugged into the 9V and running, unplug the Arduino from your computer. Enjoy the portability of your new breadboard and walk around the building a little bit. Get the temperature to change dramatically by putting your sensor board into a freezer.  Wait for about 2-5 minutes to allow the temperature to adjust. Then carry your board to the Ford Robotics Building and go up to the top floor, shaking the package intermittently. This should provide plenty of data for all of your sensors!

Go back to the lab and unplug the 9V now (unplug the battery and leave the wires connected to your board). Carefully remove the microSD from the adapter module, and plug it into your computer. You should see a `DATALOG.CSV` file. If you do not, or the file seems corrupted or very small, delete the file, plug the microSD card back in, and watch what the Serial monitor on your computer says while running the code.

Once you have a sufficiently long test (1-2 minutes) and can see that there are clear changes in the data in the file created, you are done with the hardware portion of this lab!

Before returning all of your equipment, make sure you save your file on your computer!! Maybe even upload it and share it with team members so you have a backup!

Then, delete the .csv file and any other .txt files off of the microSD card (you can leave any folders) so that other teams in future labs have to actually do the lab themselves, and don't just steal your data!

### 9. Analyzing the Data in MATLAB

At this point, you should have a CSV file saved to your computer. This file should be a matrix of values with 9 columns (time + sensors), and twice as many rows as the number of seconds the program collected data. Since we have a matrix of data, let's use MATLAB (MATrix LABoratory) to make sense of all this data!

<!-- NEED TO ADD A LINK BELOW -->
Start by opening the script provided to you here<!-- LINK -->. Look through the script, editing values or variables where directed, and then run the script to analyze your data. You should see plots for internal and external temperatures, pressure, humidity, and acceleration!

<div class="primer-spec-callout warning" markdown="1">
Make sure you follow "common practice" TechComm rules, labelling all plots' axes and titles, and add legends where necessary.
</div>

## Submission

On Canvas, you will submit ***ONE PDF*** that will include all of the following:

- [ ] A picture of your complete circuit with proper color conventions
- [ ] Screenshots or exported images of the finished plots from MATLAB (with labels!)
- [ ] A screenshot of your serial monitor once all sensors are printing values in the same line

To put said content into a PDF, it is suggested you create a new Google Doc ([docs.new](https://docs.new)) and paste your images and write any text in the document. Export/Download this document as a PDF and upload it. **DO NOT SUBMIT A GOOGLE DOC FILE OR SPREADSHEET FILES.**

<div class="primer-spec-callout danger" markdown="1">
Submitting anything other than a single PDF may result in your work not being graded or your scores being heavily delayed.
</div>