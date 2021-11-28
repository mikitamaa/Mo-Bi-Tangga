#include "../mesin_kar/mesin_kar.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

// Mesin kata dimulai dengan membaca file "konfigurasi.txt". Pita kata dimulai dari karakter pertama.
// I.S. File "konfigurasi.txt".
// F.S. CC adalah karakter pertama dari pita.
void START() {
   
   // Membuka file "konfigurasi.txt" untuk dibaca.
   pita = fopen("konfigurasi.txt", "r");
   ADV();
}

// Mesin kata akan memroses karakter berikutnya.
// I.S. CC sembarang.
// F.S. CC selanjutnya.
void ADV() {

   // retval digunakan untuk mengecek apakah terdapat suatu karakter setelah sebuah karakter.
   // Jika retval bernilai negatif, maka tidak terdapat karakter setelah karakter yang dicek.
   retval = fscanf(pita,"%c",&CC);
   EOP = (retval < 0);

   // Jika sudah berada pada akhir kata, file "konfigurasi.txt" akan ditutup.
   if (EOP) {
      fclose(pita);
   }
}

// Mesin kata dimulai dengan membaca input user. Pita karakter dimulai dari karakter pertama.
// I.S. Input user sembarang.
// F.S. CC adalah karakter pertama dari pita.
void STARTCOMMAND() {

   // Membaca input dari user.
   pita = stdin;
   ADV();
}
