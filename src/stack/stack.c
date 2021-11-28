#include "../stack/stack.h"
#include <stdio.h>


// Membuat sebuah stack S kosong.
// I.S. sembarang. 
// F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl 
//      jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai.
void CreateEmptyStack (Stack * S) {
   Top(*S) = NilStack;
}

// Mengirim true jika Stack kosong.
boolean IsEmpty (Stack S) {
    return (Top(S) == NilStack);
}

// Mengirim true jika tabel penampung nilai elemen stack penuh.
boolean IsFull (Stack S) {
    return (Top(S) == MaxEl);
}

// Menambahkan P sebagai elemen Stack S. 
// I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh.
// F.S. X menjadi TOP yang baru,TOP bertambah 1.
void Push (Stack * S, Player * P) {

    // Jika stack S tidak kosong, maka address TOP akan bertambah 1.
    if (!IsEmpty(*S)) {
        Top(*S)++ ;
    }

    // Jika stack S kosong, address TOP akan menjadi 1.
    else {
        Top(*S) = 1 ;
    }

    // Top dari stack S akan mengandung data Player P.
    InfoTop(*S) = *P ;

    // Karena Skills berbentuk list linear dan Player P hanya menyimpan address skill pertama, 
    // maka perlu dibuat sebuah list baru untuk menyimpan datanya.
    // Jika tidak dibuat sebuah list baru, list akan terus berubah dan data tidak akan tersimpan dengan baik.
    for (int i = 1; i <= (*P).Neff; i++) {
        (*S).P[Top(*S)].skills[i] = Nil ;
        copySkill((*P).skills[i], &(*S).P[Top(*S)].skills[i]) ;
    }
}

// Menghapus X dari Stack S. 
// I.S. S mungkin kosong.
// F.S. P adalah nilai elemen TOP yang lama, TOP berkurang 1.
void Pop (Stack * S, Player * P, boolean *PopBerhasil) {

    // Jika Stack S tidak kosong, P akan di-assign dengan data Player dari TOP Stack.
    // Address TOP akan berkurang 1 dan boolean PopBerhasil menunjukan bahwa Pop berhasil dilakukan.
    if (!IsEmpty(*S)){
        *P = InfoTop(*S);
        Top(*S)--;
        *PopBerhasil = true ;

    // Jika Stack S kosong, Stack tidak akan melakukan Pop dan menuliskan sebuah pesan.
    } else{
        printf("Tidak dapat undo permainan.\n");
        *PopBerhasil = false ;
    }
}
