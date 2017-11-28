#include "bintree.h"
#include <stdio.h>
#include <math.h>

int i;
char s[500];

BinTree BuildBalancedTree(int N){
	BinTree P,L,R;
	infotype a;
	char c;
	int Nl, Nr;
	if(N == 0)
		return Nil;
	else{
		c = s[i];
		if(c=='+')
			a = -2;
		else if(c=='-')
			a = -1;
		else if(c=='*')
			a = -3;
		else if(c=='/')
			a = -4;
		else if(c=='^')
			a = -5;
		else if(c=='%')
			a = -6;
		else
			a = c-'0';
		i++;
		P = AlokNode(a);
		if(P!=Nil){
			if(a>=0){
				Nl = Nr = 0;
			}
			else{
				Nl = Nr = 1;
			}
			L = BuildBalancedTree(Nl);
			Left(P) = L;
			R = BuildBalancedTree(Nr);
			Right(P) = R;
		}
		return P;
	}
}

void hitung(BinTree *T){
	if(IsTreeEmpty(*T));
	else if(Akar(*T)<0){
		BinTree l,r;
		l = Left(*T);
		r = Right(*T);
		hitung(&l);
		hitung(&r);
		if(Akar(*T)==-1)
			Akar(*T)= Akar(l) - Akar(r);
		else if(Akar(*T)==-2)
			Akar(*T)= Akar(l) + Akar(r);
		else if(Akar(*T)==-3)
			Akar(*T)= Akar(l) * Akar(r);
		else if(Akar(*T)==-4)
			Akar(*T)= Akar(l) / Akar(r);
		else if(Akar(*T)==-5)
			Akar(*T)= pow(Akar(l),Akar(r));
		else
			Akar(*T)= Akar(l) % Akar(r);
	}
}

void PPrintPostorder (BinTree P)
{
	if(IsTreeEmpty(P));
	else{
		PPrintPostorder(Left(P));
		PPrintPostorder(Right(P));
		if(Akar(P) == -1)
			printf("-");
		else if(Akar(P) == -2)
			printf("+");
		else if(Akar(P) == -3)
			printf("*");
		else if(Akar(P) == -4)
			printf("/");
		else if(Akar(P) == -5)
			printf("^");
		else if(Akar(P) == -6)
			printf("%c",37 );
		else
			printf("%d",Akar(P));
	}
}

int main(){
	BinTree T = Nil;
	fgets(s, 500, stdin);
	if(s[0]=='\n'||s[0]=='\0'){
		printf("Ekspresi kosong\n");
	}
	else{
		i=0;
		T = BuildBalancedTree(1);
		PPrintPostorder(T);
		hitung(&T);
		printf("\n=%d\n", Akar(T));
	}
	return 0;
}