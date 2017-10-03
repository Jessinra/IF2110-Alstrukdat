

#include "mesinkata.h"
#include <stdio.h>


boolean IsKataSama(Kata K1, Kata K2){

    int len;
    int i;

    if (K1.Length != K2.Length){
        return false;
    }

    if (K1.Length > K2.Length){
        len = K1.Length;
    }
    else {
        len = K2.Length;
    }


    for ( i = 1; i <= len; i++ ){
        if (K1.TabKata[i] != K2.TabKata[i]){
            return false;
        }
    }

    return true;

}


int main(void){
int kReg = 0, kPanj = 0;
	int i, idx, banyakkata = 0;
	Kata CKoma, CTitik;

	CKoma.Length = 4;
	CTitik.Length = 5;
	CKoma.TabKata[1] = 'K';
	CKoma.TabKata[2] = 'O';
	CKoma.TabKata[3] = 'M';
	CKoma.TabKata[4] = 'A';
	CTitik.TabKata[1] = 'T';
	CTitik.TabKata[2] = 'I';
	CTitik.TabKata[3] = 'T';
	CTitik.TabKata[4] = 'I';
	CTitik.TabKata[5] = 'K';

	STARTKATA();

	while (!EndKata) {
		if ((!IsKataSama(CKata, CKoma)) && (!IsKataSama(CKata,CTitik))) {
			if (banyakkata > 0) {
				printf(" ");
			}
			for (i = 1; i <= CKata.Length; i++) {
				printf("%c", CKata.TabKata[i]);
			}
			if (CKata.Length < 10) {
				kReg++;
			} else {
				kPanj++;
			}
		} else {
			if (IsKataSama(CKata, CKoma)) {
				printf(",");
			} else if (IsKataSama(CKata, CTitik)) {
				printf(".");
			}
		}
		banyakkata++;
		ADVKATA();
	}
	printf("\n");
	printf("%d\n", kReg);
	printf("%d\n", kPanj);
	int total = kReg*1000 + kPanj*1500;

	if (banyakkata > 10) {
		total = total - 10*total/100;
	}

	printf("%d\n", total);
	return 0;
}
