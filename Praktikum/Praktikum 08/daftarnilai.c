/*
 *	Nama 		: Jessin
 *  Nim 		: 13516112 
 * 	Tanggal 	: 25 Oct 2017
 * 	Topik 		: ADT list linear
 */

#include "listlinier.h"
#include <stdio.h>

int main(void){
	
	List LIST;
	CreateEmpty(&LIST);
	int input;
	
	while(1) {
		
		scanf("%d",&input);		
		if ((input <= 100) && (input >= 0)){
			InsVFirst(&LIST, input);
		}
		else{
			break;
		}
	} 
	
	if (!IsEmpty(LIST)){
		printf("%d\n", NbElmt(LIST));
		printf("%d\n", Max(LIST));
		printf("%d\n", Min(LIST));	
		printf("%.2f\n", Average(LIST));
		
		List Inverted;
		CreateEmpty(&Inverted);
		
		Inverted = FInversList(LIST);
		PrintInfo(Inverted);
		printf("\n");
		PrintInfo(LIST);
		printf("\n");
		
	}
	else{
		printf("Daftar nilai kosong\n");
	}

	
	
	
	return 0;
}
