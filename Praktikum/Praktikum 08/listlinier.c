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

void InsVFirst (List *L, infotype X);
void InsVLast (List *L, infotype X);

void DelVFirst (List *L, infotype *X);
void DelVLast (List *L, infotype *X);

void InsertFirst (List *L, address P);
void InsertAfter (List *L, address P, address Prec);
void InsertLast (List *L, address P);

void DelFirst (List *L, address *P);
void DelP (List *L, infotype X);
void DelLast (List *L, address *P);
void DelAfter (List *L, address *Pdel, address Prec);

void PrintInfo (List L);
int NbElmt (List L);

infotype Max (List L);
infotype Min (List L);
infotype Avg (List L);

void Konkat1 (List *L1, List *L2, List *L3);
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
            DelFirst(L, P);
        }
        else {

            while(Next(prec) != P) { // search for the predecesor
                prec = Next(prec);
            }

            DelAfter(L, P, prec);
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

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{

    infotype Max = Info(First(L));
    address CP = First(L);

    while(CP != Nil){

        if (Info(CP) > Max){
            Max = Info(CP);
        }

        CP = Next(CP);
    }

    return Max;
}

infotype Min (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{

    infotype Min = Info(First(L));
    address CP = First(L);

    while(CP != Nil){

        if (Info(CP) < Min){
            Min = Info(CP);
        }

        CP = Next(CP);
    }

    return Min;
}

infotype Avg (List L)
/* Mengirimkan nilai rata rata Info(P) */
{
    int Count = 0;
    infotype Sum = 0;
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
