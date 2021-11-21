#include "command.h"
#include "map.h"
#include "roll.h"
#include <stdio.h>

void command(MAP *Map) {
    int i, hasilcommand ;
    boolean endthisturn = false ;

    while (!endthisturn) {
        hasilcommand = 0 ;
        printf("Masukkan command: ") ;
        STARTKATACOMMAND() ;

        boolean valid ;
        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != skill[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 1 ;
        }

        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != map[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 2 ;
        }

        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != buff[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 3 ;
        }

        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != inspect[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 4 ;
        }

        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != roll[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 5 ;
        }

        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != save[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 6 ;
        }

        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != endturn[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 7 ;
        }

        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != undo[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 8 ;
        }

        switch(hasilcommand) {
            // SKILL
            case 1 :
                printf("skill\n") ;
                break ;

            // MAP    
            case 2 :
                printf("map\n") ;
                break ;

            // BUFF
            case 3 :
                printf("buff\n") ;
                break ;

            // INSPECT
            case 4 :
                printf("Masukkan petak: ") ;
                int petakcommand ;
                scanf("%d", &petakcommand) ;
                if ((*Map).TabMap[petakcommand].IsiPetak == '.') {
                    if ((*Map).TabMap[petakcommand].Teleporter == -1) {
                        printf("Petak %d merupakan petak kosong.\n", petakcommand) ;
                    }
                    else {
                        printf("Petak %d memiliki teleporter menuju %d.\n", petakcommand, (*Map).TabMap[petakcommand].Teleporter) ;
                    }
                }
                else {
                    printf("Petak %d merupakan petak terlarang.\n", petakcommand) ;
                }
                break ;

            // ROLL
            case 5 :
                printf("roll\n") ;
                break ;

            // SAVE
            case 6 :
                printf("save\n") ;
                break ;

            // ENDTURN
            case 7 :
                endthisturn = true ;
                break ;

            // UNDO
            case 8 :
                printf("undo\n") ;
                break;

            // INPUT SALAH
            default :
                printf("invalid\n") ;
        }
    }
}
