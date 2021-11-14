/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesin_kar.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void START() {
   pita = fopen("konfigurasi.txt", "r");
   ADV();
}

void ADV() {
   retval = fscanf(pita,"%c",&CC);
   EOP = (retval < 0);
   if (EOP) {
      fclose(pita);
   }
}