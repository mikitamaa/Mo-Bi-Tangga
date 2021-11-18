#include "player.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void createEmptyPlayerList(Player *P)
{
    (*P).Neff = 0;
}

void summonPlayer(Player *P, int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("Masukkan Username:\n");
        scanf("%s", &((*P).uname[i]));
        (*P).isTelep[i] = FALSE;
        (*P).pos[i] = 1;
        (*P).isImmu[i] = FALSE;
        (*P).Skills[i] = Nil;
    }
    (*P).Neff = n;
}

int getIdxOfPlayer(Player P, char *nameSearch)
{
    int i = IdxMin;
    int idxP = IdxUndef;
    while (i <= IdxMax)
    {
        if (strcmp(nameSearch, P.uname[i]) != 0)
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

boolean isEmptyList(Skill pS)
{
    return ((ADDR_HEADSKILL(pS)) == Nil);
}

boolean getTeleportedConditionOfPlayer(Player P, char *uname)
{
    int idx = getIdxOfPlayer(P, uname);
    if (idx != IdxUndef)
    {
        return (P.isTelep[idx]);
    }
}

boolean getImmunityConditionOfPlayer(Player P, char *uname)
{
    int idx = getIdxOfPlayer(P, uname);
    if (idx != IdxUndef)
    {
        return (P.isImmu[idx]);
    }
}

int getPositionOfPlayer(Player P, char *uname)
{
    int idx = getIdxOfPlayer(P, uname);
    if (idx != IdxUndef)
    {
        return (P.pos[idx]);
    }
}
