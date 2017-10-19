/* 
 * Nama			: Jessin
 * Nim 			: 13516112
 * Tanggal	 	: 19 Oct 2017
 * Topik 		: ADT STACK
*/

#include <stdio.h>
#include "stackt.h"
#include <stdlib.h>

int CharToInt(char X){
	
	if (X == '0'){
		return 0;
	}
	else if (X == '1'){
		return 1;
	}
	else if (X == '2'){
		return 2;
	}
	else if (X == '3'){
		return 3;
	}
	else if (X == '4'){
		return 4;
	}
	else if (X == '5'){
		return 5;
	}
	else if (X == '6'){
		return 6;
	}
	else if (X == '7'){
		return 7;
	}
	else if (X == '8'){
		return 8;
	}
	else if (X == '9'){
		return 9;
	}
	else {
		return -999;
	}
}

void PrintSum(Stack S)
{
    int i;

    for (i = Top(S); i > 0; i--){
        printf("%d",S.T[i]);
    }
}

int main(void){
	
	Stack S1;
	Stack S2;
	Stack Sum;
	
	int carry, mod = 0;
	infotype El1, El2;
	char temp;
	
	CreateEmpty(&S1);
	CreateEmpty(&S2);
	CreateEmpty(&Sum);
		
	do {
		scanf("%c", &temp);
		if ((temp != '#')&&(temp != '\n')){
			Push(&S1, CharToInt(temp));
		}
		
	} while( temp != '#');
	
	do {
		scanf("%c", &temp);
		if ((temp != '#')&&(temp != '\n')){
			Push(&S2, CharToInt(temp));
		}
	} while( temp != '#');
	
	while(!(IsEmpty(S1) && IsEmpty(S2))){  // if theres still element
		
		if(!IsEmpty(S1) && !IsEmpty(S2)){
			Pop (&S1, &El1);
			Pop (&S2, &El2);
			

			mod = (carry + El1 + El2) % 10;
			
			carry = (carry + El1 + El2) / 10;
			Push (&Sum, mod);
		}
		
		else if(IsEmpty(S1) && !IsEmpty(S2)){
			Pop (&S2, &El2);
			
			mod = (carry + El2) % 10;
			
			carry = (carry + El2) / 10;
			Push (&Sum, mod);
		}
		
		else if(!IsEmpty(S1) && IsEmpty(S2)){
			Pop (&S1, &El1);
			
			mod = (carry + El1 ) % 10;
			
			carry = (carry + El1 ) / 10;
			Push (&Sum, mod);
		}
	}
	
	if (carry != 0){
		Push(&Sum, carry);
	}
	PrintSum(Sum);
	printf("\n");
	
	return 0;
}
