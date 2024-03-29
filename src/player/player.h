#ifndef PLAYER_H
#define PLAYER_H

#include "../boolean/boolean.h"
#include <stdlib.h>

#define Nil NULL

typedef int ElType;
#define IdxMax 5
#define IdxMin 1
#define IdxUndef -999

typedef struct listSkillNode *address;
typedef address lSkill;

/* Membuat ADT Player Menggunakan Array */
typedef struct
{
    int Neff;
    char uName[IdxMax - IdxMin + 1][16];
    ElType pos[IdxMax - IdxMin + 1];
    boolean isTelep[IdxMax - IdxMin + 1];
    boolean isImmu[IdxMax - IdxMin + 1];
    boolean isSenPem[IdxMax - IdxMin + 1];
    boolean isSenPeng[IdxMax - IdxMin + 1];
    boolean isCermin[IdxMax - IdxMin + 1];
    boolean isUdahRoll[IdxMax - IdxMin + 1];
    lSkill skills[IdxMax - IdxMin + 1];
} Player;

typedef struct listSkillNode
{
    int Id;
    /* Setiap jenis skill memiliki identifier tersendiri. */
    int Target;
    address next;
    void (*effect)(Player *, int);
} Skill;

#define Id(P) (P)->Id
#define Target(P) (P)->Target
#define Next(P) (P)->next
#define Effect(P) (P)->effect

#define uName(P) (P).uName
#define pos(P) (P).pos
#define isTelep(P) (P).isTelep
#define isImmu(P) (P).isImmu
#define isSenPem(P) (P).isSenPem
#define isSenPeng(P) (P).isSenPeng
#define isCermin(P) (P).isCermin
#define isUdahRoll(P) (P).isUdahRoll
#define skills(P) (P).skills
#define Neff(P) (P).Neff

void createEmptyPlayerList(Player *P);
/*
 I.S. array P sembarang
 F.S. array P kosong
*/
void addPlayer(Player *P, int n);
/*
 Prosedur untuk membuat list player sebanyak n pemain
 I.S array Player.uName, Player.pos, Player.isTelep,
    Player.isImmu, Player.skills kosong dan Neff berisi 0
 F.S array Player.uName, Player.pos, Player.isTelep, Player.isImmu, Player.skills sebanyak n
    terisi inputan dan Neff menjadi n
*/
int getPlayerIdx(Player P, char *name);
/*
 Fungsi untuk mereturn index player dalam array uName dengan uName sebagai parameter input
 Apabila input tidak terdapat di list uName, maka akan mereturn IdxUndef
*/
boolean isPlayerTeleported(Player P, char *uName);
/*
 Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter
 mengenai apakah player tersebut terkena portal atau tidak
*/
boolean isPlayerImmune(Player P, char *uName);
/*
 Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter
 mengenai apakah player tersebut sedang imun atau tidak
*/
boolean isPlayerSenterPembesar(Player P, char *uName);
/*
 Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter
 mengenai apakah player tersebut memakai senter pembesar atau tidak
*/
boolean isPlayerSenterPengecil(Player P, char *uName);
/*
 Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter
 mengenai apakah player tersebut memakai senter pengecil atau tidak
*/
boolean isPlayerCerminPengganda(Player P, char *uName);
/*
 Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter
 mengenai apakah player tersebut memakai cermin pengganda atau tidak
*/
int getPlayerPosition(Player P, char *uName);
/*
 Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter
 mengenai posisi player;
*/

void PeringkatPlayer(Player *P);
/*
 Prosedur untuk menuliskan peringkat player berdasarkan posisi
  I.S. array Player.pos dan Player.uName sembarang
  F.S. menuliskan peringkat player berdasarkan posisi
*/
#endif
