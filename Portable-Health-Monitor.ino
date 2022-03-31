#include <DallasTemperature.h>
#include <OneWire.h>

// Data wire is plugged into digital pin 7 on the Arduino
#define ONE_WIRE_BUS 42

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(44, 45, 41, 39, 37, 35);

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);


void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  //W23sensors.begin();  // Start up the library
  pinMode(46, INPUT); // Setup for leads off detection LO +
  pinMode(48, INPUT); // Setup for leads off detection LO -

  //lcd.begin(16, 2);
  //lcd.clear();
}

void loop() {


  //====================================
  //TEMPERATURE SENSOR
  //====================================
  // Send the command to get temperatures
  
  //sensors.requestTemperatures(); 

  //float temp = sensors.getTempCByIndex(0);
  /*
  //print the temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print((char)176);//shows degrees character
  Serial.print("C  |  ");
  
  //print the temperature in Fahrenheit
  Serial.print((temp * 9.0) / 5.0 + 32.0);
  Serial.print((char)176);//shows degrees character
  Serial.println("F");
  */
  //String string_temp = "Temp: " + String(temp);
  
  //lcd.setCursor(0, 0);
  //lcd.print(string_temp);
  
  //====================================
  //ECG HEART SENSOR
  //====================================
  
  if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
    Serial.println('!');
  }
  else{
    // send the value of analog input 0:
      int val = analogRead(A1);
      String string_ecg = "" + String(val);
      Serial.println(string_ecg);
      //lcd.setCursor(0, 1);
      //lcd.print(string_ecg);
  }
  //Wait for a bit to keep serial data from saturating
  delay(10);
  
}
