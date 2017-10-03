

#include <stdio.h>
#include "boolean.h"
#include "mesintoken.h"

int main() {

	STARTTOKEN();

	if (EndToken) {
		printf("Ekspresi kosong\n");
	} else {
		while (!EndToken) {
			if (CToken.tkn != 'b') {
				printf("%c\n", CToken.tkn);
			} else {
				printf("%d\n", CToken.val);
			}
			ADVTOKEN();
		}

	}

	return 0;
}
