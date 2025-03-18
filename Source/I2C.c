#include "../HEADER/I2C.h"

I2C_Status I2CInit(I2CConfig_t *I2C){
    if(!I2C)return I2C_ERROR_NotValid_PTR;
    switch (I2C->mode){
        case I2CMaster:
            TWBR = ((F_CPU / I2C->Freq) - 16) / 2;
            TWSR=I2C->pre;
            TWCR = (1 << TWEN);
            break;
        case I2cSlave:
            TWAR=(I2C->SlaveAdress<<1);
            TWCR = (1 << TWEN);
            SetBit(TWCR,TWINT);
            if (I2C->ACKEnable) {
                SetBit(TWCR,TWEA);
            } else {
                SetBit(TWCR,TWEA);
            }

            break;
        default:
            return I2C_ERROR_UNKNOWN;
    }
    return I2C_SUCCESS;        
}
I2C_Status I2CStart(void){
    TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    while (!(TWCR&(1<<TWINT))) ;
    if((TWDR&0xF8)!=0x08){
        return I2C_ERROR_START;
    }
    return I2C_SUCCESS;
}
I2C_Status I2CStop(void){
    TWCR = (1 << TWSTO) | (1 << TWEN) | (1 << TWINT);
}
I2C_Status i2c_send_Adress(uint8_t data){
    TWDR=data;
    TWCR=(1<<TWINT)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
    if ((TWSR & 0xF8) !=0x18)return I2C_ERROR_ADDR_NACK;
    return I2C_SUCCESS;
}
I2C_Status i2c_send_data(uint8_t data){
    TWDR=data;
    TWCR=(1<<TWINT)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
    if ((TWSR & 0xF8) !=0x28)return I2C_ERROR_DATA_NACK;
    return I2C_SUCCESS;
}
I2C_Status i2c_receive_data(uint8_t *Data, uint8_t ack) {
    if (!Data) return I2C_ERROR_UNKNOWN; // Null pointer check

    // Enable reception and decide whether to send ACK or NACK
    TWCR = (1 << TWINT) | (1 << TWEN) | (ack ? (1 << TWEA) : 0);
    while (!(TWCR & (1 << TWINT))); // Wait for data

    // Check for successful reception
    if ((TWSR & 0xF8) == 0x50 || (TWSR & 0xF8) == 0x58) { 
        *Data = TWDR; // Store received byte
        return I2C_SUCCESS;
    }

    return I2C_ERROR_DATA_NACK; // Error if not in correct state
}
I2C_Status i2c_check_ack(void){
    uint8_t status = TWSR & 0xF8;

    if (status == 0x18 || status == 0x28 || status == 0x50) {
        return I2C_SUCCESS; // ACK received
    } else if (status == 0x20 || status == 0x30) {
        return I2C_ERROR_ADDR_NACK; // NACK after address
    } else if (status == 0x48) {
        return I2C_ERROR_DATA_NACK; // NACK after data
    }

    return I2C_ERROR_UNKNOWN; // Undefined state
}

I2C_Status i2c_get_error(void){
     uint8_t status = TWSR & 0xF8;

    switch (status) {
        case 0x08: return I2C_SUCCESS;          // START transmitted
        case 0x10: return I2C_SUCCESS;          // Repeated START transmitted
        case 0x18: return I2C_SUCCESS;          // SLA+W sent, ACK received
        case 0x20: return I2C_ERROR_ADDR_NACK;  // SLA+W sent, NACK received
        case 0x28: return I2C_SUCCESS;          // Data sent, ACK received
        case 0x30: return I2C_ERROR_DATA_NACK;  // Data sent, NACK received
        case 0x38: return I2C_ERROR_BUS_BUSY;   // Arbitration lost
        case 0x48: return I2C_ERROR_ADDR_NACK;  // SLA+R sent, NACK received
        case 0x50: return I2C_SUCCESS;          // Data received, ACK sent
        case 0x58: return I2C_ERROR_DATA_NACK;  // Data received, NACK sent
        default: return I2C_ERROR_UNKNOWN;      // Unexpected status
    }
}
