/* 
 * File:   SPI.h
 * Author: omar
 *
 * Created on March 16, 2025, 11:31 PM
 */

#ifndef SPI_H
#define SPI_H

#include "GPIO.h"

// SPI Modes
#define SPI_MASTER 1
#define SPI_SLAVE  0
#define MSB        0
#define LSB        1


typedef enum {
    SPI_CLK_2,
    SPI_CLK_4,
    SPI_CLK_8,
    SPI_CLK_16,
    SPI_CLK_32,
    SPI_CLK_64,
    SPI_CLK_128,
        
}SPI_prescaler_t;

typedef enum {
    RaisingSample,
    RaisingSetup,
    FallingSample,
    FallingSetup,
            
}SPIClockModes_t_T;
// Function Prototypes

/**
 * @brief Initializes SPI as Master or Slave.
 * @param mode: SPI_MASTER or SPI_SLAVE
 */
void SPI_Init(uint8_t mode);

/**
 * @brief Transmits and receives a single byte over SPI.
 * @param data: Data byte to send.
 * @return Received byte from SPI.
 */
uint8_t SPI_Transfer(uint8_t data);

/**
 * @brief Sends a single byte over SPI.
 * @param data: Byte to send.
 */
void SPI_Send(uint8_t data);

/**
 * @brief Receives a single byte over SPI.
 * @return Received byte from SPI.
 */
uint8_t SPI_Receive(void);

/**
 * @brief Sends a buffer of data over SPI.
 * @param data: Pointer to the buffer.
 * @param length: Number of bytes to send.
 */
void SPI_SendBuffer(uint8_t *data, uint16_t length);

/**
 * @brief Receives a buffer of data over SPI.
 * @param buffer: Pointer to store received data.
 * @param length: Number of bytes to receive.
 */
void SPI_ReceiveBuffer(uint8_t *buffer, uint16_t length);

/**
 * @brief Enables SPI interrupt mode.
 */
void SPI_EnableInterrupt(void);

/**
 * @brief Disables SPI interrupt mode.
 */
void SPI_DisableInterrupt(void);

/**
 * @brief Sets the SPI clock rate.
 * @param rate: Clock rate (prescaler settings).
 */
void SPI_SetClockRate(SPI_prescaler_t rate);

/**
 * @brief Sets SPI data mode (CPOL, CPHA).
 * @param mode: SPI Mode (0, 1, 2, 3).
 */
void SPI_SetDataMode(SPIClockModes_t_T mode);

/**
 * @brief Sets SPI data order (LSB/MSB first).
 * @param order: 0 for MSB first, 1 for LSB first.
 */
void SPI_SetDataOrder(uint8_t order);



#endif // SPI_H


