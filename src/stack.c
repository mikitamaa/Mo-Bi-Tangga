#include "stack.h"
#include <stdio.h>


/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
   Top(*S) = NilStack;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S) == NilStack);
}
boolean IsFull (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S) == MaxEl);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, Player * P)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    if (!IsEmpty(*S))
    {
        Top(*S)++;
    }
    else
    {
        Top(*S) = 1;
    }
    InfoTop(*S) = *P;
    for (int i = 1; i <= (*P).Neff; i++) {
        (*S).P[Top(*S)].skills[i] = Nil ;
        copySkill((*P).skills[i], &(*S).P[Top(*S)].skills[i]) ;
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, Player * P, boolean *PopBerhasil)
/* Menghapus X dari Stack S. */
/* I.S. S  mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    if (!IsEmpty(*S)){
        *P = InfoTop(*S);
        Top(*S)--;
        *PopBerhasil = true ;
    } else{
        printf("Tidak dapat undo permainan.\n");
        *PopBerhasil = false ;
    }

}
