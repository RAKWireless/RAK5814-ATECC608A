/**
   @file RAK5814_ATECC608A.h
   @author rakwireless.com
   @brief  Written based on the ArduinoECCX08 library, adding support for RAK11200.
   @version 0.1
   @date 2022-09-14
   @copyright Copyright (c) 2022
**/

#ifndef __RAK5814_ATECC608A_H__
#define __RAK5814_ATECC608A_H__

#include <ArduinoECCX08.h>
#include <utility/ECCX08CSR.h>
#include <utility/ECCX08DefaultTLSConfig.h>

#define LIB_DEBUG 0
#if LIB_DEBUG > 0
  #define LIB_LOG(...)                      \
    {                                       \
      Serial.printf("<%s>",__FUNCTION__);   \
      Serial.printf("<%d>",__LINE__);       \
      Serial.printf(__VA_ARGS__);           \
      Serial.printf("\n");                  \
      delay(10);                            \
    }
#else
  #define LIB_LOG(...)
#endif

/**
 * @brief ATECC608A address on the I2C bus.
 */
#define ATECC608A_DEV_ADDRESS         (0x60)


class RAK_ATECC608A : public ECCX08Class
{
  public:
  RAK_ATECC608A(TwoWire& wire, uint8_t address) : ECCX08Class(wire, address){};
  ~RAK_ATECC608A(){};
};

RAK_ATECC608A ECC608A(Wire, ATECC608A_DEV_ADDRESS);

#endif
