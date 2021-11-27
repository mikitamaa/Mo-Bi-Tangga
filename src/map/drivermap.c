#include "../mesin_kar/mesin_kar.h"
#include "../mesin_kar/mesin_kar.c"
#include "../mesin_kata/mesin_kata.h"
#include "../mesin_kata/mesin_kata.c"
#include "../map/map.h"
#include "../map/map.c"
#include <stdio.h>

int main () {
    Kata Kata1 ;
    Kata1.Length = 1 ;
    Kata1.TabKata[1] = '5' ;        // Satuan 5
                                    // Total = 5

    Kata Kata2 ;
    Kata2.Length = 2 ;
    Kata2.TabKata[1] = '6' ;        // Puluhan 60
    Kata2.TabKata[2] = '9' ;        // Satuan 9
                                    // Total = 69

    Kata Kata3 ;
    Kata3.Length = 3 ;
    Kata3.TabKata[1] = '4' ;        // Ratusan 40
    Kata3.TabKata[2] = '2' ;        // Puluhan 20
    Kata3.TabKata[3] = '0' ;        // Satuan 0
                                    // Total = 420

    int result1, result2, result3 ;
    ArrayOfCharToInt(Kata1, &result1) ;
    ArrayOfCharToInt(Kata2, &result2) ;
    ArrayOfCharToInt(Kata3, &result3) ;

    printf("Hasil konversi Kata1 menjadi integer: %d\n", result1) ;
    printf("Hasil konversi Kata2 menjadi integer: %d\n", result2) ;
    printf("Hasil konversi Kata3 menjadi integer: %d\n", result3) ;


    MAP Map ;
    KonfigurasiToMap(&Map) ;        // File konfigurasi yang dibaca : "konfigurasi.txt"

    printf("\n") ;
    printf("Panjang Map: %d\n", Map.PanjangMap) ;
    printf("Max Roll: %d\n", Map.MaxRoll) ;
    printf("Jumlah Teleporter: %d\n\n", Map.JumlahTeleporter) ;

    // Membaca data petak 1 ;
    printf("Alamat: %d\n", Map.TabMap[1].Alamat) ;
    printf("Isi Petak: %c\n", Map.TabMap[1].IsiPetak) ;
    printf("Teleporter: %d\n\n", Map.TabMap[1].Teleporter) ;

    // Membaca data petak 4 ;
    printf("Alamat: %d\n", Map.TabMap[4].Alamat) ;
    printf("Isi Petak: %c\n", Map.TabMap[4].IsiPetak) ;
    printf("Teleporter: %d\n\n", Map.TabMap[4].Teleporter) ;
    
    // Membaca data petak 8 ;
    printf("Alamat: %d\n", Map.TabMap[8].Alamat) ;
    printf("Isi Petak: %c\n", Map.TabMap[8].IsiPetak) ;
    printf("Teleporter: %d\n\n", Map.TabMap[8].Teleporter) ;
}