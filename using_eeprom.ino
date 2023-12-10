/*
 Name:		using_eeprom.ino
 Created:	23.04.2023 17:55:01
 Author:	DarthSidious
*/

#include <Arduino.h>
#include <EEPROM.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Hello YouTube");

  uint32_t reboot_cntr = 0;

  /// create pointer to reboot counter
  uint8_t* ptr = (uint8_t*)&reboot_cntr;

  /// read 4 following bytes from EEPROM and write as reboot_cntr
  for (uint8_t i = 0; i < sizeof(reboot_cntr); i++) {
    *(ptr + i) = EEPROM.read(i);
  }

  Serial.println("Rebot counter is " + String(reboot_cntr));

  /// update reboot_cntr
  reboot_cntr++;

  /// write each byte of reboot_cntr as 4 following bytes into EEPROM
  for (uint8_t i = 0; i < sizeof(reboot_cntr); i++) {
    EEPROM.write(i, *(ptr + i));
  }
}

// the loop function runs over and over again until power down or reset
void loop() {
}
