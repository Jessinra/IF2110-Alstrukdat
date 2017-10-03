/*
NIM				: 13516112
Nama			: Jessin
Tanggal			: 31 Agustus 2017
Topik praktikum : Jam
Deskripsi		: membuat penghitung durasi telepon

*/

#include "jam.h"
#include <stdio.h>

int main(){
	
	long jam_min = 1000000 ;
	long jam_max = -100000 ;
	long dur,jam_temp ;
	int jumlah;
	JAM J1, J2;
	
	
	scanf("%d",&jumlah);
	
	for (int i = 1; (i <= jumlah ); i++){
		
		printf("[%d]\n",i);
		BacaJAM(&J1);
		BacaJAM(&J2);
		
		if (JLT(J1,J2)){
			dur = Durasi(J1, J2);
			
			jam_temp = JAMToDetik(J2);
			if (jam_temp > jam_max){
				jam_max = JAMToDetik(J2);
			
			}
			if (JAMToDetik(J1) < jam_min ){
				jam_min = JAMToDetik(J1);
			}
		}
		else{
			dur = Durasi(J2, J1);
			if (JAMToDetik(J1) > jam_max) {
				jam_max = JAMToDetik(J1);
			
			}
			if (JAMToDetik(J2) < jam_min ){
				jam_min = JAMToDetik(J2);
			}
		}
		printf("%ld\n", dur);
				
		
		
		}
		
		TulisJAM(DetikToJAM(jam_min));
		printf("\n");
		TulisJAM(DetikToJAM(jam_max));
		printf("\n");
	
	return 0;
}
