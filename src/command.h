#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "mesin_kar.h"
#include "mesin_kata.h"
#include "map.h"
#include "player.h"
#include "stack.h"

char skill[5] = {'S','K','I','L','L'} ;                 //1
char map[3] = {'M','A','P'} ;                           //2
char buff[4] = {'B','U','F','F'} ;                      //3
char inspect[7] = {'I','N','S','P','E','C','T'} ;       //4
char roll[4] = {'R','O','L','L'} ;                      //5
char save[4] = {'S','A','V','E'} ;                      //6
char endturn[7] = {'E','N','D','T','U','R','N'} ;       //7
char undo[4] = {'U','N','D','O'} ;                      //8

char newgame[7] = {'N','E','W','G','A','M','E'} ;       //1
char exitgame[4] = {'E','X','I','T'} ;                  //2
char loadgame[8] = {'L','O','A','D','G','A','M','E'} ;  //3

void command(MAP *Map, Player *P,Stack *Stack, int turnplayer, boolean *endgame, boolean *endronde, int *jumlahronde) ;

void maincommand(boolean *endgame) ;

#endif
