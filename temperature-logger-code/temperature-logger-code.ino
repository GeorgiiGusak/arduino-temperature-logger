//Arduino temp sensor

#include OneWire.h
#define DS18B20_Pin 8
Onewire on(DS18B20_Pin);


void setup()
{

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
  ow.write(0x33)
  
  for (int i=0; i<8; i++)
  {
    rom_code[i] = ow.read();
  }
  
    //Start sequence to convert temp

  ow.reset();
  ow.write(0xCC);
  ow.write(0x44);

    //Start sequence to read data from scratch
  byte Scratchpad[9];

  ow.reset();
  ow.write(0xCC);
  ow.write(0xBE)
  for (int n=0; n<9; n++)
  {
    Scratchpad[n] = ow.read();
  }
  
}