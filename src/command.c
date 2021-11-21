#include "command.h"
#include "map.h"
#include "roll.h"
#include "player.h"
#include <stdio.h>
#include <string.h>

void command(MAP *Map, Player *P, int turnplayer, boolean endgame) {
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
                for (int imap = 1; imap <= (*P).Neff; imap++) {
                    printf("%s", (*P).uName[imap]) ;
                    printf(" : ") ;
                    for (int jmap = 1; jmap <= (*Map).PanjangMap; jmap++) {
                        if ((*P).pos[imap] == jmap) {
                            printf("*") ;
                        }
                        else {
                            printf("%c", (*Map).TabMap[jmap].IsiPetak) ;
                        }
                    }
                    printf(" %d", (*P).pos[imap]) ;
                    printf("\n") ;
                }
                printf("\n") ;
                break ;

            // BUFF
            case 3 :
                for (int ibuff = 1; ibuff <= (*P).Neff; ibuff++) {
                    printf("Buff yang dimiliki %s: \n", (*P).uName[ibuff]) ;
                    boolean adabuffaktif = false ;
                    if ((*P).isImmu[ibuff]) {
                        printf("- Immunitas Teleport\n") ;
                        adabuffaktif = true ;
                    }
                    if ((*P).isCermin[ibuff]) {
                        printf("- Cermin Pengganda\n") ;
                        adabuffaktif = true ;
                    }
                    if ((*P).isSenPem[ibuff]) {
                        printf("- Senter Pembesar Hoki\n") ;
                        adabuffaktif = true ;
                    }
                    if ((*P).isSenPeng[ibuff]) {
                        printf("- Senter Pengecil Hoki\n") ;
                        adabuffaktif = true ;
                    }
                    if (!adabuffaktif) {
                        printf("-\n") ;
                    }
                    printf("\n") ;
                }
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
                printf("\n") ;
                break ;

            // ROLL
            case 5 : 
                if (!(*P).isUdahRoll[turnplayer]) {
                    int roll = HasilRoll(*Map, *P, turnplayer) ;
                    printf("%s mendapatkan angka %d.\n", (*P).uName[turnplayer], roll) ;
                    int kemungkinan1 = (*P).pos[turnplayer] + roll ;
                    int kemungkinan2 = (*P).pos[turnplayer] - roll ;
                    boolean bergerak = false ; 
                    if ((*Map).TabMap[kemungkinan1].IsiPetak == '.' && (*Map).TabMap[kemungkinan2].IsiPetak == '.' && kemungkinan1 <= (*Map).PanjangMap && kemungkinan2 >= 1) {
                        bergerak = true ;
                        printf("%s dapat maju dan mundur.\n", (*P).uName[turnplayer]) ;
                        printf("Ke mana %s mau bergerak:\n", (*P).uName[turnplayer]) ;
                        printf("   1. %d\n", kemungkinan2) ;
                        printf("   2. %d\n", kemungkinan1) ;
                        boolean pilihanrollvalid = false ;
                        int pilihanroll ;
                        while (!pilihanrollvalid) {
                            printf("Masukkan pilihan: ") ;
                            scanf("%d", &pilihanroll) ;
                            if (pilihanroll == 1) {
                                pilihanrollvalid = true ;
                                (*P).pos[turnplayer] = kemungkinan2 ;
                                printf("%s mundur %d langkah.\n", (*P).uName[turnplayer], roll) ;
                                printf("%s berada di petak %d.\n", (*P).uName[turnplayer], (*P).pos[turnplayer]) ;
                            }
                            else if (pilihanroll == 2) {
                                pilihanrollvalid = true ;
                                (*P).pos[turnplayer] = kemungkinan1 ;
                                printf("%s maju %d langkah.\n", (*P).uName[turnplayer], roll) ;
                                printf("%s berada di petak %d.\n", (*P).uName[turnplayer], (*P).pos[turnplayer]) ;
                            }
                            else {
                                printf("Pilihan roll harus 1 atau 2.\n\n") ;
                            }
                        }
                    }
                    else if ((*Map).TabMap[kemungkinan1].IsiPetak == '.' && kemungkinan1 <= (*Map).PanjangMap) {
                        bergerak = true ;
                        printf("%s dapat maju.\n", (*P).uName[turnplayer]) ;
                        (*P).pos[turnplayer] = kemungkinan1 ;
                        printf("%s maju %d langkah.\n", (*P).uName[turnplayer], roll) ;
                        printf("%s berada di petak %d.\n", (*P).uName[turnplayer], (*P).pos[turnplayer]) ;

                    }
                    else if ((*Map).TabMap[kemungkinan2].IsiPetak == '.' && kemungkinan2 >= 1) {
                        bergerak = true ;
                        printf("%s dapat mundur.\n", (*P).uName[turnplayer]) ;
                        (*P).pos[turnplayer] = kemungkinan2 ;
                        printf("%s mundur %d langkah.\n", (*P).uName[turnplayer], roll) ;
                        printf("%s berada di petak %d.\n", (*P).uName[turnplayer], (*P).pos[turnplayer]) ;
                    }
                    else {
                        printf("%s tidak dapat bergerak.\n", (*P).uName[turnplayer]) ;
                    }

                    if (bergerak) {
                        if ((*Map).TabMap[(*P).pos[turnplayer]].Teleporter == -1) {
                            printf("%s tidak menemukan teleporter.\n", (*P).uName[turnplayer]) ;
                        }
                        else {
                            printf("%s menemukan teleporter.\n", (*P).uName[turnplayer]) ;
                            if ((*P).isImmu[turnplayer]) {
                                printf("%s memiliki imunitas teleport.\n", (*P).uName[turnplayer]) ;
                                printf("Apakah %s ingin teleport (Y/N)? ", (*P).uName[turnplayer]) ;
                                boolean pilihanteleportvalid = false ;
                                char pilihanteleport ;
                                while (!pilihanteleportvalid) {
                                    scanf("%c", &pilihanteleport) ;
                                    if (pilihanteleport == 'Y') {
                                    (*P).pos[turnplayer] = (*Map).TabMap[(*P).pos[turnplayer]].Teleporter ;
                                    printf("%s teleport ke petak %d.\n", (*P).uName[turnplayer], (*P).pos[turnplayer]) ;
                                    }
                                    else if (pilihanteleport == 'N') {
                                        printf("%s tidak teleport.\n", (*P).uName[turnplayer]) ;
                                        (*P).isImmu[turnplayer] = false ;
                                        printf("Buff imunitas teleport hilang.\n") ;
                                    }
                                    else {
                                        printf("Pilihan teleport harus Y atau N.\n\n") ;
                                    }
                                }
                            }
                            else {
                                printf("%s tidak memiliki imunitas teleport.\n", (*P).uName[turnplayer]) ;
                                (*P).pos[turnplayer] = (*Map).TabMap[(*P).pos[turnplayer]].Teleporter ;
                                printf("%s teleport ke petak %d.\n", (*P).uName[turnplayer], (*P).pos[turnplayer]) ;
                            }
                        }
                    }
                    (*P).isUdahRoll[turnplayer] = true ;
                    printf("\n") ;
                }
                else {
                    printf("Tidak dapat melakukan roll 2 kali dalam 1 turn.\n\n") ;
                }
                if ((*P).pos[turnplayer] == (*Map).PanjangMap) {
                    endthisturn = true ;
                    printf("%s telah mencapai ujung.\n", (*P).uName[turnplayer]) ;
                    printf("Pemenang game ini adalah %s.\n\n", (*P).uName[turnplayer]) ;
                    endgame = true ;
                }
                break ;

            // SAVE
            case 6 :
                printf("save\n") ;
                break ;

            // ENDTURN
            case 7 :
                if ((*P).isUdahRoll[turnplayer]) {
                    endthisturn = true ;
                    printf("\n") ;
                }
                else {
                    printf("Belum bisa endturn sebelum melakukan roll.\n\n") ;
                }
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
