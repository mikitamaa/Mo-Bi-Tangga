/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"

#define NEWLINE '\n'
/* State Mesin */
extern char CC;
extern boolean EOP;

void START();

void ADV();

#endif