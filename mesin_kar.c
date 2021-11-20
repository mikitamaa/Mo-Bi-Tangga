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

void STARTCOMMAND() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

   /* Algoritma */
   pita = stdin;
   ADV();
}