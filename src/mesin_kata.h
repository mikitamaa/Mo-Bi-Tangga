/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesin_kar.h"

#define NMax 105
#define BLANK ' '

typedef struct {
  char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();

void SalinKata();
          
void STARTKATA();

void STARTKATACOMMAND();

void ADVKATA();

#endif
