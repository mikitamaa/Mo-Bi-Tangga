#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean/boolean.h"
#include "../mesin_kar/mesin_kar.h"

#define NMax 105
#define BLANK ' '

typedef struct {
    char TabKata[NMax+1] ; 
    int Length ;
} Kata;

extern boolean EndKata;
extern Kata CKata;

// Mesin kata akan mengabaikan seluruh ' ' dan '\n', membaca karakter selanjutnya selama bukan EOP.
// I.S. CC sembarang.
// F.S. CC karakter selanjutnya selama bukan EOP.
void IgnoreBlank() ;

// Mesin kata akan menyimpan sebuah "Kata", setiap kata dipisahkan oleh ' ' atau '\n'.
// I.S. CC sembarang.
// F.S. CKata.TabKata mengandung karakter-karakter dari sebuah kata, CKata.Length berupa panjang kata.
void SalinKata() ;

// Mesin kata akan membaca kata pertama dari file "konfigurasi.txt".
// I.S. File konfigurasi.
// F.S. CKata.TabKata menyimpan karakter-karakter yang membentuk kata pertama pada file "konfigurasi.txt",
//      CKata.Length berupa panjang kata.
void STARTKATA() ;

// Mesin kata akan membaca kata pertama dari input user.
// I.S. Input user.
// F.S. CKata.TabKata menyimpan karakter-karakter yang membentuk kata pertama dari input user,
//      CKata.Length berupa panjang kata.
void STARTKATACOMMAND() ;

// Mesin kata akan memroses kata selanjutnya.
// I.S. Kata sembarang.
// F.S. CKata.TabKata menyimpan karakter-karakter yang membentuk kata pertama dari input user,
//      CKata.Length berupa panjang kata.
void ADVKATA() ;

#endif
