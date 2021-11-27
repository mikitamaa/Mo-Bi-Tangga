#include "../map/map.h"
#include "../player/player.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

// Fungsi yang menghasilkan hasil roll yang random.
int HasilRoll(MAP Map, Player P, int i) {

    // Karena hasil dari random berpola tergantung dari seednya,
    // maka digunakan time juga agar hasil yang didapatkan lebih random.
    time_t t ;
    srand((unsigned) time(0)) ;
    
    int MaxRoll = Map.MaxRoll ;
    int MinRoll = 1 ;

    // Jika Senter Pembesar Hoki aktif, hasil roll akan berada di interval 
    // floor(MaxRoll/2) sampai dengan MaxRoll (contoh : MaxRoll = 10, maka roll antara 5 sampai 10).
    if (isSenPem(P)[i]) {
        return (rand() % (MaxRoll - (int)floor(MaxRoll/2) + 1) + (int)floor(MaxRoll/2)) ;
    }

    // Jika Senter Pengecil Hoki aktif, hasil roll akan berada di interval 
    // 1 sampai dengan floor(MaxRoll/2) (contoh : MaxRoll = 10, maka roll antara 1 sampai 5).
    else if (isSenPeng(P)[i]) {
        return (rand() % (int)floor(MaxRoll/2) + 1) ;
    }

    // Jika tidak ada buff yang aktif, hasil roll akan berada di interval 1 sampai MaxRoll.
    else {
        return (rand() % MaxRoll + 1) ;
    }
}
