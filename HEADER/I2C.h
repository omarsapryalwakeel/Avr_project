/* 
 * File:   I2C.h
 * Author: omar
 *
 * Created on March 17, 2025, 2:48 PM
 */

#ifndef I2C_H
#define	I2C_H

#include "GPIO.h"

#define I2CMaster   0
#define I2cSlave    1
typedef enum {
    I2C_SUCCESS = 0,
    I2C_ERROR_START = 1,
    I2C_ERROR_ADDR_NACK = 2,
    I2C_ERROR_DATA_NACK = 3,
    I2C_ERROR_BUS_BUSY = 4,
    I2C_ERROR_NotValid_PTR = 5,        
    I2C_ERROR_UNKNOWN = 255
} I2C_Status;
typedef enum {
    I2CPrescaler_1,
    I2CPrescaler_4,
    I2CPrescaler_16,
    I2CPrescaler_64
}I2CPrescaler_t;
typedef struct {
    uint8_t mode;
    uint32_t Freq;
    I2CPrescaler_t pre;
    uint8_t SlaveAdress;
    uint8_t ACKEnable;
}I2CConfig_t;


I2C_Status I2CInit(I2CConfig_t *I2C);
I2C_Status I2CStart(void);
I2C_Status I2CStop(void);
I2C_Status i2c_send_Adress(uint8_t data);
I2C_Status i2c_send_data(uint8_t data);
I2C_Status i2c_receive_data(uint8_t *Data, uint8_t ack);
I2C_Status i2c_check_ack(void);
I2C_Status i2c_get_error(void);




#endif	/* I2C_H */

