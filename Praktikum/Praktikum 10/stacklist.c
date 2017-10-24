/*------------------*/
/* Jessin Donnyson  */
/*     13516112     */
/*   Praktikum 10   */
/*   24 OCT 2017    */
/*------------------*/

/* NOTES

CONSTANT        : Nil = NULL
STRUCT TYPE     : ElmtStack, Stack
Selector        : Top(S) InfoTop(S) Next(P) Info(P)

Method list:

void Alokasi (address *P, infotype X);
void Dealokasi (address P);

boolean IsEmpty (Stack S);
void CreateEmpty (Stack * S);

void Push (Stack * S, infotype X);
void Pop (Stack * S, infotype * X);

void PrintInfo (Stack S);

*/

#include "stacklist.h"

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
    *P = (address) malloc(sizeof(ElmtStack));

    if (*P != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi (address P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    free(P);
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
{
    return Top(S) == Nil;
}

void CreateEmpty (Stack * S)
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
{
    Top(*S) = Nil;
}

void Push (Stack * S, infotype X)
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
{
    address P;
    Alokasi (&P, X);

    if (P != Nil){
        Next(P) = Top(*S);
        Top(*S) = P;
    }
}

void Pop (Stack * S, infotype * X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
{

    address P = Top(*S);

    if (Next(Top(*S)) == Nil)    // 1 element only
        CreateEmpty(S);
    else
        Top(*S) = Next(Top(*S));

    *X = Info(P);
    Dealokasi(P);
}

void PrintInfo (Stack S)
{
    printf("[");
    if (!IsEmpty(S)){

        address CP = Top(S);

        printf(" <T> ");

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
