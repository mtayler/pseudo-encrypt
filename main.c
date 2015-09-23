/*
 * pseudo-encrypt - RSA-based encryption program for educational purposes
 * Copyright (C) 2014  Tayler Mulligan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define E_OUTPUT "output.vir"
#define D_OUTPUT "output.txt"

unsigned int cypher(int, unsigned long, unsigned long*);
int load_keys(unsigned long*, unsigned long*, unsigned long*);

FILE *target;
FILE *keys;

int main(int argc, char *argv[]) {
	int input;
	int result;

	unsigned long public_key = 0;		/* e */
	unsigned long private_key = 0;		/* d */
	unsigned long divisor = 0;	  	 	/* n */

	if (load_keys(&public_key, &divisor, &private_key)) {
		printf("Unable to load keys. Exiting with error 1");
		exit(1);
	}

	/* If encrypting */
	if (argc > 1 && strcmp(argv[1], "-e") == 0)  {
		target = fopen(E_OUTPUT, "w");

		while ((input = getchar()) != EOF) {
			result = cypher(input, public_key, &divisor);

			fprintf(target, "%c", (char)result);
		}
	}
	else {
		target = fopen(D_OUTPUT, "w");

		while ((input = getchar()) != EOF) {
			result = cypher(input, private_key, &divisor);

			fprintf(target, "%c", (char)result);
		}
	}
	return 0;
}

int load_keys(unsigned long *public_key, unsigned long *divisor, unsigned long *private_key) {
	keys = fopen("keys", "r");

	if (keys == NULL) {
		return 1;
	}

	fscanf(keys, "%lu\n", public_key);
	fscanf(keys, "%lu\n", divisor);
	fscanf(keys, "%lu\n", private_key);

	if (*public_key == 0 || *divisor == 0 || *private_key == 0) {
		return 2;
	}

	return 0;
}

unsigned int cypher(int input, unsigned long key, unsigned long *divisor) {
	if (key == 1) {
		return input;
	}
	return (input * cypher(input, key-1, divisor)) % *divisor;
}
