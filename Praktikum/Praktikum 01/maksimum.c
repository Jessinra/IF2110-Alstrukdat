/* 
NIM 		: 13516112
Nama 		: Jessin Donnyson
Tanggal 	: 24 Agustus 2017
Topik 		: Tutorial praktikum
Deskripsi	: Penjumlahan
*/

/* File hello.c */ 
#include <stdio.h>

int main(){
	int num;
	int i = 0;
	int max = -999;
	
	for (i = 1; i <= 3; i++){
		scanf("%d",&num);
		if (num > max) {
			max = num;
		}
	}
	
	printf("%d\n",max);
	
	
	
	return 0;
}
