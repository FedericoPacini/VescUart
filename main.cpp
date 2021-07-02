#include <Arduino.h>

/*
  Name:    getVescValues.ino
  Created: 19-08-2018
  Author:  SolidGeek
  Description:  This example is made using a Arduino Micro (Atmega32u4) that has a HardwareSerial port (Serial1) seperated from the Serial port. 
                A Arduino Nano or Uno that only has one Serial port will not be able to display the data returned.
*/

#include <VescUart.h>

/** Initiate VescUart class */
VescUart UART;
VescUart UART_1;

void setup() {

  /** Setup Serial port to display data */
  Serial.begin(115200);

  /** Setup UART port (Serial1 on Atmega32u4) */
  //Serial2.begin(115200);
  Serial1.begin(115200);
  
  while (!Serial) {;}

  /** Define which ports to use as UART */
  //UART.setSerialPort(&Serial2);
  /** Define which ports to use as UART */
  UART_1.setSerialPort(&Serial1);
}

unsigned int now = 0, now_1 = 0;

void loop() {
  
  /** Call the function getVescValues() to acquire data from VESC */
  /*if ( UART.getVescValues() ) {

    Serial.println(UART.data.rpm);
    //Serial.println(UART.data.inpVoltage);
    //Serial.println(UART.data.ampHours);
    //Serial.println(UART.data.tachometerAbs);

    if(now == 0)
      now = millis();

    if(millis() - now < 2000){
      //UART.nunchuck.valueY = 155;
      UART.setRPM(2000);
      Serial.println("Go!");
    }
    else{
      //UART.nunchuck.valueY = 127;
      UART.setRPM(0);
      Serial.println("Stop!");
    }

    // Call the function setNunchuckValues to send the current nunchuck values to the VESC 
    //UART.setNunchuckValues();
  }
  else
  {
    Serial.println("Failed to get data!");
  }
  */
  if ( UART_1.getVescValues() ) {

    Serial.println(UART_1.data.rpm);
    //Serial.println(UART.data.inpVoltage);
    //Serial.println(UART.data.ampHours);
    //Serial.println(UART.data.tachometerAbs);

    if(now_1 == 0)
      now_1 = millis();

    if(millis() - now_1 < 5000){
      //UART.nunchuck.valueY = 155;
      UART_1.setRPM(1000);
      Serial.println("Go!");
    }
    else{
      //UART.nunchuck.valueY = 127;
      UART_1.setRPM(0);
      Serial.println("Stop!");
    }

    /** Call the function setNunchuckValues to send the current nunchuck values to the VESC */
    //UART.setNunchuckValues();
  }
  else
  {
    Serial.println("Failed to get data from UART_1!");
  }

  delay(50);
}
