#ifndef skill_H
#define skill_H

#include "boolean.h"
#include "Player.h"

#define Nil NULL

void CreateEmpty(lSkill *ls);
/* I.S: *ls sembarang
   F.S: *ls = Nil */
void draw(Player *P, int currentPlayer);
// Menambahkan 1 Skill secara random ke lSkill Player yang sedang bermain di giliran ini.
void insertSkill (lSkill *lS, address S);
// Menambahkan Skill dengan alamat S ke lSkill
void discard(lSkill *ls, int skillOrder);
// Membuang Skill dengan nomor urut skillOrder dari lSkill suatu pemain.
void pintuGKM(Player *P, int currentPlayer);
/* Player mendapat buff imunitas dari teleporter */
/* tidak mendapat ekstra ketika diaktifkan berulang kali */
void cerminPengganda(Player *P, int currentPlayer);
/* Menjalankan prosedur draw sebanyak 2 kali dan menambahkan skill yang didapat ke pemain */
void senterPembesarHoki(Player *P, int currentPlayer);
/* Pada giliran ini, dadu akan menghasilkan angka antara floor(MaxRoll/2) dan MaxRoll. */
/* Tidak dapat digunakan berulang kali atau bersamaan dengan senter lain. */
void senterPengecilHoki(Player *P, int currentPlayer);
/* Pada giliran ini, dadu akan menghasilkan angka antara 1 dan floor(MaxRoll/2). */
/* Tidak dapat digunakan berulang kali atau bersamaan dengan senter lain. */
void mesinPenukarPosisi(Player *P, int currentPlayer);
/* Menukarkan posisi dua pemain pada map. */
/* tidak mengaktifkan teleporter. */
void  SKILL();
/* Membuka menu skill untuk player yang menjalankan command "SKILL". */

#endif