/*

NIM				: 13516112
Nama			: Jessin Donnyson
Tanggal			: 14 Sept 2017
Topik praktikum : 
Deskripsi 		: 

*/

#include <stdio.h>
#include "boolean.h"
#include "matriks.h"

void TulisNilaiX (MATRIKS M, indeks j, ElType X){
	
	indeks i;
	
	printf("[");
	
	boolean koma = false;
	for (i = BrsMin; i <= GetLastIdxBrs(M) ; i++){
			if (Elmt(M,i,j) == X){
				if (koma) {
					printf(",%d",i);
				}
				else {
					printf("%d",i);
					koma = true;
				}
			}
	
	}
	printf("]");
}

void TulisStatistikMhs ( MATRIKS M, indeks i){
	
	float avg = RataBrs(M, i);
	int max,min;
	MaxMinBrs(M,i,&max,&min);
	
	printf("[%d] %.2f %d %d",i,avg,max,min);
	printf("\n");
	
}


void TulisStatistikMK (MATRIKS M, indeks j){
	
	
		
	float avg = RataKol(M, j);
	printf("[%d] %.2f ",j,avg);
	
	int max,min;
	MaxMinKol(M,j,&max,&min);
	int cmax = CountXKol(M,j, max);
	int cmin = CountXKol(M,j, min);	
	
	printf("[%d %d ",max,cmax);
	TulisNilaiX(M, j, max);
	printf("] ");
	printf("[%d %d ",min,cmin);
	TulisNilaiX(M, j, min);
	printf("]\n");
	
}

int main(){
	
	int n, m;
	indeks i,j;
	MATRIKS MNilai;
	
	scanf("%d",&n); // baca baris (nim mahasiswa)
	scanf("%d",&m); // baca kolom (kelas)
	BacaMATRIKS(&MNilai, n, m);
	
	printf("STATISTIK PER MAHASISWA\n");
	for (i = BrsMin; i <= GetLastIdxBrs(MNilai) ; i++){
	TulisStatistikMhs(MNilai,i);
	}
	
	printf("STATISTIK PER MATA KULIAH\n");
	for (j = KolMin; j <= GetLastIdxKol(MNilai) ; j++){
	TulisStatistikMK(MNilai, j);
}
	return 0;
}
