#include "../map/map.h"
#include "../mesin_kar/mesin_kar.h"
#include "../mesin_kata/mesin_kata.h"

// Fungsi untuk membaca Array of Character dari mesin karakter dan mengubahnya menjadi type integer.
int ArrayOfCharToInt (Kata CKata, int *result) {
    int i, temp, multiplier ;

    // Panjang dari karakter akan disimpan.
    temp = CKata.Length ;

    // Dibuat sebuah multiplier 10^.
    multiplier = 10 ;

    // Karakter paling akhir akan diubah menjai sebuah integer berdasarkan ASCII table (48 = 0).
    *result = ((int) CKata.TabKata[temp] - 48) ;

    // Array of character akan diakses dari belakang karena karakter 
    // paling belakang merupakan satuan, kedua merupakan puluhan, dst.
    for (i = temp - 1; i > 0; i--) {
        *result += ((int) CKata.TabKata[i] - 48) * multiplier ;
        multiplier = multiplier * 10 ;
    }
}

//  I.S Konfigurasi yang sudah terdefinisi.
//  F.S Seluruh konfigurasi game dipindahkan ke MAP 
//      (PanjangMap, MaxRoll, JumlahTeleporter, dan data setiap petak).
void KonfigurasiToMap (MAP *Map) {
    int t ;

    // Prosedur diinisialisasi dengan file "konfigurasi.txt" sebagai dasar.
    STARTKATA() ;

    // Baris pertama pada konfigurasi dijamin merupakan panjang map. 
    // Informasi panjang map disimpan pada Map.
    ArrayOfCharToInt(CKata, &t) ;
    (*Map).PanjangMap = t ;

    // Informasi tersimpan pada baris selanjutnya pada file konfigurasi
    // sehingga program dapat mengabaikan newline. 
    IgnoreBlank() ;

    // Baris kedua pada konfigurasi dijamin merupakan map.
    // Informasi setiap petak yang berupa karakter akan disimpan pada Map.
    for (int i = 1; i <= (*Map).PanjangMap; i++) {
        (*Map).TabMap[i].Alamat = i ;           // Alamat berdasarkan urutan karakter.
        (*Map).TabMap[i].IsiPetak = CC ;        // IsiPetak berdasarkan karakter yang dibaca.
        (*Map).TabMap[i].Teleporter = -1 ;      // Teleporter pada dasarnya bernilai -1.
        ADV() ;
    }

    // Setelah selesai membaca map, program akan pindah ke informasi 
    // selanjutnya yang berada pada baris selanjutnya.
    ADVKATA() ;

    // Baris ketiga pada konfigurasi dijamin merupakan roll maksimum.
    ArrayOfCharToInt(CKata, &t) ;
    (*Map).MaxRoll = t ;

    // Setelah selesai membaca maxroll, program akan pindah ke informasi 
    // selanjutnya yang berada pada baris selanjutnya.
    ADVKATA() ;

    // Baris keempat pada konfigurasi dijamin merupakan jumlah teleporter. 
    ArrayOfCharToInt(CKata, &t) ;
    (*Map).JumlahTeleporter = t ;

    // Baris kelima dan selanjutnya pada konfigurasi dijamin 
    // merupakan alamat teleporter dan destinasi teleport.
    // Dibuat sebuah looping untuk membaca alamat dan destinasi 
    // dari setiap baris sebanyak jumlah teleporter.
    int Lokasi, Tujuan ;
    for (int j = 1; j <= (*Map).JumlahTeleporter; j++) {

        // Program akan membaca Kata selanjutnya dan menyimpan alamat dari teleporter.
        ADVKATA() ;
        ArrayOfCharToInt(CKata, &Lokasi) ;

        // Program akan membaca Kata selanjutnya dan menyimpan destinasi dari teleporter.
        ADVKATA() ;
        ArrayOfCharToInt(CKata, &Tujuan) ;

        // Data destinasi teleporter akan disimpan berdasarkan alamat teleporter.
        (*Map).TabMap[Lokasi].Teleporter = Tujuan ;
    }
}