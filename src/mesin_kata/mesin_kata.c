#include "../mesin_kata/mesin_kata.h"
#include "../mesin_kar/mesin_kar.h"
#include "../boolean/boolean.h"
#include <stdio.h>

boolean EndKata ;
Kata CKata ;

// Mesin kata akan mengabaikan seluruh ' ' dan '\n', membaca karakter selanjutnya selama bukan EOP.
// I.S. CC sembarang.
// F.S. CC karakter selanjutnya selama bukan EOP.
void IgnoreBlank() {

    // Selama CC bukan merupakan ' ' atau '\n', maka mesin kata akan membaca karakter selanjutnya.
    while ((CC == BLANK) || (CC == NEWLINE) && (!EOP)) {
        ADV() ;
    }
}

// Mesin kata akan menyimpan sebuah "Kata", setiap kata dipisahkan oleh ' ' atau '\n'.
// I.S. CC sembarang.
// F.S. CKata.TabKata mengandung karakter-karakter dari sebuah kata, CKata.Length berupa panjang kata.
void SalinKata() {
    int i = 1;

    // Selama CC bukan merupakan ' ' atau '\n', maka mesin kata akan menyimpan karakter pada CKata.TabKata.
    while ((CC != BLANK) && (CC != NEWLINE) && (i <= NMax) && (!EOP)) {
        CKata.TabKata[i] = CC ;
        ADV() ;
        i++ ;
    }

    // Panjang kata akan disimpan pada CKata.Length.
    CKata.Length = i - 1 ;
}

// Mesin kata akan membaca kata pertama dari file "konfigurasi.txt".
// I.S. File konfigurasi.
// F.S. CKata.TabKata menyimpan karakter-karakter yang membentuk kata pertama pada file "konfigurasi.txt",
//      CKata.Length berupa panjang kata.          
void STARTKATA() {

    // Membaca file "konfigurasi.txt" dan CC terletak pada karakter pertama.
    START() ;

    // Memastikan tidak terdapat ' ' atau '\n'.
    IgnoreBlank() ;

    // Jika CC bukan ' ' atau '\n', mesin kata akan membaca Kata.
    if ((CC != BLANK) && (CC != NEWLINE) && (!EOP)) {
        SalinKata() ;
    }
}

// Mesin kata akan membaca kata pertama dari input user.
// I.S. Input user.
// F.S. CKata.TabKata menyimpan karakter-karakter yang membentuk kata pertama dari input user,
//      CKata.Length berupa panjang kata.
void STARTKATACOMMAND() {
    
    // Membaca input user dan CC terletak pada karakter pertama.
    STARTCOMMAND() ;

    // Memastikan tidak terdapat ' ' atau '\n'.
    IgnoreBlank() ;

    // Jika CC bukan ' ' atau '\n', mesin kata akan membaca Kata.
    if ((CC != BLANK) && (CC != NEWLINE) && (!EOP)) {
        SalinKata() ;
    }
}

// Mesin kata akan memroses kata selanjutnya.
// I.S. Kata sembarang.
// F.S. CKata.TabKata menyimpan karakter-karakter yang membentuk kata pertama dari input user,
//      CKata.Length berupa panjang kata.
void ADVKATA() {
    
    // Memastikan tidak terdapat ' ' atau '\n'.
    IgnoreBlank() ;

    // Jika CC bukan ' ' atau '\n', mesin kata akan membaca Kata.
    if ((CC != BLANK) && (CC != NEWLINE) && (!EOP)) {
        SalinKata() ;
    }
}
