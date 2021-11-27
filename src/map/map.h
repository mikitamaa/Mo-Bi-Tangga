#ifndef __MAP_H__
#define __MAP_H__

#include "../mesin_kar/mesin_kar.h"
#include "../mesin_kata/mesin_kata.h"
#include <stdio.h>

typedef struct {
    int Alamat ;                // Berupa urutan dari petak.
    char IsiPetak ;             // Berupa '.' atau '#'.
    int Teleporter ;            // Menyimpan -1 bila petak tidak memiliki teleporter dan menyimpan
                                // sebuah alamat hasil teleport bila petak memiliki teleporter.
} PETAK;

typedef struct {
    int PanjangMap ;            // Menyimpan panjang dari map.
    int MaxRoll ;               // Menyimpan roll max pada permainan.
    int JumlahTeleporter ;      // Menyimpan jumlah teleporter pada permainan.
    PETAK TabMap[100 + 1] ;     // Menyimpan data PETAK dari setiap petak.
} MAP;

// Fungsi untuk membaca Array of Character dari mesin karakter dan mengubahnya menjadi type integer.
int ArrayOfCharToInt (Kata CKata, int *result) ;

//  I.S Konfigurasi yang sudah terdefinisi.
//  F.S Seluruh konfigurasi game dipindahkan ke MAP 
//      (PanjangMap, MaxRoll, JumlahTeleporter, dan data setiap petak).
void KonfigurasiToMap (MAP *Map) ;

#endif