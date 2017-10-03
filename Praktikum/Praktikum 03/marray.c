/*
NIM				: 13516112
Nama			: Jessin Donnyson
Tanggal			: 7 Sept 2017
Topik praktikum	: array static eksplisit
Deskripsi		: 
*/

#include <stdio.h>
#include "array.h"

int CountX (TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
	int count = 0;
	int i;
	
	for (i = IdxMin; i <= Neff(T) ; i++){
		if (Elmt(T,i) == X){
			count += 1;
		}
	
	}
	return count;
}

int main(){
	
	TabInt T;
	int X;
	
	BacaIsi(&T);
	TulisIsiTab(T);
	printf("\n");
	
	scanf("%d",&X);
	int count = CountX(T, X);
	printf("%d\n",count);


	if (SearchB(T, X)){
		int index = Search1(T, X);
		printf("%d\n",index);
		
		InsSortAsc(&T);
		
		
		if (Elmt(T,Neff(T)) == X ){
			printf("maksimum\n");
		}
		if (Elmt(T,IdxMin) == X) {
			printf("minimum\n");
		}
		
		if ((Neff(T) % 2 )== 0){
			if (Elmt(T,(Neff(T) / 2)) == X) {
				printf("median\n");
			}
		}
		else {
			if (Elmt(T,((Neff(T) / 2) + 1)) == X) {
				printf("median\n");
			}
		}
	}
	else{
		printf("%d tidak ada\n",X);
	}


	
	return 0;
	}
	
