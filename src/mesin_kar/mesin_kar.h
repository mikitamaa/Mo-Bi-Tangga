#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../boolean/boolean.h"

#define NEWLINE '\n'

extern char CC ;
extern boolean EOP ;

// Mesin kata dimulai dengan membaca file "konfigurasi.txt". Pita kata dimulai dari karakter pertama.
// I.S. File "konfigurasi.txt".
// F.S. CC adalah karakter pertama dari pita.
void START() ;

// Mesin kata akan memroses karakter berikutnya.
// I.S. CC sembarang.
// F.S. CC selanjutnya.
void ADV() ;

// Mesin kata dimulai dengan membaca input user. Pita karakter dimulai dari karakter pertama.
// I.S. Input user sembarang.
// F.S. CC adalah karakter pertama dari pita.
void STARTCOMMAND() ;

#endif
