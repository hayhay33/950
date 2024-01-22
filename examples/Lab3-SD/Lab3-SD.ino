// These are the pins your MicroSD Card Adapter will be connected to.
// These pins are specific and should not change. You do not need to worry
// about why these are the pins, just connect them as listed.
// MOSI - pin 11
// MISO - pin 12
// CLK  - pin 13
// CS   - pin 10
const int chipSelect = 10;

// This is the pin your first TMP36 is connected to.
// Change this as needed.
const int tmp1Pin = A0;

// This is the pin your second TMP36 is connected to.
// Change this as needed.
const int tmp2Pin = A1;

// This is the pin your voltage divider is connected to.
// Change this as needed.
const int vDivPin = A2;

// This is the pin your pressure sensor is connected to.
// Change this as needed.
const int pressPin = A3;

// This is the pin your humidity sensor is connected to.
// Change this as needed.
const int humidPin = A4;

// These are the pins your accelerometer is connected to (x, y, and z axes)
// Change these as needed.
const int accelxPin = A5;
const int accelyPin = A6;
const int accelzPin = A7;

// For future labs, you may find it helpful to copy the above settings for additional sensors.
// **HINT HINT WINK WINK**

// This is the string that goes at the top of your csv file. It is the column headers for your spreadsheet.
// You can change this as needed.
const String header = "Time (ms),TMP36_1 (Raw),TMP36_2 (Raw),Voltage (Raw),Pressure (raw),Humidity (raw),Accel_x (raw),Accel_y (raw),Accel_z (raw)";

#include <SPI.h>
#include <SD.h>

void setup() {
    Serial.begin(9600);

    delay(100); // arbitrary delay to let the serial monitor start up
    Serial.print("Initializing SD card...");

    // see if the card is present and can be initialized:
    if (!SD.begin(chipSelect)) {
        Serial.println("Card failed, or not present");
        // don't do anything more:
        while (1);
    }
    Serial.println("card initialized.");

    // now, before we actually start reading data, we need to write the header to the file.
    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    File dataFile = SD.open("datalog.csv", FILE_WRITE);
    if (dataFile) {
        dataFile.println(header);
        dataFile.close();
    } else {
        Serial.println("error opening datalog.csv");
    }
}

void loop() {

    // Note: in future labs, you may need to change this to add additional sensors.

    int tmp1Val = analogRead(tmp1Pin); // First temperature reading (raw)
    int tmp2Val = analogRead(tmp2Pin); // Second temperature reading (raw)
    int vDivVal = analogRead(vDivPin); // Battery voltage reading (####THIS IS FROM VOLTAGE DIVIDER, ADJUST ACCORDINGLY####)
    int pressVal = analogRead(pressPin); // Pressure reading (raw)
    int humidVal = analogRead(humidPin); // Humidity reading (raw)
    int accelxVal = analogRead(accelxPin); // X-Acceleration reading (raw)
    int accelyVal = analogRead(accelyPin); // Y-Acceleration reading (raw)
    int accelzVal = analogRead(accelzPin); // Z-Acceleration reading (raw)

    // Now let's make a nice string to write to the file.
    // This is a comma-separated value (csv) file, so we need to separate each value with a comma.
    String dataString = "";
    // add the time (since boot) in milliseconds
    dataString += String(millis());
    dataString += ",";
    // add the first raw TMP36 value
    dataString += String(tmp1Val);
    dataString += ",";
    // add the second raw TMP36 value
    dataString += String(tmp2Val);
    dataString += ",";
    // add the raw voltage divider value
    dataString += String(vDivVal);
    dataString += ",";
    // add the raw pressure value
    dataString += String(pressVal);
    dataString += ",";
    // add the raw humidity value
    dataString += String(humidVal);
    dataString += ",";
    // add the raw x-accel value
    dataString += String(accelxVal);
    dataString += ",";
    // add the raw y-accel value
    dataString += String(accelyVal);
    dataString += ",";
    // add the raw z-accel value
    dataString += String(accelzVal);

    // now let's open the file again
    File dataFile = SD.open("datalog.csv", FILE_WRITE);
    // if the file is available, write to it:
    if (dataFile) {
        dataFile.println(dataString);
        dataFile.close();

        // if you want to print to the serial port as well, uncomment the following line...
        // Serial.println(dataString);
    }
    // if the file isn't open, pop up an error:
    else {
        Serial.println("error opening datalog.txt");
    }

    // This line means we will be printing data to the SD card about once every 500 milliseconds, or half a second
    delay(500);
}