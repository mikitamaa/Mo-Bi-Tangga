
#ifndef player_H
#define player_H

#include "boolean.h"
#include <stdlib.h>
#define Nil NULL

typedef int ElType;
#define IdxMax 4
#define IdxMin 1
#define IdxUndef -999


/* Player menggunakan array */
typedef struct
{
    char uname[IdxMax - IdxMin + 1][16];
    int Neff;
    ElType posisition;
    Lskill skillList;
    boolean isTeleported;
    boolean immunity;
} Player;

typedef struct
{
    address List[IdxMax - IdxMin + 1];
} LsPlayer;

typedef struct listSkillNode *address;
typedef struct listSkillNode
{
    char Name[25];
    int Identifier;
    /* Setiap jenis skill memiliki identifier tersendiri. */
    address next;
} Skill;

typedef struct
{
    address FirstSkill;
} Lskill;

#define uname(p) (p)->uname
#define Posisition(p) (p)->position
#define skillList(p) (p)->skillList
#define isTeleported(p) (p)->isTeleported
#define Immunity(p) (p)->immunity

#define NEXT(p) (p)->next
#define Identifier(p) (p)->Identifier
#define NAME(p) (p)->Name

#define FirstSKILL(p) (p)->FirstSkill


void createEmptyPlayerList(LsPlayer *pU);
/*
 I.S. array pU sembarang
 F.S. array pU kosong
*/

void summonPlayer(LsPlayer *pU, int n);
/*
 Prosedur untuk membuat list pemain sebanyak n pemain
 I.S array pU, pT, pP, pI kosong
 F.S array pU, pT, pP, pI terisi informasi kondisi awal permainan sebanyak n
  pU.uname[ indexPlayer ] terisi inputan
*/
int getIdxOfPlayer(LsPlayer pU, char *name);
/*
 Fungsi mereturn index player dalam array pU dengan username parameter input uname
 Jika tidak ditemukan player uname di dalam array pU, maka akan meretrun IdxUndef
*/

boolean getTeleportedConditionOfPlayer(LsPlayer pU, char *uname);
/*
 Fungsi untuk mendapatkan informasi kondisi pemain dengan username uname, apakah
sebelumnya terkena portal (teleported) atau tidak
*/
boolean getImmunityConditionOfPlayer(LsPlayer pU, char *uname);
/*
 Fungsi untuk mendapatkan informasi kondisi pemain dengan username uname, apakah
 Sedang imune terhadap efek apapun atau tidak
*/
int getPositionOfPlayer(LsPlayer pU, char *uname);
/*
 Fungsi untuk mendapatkan informasi posisi terakhir dari pemain dengan username
 uname;
*/


#endif