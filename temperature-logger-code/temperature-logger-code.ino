//Arduino temp sensor

#include <OneWire.h>
#define DS18B20_Pin 8
OneWire ow(DS18B20_Pin);


void setup()
{
  Serial.begin(9600);
}

void loop()
{
    /*
    We always need to follow this sequence
    1st sequence: initialization
    2nd sequence: ROM command
    3rd sequence: DS18B20 command 
    */
  byte rom_code[8]; 

  ow.reset();
  ow.write(0x33);
  
  for (int i=0; i<8; i++)
  {
    rom_code[i] = ow.read();
  }
  
    //Start sequence to convert temp

  ow.reset();
  ow.write(0xCC);
  ow.write(0x44);
    // Wait for temp to convert
    while (ow.read_bit() == 0)
    {
      delay(10);
    }
    //Start sequence to read data from scratch
  byte Scratchpad[9];

  ow.reset();
  ow.write(0xCC);
  ow.write(0xBE);
  for (int n=0; n<9; n++)
  {
    Scratchpad[n] = ow.read();
  }
  
  //Extract info from retrieved data
  //Get Serial N from ROM code data
  if (rom_code[0] != 0x28)
  {
    Serial.print('#is not a DS18B20');
  }
  String registration_number = "";
  for (int i=1; i<7; i++)
  {
    registration_number += String(rom_code[i], HEX);
  }
  Serial.println(registration_number);

  //Read Temperature info
  int16_t TempRead=(Scratchpad[1]<<8) | Scratchpad[0];
  float tempCelsius = (float)TempRead/16.0; //16=2**4
  Serial.println(tempCelsius);
  delay(1500);
}