#include "garis.h"
#include <stdio.h>
void print_bool(boolean B){

    if (B) {
        printf("true");
    }
    else {
        printf("false");
    }
    }

void print_point(POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
    }


int main(){
	GARIS L;
	float f;
	
	BacaGARIS(&L);
	printf("\n test baca garis \n");
	TulisGARIS(L);
	
	f = PanjangGARIS(L);
	printf("\n test panjang \n");
	printf("%f",f);
	
	f = Gradien(L);
	printf("\n test grad \n");
	printf("%f",f);
	
	GeserGARIS(&L,10,10);
	printf("\n test geser garis \n");
	TulisGARIS(L);
	
	printf("\n test tegak \n");
	print_bool(IsTegakLurus(L, L));
	
	printf("\n test sjjt \n");
	print_bool(IsSejajar(L, L));
	
	
	return 0;
}
