#ifndef skill_H
#define skill_H

#include "boolean.h"

#define Nil NULL

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	infotype info;
	address next;
} Skill;
typedef struct {
	address First;
} List;

Skill draw();
/* Mengembalikan 1 Skill secara random sesuai dengan chance pada spesifikasi */
void pintuGKM(/* Player */);
/* Player mendapat buff imunitas dari teleporter */
/* tidak mendapat ekstra ketika diaktifkan berulang kali */
void cerminPengganda(/* Player */);
/* Menjalankan prosedur draw sebanyak 2 kali dan menambahkan skill yang didapat ke pemain */
void senterPembesarHoki();
/* Pada giliran ini, dadu akan menghasilkan angka antara floor(MaxRoll/2) dan MaxRoll. */
/* Tidak dapat digunakan berulang kali atau bersamaan dengan senter lain. */
void senterPengecilHoki();
/* Pada giliran ini, dadu akan menghasilkan angka antara 1 dan floor(MaxRoll/2). */
/* Tidak dapat digunakan berulang kali atau bersamaan dengan senter lain. */
void mesinPenukarPosisi(/* Player1, Player2 */);
/* Menukarkan posisi dua pemain pada map. */
/* tidak mengaktifkan teleporter. */
void  SKILL(/* Player1 */);
/* Membuka menu skill untuk player yang menjalankan command "SKILL". */

#endif