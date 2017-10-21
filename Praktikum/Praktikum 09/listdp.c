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

void DelVFirst (List *L, infotype *X);
void DelVLast (List *L, infotype *X);

void InsertFirst (List *L, address P);
void InsertLast (List *L, address P);
void InsertAfter (List *L, address P, address Prec);
void InsertBefore (List *L, address P, address Succ);

void DelFirst (List *L, address *P);
void DelLast (List *L, address *P);
void DelP (List *L, infotype X
void DelAfter (List *L, address *Pdel, address Prec);
void DelBefore (List *L, address *Pdel, address Succ);

void PrintForward (List L);
void PrintBackward (List L);
*/

#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return ( (First(L) == Nil) && (Last(L) == Nil) );
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
    Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
    ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));             // TAKE NOTES !!!

    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
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
/* Mencari apakah ada elemen list dengan Info(P)=X */
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
    address P = Alokasi(X);
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
    Dealokasi(P);
}
void DelVLast (List *L, infotype *X)
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
    if (!IsEmpty(*L))
        InsertBefore(L, P, First(*L));

    else{   // is empty, insert first element

        First(*L) = P;
        Last(*L) = P;
        Prev(P) = Nil;
        Next(P) = Nil;
    }
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (!IsEmpty(*L))
        InsertAfter(L, P, Last(*L));

    else{   // is empty, insert first element

        First(*L) = P;
        Last(*L) = P;
        Prev(P) = Nil;
        Next(P) = Nil;
    }
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec); // pointer P -> succ

    if (Next(Prec) != Nil){ // prec not last element
        Prev(Next(Prec)) = P;   // pointer succ -> P
    }
    else{ // Next prec is nil (prec is last element)
        Last(*L) = P;
    }

    Next(Prec) = P; // pointer prec -> P
    Prev(P) = Prec; // pointer P -> prec
}

void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
    Prev(P) = Prev(Succ); // pointer P -> prec

    if (Prev(Succ) != Nil){ // succ not first element
        Next(Prev(Succ)) = P;   // pointer prec -> P
    }
    else{ // prev succ is nil (succ is first element)
        First(*L) = P;
    }

    Prev(Succ) = P; // pointer succ -> P
    Next(P) = Succ; // pointer P -> succ
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(First(*L));
    if (First(*L) == Nil){  // if the new list doesnt have first element (possibly there was only 1 element)
        CreateEmpty(L);
    }
    else{
        Prev(First(*L)) = Nil;
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
    *P = Last(*L);
    Last(*L) = Prev(Last(*L));
    if (Last(*L) == Nil){  // if the new list doesnt have last element (possibly there was only 1 element)
        CreateEmpty(L);
    }
    else{
        Next(Last(*L)) = Nil;
    }
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = Search(*L, X);

    if (P != Nil){

        if (Prev(P) != Nil) // if it's not first element
            DelAfter(L, P, Prev(P));

        else if (Next(P) != Nil)   // if it's first element
            DelBefore(L, P, Next(P));

        else // if deleted element is singular
            CreateEmpty(L);

        Dealokasi(P);
    }
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);

    Next(Prec) = Next(*Pdel);        // prec -> succ
    if (Next(*Pdel) != Nil){         // deleted element is not last element
        Prev(Next(*Pdel)) = Prec;    // succ -> prec
    }
    else{                            // deleted is last
        Last(*L) = Prec;
    }

    Next(*Pdel) = Nil;
    Prev(*Pdel) = Nil;
}

void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Prev(Succ);

    Prev(Succ) = Prev(*Pdel);       // succ -> prec
    if (Prev(*Pdel) != Nil){        // deleted element is not first element
        Next(Prev(*Pdel)) = Succ;   // prec -> succ
    }
    else {                          // deleted is first
        First(*L) = Succ;
    }

    Next(*Pdel) = Nil;
    Prev(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
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
void PrintBackward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmpty(L)){

        address CP = Last(L);

        do{

            printf("%d",Info(CP));

            CP = Prev(CP);

            if (CP != Nil){ // last element no ','
                printf(",");
            }

        } while (CP != Nil);

    }

    printf("]");
}

