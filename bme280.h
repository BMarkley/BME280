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
 * @changes DODOUBLE by Default
 * 
*/

 #define DODOUBLE 1

enum
{
  oversample_0,
  oversample_1,
  oversample_2,
  oversample_4,
  oversample_8,
  oversample_16
};
  
enum
{
  BME280_sleep,
  BME280_forced,
  BME280_forced1,
  BME280_normal
};

enum
{
  standby5,
  standby625,
  standby1250,
  standby2500,
  standby5000,
  standby10000,
  standby100,
  standby200
};

enum
{
  filter0,
  filter2,
  filter4,
  filter8,
  filter16
};

/**
 * @brief Open i2c connection to BME280
 * 
 * @param scl I2c clock pin
 * @param sda I2c data pin
 * @return 0x60 or BME280 id
 */
int BME280_open(int scl, int sda);

/**
 * @brief Get BME280 ID (0x60)
 * 
 * @return 0x60
 */
int BME280_getID(void);

/**
 * @brief Do soft reset of BME280
 * 
 */
void BME280_reset(void);

/**
 * @brief Get measurement status 
 * 
 * @return BME280 status
 */
int BME280_getStatus(void);

/**
 * @brief Forced mode standby rate
 *        .5, 62.5 125, 250, 500, 1000, 100, and 200
 * @param Standby Item name
 */
void BME280_setStandbyRate(int);

/**
 * @brief Forced mode filter rate
 *        0, 2, 4, 8, 16
 * @param Filter rate item name
 */
void BME280_setFilterRate(int);

/**
 * @brief Set BME280 Mode of operation
 *        Sleep, Forced, and Normal
 * @param Mode item name
 */
void BME280_setMode(int);

/**
 * @brief get BME280 Mode of operation
 * 
 * @return Mode value for Sleep, Forced and Normal
 */
int BME280_getMode(void);

/**
 * @brief Set pressure measurement sampling
 *        0, 1, 2, 4, 8, 16
 * @param Frequency Item Name
 */
void BME280_setPressure(int);

/**
 * @brief Set Temperature measurment sampling
 *        0, 1, 2, 4, 8, 16
 * @param Frequency Item Name
 */
void BME280_setTemp(int);

/**
 * @brief Set Humidity measurement sampling
 *        0, 1, 2, 4, 8, 16
 * @param Frquency Item Name
 */
void BME280_setHumidity(int);

/**
 * @brief Get Pressure in pascals
 * 
 * @return Pascal value
 */
int BME280_getPressure(void);

/**
 * @brief Get Temperature in celius
 * 
 * @return celius temperature
 */
int BME280_getTemp(void);

/**
 * @brief Get Humidity in percent times 100
 * 
 * @return Percent humidity time 100
 */
int BME280_getHumidity(void);

/**
 * @brief Get Temperature in Fahrenheit
 * 
 * @return Temperature in Fahrenheit time 100
 */
int BME280_getTempF(void);

/**
 * @brief Get Pressure in inch of mercury
 * 
 * @return inches of mercury time 100
 */
int BME280_getPressureM(void);

#ifdef DODOUBLE

float BME280_getTemperaturef(void);

float BME280_getPressuref(void);

float BME280_getHumidityf(void);

#endif
