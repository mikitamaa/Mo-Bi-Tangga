#include "../command/command.h"
#include "../map/map.h"
#include "../roll/roll.h"
#include "../player/player.h"
#include "../skill/skill.h"
#include "../stack/stack.h"
#include <stdio.h>
#include <string.h>

// Merupakan jantung dari permainan MobiTangga, menerima input user dan mengolah informasi dari permainan.
// I.S. State permainan MobiTangga sembarang.
// F.S. State permainan MobiTangga setelah giliran seorang pemain.
void command(MAP *Map, Player *P, Stack *Stack, int turnplayer, boolean *endgame, boolean *endronde, int *jumlahronde) {
    int i, hasilcommand ;

    // Diinisialisasi sebuah boolean. Selama belum akhir giliran command akan terus berjalan.
    boolean endthisturn = false ;
    while (!endthisturn) {
        hasilcommand = 0 ;

        // Meminta input user untuk membaca command.
        printf("Masukkan command: ") ;
        STARTKATACOMMAND() ;

        // Command akan mengecek command input user, dan menentukan command yang dimaksud.
        boolean valid ;

        // Jika input user = "SKILL", maka command akan membaca command skill.
        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != skill[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 1 ;
        }

        // Jika input user = "MAP", maka command akan membaca command map.
        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != map[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 2 ;
        }

        // Jika input user = "BUFF", maka command akan membaca command buff.
        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != buff[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 3 ;
        }

        // Jika input user = "INSPECT", maka command akan membaca command inspect.
        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != inspect[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 4 ;
        }

        // Jika input user = "ROLL", maka command akan membaca command roll.
        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != roll[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 5 ;
        }

        // Jika input user = "SAVE", maka command akan membaca command save.
        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != save[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 6 ;
        }

        // Jika input user = "ENDTURN", maka command akan membaca command endturn.
        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != endturn[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 7 ;
        }

        // Jika input user = "UNDO", maka command akan membaca command undo.
        valid = true ;
        for (i = 0; i < CKata.Length; i++) {
            if (CKata.TabKata[i + 1] != undo[i]) {
                valid = false ;
            }
        }
        if (valid) {
            hasilcommand = 8 ;
        }

        // Command kemudian akan menentukan command apa yang sesuai dengan input user.
        switch(hasilcommand) {
            
            // Jika command merupakan "SKILL".
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
                                    discard(&skills(*P)[turnplayer], activate);
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
                                    discard(&skills(*P)[turnplayer], activate);
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

            // Jika command merupakan "MAP".    
            case 2 :

                // Dibuat sebuah looping untuk menuliskan posisi dari setiap pemain.
                for (int imap = 1; imap <= (*P).Neff; imap++) {

                    // Menuliskan nama pemain pada layar.
                    printf("%s", (*P).uName[imap]) ;
                    printf(" : ") ;

                    // Dibuat sebuah looping untuk menuliskan peta dari pemain, 
                    // dengan '*' menunjukkan posisi pemain pada peta.
                    for (int jmap = 1; jmap <= (*Map).PanjangMap; jmap++) {
                        if ((*P).pos[imap] == jmap) {
                            printf("*") ;
                        }

                        // Menuliskan isi petak jika bukan merupakan petak posisi pemain.
                        else {
                            printf("%c", (*Map).TabMap[jmap].IsiPetak) ;
                        }
                    }

                    // Menuliskan posisi pemain.
                    printf(" %d", (*P).pos[imap]) ;
                    printf("\n") ;
                }
                printf("\n") ;
                break ;

            // Jika command merupakan "BUFF".
            case 3 :

                // Dibuat sebuah looping untuk menuliskan buff dari setiap pemain.
                for (int ibuff = 1; ibuff <= (*P).Neff; ibuff++) {
                    printf("Buff yang dimiliki %s: \n", (*P).uName[ibuff]) ;

                    // Diinisialisasi sebuah boolean untuk kasus dimana seorang player tidak memiliki buff.
                    boolean adabuffaktif = false ;

                    // Jika pemain memiliki buff Imunitas Teleport.
                    if ((*P).isImmu[ibuff]) {
                        printf("- Immunitas Teleport\n") ;
                        adabuffaktif = true ;
                    }

                    // Jika pemain memiliki buff Cermin Pengganda.
                    if ((*P).isCermin[ibuff]) {
                        printf("- Cermin Pengganda\n") ;
                        adabuffaktif = true ;
                    }

                    // Jika pemain memiliki buff Senter Pembesar Hoki.
                    if ((*P).isSenPem[ibuff]) {
                        printf("- Senter Pembesar Hoki\n") ;
                        adabuffaktif = true ;
                    }

                    // Jika pemain memiliki buff Senter Pengecil Hoki.
                    if ((*P).isSenPeng[ibuff]) {
                        printf("- Senter Pengecil Hoki\n") ;
                        adabuffaktif = true ;
                    }

                    // Jika pemain tidak memiliki buff apapun.
                    if (!adabuffaktif) {
                        printf("-\n") ;
                    }
                    printf("\n") ;
                }
                break ;

            // Jika command merupakan "INSPECT".
            case 4 :

                // Menuliskan informasi dari sebuah petak sesuai permintaan pemain.
                printf("Masukkan petak: ") ;
                int petakcommand ;
                scanf("%d", &petakcommand) ;

                // Jika petak merupakan petak kosong atau '.', petak akan 
                // dicek apakah petak memiliki sebuah teleporter.
                if ((*Map).TabMap[petakcommand].IsiPetak == '.') {

                    // Jika petak kosong tidak memiliki sebuah teleporter.
                    if ((*Map).TabMap[petakcommand].Teleporter == -1) {
                        printf("Petak %d merupakan petak kosong.\n", petakcommand) ;
                    }

                    // Jika petak kosong memiliki sebuah teleporter.
                    else {
                        printf("Petak %d memiliki teleporter menuju %d.\n", petakcommand, (*Map).TabMap[petakcommand].Teleporter) ;
                    }
                }

                // Jika petak merupakan petak terlarang.
                else {
                    printf("Petak %d merupakan petak terlarang.\n", petakcommand) ;
                }
                printf("\n") ;
                break ;

            // Jika command merupakan "ROLL".
            case 5 : 

                // Pemain hanya dapat melakukan command roll bila belum melakukan roll pada turn ini.
                if (!(*P).isUdahRoll[turnplayer]) {

                    // Hasil roll akan didapatkan dari fungsi HasilRoll.
                    int roll = HasilRoll(*Map, *P, turnplayer) ;
                    printf("%s mendapatkan angka %d.\n", (*P).uName[turnplayer], roll) ;

                    // Menentukan 2 kemungkinan posisi setelah pemain melakukan roll.
                    int kemungkinan1 = (*P).pos[turnplayer] + roll ;
                    int kemungkinan2 = (*P).pos[turnplayer] - roll ;

                    // Diinisialisasi sebuah boolean untuk menentukan apakah pemain bergerak atau tidak.
                    boolean bergerak = false ; 

                    // Jika petak kemungkinan pertama dan petak kemungkinan kedua merupakan petak kosong
                    // dan tidak melewati batas bawah map, yaitu 1 dan batas atas map, yaitu panjang map.
                    if ((*Map).TabMap[kemungkinan1].IsiPetak == '.' && (*Map).TabMap[kemungkinan2].IsiPetak == '.' && kemungkinan1 <= (*Map).PanjangMap && kemungkinan2 >= 1) {
                        
                        // Karena pemain dapat bergerak boolean bergerak true.
                        bergerak = true ;

                        // Memberikan sebuah pilihan kepada pemain, ke petak mana mereka ingin bergerak.
                        printf("%s dapat maju dan mundur.\n", (*P).uName[turnplayer]) ;
                        printf("Ke mana %s mau bergerak:\n", (*P).uName[turnplayer]) ;
                        printf("   1. %d\n", kemungkinan2) ;
                        printf("   2. %d\n", kemungkinan1) ;

                        // Diinisialisasi sebuah boolean untuk menentukan apakah pilihan pemain valid atau tidak.
                        boolean pilihanrollvalid = false ;
                        int pilihanroll ;

                        // Selama pilihan pemain pemain tidak valid, akan dilakukan sebuah looping.
                        while (!pilihanrollvalid) {

                            // Meminta input pemain.
                            printf("Masukkan pilihan: ") ;
                            scanf("%d", &pilihanroll) ;

                            // Jika pemain memilih 1, maka pemain akan bergerak ke petak kemungkinan kedua.
                            if (pilihanroll == 1) {

                                // Karena pilihan roll pemain valid, maka pilihanrollvalid akan menjadi true.
                                pilihanrollvalid = true ;
                                (*P).pos[turnplayer] = kemungkinan2 ;
                                printf("%s mundur %d langkah.\n", (*P).uName[turnplayer], roll) ;
                                printf("%s berada di petak %d.\n", (*P).uName[turnplayer], (*P).pos[turnplayer]) ;
                            }

                            // Jika pemain memilih 2, maka pemain akan bergerak ke petak kemungkinan pertama.
                            else if (pilihanroll == 2) {

                                // Karena pilihan roll pemain valid, maka pilihanrollvalid akan menjadi true.
                                pilihanrollvalid = true ;
                                (*P).pos[turnplayer] = kemungkinan1 ;
                                printf("%s maju %d langkah.\n", (*P).uName[turnplayer], roll) ;
                                printf("%s berada di petak %d.\n", (*P).uName[turnplayer], (*P).pos[turnplayer]) ;
                            }

                            // Jika pilihan pemain tidak valid, akan dituliskan 
                            // sebuah pesan dan kembali ke dalam loop.
                            else {
                                printf("Pilihan roll harus 1 atau 2.\n\n") ;
                            }
                        }
                    }

                    // Jika petak kemungkinan pertama merupakan petak kosong 
                    // dan tidak melewati batas atas map, yaitu panjang map.
                    else if ((*Map).TabMap[kemungkinan1].IsiPetak == '.' && kemungkinan1 <= (*Map).PanjangMap) {
                        
                        // Karena pemain dapat bergerak boolean bergerak true.
                        bergerak = true ;

                        // Pemain akan bergerak ke petak kemungkinan pertama.
                        printf("%s dapat maju.\n", (*P).uName[turnplayer]) ;
                        (*P).pos[turnplayer] = kemungkinan1 ;
                        printf("%s maju %d langkah.\n", (*P).uName[turnplayer], roll) ;
                        printf("%s berada di petak %d.\n", (*P).uName[turnplayer], (*P).pos[turnplayer]) ;
                    }

                    // Jika petak kemungkinan kedua merupakan petak kosong 
                    // dan tidak melewati batas bawah map, yaitu panjang 1.
                    else if ((*Map).TabMap[kemungkinan2].IsiPetak == '.' && kemungkinan2 >= 1) {

                        // Karena pemain dapat bergerak boolean bergerak true.
                        bergerak = true ;

                        // Pemain akan bergerak ke petak kemungkinan kedua.
                        printf("%s dapat mundur.\n", (*P).uName[turnplayer]) ;
                        (*P).pos[turnplayer] = kemungkinan2 ;
                        printf("%s mundur %d langkah.\n", (*P).uName[turnplayer], roll) ;
                        printf("%s berada di petak %d.\n", (*P).uName[turnplayer], (*P).pos[turnplayer]) ;
                    }

                    // Jika petak kemungkinan pertama dan petak kemungkinan kedua merupakan petak terlarang
                    // atau petak kemungkinan pertama merupakan petak kosong, tetapi melewati batas atas map, 
                    // yaitu panjang map, atau petak kemungkinan kedua merupakan petak kosong, tetapi 
                    // melewati batas bawah map, yaitu 1.
                    else {
                        printf("%s tidak dapat bergerak.\n", (*P).uName[turnplayer]) ;
                    }

                    // Jika pemain bergerak pada gilirannya, akan dicek apakah 
                    // petak destinasi memiliki teleporter atau tidak.
                    if (bergerak) {

                        // Jika petak tidak memiliki teleporter (bernilai -1), pemain tidak akan teleport.
                        if ((*Map).TabMap[(*P).pos[turnplayer]].Teleporter == -1) {
                            printf("%s tidak menemukan teleporter.\n", (*P).uName[turnplayer]) ;
                        }

                        // Jika petak memiliki teleporter.
                        else {
                            printf("%s menemukan teleporter.\n", (*P).uName[turnplayer]) ;

                            // Jika pemain memiliki imunitas teleport, maka pemain akan diberikan 
                            // pilihan untuk teleport atau untuk tidak teleport.
                            if ((*P).isImmu[turnplayer]) {
                                printf("%s memiliki imunitas teleport.\n", (*P).uName[turnplayer]) ;
                                printf("Apakah %s ingin teleport (Y/N)? ", (*P).uName[turnplayer]) ;
                                
                                // Diinisialisasi sebuah boolean untuk menentukan apakah 
                                // pilihan teleport pemain valid atau tidak.
                                boolean pilihanteleportvalid = false ;
                                char pilihanteleport ;

                                // Selama pilihan teleport tidak valid, akan dilakukan sebuah looping.
                                while (!pilihanteleportvalid) {

                                    // Meminta input pemain.
                                    scanf("%c", &pilihanteleport) ;

                                    // Jika input pemain = 'Y', pemain akan bergerak 
                                    // ke posisi destinasi teleport.
                                    if (pilihanteleport == 'Y') {
                                        (*P).pos[turnplayer] = (*Map).TabMap[(*P).pos[turnplayer]].Teleporter ;
                                        printf("%s teleport ke petak %d.\n", (*P).uName[turnplayer], (*P).pos[turnplayer]) ;
                                    
                                        // Karena pilihan pemain valid, maka pilihanteleportvalid akan true.
                                        pilihanteleportvalid = true ;
                                        }

                                    // Jika input pemain = 'N', pemain tidak akan bergerak 
                                    // dan buff Imunitas Teleportnya akan habis.
                                    else if (pilihanteleport == 'N') {
                                        printf("%s tidak teleport.\n", (*P).uName[turnplayer]) ;
                                        (*P).isImmu[turnplayer] = false ;
                                        printf("Buff imunitas teleport hilang.\n") ;
                                        
                                        // Karena pilihan pemain valid, maka pilihanteleportvalid akan true.
                                        pilihanteleportvalid = true ;
                                    }

                                    // Jika pilihan pemain tidak valid, akan dituliskan 
                                    // sebuah pesan dan kembali ke dalam loop.
                                    else {
                                        printf("Pilihan teleport harus Y atau N.\n\n") ;
                                    }
                                }
                            }

                            // Jika pemain tidak memiliki Imunitas Teleport, 
                            // pemain akan bergerak ke posisi destinasi teleport. 
                            else {
                                printf("%s tidak memiliki imunitas teleport.\n", (*P).uName[turnplayer]) ;
                                (*P).pos[turnplayer] = (*Map).TabMap[(*P).pos[turnplayer]].Teleporter ;
                                printf("%s teleport ke petak %d.\n", (*P).uName[turnplayer], (*P).pos[turnplayer]) ;
                            }
                        }
                    }

                    // isUdahRoll menandakan bahwa pemain sudah melakukan roll pada turn ini.
                    (*P).isUdahRoll[turnplayer] = true ;
                    printf("\n") ;
                }

                // Jika pemain sudah melakukan roll pada turn ini, maka player tidak dapat melakukan roll lagi.
                else {
                    printf("Tidak dapat melakukan roll 2 kali dalam 1 turn.\n\n") ;
                }

                // Jika setelah melakukan roll, pemain berada pada petak terakhir, 
                // turn akan berakhir, ronde akan berakhir, dan game juga akan berakhir.
                if ((*P).pos[turnplayer] == (*Map).PanjangMap) {
                    endthisturn = true ;
                    printf("%s telah mencapai ujung.\n", (*P).uName[turnplayer]) ;
                    printf("Pemenang game ini adalah %s.\n", (*P).uName[turnplayer]) ;
                    *endgame = true ;
                    *endronde = true ;
                }
                break ;

            // Jika command merupakan "SAVE".
            case 6 :

                // Hanya menuliskan pesan karena kita tidak membuat command save :D
                printf("Gabisa save game hehe :D\n\n") ;
                break ;

            // Jika command merupakan "ENDTURN".
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

                // Jika pemain sudah melakukan roll, pemain baru bisa melakukan endturn.
                if ((*P).isUdahRoll[turnplayer]) {
                    endthisturn = true ;

                    // Seluruh buff pada player akan di-reset, kecuali Imunitas Teleport.
                    (*P).isCermin[turnplayer] = false ;
                    (*P).isSenPem[turnplayer] = false ;
                    (*P).isSenPeng[turnplayer] = false ;
                    printf("\n") ;
                }

                // Jika pemain belum melakukan roll, endturn tidak akan dieksekusi.
                else {
                    printf("Belum bisa endturn sebelum melakukan roll.\n\n") ;
                }
                break ;

            // Jika command merupakan "UNDO".
            case 8 :

                // Turn dan ronde akan berakhir ketika pemain melakukan 
                // undo dan kembali ke akhir turn sebelumnya.
                endthisturn = true ;
                *endronde = true ;

                // Diinisialisasi sebuah boolean untuk menentukan apakah undo dapat dilakukan atau tidak.
                boolean undovalid = true ;

                // Diinisialisasi sebuah boolean untuk menentukan apakah undo berhasil dilakukan atau tidak.
                boolean PopBerhasil ;
                char undo ;

                // Jumlah ronde akan berkurang karena permainan akan kembali ke akhir ronde sebelumnya.
                (*jumlahronde)-- ;

                // Permainan akan me-load state dari akhir ronde sebelumnya.
                Pop(Stack, P, &PopBerhasil) ;

                // Jika undo berhasil digunakan.
                if (PopBerhasil) {
                    printf("Command Undo berhasil digunakan.\n") ;

                    // Jika permainan sudah berada pada state awal permainan, tidak dapat melakukan undo lagi.
                    if (*jumlahronde == 0) {
                        printf("State permainan akan kembali ke awal permainan.\n\n") ;
                        PopBerhasil = false ;
                    }

                    // Jika permainan belum berada pada state awal permainan, undo dapat dilakukan lagi.
                    else {
                        printf("State permainan akan kembali ke akhir ronde %d.\n\n", *jumlahronde) ;
                    }
                }

                // Jika undo gagal dilakukan.
                else {
                    printf("Undo gagal.\n\n") ;
                }

                // Selama masih dapat melakukan undo dan undo berhasil, akan dilakukan sebuah looping.
                while (undovalid && PopBerhasil) {

                    // Pemain akan diberi pilihan untuk melakukan undo lagi.
                    printf("Apakah ingin melakukan undo lagi? (Y/N): ") ;
                    scanf(" %c", &undo) ;

                    // Jika input pemain = 'Y', akan dilakukan undo lagi.
                    if (undo == 'Y') {

                        // Jika undo berhasil dilakukan.
                        Pop(Stack, P, &PopBerhasil) ;
                        if (PopBerhasil) {

                            // Jumlah ronde akan berkurang karena permainan 
                            // akan kembali ke akhir ronde sebelumnya. 
                            (*jumlahronde)-- ;
                            printf("Command Undo berhasil digunakan.\n") ;

                            // Jika permainan sudah berada pada state awal permainan, 
                            // tidak dapat melakukan undo lagi.
                            if (*jumlahronde == 0) {
                                printf("State permainan akan kembali ke awal permainan.\n\n") ;
                                PopBerhasil = false ;
                            }

                            // Jika permainan belum berada pada state awal permainan, undo dapat dilakukan lagi. 
                            else {
                                printf("State permainan akan kembali ke akhir ronde %d.\n\n", *jumlahronde) ;
                            }       
                        }

                        // Jika undo gagal dilakukan.
                        else {
                            printf("Undo gagal.\n\n") ;
                        }
                    }

                    // Jika input pemain = 'N', tidak akan dilakukan undo lagi.
                    else if (undo == 'N') {
                        undovalid = false ;
                        printf("\n") ;
                    }

                    // Jika pilihan pemain tidak valid, akan dituliskan  sebuah pesan dan kembali ke dalam loop. 
                    else {
                        printf("Pilihan undo harus Y atau N.\n\n") ;
                    }
                }
                break ;

            // Jika input user salah, command tidak membaca command apapun dan mengirimkan pesan.
            default :
                printf("\nInvalid\n\n") ;
        }
    }
}

