#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "../mesin_kar/mesin_kar.h"
#include "../mesin_kata/mesin_kata.h"
#include "../map/map.h"
#include "../player/player.h"
#include "../stack/stack.h"

char skill[5] = {'S','K','I','L','L'} ;                 // 1 Skill
char map[3] = {'M','A','P'} ;                           // 2 Map
char buff[4] = {'B','U','F','F'} ;                      // 3 Buff
char inspect[7] = {'I','N','S','P','E','C','T'} ;       // 4 Inspect
char roll[4] = {'R','O','L','L'} ;                      // 5 Roll
char save[4] = {'S','A','V','E'} ;                      // 6 Save
char endturn[7] = {'E','N','D','T','U','R','N'} ;       // 7 Endturn
char undo[4] = {'U','N','D','O'} ;                      // 8 Undo

char newgame[7] = {'N','E','W','G','A','M','E'} ;       // 1 New Game
char exitgame[4] = {'E','X','I','T'} ;                  // 2 Exit 
char loadgame[8] = {'L','O','A','D','G','A','M','E'} ;  // 3 Load Game

// Merupakan jantung dari permainan MobiTangga, menerima input user dan mengolah informasi dari permainan.
// I.S. State permainan MobiTangga sembarang.
// F.S. State permainan MobiTangga setelah giliran seorang pemain.
void command(MAP *Map, Player *P,Stack *Stack, int turnplayer, boolean *endgame, boolean *endronde, int *jumlahronde) ;

// Menerima input user untuk main menu dan menentukan langkah permainan selanjutnya.
// I.S. Welcoming menu MobiTangga.
// F.S. State permainan tergantung command pemain, antara new game atau exit.
void maincommand(boolean *endgame) ;

#endif
