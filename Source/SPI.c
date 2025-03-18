

#include "../HEADER/SPI.h"

/**
 * @brief Initializes SPI as Master or Slave.
 * @param mode: SPI_MASTER or SPI_SLAVE
 */
void SPI_Init(uint8_t mode){
    
    switch(mode){
        case SPI_MASTER:
         // SetBit  (DDRB,P2);
          SetBit  (DDRB,P3);
          SetBit  (DDRB,P5);
          ClearBit(DDRB,P4);
          SetBit  (SPCR,SPE);
          SetBit  (SPCR,MSTR);
          break;
        case SPI_SLAVE:
          ClearBit(DDRB,P2);
          ClearBit(DDRB,P3);
          ClearBit(DDRB,P5);
          SetBit  (DDRB,P4);
          SetBit  (SPCR,SPE);  
          break;
    }
}

/**
 * @brief Transmits and receives a single byte over SPI.
 * @param data: Data byte to send.
 * @return Received byte from SPI.
 */
uint8_t SPI_Transfer(uint8_t data){
    /* Start transmission */
    SPDR = data;
    /* Wait for transmission complete */
    while(!(SPSR & (1<<SPIF))) ;
    return SPDR;
}

/**
 * @brief Sends a single byte over SPI.
 * @param data: Byte to send.
 */
void SPI_Send(uint8_t data){
    SPI_Transfer(data);
}

/**
 * @brief Receives a single byte over SPI.
 * @return Received byte from SPI.
 */
uint8_t SPI_Receive(void){
    return SPI_Transfer(0xFF);
}

/**
 * @brief Sends a buffer of data over SPI.
 * @param data: Pointer to the buffer.
 * @param length: Number of bytes to send.
 */
void SPI_SendBuffer(uint8_t *data, uint16_t length){
    int i;
    for (i = 0; i < length; i++) {
        SPI_Send(data[i]);

    }

}

/**
 * @brief Receives a buffer of data over SPI.
 * @param buffer: Pointer to store received data.
 * @param length: Number of bytes to receive.
 */
void SPI_ReceiveBuffer(uint8_t *buffer, uint16_t length){
    int i;
    for (i = 0; i < length; i++) {
        buffer[i] = SPI_Receive();  
    }

     
}

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
void SPI_SetClockRate(SPI_prescaler_t rate){
    switch(rate){
        case SPI_CLK_2:
           SetBit  (SPSR,SPI2X); 
           ClearBit(SPCR,SPR1); 
           ClearBit(SPCR,SPR0); 
        case SPI_CLK_4:
           ClearBit(SPSR,SPI2X); 
           ClearBit(SPCR,SPR1); 
           ClearBit(SPCR,SPR0);
           break;
        case SPI_CLK_8:
           SetBit  (SPSR,SPI2X); 
           ClearBit(SPCR,SPR1); 
           SetBit  (SPCR,SPR0);
           break;
           case SPI_CLK_16:
           ClearBit(SPSR,SPI2X); 
           ClearBit(SPCR,SPR1); 
           SetBit  (SPCR,SPR0);
           break;
           case SPI_CLK_32:
           SetBit  (SPSR,SPI2X); 
           SetBit  (SPCR,SPR1); 
           ClearBit(SPCR,SPR0);
           break;
           case SPI_CLK_64:
           ClearBit(SPSR,SPI2X); 
           SetBit  (SPCR,SPR1); 
           ClearBit(SPCR,SPR0);
           break;
        case SPI_CLK_128:
           ClearBit(SPSR,SPI2X); 
           SetBit  (SPCR,SPR1); 
           SetBit  (SPCR,SPR0);
           break;
           
    }
}

/**
 * @brief Sets SPI data mode (CPOL, CPHA).
 * @param mode: SPI Mode (0, 1, 2, 3).
 */
void SPI_SetDataMode(SPIClockModes_t_T mode){
    switch(mode){
        case RaisingSample:
            ClearBit(SPCR,CPOL);
            ClearBit(SPCR,CPHA);
            break;
        case RaisingSetup:
            ClearBit(SPCR,CPOL);
            SetBit  (SPCR,CPHA);
            break;
        case FallingSample:
            SetBit  (SPCR,CPOL);
            ClearBit(SPCR,CPHA);
            break;
        case FallingSetup:
            SetBit  (SPCR,CPOL);
            SetBit  (SPCR,CPHA);
            break;
    }
}

/**
 * @brief Sets SPI data order (LSB/MSB first).
 * @param order: 0 for MSB first, 1 for LSB first.
 */
void SPI_SetDataOrder(uint8_t order){
    if (order==LSB) {
        SetBit(SPCR,DOR0);
    } else {
        ClearBit(SPCR,DOR0);
    }

}



