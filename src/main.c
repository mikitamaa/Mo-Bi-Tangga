#include "command.h"
#include "command.c"
#include "map.h"
#include "map.c"
#include "roll.h"
#include "roll.c"
#include "player.h"
#include "player.c"
#include "skill.h"
#include "skill.c"
#include "stack.h"
#include "stack.c"
#include "mesin_kar.h"
#include "mesin_kar.c"
#include "mesin_kata.h"
#include "mesin_kata.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    // boolean endgame = false ;
    // int hasilcommandmain ;
    // while (!endgame) {
    //     hasilcommandmain = 0 ;
    //     printf("Selamat datang di permainan MobiTangga!\n") ;
    //     printf("--- Main Menu ---\n") ;
    //     prinft("NEW GAME\n") ;
    //     printf("EXIT\n") ;
    //     printf("LOAD GAME\n") ;
    //     printf("Masukkan command: ") ;

    // }

    boolean jumlahpemainvalid = false ;
    int jumlahpemain ; 
    while (!jumlahpemainvalid) {
        printf("Masukkan jumlah pemain: ") ;
        scanf("%d", &jumlahpemain) ;
        if (jumlahpemain < 2 || jumlahpemain > 4) {
            printf("Jumlah pemain harus diantara 2 sampai 4 pemain.\n") ;
        }
        else {
            jumlahpemainvalid = true ;
        }
        printf("\n") ;
    }
    Player P ;
    createEmptyPlayerList(&P) ;
    addPlayer(&P, jumlahpemain) ;

    printf("\n") ;

    MAP Map ;
    KonfigurasiToMap(&Map) ;

    Stack Stack ;
    CreateEmptyStack(&Stack) ;

    // Game akan terus berjalan hingga ada pemain yang menang (endgame = true)
    boolean endgame = false ;
    boolean endronde = false ;
    int jumlahronde = 1 ;
    Push(&Stack, &P) ;
    while (!endgame) {
        int i = 1;
        endronde = false ;
        printf("-- Ronde ke-%d --\n\n", jumlahronde) ;

        // Setiap player mendapatkan turn pada sebuah ronde
        while (!endronde && i <= jumlahpemain) {
            printf("-- Giliran %s --\n\n", P.uName[i]) ;
            draw(&P, i, 0) ;

            // Menuliskan Map setiap awal giliran
            for (int imap = 1; imap <= P.Neff; imap++) {
                    printf("%s\t", P.uName[imap]) ;
                    printf(" : ") ;
                    for (int jmap = 1; jmap <= Map.PanjangMap; jmap++) {
                        if (P.pos[imap] == jmap) {
                            printf("*") ;
                        }
                        else {
                            printf("%c", Map.TabMap[jmap].IsiPetak) ;
                        }
                    }
                    printf(" %d", P.pos[imap]) ;
                    printf("\n") ;
                }
            printf("\n") ;

            command(&Map, &P, &Stack, i, &endgame, &endronde, &jumlahronde) ;
            i++ ;
            
        }
        for (i = 1; i <= P.Neff; i++) {
            P.isUdahRoll[i] = false ;
        }
        jumlahronde++ ;
        printf("\n") ;
        Push(&Stack, &P) ;
    }
}