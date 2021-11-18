#ifndef _PLAYER_H
#define _PLAYER_H
#include "boolean.h"
#include <stdlib.h>
#define Nil NULL

typedef int ElType;
#define IdxMax 4
#define IdxMin 1
#define IdxUndef -999

typedef struct listSkillNode *address;
typedef struct listSkillNode
{
    char Name[25];
    int Identifier;
    /* Setiap jenis skill memiliki identifier tersendiri. */
    address next;
} Skill;

typedef address lSkill;

/* Player menggunakan array */
typedef struct
{
    int Neff;
    char uname[IdxMax - IdxMin + 1][16];
    ElType pos[IdxMax - IdxMin + 1];
    boolean isTelep[IdxMax - IdxMin + 1];
    boolean isImmu[IdxMax - IdxMin + 1];
    lSkill Skills[IdxMax - IdxMin + 1];
} Player;

#define ADDR_HEADSKILL(p) (p).addrFirstSkill
#define NEXTSKILL(p) (p)->nextskill
#define SKILLNAME(p) (p)->skillName

void createEmptyPlayerList(Player *P);
/*
 I.S. array pU sembarang
 F.S. array pU kosong
*/
void summonPlayer(Player *P, int n);
/*
 Prosedur untuk membuat list pemain sebanyak n pemain
 I.S array pU, pT, pP, pI kosong
 F.S array pU, pT, pP, pI terisi informasi kondisi awal permainan sebanyak n
  pU.uname[ indexPlayer ] terisi inputan
*/
int getIdxOfPlayer(Player P, char *name);
/*
 Fungsi mereturn index player dalam array pU dengan username parameter input uname
 Jika tidak ditemukan player uname di dalam array pU, maka akan meretrun IdxUndef
*/
boolean isEmptyList(Skill pS);
/*
 Mereturn True jika pS kosong
*/
boolean getTeleportedConditionOfPlayer(Player P, char *uname);
/*
 Fungsi untuk mendapatkan informasi kondisi pemain dengan username uname, apakah
sebelumnya terkena portal (teleported) atau tidak
*/
boolean getImmunityConditionOfPlayer(Player P, char *uname);
/*
 Fungsi untuk mendapatkan informasi kondisi pemain dengan username uname, apakah
 Sedang imune terhadap efek apapun atau tidak
*/
int getPositionOfPlayer(Player P, char *uname);
/*
 Fungsi untuk mendapatkan informasi posisi terakhir dari pemain dengan username
 uname;
*/

#endif
