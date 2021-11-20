#include "Player.h"
#include "Player.c"
#include "skill.h"
#include <stdio.h>

/* 
Identifier Skill
1 = Pintu Ga Ke Mana Mana
2 = Cermin Pengganda
3 = Senter Pembesar Hoki
4 = Senter Pengecil Hoki
5 = Mesin Penukar Posisi
6 = Teknologi Gagal
 */

// ----------------------------------------------------------------------- Generic Purpose Use ----------------------------------------------------------------------------------- //
address newSkillNode(){
/*
 Fungsi mereturn sebuah address dari Skill (list skill node)
 Jika fungsi gagal mengalokasi Skill maka akan mereturn Nil
*/
    address S = (address)malloc(sizeof(Skill));
    if (S != Nil)
    {
        Id(S) = 0;
        Next(S) = Nil;

        return S;
    }
    else {
        return Nil;
    }
}


void CreateEmpty (lSkill *lS) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    *lS = Nil;
}


void insertSkill (lSkill *lS, address S){
    address last;

    if (*lS == Nil)
    {
        *lS = S;
        *lS = S;
    }

    else {
        last = *lS;
        while (Next(last) != Nil)
        {
            last = Next(last);
        }
        last = S;
        *lS = S;
    }
    
}


void draw(Player *P, int currentPlayer){
    address S;
    S = newSkillNode();
    Id(S) = 1;
    insertSkill(&skills(*P)[currentPlayer], S);
}


// ----------------------------------------------------------------------- Skill Effects ----------------------------------------------------------------------------------- //
void pintuGKM(Player *P, int currentPlayer){
/* Player mendapat buff imunitas dari teleporter */
/* tidak mendapat ekstra ketika diaktifkan berulang kali */
    if (isImmu(*P)[currentPlayer] == false)
    {
        isImmu(*P)[currentPlayer] = true;
    }
}


void cerminPengganda(Player *P, int currentPlayer){
/* Menjalankan prosedur draw sebanyak 2 kali dan menambahkan skill yang didapat ke pemain */
    if (!isCermin(*P)[currentPlayer])
    {
        draw(&P, currentPlayer);
        draw(&P, currentPlayer);
    } 
}


void mesinPenukarPosisi(Player *P, int currentPlayer){
/* Menukarkan posisi dua pemain pada map. */
/* tidak mengaktifkan teleporter. */
    ElType temp;
    int targetedPlayer;
    printf("Masukkan nomor player yang ingin ditarget: ");
    scanf("%d", &targetedPlayer);
    temp = pos(*P)[targetedPlayer];
    pos(*P)[targetedPlayer] = pos(*P)[currentPlayer];
    pos(*P)[currentPlayer] = temp;

}