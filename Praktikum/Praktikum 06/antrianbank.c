/*
NIM					: Jessin Donnyson
Nama				: 13516112
Tanggal				: 5 Oct 2017
Topik praktikum		: Queue
Deskripsi			: 
*/

#include "queue.h"
#include <stdio.h>

float AvgElmt(Queue Q){
	float sum = 0;
	int i = Head(Q);
	
	while(i != (Tail(Q)))
        {
            sum += Q.T[i];
            i = (i % MaxEl(Q)) + 1;
        }
	sum += Q.T[Tail(Q)];
	
	return (sum/NBElmt(Q));
}


int main(void){
	
	int El = 0;
	Queue Antri;
	int kode = -999;
	int add_amount;
	int deleted;
	
	scanf("%d",&El);
	CreateEmpty(&Antri, El);
	
	
	scanf("%d", &kode);
	while(kode == 1 || kode == 2){
		
		if (kode == 1){
			scanf("%d", &add_amount);
			if (IsFull(Antri)){
				printf("Queue penuh\n");
			}
			else{
				Add(&Antri, add_amount);
			}
		}
		
		else if (kode == 2){

			if (IsEmpty(Antri)){
				printf("Queue kosong\n");
			}
			else{
				Del(&Antri, &deleted);
			}
		
		}
		
		scanf("%d", &kode);
	}
	
	printf("%d\n",NBElmt(Antri));
	if (IsEmpty(Antri)){
		printf("Tidak bisa dihitung\n");
	}
	else{
		printf("%.2f\n",AvgElmt(Antri));
	}
	
	
	return 0;
}
