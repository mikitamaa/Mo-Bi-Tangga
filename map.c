#include "map.h"
#include "mesin_kar.h"
#include "mesin_kata.h"

int ArrayOfCharToInt (Kata CKata, int *result) {
    int i, temp, multiplier ;
    temp = CKata.Length ;
    multiplier = 10 ;
    *result = ((int) CKata.TabKata[temp] - 48) ;
    for (i = temp - 1; i > 0; i--) {
        *result += ((int) CKata.TabKata[i] - 48) * multiplier ;
        multiplier = multiplier * 10 ;
    }
}

void KonfigurasiToMap (MAP *Map) {
    int t ;
    STARTKATA() ;
    ArrayOfCharToInt(CKata, &t) ;
    (*Map).PanjangMap = t ;

    IgnoreBlank() ;
    for (int i = 1; i <= (*Map).PanjangMap; i++) {
        (*Map).TabMap[i].Alamat = i ;
        (*Map).TabMap[i].IsiPetak = CC ;
        ADV() ;
    }

    ADVKATA() ;
    ArrayOfCharToInt(CKata, &t) ;
    (*Map).MaxRoll = t ;

    ADVKATA() ;
    ArrayOfCharToInt(CKata, &t) ;
    (*Map).JumlahTeleporter = t ;

    for (int k = 1; k <= (*Map).JumlahTeleporter; k++) {
        (*Map).TabMap[k].Teleporter = -1 ;
    }

    int Lokasi, Tujuan ;
    for (int j = 1; j <= (*Map).JumlahTeleporter; j++) {
        ADVKATA() ;
        ArrayOfCharToInt(CKata, &Lokasi) ;
        ADVKATA() ;
        ArrayOfCharToInt(CKata, &Tujuan) ;
        (*Map).TabMap[Lokasi].Teleporter = Tujuan ;
    }
}