#include "Player.h"
#include "skill.h"

/* 
Identifier Skill
1 = Pintu Ga Ke Mana Mana
2 = Cermin Pengganda
3 = Senter Pembesar Hoki
4 = Senter Pengecil Hoki
5 = Mesin Penukar Posisi
6 = Teknologi Gagal
 */

boolean isEmptyList(Lskill *pS){
/*
 Mereturn True jika pS kosong
*/
    return (FirstSKILL(pS) == Nil);
}

Skill draw(){

}


void pintuGKM(pIsImune *I, int P){
/* Player mendapat buff imunitas dari teleporter */
/* tidak mendapat ekstra ketika diaktifkan berulang kali */
    if (I->isImun[P] != true)
    {
        I->isImun[P] = true;
    }
}


void cerminPengganda(Lskill *LS){
/* Menjalankan prosedur draw sebanyak 2 kali dan menambahkan skill yang didapat ke pemain */
    Skill S1, S2;
    S1 = draw();
    S2 = draw();
    insertVSkill(LS, S1);
    insertVSkill(LS, S2);
}


void mesinPenukarPosisi(pPosition *p, int pA, int pB){
/* Menukarkan posisi dua pemain pada map. */
/* tidak mengaktifkan teleporter. */
    ElType temp = &p->pos[pB];
    p->pos[pB] = p->pos[pA];
    p->pos[pA] = temp;
}


