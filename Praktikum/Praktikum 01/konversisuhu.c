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
	float suhu_c;
	float suhu_conv;
	char suhu_tujuan;
 
	scanf("%f\n", &suhu_c); 
	scanf("%s", &suhu_tujuan); 
	switch (suhu_tujuan) 
	{ 
		case 'R': 
		  { 
		  suhu_conv = (0.8 * suhu_c);
		  break;
		  } 
		case 'F': 
		  { 
		  suhu_conv = (1.8 * suhu_c) + 32;
		  break;
		  } 
		case 'K': 
		  { 
		  suhu_conv = suhu_c + 273.15;
		  break;
		  } 
	}
	
	printf("%.2f\n",suhu_conv);
	
	return 0;
}
