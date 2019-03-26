/**
 * @brief BME280 sensor library
 * @author Michael Burmeister
 * @date December 14, 2017
 * @version 1.1
 * 
*/

/**
 * @brief Interface to BME280 sensor
 * @author Brian Markley EIT BMarkley@Ualberta.ca
 * @date March 26, 2019
 * @version 1.2
 * 
 * @changes Edited the print formatting
 * 
*/

#include "simpletools.h"
#include "bme280.h"


#define BMESCL 14
#define BMESDA 13



int main()
{
  int i;
  int j;
  float f;
  print("start");
  
  i = BME280_open(BMESCL, BMESDA);
  
  print("should be hex (60):%x \n", i);
  
  BME280_reset();
  
  BME280_setHumidity(oversample_1);
  BME280_setTemp(oversample_1);
  BME280_setPressure(oversample_1);
  BME280_setStandbyRate(standby625);
  BME280_setMode(BME280_normal);
  
  i = BME280_getMode();
  print("Mode: %x \n", i);
  
  f = 0;
  
  while(1)
  {
    while (i != 0)
    {
      j = 1;
      print("<%b> ", i);
      pause(1000);
      i = BME280_getStatus();
    }
    
    if (j != 0)
    {
      j = 0;
      print("\n");
    }
          
    i = BME280_getTemp();
    f = BME280_getTemperaturef();
    printf("Temp: %d %2.2f\n", i, f);
//    print("Temp: %d ", i);
    
    i = BME280_getPressure();
    f = BME280_getPressuref();
    printf("Pressure: %d %2.2f\n", i, f);
//    print("Pressure: %d ", i);
    
    i = BME280_getHumidity();
    f = BME280_getHumidityf();
    printf("Humidity: %d %2.2f\n", i, f);
//    print("Humidity: %d \n", i);
    
    i = BME280_getStatus();
  }  
}
