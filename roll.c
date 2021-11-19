#include "map.h"
#include "Player.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int HasilRoll(MAP Map, Player Player, int i) {
    time_t t ;
    srand((unsigned) time(0)) ;
    
    int MaxRoll = Map.MaxRoll ;
    int MinRoll = 1 ;

    if (Player.IsSenPem[i]) {
        return (rand() % (MaxRoll - floor(MaxRoll/2) + 1) + floor(MaxRoll/2)) ;
    }
    else if (Player.IsSenPeng[i]) {
        return (rand() % floor(MaxRoll/2) + 1) ;
    }
    else {
        return (rand() % MaxRoll + 1) ;
    }
}