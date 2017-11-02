/* 
NIM					: 13516112
Nama				: Jessin
Tanggal				: 2 Nov 2017
Topik praktikum		: Variasi List Linier
Deskripsi			: \ ( ^ . ^ ) /
*/

#include<stdio.h>
#include "listdp.h"


address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya>=X */
/* Mencari apakah ada elemen list dengan Info(P)>=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)>=X pertama. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
{
	address prec = Nil;
	boolean found = false;
    address CP = First(L);

    if (!IsEmpty(L)){

        do{
            if (Info(CP) >= X){
                found = true;
            }
            else{
				prec = CP;
                CP = Next(CP);
            }

        }while ((CP != Nil) && !found);
    }

	return prec;
}

void InsertUrut (List *L, infotype X)
/* Menambahkan elemen pada list L tanpa mengganggu keterurutan L.
Manfaatkan fungsi SearchPrec. */
/* I.S. X terdefinisi. L terdefinisi, mungkin kosong.
Jika tidak kosong, L terurut membesar. */
/* F.S. X dialokasi. Jika alokasi berhasil, maka X dimasukkan sebagai salah
satu elemen L tanpa mengganggu keterurutan L. Insert elemen baru
dapat dilakukan di awal, di tengah, maupun di akhir.
Jika alokasi gagal, L tetap. */
{
	address prec = SearchPrec(*L, X);
	address P = Alokasi(X);
	
	if (P != Nil){
		
		if (prec != Nil){
			InsertAfter(L, P, prec);
		}
		
		else{
			InsertFirst(L, P);
		}
	}
	
}

infotype Max (List L)
/* Menghasilkan nilai terbesar dari elemen list L. L tidak kosong. */
{
	address temp;
	DelLast(&L, &temp);
	InsertLast(&L, temp);
	
	return Info(temp);
}


infotype Min (List L)
/* Menghasilkan nilai terkecil dari elemen list L. L tidak kosong. */
{
	address temp;
	DelFirst(&L, &temp);
	InsertFirst(&L, temp);
	
	return Info(temp);
}

float Average (List L)
/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */
{
	float sum = 0;
	int count = 0;
	
	address CP = First(L);
	while(CP != Nil){
		sum += Info(CP);
		count += 1;
		CP = Next(CP);
	}
	
	return sum/count;
}

int main (void){
	
	List LIST;
	CreateEmpty(&LIST);
	infotype temp = 0;
	
	while(temp != (-9999)){
		
		scanf("%d", &temp);
		if (temp != (-9999)){
			InsertUrut(&LIST, temp);
		}
	}
	
	if (!IsEmpty(LIST)){
		infotype max = Max(LIST);
		infotype min = Min(LIST);
		float avg = Average(LIST);
		
		printf("%d\n",max);
		printf("%d\n",min);
		printf("%.2f\n",avg);
		PrintForward(LIST);
		printf("\n");
		PrintBackward(LIST);
		printf("\n");
		
	}
	else {
		printf("[]\n");
	}
	
	return 0;
}
