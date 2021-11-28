#include "../stack/stack.h"
#include "../stack/stack.c"
#include "../player/player.h"
#include "../player/player.c"
#include "../skill/skill.h"
#include "../skill/skill.c"

int main () {

    // Dinisialisasi sebuah stack kosong.
    Stack S ;
    CreateEmptyStack(&S) ;

    Player P ;
    P.isCermin[1] = true ;
    P.isImmu[1] = true ;
    P.isSenPem[1] = false ;
    P.isSenPeng[1] = false ;
    P.isUdahRoll[1] = true ;
    P.Neff = 1 ;
    P.pos[1] = 5 ;

    // Untuk mempermudah testing push akan digunakan beberapa prosedur dari skill.h.
    CreateEmpty(&P.skills[1]) ;

    address tmp ;
    tmp = newSkillNode() ;
    constructSkill(tmp, 1);
    insertSkill(&P.skills[1], tmp);
    
    tmp = newSkillNode() ;
    constructSkill(tmp, 2);
    insertSkill(&P.skills[1], tmp);

    // Karena stack masih kosong, IsEmpty akan mengembalikan true dan IsFull akan mengembalikan false.
    if (IsEmpty(S) && !IsFull(S)) {
        
        // Data akan dimasukkan ke dalam Stack S.
        Push(&S, &P) ;
        printf("Jumlah pemain: %d\n", S.P[Top(S)].Neff) ;
        printf("Posisi pemain: %d\n", S.P[Top(S)].pos[1]) ;
        printf("Id skill pertama: %d\n", S.P[Top(S)].skills[1]->Id) ;
        printf("Id skill kedua: %d\n\n", S.P[Top(S)].skills[1]->next->Id) ;

        // Data akan dimasukkan ke dalam Player P2.
        boolean PopBerhasil ;
        Player P2 ;
        Pop(&S, &P2, &PopBerhasil) ;

        // Data akan berada pada Player P2.
        printf("Jumlah pemain: %d\n", P2.Neff) ;
        printf("Posisi pemain: %d\n", P2.pos[1]) ;
        printf("Id skill pertama: %d\n", P2.skills[1]->Id) ;
        printf("Id skill kedua: %d\n\n", P2.skills[1]->next->Id) ;
    }   
}