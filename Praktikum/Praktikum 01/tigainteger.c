/* 
NIM 		: 13516112
Nama 		: Jessin Donnyson
Tanggal 	: 24 Agustus 2017
Topik 		: Tutorial praktikum
Deskripsi	: Penjumlahan
*/

/* Program TigaInteger */

/* Input: 3 integer: A, B, C */

/* Output: Sifat integer dari A, B, C (positif/negatif/nol dan ganjil/genap)

           Nilai maksimum, minimum, dan nilai tengah */

#include <stdio.h>

 

/* PROCEDURE DAN FUNCTION */

void CekInteger (int x){

/* I.S.: x terdefinisi */

/* F.S.: Jika x positif dan genap, maka tertulis di layar: POSITIF-GENAP

         Jika x positif dan ganjil, maka tertulis di layar: POSITIF-GANJIL

         Jika x negatif, maka tertulis di layar: NEGATIF

         Jika x nol, maka tertulis di layar: NOL */

	if (x < 0) {
		printf("NEGATIF\n");
	}
	else if (x == 0) { 
		printf("NOL\n");
	}
	else if (x > 0) {
		if (x % 2 == 1) {
			printf("POSITIF-GANJIL\n");
		}
		else if (x % 2 == 0) {
			printf("POSITIF-GENAP\n");
		}      
}}


int Max (int a, int b, int c){

/* menghasilkan nilai terbesar di antara a, b, c */
	if (a >= b && a >= c) {
		return a;
	}
	else if (b >= a && b >= c){
		return b;
	}
	else {
		return c;
	}

}

int Min (int a, int b, int c){

/* menghasilkan nilai terkecil di antara a, b, c */
if (a <= b && a <= c) {
		return a;
	}
	else if (b <= a && b <= c){
		return b;
	}
	else {
		return c;
	}
       
}
/* PROGRAM UTAMA */

int main () {

       /* KAMUS */

       int A, B, C;

       int nilaitengah;

 

       /* ALGORITMA */

       /* Input */

       scanf("%d", &A);

       scanf("%d", &B);

       scanf("%d", &C);

      

       /* Menuliskan sifat integer */

       CekInteger(A);

       CekInteger(B);

       CekInteger(C);

 

       /* Penulisan maksimum, minimum, dan nilai tengah */

       printf("%d\n", Max(A,B,C));

       printf("%d\n", Min(A,B,C));

       nilaitengah = A + B + C - Max(A,B,C) - Min(A,B,C);

       printf("%d\n", nilaitengah);

      

      return 0;

}


