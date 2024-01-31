---
layout: spec
latex: true
---

# Lab 4: Power Management

## Contents 

- [Lab 4: Power Management](#lab-4-power-management)
  - [Contents](#contents)
  - [Materials](#materials)
  - [Safety](#safety)
    - [Power Supply](#power-supply)
    - [Electrostatic Discharge](#electrostatic-discharge)
  - [Introduction](#introduction)
  - [Lab Overview](#lab-overview)
  - [Procedure](#procedure)
    - [Power Management](#1-power-management)
  - [Submission](#submission)

## Materials

- [ ] 1 Arduino Nano
- [ ] 1 Breadboard
- [ ] 1 Programming Cable (and adapters if necessary)
- [ ] A computer with the Arduino IDE [installed](/tutorials#arduino-ide-install) and [setup](/tutorials#arduino-library).
- [ ] ENGR100-950 Arduino Library

## Safety

This lab involves working with a power supply which can provide higher voltages/currents than the Arduinos! Read the following sections carefully to maintain your safety and the safety of the components we are using.

### Power Supply

The figure below shows a lab **power supply.** This is a device we frequently use in labs to power circuits: sometimes to avoid using the USB cable and a computer for power, and sometimes when we need a higher voltage than can be provided by the Arduino. There are multiple channels on the power supply, to allow for powering more than one device or produce more than one voltage at the same time.

![Power Supply](/media/power-supply.png)

You will be using the power supply on your workbenches today to power portions on your circuit. Please do **NOT** connect the power supply to the board until looked at by one of the instructors. The power supply has been current-limited at 500 mA and can cause some serious damage if used improperly. Please call the instructor to have them examine the breadboard before connecting to power. Also, do not increase the power supply voltage above 7.4V.

The wires to the power supply should already be connected (Red = positive and Black = negative). Connect the red wire to the positive rail located at the top of the breadboard, and the black wire to the blue rail located adjacent to it. Do not connect them in holes adjacent to one another; we want to remove any possibility of the two wires accidentally coming in contact and shorting the circuit. **Please do not turn on the power supply until your connections have been verified by an instructor.** Please do not adjust the wires connected to the power supply unless the supply is turned off. You can use this rail to power the components of your circuit as illustrated in Part 1 below.

<div class="primer-spec-callout danger" markdown="1">
Do not turn on the power supply until your connections have been verified by an instructor!
</div>

### Electrostatic Discharge

In this lab we will start taking precautions when dealing with electronics as there is possibly of ESDs damaging components. When you eventually start soldering your PCB’s, you will be dealing with much smaller components and will thus absolutely need to take ESD precautions. For the subteam that will be working with the power portion of the lab: whoever is touching and interacting with the circuit will be needing to wear an ESD bracelet at all times.

An ESD bracelet provides your body contact through a conductive element to ground, therefore allowing any static discharge accumulated on your body to be discharged to ground. The blue ESD mats serve a similar purpose, and when using the smaller board to do the power lab please do so on the blue mat.

## Introduction

Power management is one of the most critical aspects of any engineering system. Without the proper voltage levels, current levels, switching speeds, and noise suppression, most systems cannot work at their maximum efficiency.

**Voltage regulators** are an integral part of power management and allow a constant output voltage regardless of the input voltage (with constraints). This allows a steady voltage to components that need a small margin (error) in input voltage to output accurate data.

One type of voltage regulator is one we’ve discussed: the voltage divider. Previously, you have seen voltage dividers composed of two or more resistors in series. However, these configurations are not efficient, and so modern electronics do not usually include them. The most simple circuit for a modern voltage divider consists of a resistor and zener diode.

![Zener Diode](/media/zener-diode.png)

Zener diodes have a characteristic property wherein they allow current flow in the same direction as standard diodes (from anode to cathode) but they also allow current opposite direction once a “Zener Voltage” is reached. Once this voltage is reached, they operate reliably at the same voltage for increasing current levels. The I-V curve for a zener diode with a zener voltage of 17.1V is below. Notice how once the Zener Voltage is reached the voltage level is nearly constant for increasing current. The zener diodes used on voltage regulators have their zener voltages at the specified output voltage to ensure constant voltage at the output.

## Procedure

This lab will involve building a circuit to test the behavior of two low-dropout (LDO) regulators, consolidating your sensors and GPS in to the first version of your final breadboard, and integrating the LDOs on to the breadboard to supply your Arduino with onboard power. To do this most efficiently, we recommend two team members work on the LDO testing circuit with the GPS (part 1) and two team members work on breadboard consolidation with the SD card (part 2). Your team will work together to integrate the LDOs and GPS to your sensor board (part 3). Members are welcome to work on what they’re most interested in, but no one team member should be assigned a task to work on alone. If you don’t have enough team members (due to solder challenge), consolidate teams and have two teams work together on both the boards.

![Zener Diode IV](/media/zener-diode-IV.png)

### Power Management

Make the circuit below on an (initially) empty breadboard. The power connection is coming from the power supply.

NOTE: The longer lead of the capacitor is the positive end. This means you should connect the longer lead to the side with a non-zero (non-ground) voltage, and the shorter lead to the ground line.

NOTE: Your system and your power supply need to share a common ground for you to get correct voltage measurements. Electrically connect all GND pins together to the power supply’s negative terminal.

**Have a staff member check your circuit before you proceed.**
Use a multimeter to measure the actual outputs of the 5V and 3.3V LDO lines. If the 5V line is not exactly 5V, it can cause errors on the conversions of the sensor data from voltage into actual ”geophysical” units (C, %, g, etc.) You may want to use the reading from the 5V LDO in your calibration calculations.

Slowly reduce the voltage on the power supply (you can use the “Coarse” knob but rotate it slowly). Reduce it to 0V in increments of 1V, using a multimeter to record the voltage on the 5V line. **Note the power supply voltage at which the 5V line no longer reads 5V.**

![Power Circuit](/media/power-circuit.png)

**Turn the power supply off!**
Add the Arduino and GPS to the circuit, with the Arduino (power goes into 5V pin), GPS (5V), and level shifter (3.3V and 5.0V) all getting power from the LDOs. Make sure everything is connected to the GND and the GND is connected to the ground on the power supply. When you turn the power supply on, your GPS and Arduino should turn on. In theory, your Arduino should be taking data, but streaming it to the serial monitor, which is not hooked up, since your computer is not hooked up.

### Battery Power

Disconnect the power supply, and add a 7.4V, 500mA battery to the top rail of your bread- board to power your Arduino. Your Arduino requires a steady 5V supply so we will route the battery power through a 5V LDO to ensure the supply voltage is properly regulated. Positive (red) lead to the positive rail and negative (black) to the negative rail. You are now free of the tyrannous USB cable.

When you connect your battery, everything should turn on and start reporting data (although you can’t see it, since your computer is not hooked up yet).

## Submission

On Canvas, you will submit ***ONE PDF*** that will include all of the following:

- [ ] A picture of your complete circuit with proper color conventions.
- [ ] A screenshot of your serial **monitor** once all sensors are printing values in the same line (you may unplug the Arduino so the data pauses).
- [ ] Exported images of the finished plots from MATLAB (with labels and calibrations!).
- [ ] Screenshot of a schematic created in Altium of your entire completed circuit.

To put said content into a PDF, it is suggested you create a new Google Doc ([docs.new](https://docs.new)) and paste your images and write any text in the document. Export/Download this document as a PDF and upload it. **DO NOT SUBMIT A GOOGLE DOC FILE OR SPREADSHEET FILES.**

<div class="primer-spec-callout danger" markdown="1">
Submitting anything other than a single PDF may result in your work not being graded or your scores being heavily delayed.
</div>