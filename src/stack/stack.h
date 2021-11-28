#ifndef stackt_H
#define stackt_H

#include "../boolean/boolean.h"
#include "../player/player.h"
#include "../skill/skill.h"

#define NilStack 0    // NilStack adalah stack dengan elemen kosong.
#define MaxEl 101

typedef int addressStack;     // Index Stack.

typedef struct {
    Player P[MaxEl];       // Tabel penyimpan elemen 
    addressStack TOP;      // Alamat TOP: elemen puncak 
} Stack;
// Definisi stack S kosong: S.TOP = NilStack

#define Top(S) (S).TOP
#define InfoTop(S) (S).P[(S).TOP]

// Membuat sebuah stack S kosong.
// I.S. sembarang. 
// F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl 
//      jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai.
void CreateEmptyStack (Stack * S) ;

// Mengirim true jika Stack kosong.
boolean IsEmpty (Stack S) ;

// Mengirim true jika tabel penampung nilai elemen stack penuh.
boolean IsFull (Stack S) ;

// Menambahkan P sebagai elemen Stack S. 
// I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh.
// F.S. X menjadi TOP yang baru,TOP bertambah 1.
void Push (Stack * S, Player * P) ;

// Menghapus X dari Stack S. 
// I.S. S mungkin kosong.
// F.S. P adalah nilai elemen TOP yang lama, TOP berkurang 1.
void Pop (Stack * S, Player * P, boolean *PopBerhasil) ;

#endif
