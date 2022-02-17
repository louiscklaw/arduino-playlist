#include <Arduino.h>
#include <SPI.h>

#include "LCD.h"
#include "DEV_Config.h"

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(LCD_CS, OUTPUT);
  pinMode(LCD_RST, OUTPUT);
  pinMode(LCD_DC, OUTPUT);

  Serial.begin(115200);
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV2);
  SPI.begin();

  LCD_SCAN_DIR Lcd_ScanDir = SCAN_DIR_DFT;
  Serial.println("LCD Init ");
  LCD.LCD_Init(Lcd_ScanDir);

  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
   // wait for a second
  delay(1000);

  Serial.println("LCD_Show ");
  LCD.LCD_Show();
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
   // wait for a second
  delay(1000);
}