// Menerima input user untuk main menu dan menentukan langkah permainan selanjutnya.
// I.S. Welcoming menu MobiTangga.
// F.S. State permainan tergantung command pemain, antara new game atau exit.
void maincommand(boolean *endgame) {
    int i, hasilcommand ;
    boolean endthisturn = false ;

    hasilcommand = 0 ;
    
    // Meminta input user untuk membaca command.
    printf("Masukkan command: ") ;
    STARTKATACOMMAND() ;

    // Command akan mengecek command input user, dan menentukan command yang dimaksud.
    boolean valid ;

    // Jika input user = "NEW GAME", maka command akan membaca command new game.
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

    // Jika input user = "EXIT", maka command akan membaca command exit.
    valid = true ;
    for (i = 0; i < CKata.Length; i++) {
        if (CKata.TabKata[i + 1] != exitgame[i]) {
            valid = false ;
        }
    }
    if (valid) {
        hasilcommand = 2 ;
    }

    // Jika input user = "LOAD GAME", maka command akan membaca command load game.
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
        
        // Jika command merupakan "NEW GAME".
        case 1 : ;
            printf("\n") ;

            // Permainan tidak akan di-set ke akhir permainan.
            *endgame = false ;
            break ;

        // Jika command merupakan "EXIT".   
        case 2 : ;
            printf("\n") ;

            // Permainan akan di-set ke akhir permainan.
            *endgame = true ;
            break ;

        // Jika command merupakan "LOAD GAME".
        case 3 : ;

            // Hanya menuliskan pesan karena kita tidak membuat command load game :D
            printf("\nGabisa load game hehe :D\n\n") ;
            *endgame = false ;
            break ;

        // Jika input user salah, command tidak membaca command apapun, mengirimkan pesan, 
        // dan permainan akan di-set ke akhir permainan.
        default :
            printf("\nInvalid\n\n") ;
            *endgame = false ;
    }
}
