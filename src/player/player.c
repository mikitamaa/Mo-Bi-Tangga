#include "../player/player.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void createEmptyPlayerList(Player *P)
/*
 I.S. array P sembarang
 F.S. array P kosong
*/
{
    (*P).Neff = 0;
}

void addPlayer(Player *P, int n)
/*
 Prosedur untuk membuat list player sebanyak n pemain
 I.S array Player.uName, Player.pos, Player.isTelep,
    Player.isImmu, Player.skills kosong dan Neff berisi 0
 F.S array Player.uName, Player.pos, Player.isTelep, Player.isImmu, Player.skills sebanyak n
    terisi inputan dan Player.Neff menjadi n
*/
{
    for (int i = 1; i <= n; i++)
    {
        printf("Masukkan Username pemain %d: ", i);
        scanf("%s", (uName(*P)[i]));
        int j = 1;
        while (j <= n)
        {
            /* Melakukan komparasi string yang barusan diamsukkan dengan array of character di array Player.uName,
            apabila hasil komparasinya sama dan indeks j dan i berbeda, maka user diminta memasukkan username lain */
            if (strcmp(uName(*P)[i], uName(*P)[j]) == 0 && j != i)
            {
                printf("Username %s sudah digunakan player lain!\n", uName(*P)[i]);
                printf("Masukkan Username lain untuk pemain %d: ", i);
                scanf("%s", (uName(*P)[i]));
            }
            else
            {
                /* Apabila hasil komparasinya berbeda, dilanjutkan dengan mengecek array array of character di array Player.uName berikutnya */
                j++;
            }
        }
        /* Mengeset value default */
        pos(*P)[i] = 1;
        isTelep(*P)[i] = false;
        isImmu(*P)[i] = false;
        isSenPem(*P)[i] = false;
        isSenPeng(*P)[i] = false;
        isCermin(*P)[i] = false;
        isUdahRoll(*P)[i] = false;
        skills(*P)[i] = Nil;
    }
    /*Mengeset Neff dengan parameter n dimana n adalah jumlah pemain */
    Neff(*P) = n;
}

int getPlayerIdx(Player P, char *nameSearch)
/*
 Fungsi untuk mereturn index player dalam array uName dengan uName sebagai parameter input
 Apabila input tidak terdapat di list uName, maka akan mereturn IdxUndef
*/
{
    int i = IdxMin;
    int idxP = IdxUndef;
    while (i <= IdxMax)
    {
        /* Melakukan komparasi string input dengan array of character di array Player.uName */
        if (strcmp(nameSearch, P.uName[i]) != 0)
        {
            /* Apabila komparasi tersebut tidak sama, akan dilakukan increment indes i */
            i++;
        }
        else
        {
            idxP = i;
            break;
        }
    }
    return idxP;
}

boolean isPlayerTeleported(Player P, char *uName)
/*
 Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter
 mengenai apakah player tersebut terkena portal atau tidak
*/
{
    int idx = getPlayerIdx(P, uName);
    if (idx != IdxUndef)
    {
        return (isTelep(P)[idx]);
    }
}

boolean isPlayerImmune(Player P, char *uName)
/*
 Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter
 mengenai apakah player tersebut sedang imun atau tidak
*/
{
    int idx = getPlayerIdx(P, uName);
    if (idx != IdxUndef)
    {
        return (isImmu(P)[idx]);
    }
}

boolean isPlayerSenterPembesar(Player P, char *uName)
/*
 Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter
 mengenai apakah player tersebut memakai senter pembesar atau tidak
*/
{
    int idx = getPlayerIdx(P, uName);
    if (idx != IdxUndef)
    {
        return (isSenPem(P)[idx]);
    }
}

boolean isPlayerSenterPengecil(Player P, char *uName)
/*
 Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter
 mengenai apakah player tersebut memakai senter pengecil atau tidak
*/
{
    int idx = getPlayerIdx(P, uName);
    if (idx != IdxUndef)
    {
        return (isSenPeng(P)[idx]);
    }
}

boolean isPlayerCerminPengganda(Player P, char *uName)
/*
 Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter
 mengenai apakah player tersebut memakai cermin pengganda atau tidak
*/
{
    int idx = getPlayerIdx(P, uName);
    if (idx != IdxUndef)
    {
        return (isCermin(P)[idx]);
    }
}

int getPlayerPosition(Player P, char *uName)
/*
 Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter
 mengenai posisi player;
*/
{
    int idx = getPlayerIdx(P, uName);
    if (idx != IdxUndef)
    {
        return (pos(P)[idx]);
    }
}

void PeringkatPlayer(Player *P)
/*
 Prosedur untuk menuliskan peringkat player berdasarkan posisi
  I.S. array Player.pos dan Player.uName sembarang
  F.S. menuliskan peringkat player berdasarkan posisi
*/
{
    int temp1[(*P).Neff];
    int temp2[(*P).Neff];
    for (int i = 0; i < (*P).Neff; i++)
    {
        temp1[i] = (*P).pos[i + 1];
        temp2[i] = i + 1;
    }

    int tmp1, tmp2;
    for (int j = (*P).Neff - 1; j >= 0; j--)
    {
        for (int k = j; k >= 0; k--)
        {
            if (temp1[j] < temp1[k])
            {
                tmp1 = temp1[j];
                temp1[j] = temp1[k];
                temp1[k] = tmp1;

                tmp2 = temp2[j];
                temp2[j] = temp2[k];
                temp2[k] = tmp2;
            }
        }
    }

    for (int l = (*P).Neff - 1; l >= 0; l--)
    {
        printf("Peringkat %d: %s dengan posisi di petak ke-%d.\n", (*P).Neff - l, (*P).uName[temp2[l]], temp1[l]);
    }
}
