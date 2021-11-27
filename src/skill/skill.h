#ifndef skill_H
#define skill_H

#include "../boolean/boolean.h"
#include "../player/player.h"

#define Nil NULL

boolean isSkillEmpty(lSkill lS);
// Mengembalikan true jika lS = Nil.
int jumlahSkill(lSkill lS);
// Mengembalikan jumlah skill yang ada pada lS.
address newSkillNode();
// Mengembalikan alamat hasil Alokasi Skill
void CreateEmpty(lSkill *ls);
/* I.S: *ls sembarang
   F.S: *ls = Nil */
void insertSkill (lSkill *lS, address S);
// Menambahkan Skill dengan alamat S ke lSkill
address Search (lSkill *ls, int skillOrder);
/* Mencari apakah ada elemen list dengan urutan = skillOrder pada ls */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
int randomize(int X);
// Mengenerate dan mengembalikan salah satu elemen index ke-X dari array of integer hasil randomize.
int randomSkill(int X);
// Mengembalikan Id skill sesuai X.
void constructSkill(address S, int id);
// Mengisi atribut-atribut skill sesuai id yang dimaksukkan.
void draw(Player *P, int currentPlayer, int randomizer);
// Menambahkan 1 Skill secara random ke lSkill Player yang sedang bermain di giliran ini.
void discard(lSkill *ls, int skillOrder);
// Membuang Skill dengan nomor urut skillOrder dari lSkill suatu pemain.
void Activate(Player *P, lSkill *lS, int skillOrder, int currentPlayer);
// Mengaktifkan efek dari Skill yang digunakan.
void printOneSkill(lSkill *lS, int skillOrder);
// Menampilkan skill pada urutan skillOrder.
void printSkill(Player *P, int currentPlayer);
// Menampilkan skill apa saja yang dimiliki oleh pemain.

// ----------------------------------------------------------- Skill Effects -----------------------------------------------------------//
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

// ----------------------------------------------------------------------- External Purposes -----------------------------------------------------------------------//
void copySkill(lSkill origin, lSkill *copy);

#endif
