/* 
NIM 		: 13516112
Nama 		: Jessin Donnyson
Tanggal 	: 24 Agustus 2017
Topik 		: Tutorial praktikum
Deskripsi	: Print hello world
*/

/* File hello.c */ 
#include <stdio.h>

int main(){
	
	int num,sum;
	int i;
	scanf("%d",&num);
	
	for (i=0 ; (i <= num); i++){
		sum += i;
	}
	
	printf("%d\n",sum);
	
	
	
	
	return 0;
}
