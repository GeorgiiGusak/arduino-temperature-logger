//Arduino temp sensor

#include OneWire.h
#define DS18B20_Pin 8
Onewire on(DS18B20_Pin)


void setup()
{

}

void loop()
{
  //1st sequence: initialization
  //2nd sequence: ROM command
  //3rd sequence: DS18B20 command  
}