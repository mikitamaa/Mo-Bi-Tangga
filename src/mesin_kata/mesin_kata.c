#include "../mesin_kata/mesin_kata.h"
#include "../mesin_kar/mesin_kar.h"
#include "../boolean/boolean.h"
#include <stdio.h>

boolean EndKata ;
Kata CKata ;

void IgnoreBlank(){
    while ((CC == BLANK) || (CC == NEWLINE) && (!EOP)) {
        ADV() ;
    }
}

void SalinKata(){
    int i = 1;
    while ((CC != BLANK) && (CC != NEWLINE) && (i <= NMax) && (!EOP)) {
        CKata.TabKata[i] = CC ;
        ADV() ;
        i++ ;
    }
    CKata.Length = i - 1 ;
}
          
void STARTKATA() {
    START() ;
    IgnoreBlank() ;
    if ((CC != BLANK) && (CC != NEWLINE) && (!EOP)) {
        SalinKata() ;
    }
}

void STARTKATACOMMAND() {
    STARTCOMMAND() ;
    IgnoreBlank() ;
    if ((CC != BLANK) && (CC != NEWLINE) && (!EOP)) {
        SalinKata() ;
    }
}

void ADVKATA(){
    IgnoreBlank() ;
    if ((CC != BLANK) && (CC != NEWLINE) && (!EOP)) {
        SalinKata() ;
    }
}
