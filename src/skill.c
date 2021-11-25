#include "Player.h"
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
boolean isSkillEmpty(lSkill lS){
    return (lS == Nil);
}

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

int jumlahSkill(lSkill lS){
    if (isSkillEmpty(lS))
    {
        return 0;
    } else
    {
        int count = 0;
        address P = lS;
        while (P != Nil)
        {
            count += 1;
            P = Next(P);
        }
        return count;
    }
    
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

int randomize(int X)
{
    // seed untuk randomizer
    srand ( time(NULL) );
    int arr[2];

    arr[0] = rand() % 80;
    arr[1] = rand() % 80;

    return arr[X];
}

int randomSkill(int X){
    if (X>=1 && X<=10)
    {
        return 1;
    } else if (X>10 && X<=16)
    {
        return 2;
    } else if (X>16 && X<=31)
    {
        return 3;
    } else if (X>31 && X<=46)
    {
        return 4;
    } else if (X>46 && X<=50)
    {
        return 5;
    } else
    {
        return 6;
    }
    
}

void draw(Player *P, int currentPlayer, int randomizer){
// Menambahkan 1 Skill secara random ke lSkill Player yang sedang bermain di giliran ini.
    address S;
    S = newSkillNode();
    int identifier = randomSkill(randomize(randomizer));
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

void Activate(Player *P, lSkill *lS, int skillOrder, int currentPlayer){
    int order = 1;
    address S = *lS;
    while (order < skillOrder)
    {
        S = Next(S);
        order += 1;
    }
    if (Effect(S) != Nil)
    {
        Effect(S)(P, currentPlayer);
    }
    discard(lS, skillOrder);
}

void printOneSkill(lSkill *lS, int skillOrder){
    address *S = lS;
    int count = 1;
    while (count<skillOrder)
    {
        *S = Next(*S);
        count += 1;
    }

    if (Id(*S) == 1)
    {
        printf("Pintu ga Kemana-mana\n");
    } else if (Id(*S) == 2)
    {
        printf("Cermin Pengganda\n");
    } else if (Id(*S) == 3)
    {
        printf("Senter Pembesar Hoki\n");
    }  else if (Id(*S) == 4)
    {
        printf("Senter Pengecil Hoki\n");
    }  else if (Id(*S) == 5)
    {
        printf("Mesin Penukar Posisi\n");
    }  else if (Id(*S) == 6)
    {
        printf("Teknologi Gagal\n");
    }
}

void printSkill(Player *P, int currentPlayer){
    address S = P->skills[currentPlayer];
    int count = 1;
    while (S != Nil)
    {
        if (Id(S) == 1)
        {
            printf("%d. Pintu ga Kemana-mana\n", count);
        } else if (Id(S) == 2)
        {
            printf("%d. Cermin Pengganda\n", count);
        } else if (Id(S) == 3)
        {
            printf("%d. Senter Pembesar Hoki\n", count);
        }  else if (Id(S) == 4)
        {
            printf("%d. Senter Pengecil Hoki\n", count);
        }  else if (Id(S) == 5)
        {
            printf("%d. Mesin Penukar Posisi\n", count);
        }  else if (Id(S) == 6)
        {
            printf("%d. Teknologi Gagal\n", count);
        }

        count += 1;
        S = Next(S);
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
        draw(P, currentPlayer, 0);
        draw(P, currentPlayer, 1);

        P->isCermin[currentPlayer] = true;
    }
}

void senterPembesarHoki(Player *P, int currentPlayer){
/* Pada giliran ini, dadu akan menghasilkan angka antara floor(MaxRoll/2) dan MaxRoll. */
/* Tidak dapat digunakan berulang kali atau bersamaan dengan senter lain. */
    P->isSenPem[currentPlayer] = true;
}

void senterPengecilHoki(Player *P, int currentPlayer){
/* Pada giliran ini, dadu akan menghasilkan angka antara 1 dan floor(MaxRoll/2). */
/* Tidak dapat digunakan berulang kali atau bersamaan dengan senter lain. */
    P->isSenPeng[currentPlayer] = true;
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

// ----------------------------------------------------------------------- External Purposes ----------------------------------------------------------------------------------- //
void copySkill(lSkill origin, lSkill *copy){
    lSkill O = origin;
    while (O != Nil)
    {
        address S;
        S = newSkillNode();
        constructSkill(S, Id(O));
        insertSkill(copy, S);
        O = Next(O);
    }
    
}
