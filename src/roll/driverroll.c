#include "../roll/roll.h"
#include "../roll/roll.c"
#include "../map/map.h"
#include "../map/map.c"
#include "../player/player.h"
#include "../player/player.c"
#include "../mesin_kar/mesin_kar.h"
#include "../mesin_kar/mesin_kar.c"
#include "../mesin_kata/mesin_kata.h"
#include "../mesin_kata/mesin_kata.c"
#include <stdio.h>

int main () {
    MAP Map ;
    Player P ;
    int i = 1 ;

    Map.MaxRoll = 10 ;
    printf("Hasil roll 1: %d\n", HasilRoll(Map, P, i)) ;
    printf("Hasil roll 2: %d\n\n", HasilRoll(Map, P, i)) ;
    // Hasil roll 1 dan roll 2 akan sama karena waktu eksekusi bersamaan.

    Map.MaxRoll = 20 ;
    P.isSenPem[i] = true ;
    P.isSenPeng[i] = false ;
    printf("Hasil roll 3: %d\n\n", HasilRoll(Map, P, i)) ;
    // Hasil roll 3 pasti diatas 10.

    P.isSenPem[i] = false ;
    P.isSenPeng[i] = true ;
    printf("Hasil roll 4: %d\n\n", HasilRoll(Map, P, i)) ;
    // Hasil roll 4 pasti dibawah 10.
}