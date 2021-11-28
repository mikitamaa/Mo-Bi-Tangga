#include "../command/command.h"
#include "../map/map.h"
#include "../roll/roll.h"
#include "../player/player.h"
#include "../skill/skill.h"
#include "../stack/stack.h"
#include <stdio.h>
#include <string.h>

void command(MAP *Map, Player *P, Stack *Stack, int turnplayer, boolean *endgame, boolean *endronde, int *jumlahronde) {
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
            case 1 : ;
                int activate = 99 ;
                if (!(*P).isUdahRoll[turnplayer]) {
                    while (activate != 0)
                    {
                        printf("\n") ;
                        if (isSkillEmpty(skills(*P)[turnplayer]))
                        {
                            printf("Kamu tidak memiliki Skill saat ini.\n");
                        }
                        else
                        {
                            printSkill(P, turnplayer);
                        }
                        printf("\n") ;
                        printf("Jika tidak ingin menggunakan skill masukkan 0.\n") ;
                        printf("Masukan skill yang ingin dipakai: ");
                        scanf("%d", &activate) ;
                        printf("\n") ;
                        if (activate != 0)
                        {
                            if (activate > jumlahSkill(skills(*P)[turnplayer]))
                            {
                                printf("Skill mu tidak sebanyak itu, Hey! Pakai yang ada!\n");
                            }
                            else if (activate>0 && activate <= jumlahSkill(skills(*P)[turnplayer]))
                            {
                                if (Id(Search(&P->skills[turnplayer], activate)) == 2)
                                {
                                    if (P->isCermin[turnplayer] == false)
                                    {
                                        printf("%s mengaktifkan ", uName(*P)[turnplayer]);
                                        printOneSkill(&skills(*P)[turnplayer], activate);
                                        Activate(P, &skills(*P)[turnplayer], activate, turnplayer);
                                    } else
                                    {
                                        printf("Kamu sudah memakai Cermin Pengganda turn ini.\n");
                                    }
                                } 
                                else if (Id(Search(&P->skills[turnplayer], activate)) == 3 || Id(Search(&P->skills[turnplayer], activate)) == 4)
                                {
                                    if (P->isSenPem[turnplayer] == false && P->isSenPeng[turnplayer] == false)
                                    {
                                        printf("%s mengaktifkan ", uName(*P)[turnplayer]);
                                        printOneSkill(&skills(*P)[turnplayer], activate);
                                        Activate(P, &skills(*P)[turnplayer], activate, turnplayer);
                                    } else
                                    {
                                        printf("Kamu sudah memakai Senter Pembesar atau Pengecil turn ini.\n");
                                    }
                                } 
                                else if (Id(Search(&P->skills[turnplayer], activate)) == 7)
                                {
                                    printf("%s mengaktifkan ", uName(*P)[turnplayer]);
                                    printOneSkill(&skills(*P)[turnplayer], activate);
                                    mesinWaktu(P, turnplayer, Map, Target(Search(&P->skills[turnplayer], activate)), endgame, endronde);
                                    if ((*P).pos[turnplayer] == (*Map).PanjangMap) {
                                        endthisturn = true ;
                                        printf("%s telah mencapai ujung.\n", (*P).uName[turnplayer]) ;
                                        printf("Pemenang game ini adalah %s.\n", (*P).uName[turnplayer]) ;
                                        *endgame = true ;
                                        *endronde = true ;
                                        break;
                                    }

                                }
                                else if (Id(Search(&P->skills[turnplayer], activate)) == 8)
                                {
                                    printf("%s mengaktifkan ", uName(*P)[turnplayer]);
                                    printOneSkill(&skills(*P)[turnplayer], activate);
                                    balingJambu(P, turnplayer, Map, Target(Search(&P->skills[turnplayer], activate)), endgame, endronde);
                                    if ((*P).pos[turnplayer] == (*Map).PanjangMap) {
                                        endthisturn = true ;
                                        printf("%s telah mencapai ujung.\n", (*P).uName[turnplayer]) ;
                                        printf("Pemenang game ini adalah %s.\n", (*P).uName[turnplayer]) ;
                                        *endgame = true ;
                                        *endronde = true ;
                                        break;
                                    }
                                }
                                else
                                {
                                    printf("%s mengaktifkan ", uName(*P)[turnplayer]);
                                    printOneSkill(&skills(*P)[turnplayer], activate);
                                    Activate(P, &skills(*P)[turnplayer], activate, turnplayer);
                                }
                            }
                            else if (activate<0 && -activate<= jumlahSkill(skills(*P)[turnplayer]))
                            {
                                printf("%s membuang ", uName(*P)[turnplayer]);
                                printOneSkill(&skills(*P)[turnplayer], activate);
                                discard(&skills(*P)[turnplayer], -activate);
                            }
                            else
                            {
                                printf("Input tidak valid!\n");
                            }
                        }
                    }
                }
                else {
                    printf("Tidak dapat melakukan command skill setelah roll.\n") ;
                }
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
                                    pilihanteleportvalid = true ;
                                    }
                                    else if (pilihanteleport == 'N') {
                                        printf("%s tidak teleport.\n", (*P).uName[turnplayer]) ;
                                        (*P).isImmu[turnplayer] = false ;
                                        printf("Buff imunitas teleport hilang.\n") ;
                                        pilihanteleportvalid = true ;
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
                    printf("Pemenang game ini adalah %s.\n", (*P).uName[turnplayer]) ;
                    *endgame = true ;
                    *endronde = true ;
                }
                break ;

            // SAVE
            case 6 :
                printf("Gabisa save game hehe :D\n\n") ;
                break ;

            // ENDTURN
            case 7 :
                if (jumlahSkill(skills(*P)[turnplayer]) > 10)
                {
                    int initSkillTotal = jumlahSkill(skills(*P)[turnplayer]);
                    for (int i = 0; i < initSkillTotal-10; i++)
                    {
                        int skillOrder;
                        printSkill(P, turnplayer);
                        printf("Skill kamu melebihi batas maksimal. Pilih Skill untuk dibuang: ");
                        scanf("%d", &skillOrder) ;
                        printf("\n") ;
                        if (skillOrder > 0)
                        {
                            if (skillOrder > jumlahSkill(skills(*P)[turnplayer]))
                            {
                                printf("Skill mu tidak sebanyak itu, Hey! Pakai yang ada!\n");
                            }
                            else
                            {
                                discard(&skills(*P)[turnplayer], skillOrder);;
                            }
                            
                        }
                        else
                        {
                            printf("Invalid!\n");
                        }
                        
                    }
                }
                if ((*P).isUdahRoll[turnplayer]) {
                    endthisturn = true ;
                    (*P).isCermin[turnplayer] = false ;
                    (*P).isSenPem[turnplayer] = false ;
                    (*P).isSenPeng[turnplayer] = false ;
                    printf("\n") ;
                }
                else {
                    printf("Belum bisa endturn sebelum melakukan roll.\n\n") ;
                }
                break ;

            // UNDO
            case 8 :
                endthisturn = true ;
                *endronde = true ;
                boolean undovalid = false ;
                boolean PopBerhasil ;
                char undo ;
                (*jumlahronde)-- ;
                Pop(Stack, P, &PopBerhasil) ;
                if (PopBerhasil) {
                    printf("Command Undo berhasil digunakan.\n") ;
                    if (*jumlahronde == 0) {
                        printf("State permainan akan kembali ke awal permainan.\n\n") ;
                        PopBerhasil = false ;
                    }
                    else {
                        printf("State permainan akan kembali ke akhir ronde %d.\n\n", *jumlahronde) ;
                    }
                }
                else {
                    printf("Undo gagal.\n\n") ;
                }
                while (!undovalid && PopBerhasil) {
                    printf("Apakah ingin melakukan undo lagi? (Y/N): ") ;
                    scanf(" %c", &undo) ;
                    if (undo == 'Y') {
                        Pop(Stack, P, &PopBerhasil) ;
                        if (PopBerhasil) {
                            (*jumlahronde)-- ;
                            printf("Command Undo berhasil digunakan.\n") ;
                            if (*jumlahronde == 0) {
                                printf("State permainan akan kembali ke awal permainan.\n\n") ;
                                PopBerhasil = false ;
                            }
                            else {
                                printf("State permainan akan kembali ke akhir ronde %d.\n\n", *jumlahronde) ;
                            }       
                        }
                        else {
                            printf("Undo gagal.\n\n") ;
                        }
                    }
                    else if (undo == 'N') {
                        undovalid = true ;
                        printf("\n") ;
                    }
                    else {
                        printf("Pilihan undo harus Y atau N.\n\n") ;
                    }
                }
                break ;

            // INPUT SALAH
            default :
                printf("\nInvalid\n\n") ;
        }
    }
}

