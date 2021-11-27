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

    boolean endgame = false ;
    maincommand(&endgame) ;

    if (!endgame) {
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
        printf("-- Peringkat Pemain --\n") ;
        PeringkatPlayer(&P) ;
        printf("\n") ;
    }
    else {
        printf("Sampai jumpa lagi.\n") ;
    }
}