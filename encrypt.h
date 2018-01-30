#ifndef ENCRYPT_INCLUDED
#define ENCRYPT_INCLUDED

#include <math.h>
#include <string.h>

#define E_OUTPUT "output.vir"
#define D_OUTPUT "output.txt"

unsigned long cypher(unsigned long, unsigned long, unsigned long*);
int load_keys(unsigned long*, unsigned long*, unsigned long*);
int encrypt(unsigned long);
int decrypt(unsigned long);

#endif // ENCRYPT_INCLUDED
