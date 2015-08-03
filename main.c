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

unsigned char cypher(unsigned char input, int key);

char input;
unsigned char result;

/* static values are placeholders until loading from file is implemented */
unsigned long public_key = 59;		/* e */
unsigned long private_key = 179;	/* d */
unsigned long divisor = 221;	   	/* n */

FILE *target;

int main(int argc, char *argv[]) {

	/* If encrypting */
	if (argc > 1 && strcmp(argv[1], "-e") == 0)  {
		target = fopen("encrypted", "w");

		while ((input = getchar()) != EOF) {
			result = cypher(input, public_key);
			printf("result #: %d, result: %c\n", result, result+0);

			putchar(result);
			fprintf(target, "%c", result);
		}
	}
	else {
		target = fopen("decrypted", "w");

		while ((input = getchar()) != EOF) {
			result = cypher(input, private_key);

			putchar(result);
			fprintf(target, "%c", result);
		}
	}
	return 0;
}

unsigned char cypher(unsigned char input, int key) {
	unsigned char result;
	if (key == 1) {
		return input;
	}
	return (input * cypher(input, key-1)) % divisor;
}
