#include <stdio.h>
#include ".../player/player.c"

void main()
{
    Player A;
    createEmptyPlayerList(&A);
    int n;
    printf("Masukkan Jumlah Pemain : ");
    scanf("%d", &n);
    printf("\nAbisini masukin salah satu username pake Rey buat ngecek\n");
    addPlayer(&A, n); /* Masukin Username "Rey" buat ngetes */
    printf("index player : %d\n", getPlayerIdx(A, "Rey"));
    printf("player teleported ga ni? : %d\n", isPlayerTeleported(A, "Rey"));
    printf("player ada senter pengecil ga ni? : %d\n", isPlayerSenterPengecil(A, "Rey"));
    printf("player ada senter pembesar ga ni? : %d\n", isPlayerSenterPembesar(A, "Rey"));
    printf("player ada cermin pengganda ga ni? : %d\n", isPlayerCerminPengganda(A, "Rey"));
    printf("player lagi imun ga ni? : %d\n", isPlayerImmune(A, "Rey"));
    printf("player di posisi berapa ni ? : %d\n", getPlayerPosition(A, "Rey"));
    printf("\nPeringkat Player : \n");
    PeringkatPlayer(&A);
}