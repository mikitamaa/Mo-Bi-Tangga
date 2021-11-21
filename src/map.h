#ifndef __MAP_H__
#define __MAP_H__

#include "mesin_kar.h"
#include "mesin_kata.h"
#include <stdio.h>

typedef struct {
    int Alamat ;
    char IsiPetak ;
    int Teleporter ;
} PETAK;

typedef struct {
    int PanjangMap ;
    int MaxRoll ;
    int JumlahTeleporter ;
    PETAK TabMap[100 + 1] ;
} MAP;

int ArrayOfCharToInt (Kata CKata, int *result) ;
/* 
Fungsi untuk membaca Array of Character dari mesin karakter
dan mengubahnya menjadi type integer
*/
void KonfigurasiToMap (MAP *Map) ;
/*
I.S Konfigurasi yang sudah terdefinisi
F.S Seluruh konfigurasi game dipindahkan ke MAP
    (PanjangMap, MaxRoll, JumlahTeleporter,)
*/
#endif
