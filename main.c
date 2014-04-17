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
#include <math.h>
#include <string.h>

char byte;
char result;

/* static values are placeholders until loading from file is implemented */
unsigned long public_key = 271;		/* e */
unsigned long private_key = 79;		/* d */
unsigned long divisor = 323;		/* n */

FILE *target;

int main(int argc, char *argv[]) {

	/* If encrypting */
	if (argc > 1 && strcmp(argv[1], "-e") == 0)  {
		target = fopen("encrypted", "w");

		while ((byte = getchar()) != EOF) {
			result = (unsigned long)pow(byte, public_key) % divisor;
			printf("result int: %d, result char: %c\n", result, result);

			fprintf(target, "%c", result);
		}
	}
	else {
		target = fopen("decrypted", "w");

		while ((byte = getchar()) != EOF) {
			result = (unsigned long)pow(byte, private_key) % divisor;
			fprintf(target, "%c", result);
		}
	}
	return 1;
}
