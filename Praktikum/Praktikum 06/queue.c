/*------------------*/
/* Jessin Donnyson  */
/*     13516112     */
/*   Praktikum 06   */
/*   29 Sept 2017   */
/*------------------*/

/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "queue.h"
#include "boolean.h"
#include <stdlib.h>
#define Nil 0
/* Konstanta untuk mendefinisikan address tak terdefinisi */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    int CountEl = (((Tail(Q)-Head(Q) + MaxEl(Q)) %MaxEl(Q))+ 1 );

    return (CountEl == MaxEl(Q));
}

int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{

    if (IsEmpty(Q)){
        return 0;
    }

    int CountEl = (((Tail(Q)-Head(Q) + MaxEl(Q)) %MaxEl(Q)) + 1 );     //  REMEMBER TO MOD FIRST THEN INCREMENT
    return (CountEl);
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype));

    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;

    } else /* alokasi gagal */ {
        MaxEl(*Q) = 0;

    }

}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh                  >>>>>   HAVE TO MAKE SURE IT'S NOT FULL !!  */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{

    if (IsEmpty(*Q)){
        Head(*Q) = 1;
        Tail(*Q) = 1;
        InfoTail(*Q) = X;
    }

    /* If not empty */
    else {
        Tail(*Q) = (Tail(*Q) % MaxEl(*Q)) + 1;
        InfoTail(*Q) = X;
    }


}


void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    if (NBElmt(*Q) == 1){

        *X = InfoHead(*Q);
        Head(*Q) = 0;
        Tail(*Q) = 0;

    }
    /* If contains more than one element */
    else{
        *X = InfoHead(*Q);
        Head(*Q) = (Head(*Q) % MaxEl(*Q)) + 1;
    }
}

void PrintQ (Queue Q){



    if (IsEmpty(Q)){
        printf("Empty queue");
    }
    else{

        int i = Head(Q);

        printf("Head : %d\n",Head(Q));
        printf("Tail : %d\n",Tail(Q));
        printf("Jumlah el : %d\n",NBElmt(Q));
        printf("element : ");

        while(i != (Tail(Q) + 1 ))
        {
            printf("[%d] > %d ",i,Q.T[i]);
            i = (i % MaxEl(Q)) + 1;
        }
    }
}

