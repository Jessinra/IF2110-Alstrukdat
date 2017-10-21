/*------------------*/
/* Jessin Donnyson  */
/*     13516112     */
/*   Praktikum 09   */
/*   20 OCT 2017    */
/*------------------*/

/* NOTES

CONSTANT        : Nil = NULL
STRUCT TYPE     : ElmtList, List
SELECTOR        : Info(P), Next(P), Prev(P), First(L), Last(L)

METHOD LIST     :

boolean IsEmpty (List L);
void CreateEmpty (List *L);
address Alokasi (infotype X);
void Dealokasi (address P);

address Search (List L, infotype X);

void InsVFirst (List *L, infotype X);
void InsVLast (List *L, infotype X);

void DelVFirst (List *L, infotype * X);
void DelVLast (List *L, infotype * X);

void InsertFirst (List *L, address P);
void InsertLast (List *L, address P);
void InsertAfter (List *L, address P, address Prec);

void DelFirst (List *L, address *P);
void DelLast (List *L, address *P);
void DelAfter (List *L, address *Pdel, address Prec);
void DelP (List *L, infotype X);

void PrintInfo (List L);

*/

#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */                       // really ?
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

void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
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

        }while ((CP != First(L)) && !found);
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
    address P = Alokasi(X);
    if (P != Nil){
       InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{

    address P;

    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(P);
}

void DelVLast (List *L, infotype * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{

    address P;

    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(P);

}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    InsertLast(L,P);
    First(*L) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address last = First(*L);

    if (IsEmpty(*L)){
        First(*L) = P;
        Next(P) = P;
    }

    else{
        while(Next(last) != First(*L)){
            last = Next(last);
        }

        InsertAfter(L, P, last);
    }

}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    address last = First(*L);

    if ( Next(last) == First(*L) ){ // only 1 element
        *P = First(*L);
        CreateEmpty(L);
    }
    else{
        while(Next(last) != First(*L)){
            last = Next(last);
        }

        DelAfter(L,P,last);
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    address prec = First(*L);

    if ( Next(prec) == First(*L) ){ // only 1 element
        *P = First(*L);
        CreateEmpty(L);
    }
    else{
        while(Next(Next(prec)) != First(*L)){
            prec = Next(prec);
        }
        DelAfter(L,P,prec);
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    if (Next(Prec) == First(*L)){       // shift first(l)
        First(*L) = Next(First(*L));
    }

    if ( Next(First(*L)) == First(*L) ){ // only 1 element
        CreateEmpty(L);
    }

    else{
        *Pdel = Next(Prec);
        Next(Prec) = Next(Next(Prec));
    }
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = Search(*L, X);
    address prec = First(*L);
    address del;

    if (P != Nil){ // element found

        if ( Next(prec) == First(*L) ){ // only 1 element
            CreateEmpty(L);
        }

        else{

            /* Search for predecessor of X */
            while(Next(prec) != P){
                prec = Next(prec);
            }

            /* got the prec of P */
            DelAfter(L, &del, prec);
            Dealokasi(del);

        }
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
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

            if (CP != First(L)){ // last element no ','
                printf(",");
            }

        } while (CP != First(L));

    }

    printf("]");
}
