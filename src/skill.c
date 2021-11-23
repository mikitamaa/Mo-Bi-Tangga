#include "Player.h"
#include "Player.c"
#include "skill.h"
#include <stdio.h>
#include <time.h>

/* 
Identifier Skill
0 = Undefined
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
// Menambahkan Skill dengan alamat S ke lSkill
    address last;

    if (*lS == Nil)
    {
        *lS = S;
    } else 
    {
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
        } else
        {
            p = Next(p);
            order += 1;
        }
    }

    return p;
    
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize ( int arr[], int n )
{
    // seed untuk randomizer
    srand ( time(NULL) );
 
    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = n-1; i > 0; i--)
    {
        // Mengenerate index secara random
        int j = rand() % (i+1);
 
        // Menukar arr[i] dengar elemen array dengan index random
        swap(&arr[i], &arr[j]);
    }
}

int randomSkill(){
    int arr[80];
    int freq[6] = {10, 6, 15, 15, 4, 30};
    int n = 0;
    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += freq[i-1];
        while (n<count)
        {
            arr[n] = i;
            n += 1;
        }
    }

    randomize(arr, 80);
    return(arr[rand()%80]);
}

void draw(Player *P, int currentPlayer){
// Menambahkan 1 Skill secara random ke lSkill Player yang sedang bermain di giliran ini.
    address S;
    S = newSkillNode();
    int identifier = randomSkill();
    Id(S) = identifier;
    constructSkill(S, Id(S));
    insertSkill(&skills(*P)[currentPlayer], S);
}

void discard(lSkill *lS, int skillOrder){
// Membuang Skill dengan nomor urut skillOrder dari lSkill suatu pemain.
    int order = 1;
    address P = *lS;
    if (skillOrder == 1)
    {
        if (Next(P) == Nil)
        {
            *lS = Nil;
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

void constructSkill(address S, int id){
    switch (id)
    {
    case 1:
        Id(S) = 1;
        Effect(S) = pintuGKM;
        break;
    case 2:
        Id(S) = 2;
        Effect(S) = cerminPengganda;
        break;
    case 3:
        Id(S) = 3;
        Effect(S) = senterPembesarHoki;
        break;
    case 4:
        Id(S) = 4;
        Effect(S) = senterPengecilHoki;
        break;
    case 5:
        Id(S) = 5;
        Effect(S) = mesinPenukarPosisi;
        break;
    case 6:
        Id(S) = 6;
        Effect(S) = Nil;
        break;
    default:
        break;
    }
}