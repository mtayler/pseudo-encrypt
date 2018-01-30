#include <stdio.h>
#include <stdlib.h>

#include "encrypt.h"


int encryptle(FILE *input, FILE *output) {
	FILE *keys;

	unsigned long in;
	unsigned long result;

	unsigned long public_key = 0;		/* e */
	unsigned long private_key = 0;		/* d */
	unsigned long divisor = 0;	  	 	/* n */

	if (load_keys(&public_key, &divisor, &private_key)) {
		printf("Unable to load keys. Exiting with error 1");
		exit(1);
	}

	/* If encrypting */
	while ((in = getchar()) != EOF) {
		result = cypher(in, public_key, &divisor);

		fprintf(output, "%lu ", result);
	}
	return EXIT_SUCCESS;
}

int decrypt_file(FILE *input, FILE *output) {
	FILE *target;
	FILE *keys;

	unsigned long in;
	unsigned long result;

	unsigned long public_key = 0;		/* e */
	unsigned long private_key = 0;		/* d */
	unsigned long divisor = 0;	  	 	/* n */

	while (scanf("%lu", &in) == 1) {
		result = cypher(in, private_key, &divisor);

		fprintf(output, "%c", (char)result);
	}
	return EXIT_SUCCESS;
}
