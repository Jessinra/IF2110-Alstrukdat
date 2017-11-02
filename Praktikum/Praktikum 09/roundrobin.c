/* 
NIM					: 13516112
Nama				: Jessin
Tanggal				: 2 Nov 2017
Topik praktikum		: Variasi List Linier
Deskripsi			: \ ( ^ . ^ ) /
*/

#include<stdio.h>
#include "listsirkuler.h"

void DeleteRR (List *L, infotype TQ)
/* Jika L tidak kosong, "menghapus" elemen terakhir list L, misal last, sesuai aturan round robin, yaitu:
- jika Info(last)>TQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-TQ
- jika Info(last)<=TQ, maka DeleteLast(L,X) dan menampilkan X ke layar */
/* Jika L kosong, cetak "List kosong" */
/* I.S. TQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir L diproses sesuai aturan round-robin.
L mungkin menjadi kosong. */
{
	address temp_add;
	
	if (!IsEmpty(*L)){
		
		DelLast(L, &temp_add);
		if (Info(temp_add) > TQ){
			
			printf("%d\n",TQ);
			Info(temp_add) = Info(temp_add) - TQ;
			InsertFirst(L, temp_add);
		}
		else{
			printf("%d\n", Info(temp_add));
			Dealokasi(temp_add);
		}
		
	}
	else{
		printf("List kosong\n");
	}
}

float Average (List L)
/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */
{
	float sum = 0;
	int count = 0;
	
	address CP = First(L);
	do {
		sum += Info(CP);
		count += 1;
		CP = Next(CP);
		
	}while(CP != First(L));
	
	return sum/count;
}

int main (void){
	
	List LIST;
	CreateEmpty(&LIST);
	
	int time_slice = (-999);
	
	infotype temp_time;
	
	char command;
	
	while(time_slice <= 0){
		scanf("%d",&time_slice);
	}


	
	while(true){
		scanf("\n%c",&command);
		
		if (command == 'A'){
			
			scanf("%d", &temp_time);
			if (temp_time > 0){
				InsVFirst(&LIST, temp_time);
			}
		}
		
		else if (command == 'D'){
			
			DeleteRR(&LIST, time_slice);
			
		}
		else if (command == 'F') {
			break;
		}
		
		else{
			printf("Kode salah\n");
		}
	} 
	
	
	if (!IsEmpty(LIST)){
	
		float avg = Average(LIST);
		printf("%.2f\n", avg);
	
	}
	else{
		printf("Proses selesai\n");
	}
	
	
	return 0;
}
