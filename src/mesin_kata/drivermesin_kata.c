#include "../mesin_kata/mesin_kata.h"
#include "../mesin_kata/mesin_kata.c"
#include "../mesin_kar/mesin_kar.h"
#include "../mesin_kar/mesin_kar.c"
#include <stdio.h>

int main () {

    // Program dimulai dengan membuka file "konfigurasi.txt".
    STARTKATA() ;

    // Program akan menuliskan kata pertama dari file "konfigurasi.txt", yaitu 20.
    for (int i = 1; i <= CKata.Length; i++) {
        printf("%c", CKata.TabKata[i]) ;
    }
    printf("\n") ;

    // Program akan membaca dan menuliskan kata selanjutnya, yaitu "...#..#...##..#...#.".
    ADVKATA() ;
    for (int i = 1; i <= CKata.Length; i++) {
        printf("%c", CKata.TabKata[i]) ;
    }
    printf("\n\n") ;

    // Program akan meminta input user dan menuliskan kata pertama.
    STARTKATACOMMAND() ;
    for (int i = 1; i <= CKata.Length; i++) {
        printf("%c", CKata.TabKata[i]) ;
    }
    printf("\n") ;

    // Program akan membaca dan menuliskan kata selanjutnya.
    ADVKATA() ;
    for (int i = 1; i <= CKata.Length; i++) {
        printf("%c", CKata.TabKata[i]) ;
    }
    printf("\n\n") ;
}