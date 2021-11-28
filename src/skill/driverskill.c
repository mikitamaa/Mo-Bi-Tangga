#include "../player/player.h"
#include "../player/player.c"
#include "../skill/skill.h"
#include "../skill/skill.c"
#include "../mesin_kar/mesin_kar.h"
#include "../mesin_kar/mesin_kar.c"
#include "../mesin_kata/mesin_kata.h"
#include "../mesin_kata/mesin_kata.c"
#include "../map/map.h"
#include "../map/map.c"
#include <stdio.h>

int main(){
    Player P;
    createEmptyPlayerList(&P);
    addPlayer(&P, 2);
    // Menambahkan 2 Player untuk menjadi subjek test.
    // Masukkan uname player 1 dengan A dan player 2 dengan B karena akan berpengaruh pada pengujian pada driver ini!

//-------------------------------- Pengujian fungsi isSkillEmpty. Karena belum ada skill, akan menammpilkan "Skill Kosong." --------------------------------//
    if (isSkillEmpty(skills(P)[1]))
    {
        printf("Skill Kosong.\n"); // isSkillEmpty mengmbalikan true.
    } else
    {
        printf("Skill Terisi.\n"); // isSkillEmpty mengmbalikan false.
    }
    printf("\n");

//-------------------------------- Pengujian newSkillNode, randomize, randomSkill, constructSKill, dan insertSkill. --------------------------------//
    lSkill lS;
    CreateEmpty(&lS); // Inisialisasi lS dengan nilai Nil.
    address S = newSkillNode();
    printf("%d\n", Id(S)); // Mengembalikan 0 atau index undefined jika berhasil dialokasi.
    int num_1 = randomize(0); // Mengembalikan bilangan random antara 1 sampai 100.
    printf("%d\n", num_1);
    int num_2 = randomSkill(num_1); // Mengembalikan Id skill sesuai distribusi probabilitas yang ada.
    printf("Id skill yang didapat adalah: %d\n", num_2);
    constructSkill(S, num_2);
    printf("Id yang ada pada Skill S adalah: %d\n", Id(S));
    insertSkill(&lS, S);
    printf("Skill pertama yang ada pada lS memiliki Id: %d\n", Id(lS)); // Harusnya mengembalikan Id yang sama dengan test sebelumnya. Tanda insertSKill berhasil.
    printf("\n");

//-------------------------------- Pengujian jumlahSkill, draw, discard, dan printSkill. -----------------------------------------//
    printf("===== Pengujian jumlahSkill, draw, discard, dan printSkill =====\n");
    printf("Skill berjumlah %d\n", jumlahSkill(skills(P)[1])); // Akan menampilkan 0 karena belum diisi.
    draw(&P, 1, 0);
    draw(&P, 1, 1);
    printf("\n");
    printf("Skill berjumlah %d yaitu:\n", jumlahSkill(skills(P)[1])); // Akan menampilkan 1, yaitu skill hasil draw.
    printSkill(&P, 1);
    printf("\n");
    // Membuang skill pertama
    discard(&skills(P)[1], 1);
    printf("Skill berjumlah %d\n", jumlahSkill(skills(P)[1])); // Akan menampilkan 1 karena sudah dibuang skill satu-satunya.
    printSkill(&P, 1);
    printf("\n");

//-------------------------------- Pengujian fungsi draw tidak akan menambahkan skill ketika Player sudah memiliki 10 skill. --------------------------------//
    for (int i = 0; i < 11; i++)
    {
        draw(&P, 1, i%2);
    } // 2 draw terakhir akan menampilkan pesan bahwa skill player 1 sudah penuh.
    printSkill(&P, 1); // Menampilkan 10 skill yang dimiliki Player 1.
    printf("\n");
     
//-------------------------------- Pengujian Search. --------------------------------//
    printf("===== Search =====\n");
    printf("%d\n", Search(&skills(P)[1], 4));
    printf("id skillnya adalah %d\n", Id(Search(&skills(P)[1], 4))); // Mengembalikan Id dari skill keempat player 1.
    printf("\n");

//-------------------------------- Pengujian Efek Skill. --------------------------------//
    printf("===== Pengujian Efek Skill =====\n");
    printf("----- Pintu GKM -----\n");
    CreateEmpty(&skills(P)[1]); //Mengosongkan Skill List Player 1.
    printf("player lagi imun ga ni? : %d\n", isPlayerImmune(P, "A"));
    pintuGKM(&P, 1);
    printf("player lagi imun ga ni? : %d\n", isPlayerImmune(P, "A"));
    printf("\n");

    printf("----- Senter Pengecil dan Pembesar -----\n");
    printf("player ada senter pengecil ga ni? : %d\n", isPlayerSenterPengecil(P, "A"));
    senterPengecilHoki(&P, 1);
    printf("player ada senter pengecil ga ni? : %d\n", isPlayerSenterPengecil(P, "A"));
    printf("\n");

    printf("player ada senter pembesar ga ni? : %d\n", isPlayerSenterPembesar(P, "A"));
    senterPembesarHoki(&P, 1);
    printf("player ada senter pembesar ga ni? : %d\n", isPlayerSenterPembesar(P, "A"));
    printf("\n");
    
    printf("----- Cermin Pengganda -----\n");
    printf("player ada cermin pengganda ga ni? : %d\n", isPlayerCerminPengganda(P, "A"));
    cerminPengganda(&P, 1);
    printSkill(&P, 1);
    printf("player ada cermin pengganda ga ni? : %d\n", isPlayerCerminPengganda(P, "A"));
    cerminPengganda(&P, 1); // Tidak akan menambahkan apa-apa karena isCermin Player 1 sudah true.
    printf("\n");

    printf("----- Mesin Penukar Posisi -----\n");
    // Insialisasi posisi Player 1 posisi 9 dan Player 2 posisi 6.
    pos(P)[1] = 9;
    pos(P)[2] = 6;
    printf("Posisi Player 1 dan 2: %d %d\n", pos(P)[1], pos(P)[2]);
    mesinPenukarPosisi(&P, 1);
    // Masukan 2 sebagai target
    printf("Posisi player 1 dan 2: %d %d\n", pos(P)[1], pos(P)[2]); // Posisi akan ditukar.
    printf("\n");

//-------------------------------- Pengujian mesinWaktu dan balingJambu --------------------------------//
    printf("----- Mesin Waktu dan Baling Jambu -----\n");
    MAP Map ;
    KonfigurasiToMap(&Map) ;  // File konfigurasi yang dibaca : "konfigurasi.txt"
    // Inisialisasi Posisi kedua Player.
    pos(P)[1] = Map.TabMap[6].Alamat;
    pos(P)[2] = Map.TabMap[1].Alamat;
    printf("Posisi Player 1: %d\n", pos(P)[1]);
    printf("Posisi Player 2: %d\n", pos(P)[2]);
    balingJambu(&P, 2, &Map, 1); // Memindahkan player 1 sebanyak 1 petak ke depan. Menampilkan pesan bahwa tidak bisa karena merupakan petak terlarang.
    balingJambu(&P, 2, &Map, 3); // Memindahkan player 1 sebanyak 3 petak ke depan.
    printf("\nPosisi Player 1: %d\n", pos(P)[1]);
    printf("Posisi Player 2: %d\n", pos(P)[2]);
    mesinWaktu(&P, 1, &Map, 3); // Memindahkan player 2 sebanyak 3 petak ke belakang. Menampilkan pesan bahwa tidak bisa karena merupakan petak terlarang.
    mesinWaktu(&P, 2, &Map, 13); // Memindahkan player 1 13 petak ke belakang.
    printf("\nPosisi Player 1: %d\n", pos(P)[1]);
    printf("Posisi Player 2: %d\n", pos(P)[2]);
    printf("\n");
//-------------------------------- Pengujian copySkill --------------------------------//
printf("===== Copy Skill =====\n");
printf("\nSkill Player 1:\n");
printSkill(&P, 1);
printf("\nSkill Player 2:\n");
printSkill(&P, 2);
printf("\nSetelah ini akan dilakukan copySkill.\n");
copySkill(skills(P)[1], &skills(P)[2]);
// Skill Player 1 akan ter-copy ke Player 2.
printf("\nSkill Player 1:\n");
printSkill(&P, 1);
printf("\nSkill Player 2:\n");
printSkill(&P, 2);
}