void maincommand(boolean *endgame) {
    int i, hasilcommand ;
    boolean endthisturn = false ;

    hasilcommand = 0 ;
    printf("Masukkan command: ") ;
    STARTKATACOMMAND() ;

    boolean valid ;
    valid = true ;
    for (i = 0; i < CKata.Length; i++) {
        if (CKata.TabKata[i + 1] != newgame[i]) {
            valid = false ;
        }
    }
    if (valid) {
        ADVKATA() ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != newgame[i + 3]) {
                valid = false ;
            }
        }
    }
    if (valid) {
        hasilcommand = 1 ;
    }

    valid = true ;
    for (i = 0; i < CKata.Length; i++) {
        if (CKata.TabKata[i + 1] != exitgame[i]) {
            valid = false ;
        }
    }
    if (valid) {
        hasilcommand = 2 ;
    }

    valid = true ;
    for (i = 0; i < CKata.Length; i++) {
        if (CKata.TabKata[i + 1] != loadgame[i]) {
            valid = false ;
        }
    }
    if (valid) {
        ADVKATA() ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != loadgame[i + 4]) {
                valid = false ;
            }
        }
    }
    if (valid) {
        hasilcommand = 3 ;
    }

    switch(hasilcommand) {
        // NEW GAME
        case 1 : ;
            printf("\n") ;
            *endgame = false ;
            break ;

        // EXIT    
        case 2 : ;
            printf("\n") ;
            *endgame = true ;
            break ;

        // LOAD GAME
        case 3 : ;
            printf("\nLoad game tidak diimplementasikan :D\n\n") ;
            *endgame = false ;
            break ;

        // INPUT SALAH
        default :
            printf("\nInvalid\n\n") ;
            *endgame = false ;
    }
}