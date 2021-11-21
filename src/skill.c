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
        Next(last) = S;
    }
    
}


address Search (lSkill *ls, int skillOrder) {
/* Mencari apakah ada elemen list dengan urutan = skillOrder pada ls */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    boolean found;
    found = false;
    address p = *ls;
    int order = 1;
    while ((!found) && (p != Nil))
    {
        if (order == skillOrder)
        {
            found = true;
        }
        else
        {
            p = Next(p);
            order += 1;
        }
    }

    return p;
    
}


void discard(lSkill *lS, int skillOrder){
    int order = 1;
    address P = *lS;
    if (skillOrder == 1)
    {
        if (Next(P) == Nil)
        {
            lS = Nil;
        } else
        {
            *lS = Next(P);
        }
    } else
    {
        address Prec = *lS;
        P = Search(lS, skillOrder);
        while (Next(Prec) != P)
        {
            Prec = Next(Prec);
        }
        Next(Prec) = Next(P);
        
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
        draw(P, currentPlayer);
        draw(P, currentPlayer);
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

void senterPembesarHoki(Player *P, int currentPlayer){
/* Pada giliran ini, dadu akan menghasilkan angka antara floor(MaxRoll/2) dan MaxRoll. */
/* Tidak dapat digunakan berulang kali atau bersamaan dengan senter lain. */
    isSenPem(*P)[currentPlayer] = true;
}

void senterPengecilHoki(Player *P, int currentPlayer){
/* Pada giliran ini, dadu akan menghasilkan angka antara 1 dan floor(MaxRoll/2). */
/* Tidak dapat digunakan berulang kali atau bersamaan dengan senter lain. */
    isSenPeng(*P)[currentPlayer] = true;
}
