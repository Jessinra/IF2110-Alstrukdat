/*------------------*/
/* Jessin Donnyson  */
/*     13516112     */
/*   Praktikum 08   */
/*   20 OCT 2017    */
/*------------------*/

/* NOTES

CONSTANT        : Nil = NULL
STRUCT TYPE     : ElmtList, List
Selector        : Info(P), Next(P), First(L)

Method list:

boolean IsEmpty (List L);
void CreateEmpty (List *L);

address Alokasi (infotype X);
void Dealokasi (address *P);

address Search (List L, infotype X);
boolean FSearch (List L, address P);
address SearchPrec (List L, infotype X);

void InsVFirst (List *L, infotype X);
void InsVLast (List *L, infotype X);
void InsertFirst (List *L, address P);
void InsertAfter (List *L, address P, address Prec);
void InsertLast (List *L, address P);

void DelVFirst (List *L, infotype *X);
void DelVLast (List *L, infotype *X);
void DelFirst (List *L, address *P);
void DelP (List *L, infotype X);
void DelLast (List *L, address *P);
void DelAfter (List *L, address *Pdel, address Prec);

void PrintInfo (List L);
int NbElmt (List L);
infotype Max (List L);
address AdrMax (List L);
infotype Min (List L);
address AdrMin (List L);
float Average (List L);

void DelAll (List *L);
void InversList (List *L);
List FInversList (List L);
void CopyList (List *L1, List *L2);
List FCopyList (List L);
void CpAlokList (List Lin, List *Lout);

void Konkat (List L1, List L2, List * L3);
void Konkat1 (List *L1, List *L2, List *L3);
void PecahList (List *L1, List *L2, List L);
*/

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));             // TAKE NOTES !!!

    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
    else {
        return Nil;
    }
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    boolean found = false;
    address found_add = Nil;
    address CP = First(L);

    if (!IsEmpty(L)){

        do{
            if (Info(CP) == X){
                found_add = CP;
                found = true;
            }
            else{
                CP = Next(CP);
            }

        }while ((CP != Nil) && !found);
    }

    return found_add;

}

boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	boolean found = false;
	address CP = First(L);

	if (!IsEmpty(L)){

        do{
            if (CP == P){
                found = true;
            }
            else{
                CP = Next(CP);
            }

        }while ((CP != Nil) && !found);
    }

    return found;

}

