/*------------------*/
/* Jessin Donnyson  */
/*     13516112     */
/*   Praktikum 10   */
/*   24 OCT 2017    */
/*------------------*/

/* NOTES

CONSTANT        : Nil = NULL
STRUCT TYPE     : ElmtQueue, Queue
Selector        : Head(Q) Tail(Q) InfoHead(Q) InfoTail(Q) Next(P) Info(P)

Method list:

void Alokasi (address *P, infotype X)
void Dealokasi (address  P);

boolean IsEmpty (Queue Q);

void CreateEmpty(Queue * Q);
int NbElmt(Queue Q);

void Add (Queue * Q, infotype X);
void Del(Queue * Q, infotype * X);

void PrintInfo (Queue Q);

*/

#include "queuelist.h"

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
    *P =  (address) malloc(sizeof(ElmtQueue));

    if (*P != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi (address  P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    free(P);
}

boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

int NbElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
    int Count = 0;
    address CP = Head(Q);

    while(CP != Nil){
        CP = Next(CP);
        Count++;
    }

    return Count;
}


/*** Kreator ***/
void CreateEmpty(Queue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/*** Primitif Add/Delete ***/
void Add (Queue * Q, infotype X)
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{
    address P;
    Alokasi (&P, X);

    if (P != Nil){

        if (IsEmpty(*Q)){ // empty list
            Head(*Q) = P;
            Tail(*Q) = P;
        }

        else{

            Next(Tail(*Q)) = P;
            Tail(*Q) = P;

        }
    }
}


void Del(Queue * Q, infotype * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{

    address P = Head(*Q);

    if (Next(Head(*Q)) == Nil)    // 1 element only
        CreateEmpty(Q);
    else
        Head(*Q) = Next(Head(*Q));

    *X = Info(P);
    Dealokasi(P);
}


void PrintInfo (Queue Q)
{
    printf("[");
    if (!IsEmpty(Q)){

        address CP = Head(Q);

        printf(" <H> ");

        do{

            printf("%d",Info(CP));

            if (CP == Tail(Q)){
                printf(" <T> ");
            }

            else{
                printf(",");
            }

            CP = Next(CP);

        } while (CP != Nil);

    }

    printf("]");
}
