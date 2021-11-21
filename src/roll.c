#include "map.h"
#include "Player.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int HasilRoll(MAP Map, Player P, int i) {
    time_t t ;
    srand((unsigned) time(0)) ;
    
    int MaxRoll = Map.MaxRoll ;
    int MinRoll = 1 ;

    if (isSenPem(P)[i]) {
        return (rand() % (MaxRoll - (int)floor(MaxRoll/2) + 1) + (int)floor(MaxRoll/2)) ;
    }
    else if (isSenPeng(P)[i]) {
        return (rand() % (int)floor(MaxRoll/2) + 1) ;
    }
    else {
        return (rand() % MaxRoll + 1) ;
    }
}