address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    boolean found = false;
    address prec = Nil;
    address found_add = Nil;
    address CP = First(L);

    if (!IsEmpty(L)){

        do{
            if (Info(CP) == X){
                found_add = prec;
                found = true;
            }
            else{
				prec = CP;
                CP = Next(CP);
            }

        }while ((CP != Nil) && !found);
    }

    return found_add;

}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P = Alokasi(X);
    if (P != Nil){
        InsertFirst(L, P);
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = Alokasi (X);
    if (P != Nil){
        InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{

    if (IsEmpty(*L)){ // empty list
        Next(P) = Nil;
        First(*L) = P;
    }
    else{
        address last = First(*L);

        while(Next(last) != Nil) {
            last = Next(last);
        }

        InsertAfter(L, P, last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    if (Next(First(*L)) == Nil)    // 1 element only
        CreateEmpty(L);
    else
        First(*L) = Next(First(*L));

}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = Search(*L, X);

    if (P != Nil){   // Found
        address prec = First(*L);

        if (prec == P){ // If its on first element
            DelFirst(L, &P);
        }
        else {

            while(Next(prec) != P) { // search for the predecesor
                prec = Next(prec);
            }

            DelAfter(L, &P, prec);
        }
    }
    Dealokasi(&P);
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    if (Next(First(*L)) == Nil){    // 1 element only

        *P = First(*L);
        CreateEmpty(L);

    }
    else {
        address prec = First(*L);

        while(Next(Next(prec)) != Nil) {
            prec = Next(prec);
        }

        // Next Next (prec ) == nil , got the prec of last element

        DelAfter(L, P, prec);

    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    if (*Pdel != Nil)
        Next(Prec) = Next(Next(Prec));
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmpty(L)){

        address CP = First(L);

        do{

            printf("%d",Info(CP));
            CP = Next(CP);

            if (CP != Nil){ // last element no ','
                printf(",");
            }

        } while (CP != Nil);

    }

    printf("]");
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int Count = 0;
    address CP = First(L);

    while(CP != Nil){
        CP = Next(CP);
        Count++;
    }

    return Count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/\

address AdrMax (List L){

	address Max = First(L);
    address CP = First(L);

    while(CP != Nil){

        if (Info(CP) > Info(Max)){
            Max = CP;
        }

        CP = Next(CP);
    }

    return Max;
}

address AdrMin (List L){

	address Min = First(L);
    address CP = First(L);

    while(CP != Nil){

        if (Info(CP) < Info(Min)){
            Min = CP;
        }

        CP = Next(CP);
    }

    return Min;
}

infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
	return Info(AdrMax(L));
}

infotype Min (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
	return Info(AdrMin(L));
}

float Average (List L)
/* Mengirimkan nilai rata rata Info(P) */
{
    int Count = 0;
    float Sum = 0;
    address CP = First(L);

    while(CP != Nil){

        Sum += Info(CP);
        Count++;
        CP = Next(CP);
    }

    return (Sum/Count);
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    CreateEmpty(L3);

    if (!(IsEmpty(*L1))){
        First(*L3) = First(*L1);

        address last1 = First(*L1);

        while(Next(last1) != Nil) {
            last1 = Next(last1);
        }

        Next(last1) = First(*L2);
    }
    else{
        First(*L3) = First(*L2);
    }


    CreateEmpty(L1);
    CreateEmpty(L2);

}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
	infotype temp;

	while(!IsEmpty (*L)){
		DelVFirst(L, &temp);
	}

	CreateEmpty(L);
}

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{

	address P,Q;
	address temp;
	address First = First(*L);

	P = First(*L);
	Q = Next(P);

	while(Q != Nil){

		P = Q;
		Q = Next(Q);

		P;
		InsertFirst(L, P);
		Next(First) = Q;
	}
}

List FInversList (List L)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
	// Create temporary list
	List TempL;
	CreateEmpty(&TempL);

	// Create duplicate of original list
	List TempOrg;
	CreateEmpty(&TempOrg);
	TempOrg = FCopyList(L);

	infotype temp;
	address tempAdr;
	while(!IsEmpty(TempOrg)){

		DelVFirst(&TempOrg, &temp);
		tempAdr = Alokasi(temp);
		if (tempAdr != Nil) {
			InsertFirst(&TempL, tempAdr);
		}
		else{
			DelAll(&TempL);
			return TempL;
		}
	}

	return TempL;
}

void CopyList (List *L1, List *L2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
	First(*L2) = First(*L1);
}


List FCopyList (List L)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
	// Create temporary list
	List TempL;
	CreateEmpty(&TempL);

	address CP = First(L);
	address tempAdr;

	while(CP != Nil){

		tempAdr = Alokasi(Info(CP));
		if (tempAdr != Nil){
			InsertLast(&TempL, tempAdr);
			CP = Next(CP);
		}
		else{
			DelAll(&TempL);
			return TempL;
		}
	}

	return TempL;
}

void CpAlokList (List Lin, List *Lout)
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
{
	CreateEmpty(Lout);
	*Lout = FCopyList(Lin);
}

void Konkat (List L1, List L2, List * L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
{
    CreateEmpty(L3);

	address tempAdr;
	infotype temp;
	address CP;
	boolean stop = false;

    if (!(IsEmpty(L1))){

        CP = First(L1);

        while ((CP != Nil) && (!stop)){

			temp = Info(CP);
			tempAdr = Alokasi(temp);
			if (tempAdr != Nil){
				InsertLast(L3, tempAdr);
				CP = Next(CP);
			}
			else {

				DelAll(L3);
				stop = true;
			}
		}

		CP = First(L2);

        while ((CP != Nil) && (!stop)){

			temp = Info(CP);
			tempAdr = Alokasi(temp);
			if (tempAdr != Nil){
				InsertLast(L3, tempAdr);
				CP = Next(CP);
			}
			else {

				DelAll(L3);
				stop = true;
			}
		}

    }
    else{

		CP = First(L2);

        while ((CP != Nil) && (!stop)){

			temp = Info(CP);
			tempAdr = Alokasi(temp);
			if (tempAdr != Nil){
				InsertLast(L3, tempAdr);
				CP = Next(CP);
			}
			else {

				DelAll(L3);
				stop = true;
			}
		}
    }
}

void PecahList (List *L1, List *L2, List L)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
{
	int repeat = NbElmt(L) / 2;
	int repeatII = NbElmt(L) - repeat;
	address tempAdr;
	infotype temp;
	address CP = First(L);

	CreateEmpty(L1);
	CreateEmpty(L2);

	while(repeat > 0){

		temp = Info(CP);
		tempAdr = Alokasi(temp);
		if (tempAdr != Nil){
			InsertLast(L1, tempAdr);
			CP = Next(CP);
			repeat--;
		}

	}

	while(repeatII > 0){

		temp = Info(CP);
		tempAdr = Alokasi(temp);
		if (tempAdr != Nil){
			InsertLast(L2, tempAdr);
			CP = Next(CP);
			repeatII--;
		}
	}
}
