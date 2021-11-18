#include "player.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void createEmptyPlayerList(Player *P)
{
    (*P).Neff = 0;
}

void addPlayer(Player *P, int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("Masukkan Username:\n");
        scanf("%s", &((*P).uName[i]));
        (*P).isTelep[i] = FALSE;
        (*P).pos[i] = 1;
        (*P).isImmu[i] = FALSE;
        (*P).Skills[i] = Nil;
    }
    (*P).Neff = n;
}

int getPlayerIdx(Player P, char *nameSearch)
{
    int i = IdxMin;
    int idxP = IdxUndef;
    while (i <= IdxMax)
    {
        if (strcmp(nameSearch, P.uName[i]) != 0)
        {
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
{
    int idx = getPlayerIdx(P, uName);
    if (idx != IdxUndef)
    {
        return (P.isTelep[idx]);
    }
}

boolean isPlayerImmune(Player P, char *uName)
{
    int idx = getPlayerIdx(P, uName);
    if (idx != IdxUndef)
    {
        return (P.isImmu[idx]);
    }
}

int getPlayerPosition(Player P, char *uName)
{
    int idx = getPlayerIdx(P, uName);
    if (idx != IdxUndef)
    {
        return (P.pos[idx]);
    }
}
