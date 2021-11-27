#include "../command/command.h"
#include "../command/command.c"
#include "../map/map.h"
#include "../map/map.c"
#include "../roll/roll.h"
#include "../roll/roll.c"
#include "../player/player.h"
#include "../player/player.c"
#include "../skill/skill.h"
#include "../skill/skill.c"
#include "../stack/stack.h"
#include "../stack/stack.c"
#include "../mesin_kar/mesin_kar.h"
#include "../mesin_kar/mesin_kar.c"
#include "../mesin_kata/mesin_kata.h"
#include "../mesin_kata/mesin_kata.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    printf("\n");
    printf("oooooo   oooooo     oooo oooooooooooo ooooo          .oooooo.     .oooooo.   ooo        ooooo oooooooooooo              ooooooooooooo   .oooooo.              \n");
    printf(" `888.    `888.     .8'  `888'     `8 `888'         d8P'  `Y8b   d8P'  `Y8b  `88.       .888' `888'     `8              8'   888   `8  d8P'  `Y8b             \n");
    printf("  `888.   .8888.   .8'    888          888         888          888      888  888b     d'888   888                           888      888      888            \n");
    printf("   `888  .8'`888. .8'     888oooo8     888         888          888      888  8 Y88. .P  888   888oooo8                      888      888      888            \n");
    printf("    `888.8'  `888.8'      888    .     888         888          888      888  8  .888.   888   888    .                      888      888      888            \n");
    printf("     `888'    `888'       888       o  888       o `88b    ooo  `88b    d88'  8    Y     888   888       o                   888      `88b    d88'            \n");
    printf("      `8'      `8'       o888ooooood8 o888ooooood8  `Y8bood8P'   `Y8bood8P'  o8o        o888o o888ooooood8                  o888o      `Y8bood8P'             \n");
    printf("                                                                                                                                                              \n");
    printf("ooo        ooooo   .oooooo.           oooooooooo.  ooooo         ooooooooooooo       .o.       ooooo      ooo   .oooooo.      .oooooo.          .o.       .o. \n");
    printf("`88.       .888'  d8P'  `Y8b          `888'   `Y8b `888'         8'   888   `8      .888.      `888b.     `8'  d8P'  `Y8b    d8P'  `Y8b        .888.      888 \n");
    printf(" 888b     d'888  888      888          888     888  888               888          .8.888.      8 `88b.    8  888           888               .8.888.     888 \n");
    printf(" 8 Y88. .P  888  888      888          888oooo888'  888               888         .8' `888.     8   `88b.  8  888           888              .8' `888.    Y8P \n");
    printf(" 8  `888'   888  888      888 8888888  888    `88b  888  8888888      888        .88ooo8888.    8     `88b.8  888     ooooo 888     ooooo   .88ooo8888.   `8' \n");
    printf(" 8    Y     888  `88b    d88'          888    .88P  888               888       .8'     `888.   8       `888  `88.    .88'  `88.    .88'   .8'     `888.  .o. \n");
    printf("o8o        o888o  `Y8bood8P'          o888bood8P'  o888o             o888o     o88o     o8888o o8o        `8   `Y8bood8P'    `Y8bood8P'   o88o     o8888o Y8P \n");
    printf("\n");
    printf("                                                                                          \n");
    printf("                                     :::---------------:::                                \n");
    printf("                                :-===========================--:                          \n");
    printf("                            :-====================================-:                      \n");
    printf("                        :-===========================================-:                   \n");
    printf("                     :-===================--:::-========-::::-===========:                \n");
    printf("                   :===================-:        :==++=:       :===========-              \n");
    printf("                 -====================:            =++           :===========-            \n");
    printf("               -=====================              :*=            :============-          \n");
    printf("              =====================+:    :::--:    :==    :::::::  +=============-        \n");
    printf("            -====================--=::::::::-++-::::=+-::+#*::::---+=-=============       \n");
    printf("           ==================-:    ---::::::::::::-=+*-:::::     ::=:   :--=========:     \n");
    printf("          -===============-         =          ::::-==--:::       :=:       :=++=====                  +++++++++++++++++++++++++++++++++++++++++++ \n");
    printf("         -============+=-::::    :::-=:         :-=+++*+=::      -=:   ::::::: :-=====                -+-----------------------------------------+ \n");
    printf("         =============:      ::--==------::::--==*#=: =***+=----=---==-:          ====-              -++-                                       -+ \n");
    printf("        ============:          ::::::::  :::::  -#**==*****:    ::::               :===              +++-           Masukkan Command :          -+ \n");
    printf("        ===========                             :********#+                         :==-            -+++-       - NEW GAME                      -+ \n");
    printf("       :========++-:::::::::::::::::             :+**#*#*=            :::::-::-::::::-==            ++++-       - EXIT                          -+ \n");
    printf("       :=========                                  ::=-:         ::::::               +=           -++++-       - LOAD GAME                     -+ \n");
    printf("        =======+:                                    -                                -+          -+++++-                                       -+ \n");
    printf("        =======+                                     -                                -+         -++++++-----------------------------------------+ \n");
    printf("        =======-          ::::::::::                 -             :::::::::::::::    =*        -+++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    printf("        -======-   :::::::                           -                           :::::+=       -++++-                                              \n");
    printf("         =======:::    :                             -                  ::::-         *:      -+-                                                  \n");
    printf("         -=====-       :::                           -                 :     =       -=      -                                                     \n");
    printf("          -====+          :::                        -                       =       =    \n");
    printf("           =====-            ::::                    -                     :-:      -     \n");
    printf("            =====                :::::               -                  ::::       :      \n");
    printf("             -====                    ::::::         -             ::::::        :        \n");
    printf("              :====:                        :::::::::-::::::::::::::            .         \n");
    printf("                -===:                                                         .           \n");
    printf("                  ===-                                                      .             \n");
    printf("                   -===:                                                  .               \n");
    printf("                   +****+-                                             :.                 \n");
    printf("\n");

    // Program akan menampilkan main menu.
    // Jika pemain memilih exit atau load game, program akan dihentikan (endgame = true).
    boolean endgame = false ;
    maincommand(&endgame) ;

    // Jika tidak endgame maka permainan akan dimulai.
    if (!endgame) {

        // Dibuat sebuah looping untuk memastikan input user
        // untuk jumlah player tepat, yaitu 2 sampai 4 pemain.
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

        // Diinisialisasi sebuah ADT Player P.
        Player P ;
        // Membuat list Player dengan jumlah player sebanyak input user.
        createEmptyPlayerList(&P) ;
        addPlayer(&P, jumlahpemain) ;

        printf("\n") ;

        // Diinisialisasi sebuah ADT MAP Map.
        MAP Map ;
        // File konfigurasi dibaca dan seluruh informasi akan disimpan pada Map. 
        KonfigurasiToMap(&Map) ;

        // Diinisialisasi sebuah ADT Stack Stack.
        Stack Stack ;
        // Membuat sebuah stack kosong.
        CreateEmptyStack(&Stack) ;


        // Diinisialisasi sebuah variabel untuk menghitung ronde dari game.
        boolean endronde = false ;
        int jumlahronde = 1 ;

        // State permainan paling awal sebelum ada player yang melakukan aksi apapun akan disimpan.
        Push(&Stack, &P) ;

        // Dibuat sebuah looping untuk setiap ronde baru pada permainan hingga permainan selesai.
        while (!endgame) {
            int i = 1;
            endronde = false ;
            printf("-- Ronde ke-%d --\n\n", jumlahronde) ;

            // Setiap player mendapatkan turn pada sebuah ronde.
            while (!endronde && i <= jumlahpemain) {
                printf("-- Giliran %s --\n\n", P.uName[i]) ;

                // Setiap player akan mendapatkan sebuah skill acak pada awal mula gilirannya.
                draw(&P, i, 0) ;

                // Menuliskan Map dan posisi setiap pemain setiap awal giliran sebuah pemain. 
                for (int imap = 1; imap <= P.Neff; imap++) {
                        printf("%s\t", P.uName[imap]) ;
                        printf(" : ") ;

                        // Petak posisi pemain akan ditandai dengan '*'.
                        for (int jmap = 1; jmap <= Map.PanjangMap; jmap++) {
                            if (P.pos[imap] == jmap) {
                                printf("*") ;
                            }
                            else {
                                printf("%c", Map.TabMap[jmap].IsiPetak) ;
                            }
                        }

                        // Posisi pemain akan ditampilkan pada ujung map.
                        printf(" %d", P.pos[imap]) ;
                        printf("\n") ;
                    }
                printf("\n") ;

                // Setiap player akan melakukan command pada gilirannya.
                // Beberapa command memiliki restriction tertentu,
                // seperti endturn yang dapat dilakukan hanya setelah player melakukan roll,
                // atau roll yang hanya dapat dilakukan sekali setiap giliran pemain.
                command(&Map, &P, &Stack, i, &endgame, &endronde, &jumlahronde) ;
                i++ ;    
            }

            // Pada akhir ronde, seluruh pemain akan dinyatakan belum
            // melakukan roll untuk mempersiapkan ronde selanjutnya.
            for (i = 1; i <= P.Neff; i++) {
                P.isUdahRoll[i] = false ;
            }

            // jumlah ronde bertambah dan state dari permainan 
            // (state dari para pemain) akan disimpan pada stack.
            jumlahronde++ ;
            printf("\n") ;
            Push(&Stack, &P) ;
        }

        // Pada akhir permainan, peringkat dari seluruh pemain akan ditampilkan berdasarkan posisi.
        printf("-- Peringkat Pemain --\n") ;
        PeringkatPlayer(&P) ;
        printf("\n") ;
    }

    // Jika permainan tidak dilakukan, program akan menuliskan sebuah pesan dan menutup program. 
    else {
        printf("Sampai jumpa lagi.\n") ;
    }
}