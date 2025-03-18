/* 
 * File:   DataTypes.h
 * Author: omar
 *
 * Created on March 13, 2025, 2:26 AM
 */

#ifndef DATATYPES_H
#define	DATATYPES_H
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdint.h>
#include <avr/io.h>
#ifndef F_CPU
#define F_CPU 16000000UL  
#endif
typedef enum {
    pdFail,
    pdSucsess,
}BaseType_t;


#endif	/* DATATYPES_H */

