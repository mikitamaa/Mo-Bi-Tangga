#include "../mesin_kar/mesin_kar.h"
#include "../mesin_kar/mesin_kar.c"
#include <stdio.h>

int main () {
    
    // Program dimulai dengan membuka file "konfigurasi.txt".
    START() ;

    // Program akan menuliskan karakter pertama dari file "konfigurasi.txt", yaitu 2.
    printf("%c\n", CC) ;

    // Program akan membaca dan menuliskan karakter selanjutnya, yaitu 0.
    ADV() ;
    printf("%c\n\n", CC) ;

    // Program akan meminta input user dan menuliskan karakter pertama.
    STARTCOMMAND() ;
    printf("%c\n", CC) ;

    // Program akan membaca dan menuliskan karakter selanjutnya.
    ADV() ;
    printf("%c\n\n", CC) ;
}