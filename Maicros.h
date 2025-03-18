/* 
 * File:   Maicros.h
 * Author: omar
 *
 * Created on March 13, 2025, 2:48 AM
 */

#ifndef MAICROS_H
#define	MAICROS_H

#define SetBit(Reg,Bit)         Reg|=(1<<Bit)
#define ClearBit(Reg,Bit)       Reg &=~(1<<Bit)
#define ToggleBit(Reg,Bit)      Reg ^=(1<<Bit)

#endif	/* MAICROS_H */

