/*------------------*/
/* Jessin Donnyson  */
/*     13516112     */
/*   Praktikum 12   */
/*   12 Nov 2017    */
/*------------------*/

/* NOTES

STRUCT : Node, BinTree, addrNode
SELECTOR :  /* Akar(P), Left(P), Right(P)

METHOD LIST :
BinTree Tree (infotype Akar, BinTree L, BinTree R);
void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P);

addrNode AlokNode (infotype X);
void DealokNode (addrNode P);

boolean IsTreeEmpty (BinTree P);
boolean IsTreeOneElmt (BinTree P);
boolean IsUnerLeft (BinTree P);
boolean IsUnerRight (BinTree P);
boolean IsBiner (BinTree P);
boolean IsSkewLeft (BinTree P);
boolean IsSkewRight (BinTree P);
boolean SearchTree (BinTree P, infotype X);

void PrintPreorder (BinTree P);
void PrintInorder (BinTree P);
void PrintPostorder (BinTree P);
void PrintTree (BinTree P, int h);

int NbElmt (BinTree P);
int NbDaun (BinTree P);
int Level (BinTree P, infotype X);
int Tinggi (BinTree P);

void AddDaunTerkiri (BinTree *P, infotype X);
void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri);
void DelDaunTerkiri (BinTree *P, infotype *X);
void DelDaun (BinTree *P, infotype X);

List MakeListDaun (BinTree P);
List MakeListPreorder (BinTree P);
List MakeListLevel (BinTree P, int N);

*/

#include "bintree.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* *** PROTOTYPE *** */

/* *** Konstruktor *** */
BinTree Tree (infotype Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
    BinTree New_tree = (BinTree) malloc(sizeof(BinTree));

    if (New_tree != Nil){
        Akar(New_tree) = Akar;
        Left(New_tree) = L;
        Right(New_tree) = R;

        return New_tree;
    }
    else {

        return Nil;
    }
}


void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
{

    *P = Tree(Akar, L, R);
}

/* Manajemen Memory */
addrNode AlokNode (infotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addrNode New_node = (addrNode) malloc(sizeof(Node));

    if (New_node != Nil){
        Akar(New_node) = X;
        Left(New_node) = Nil;
        Right(New_node) = Nil;

        return New_node;
    }
    else {

        return Nil;
    }
}

void DealokNode (addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
    free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
    return P == Nil;
}

boolean IsTreeOneElmt (BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
    if (!IsTreeEmpty(P)){
        return ((Left(P) == Nil) && (Right(P) == Nil));
    }
    else{
        return false;
    }
}

boolean IsUnerLeft (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
    if (!IsTreeEmpty(P)){
        return ((Left(P) != Nil) && (Right(P) == Nil));
    }
    else{
        return false;
    }
}

boolean IsUnerRight (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
    if (!IsTreeEmpty(P)){
        return ((Left(P) == Nil) && (Right(P) != Nil));
    }
    else{
        return false;
    }
}

boolean IsBiner (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
    if (!IsTreeEmpty(P)){
        return ((Left(P) != Nil) && (Right(P) != Nil));
    }
    else{
        return false;
    }
}

/* *** Traversal *** */
void PrintPreorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{

    printf("(");

    if (!IsTreeEmpty(P)){

        printf("%d", Akar(P));
        PrintPreorder(Left(P));
        PrintPreorder(Right(P));
    }

    printf(")");
}

void PrintInorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{

    printf("(");

    if (!IsTreeEmpty(P)){

        PrintInorder(Left(P));
        printf("%d", Akar(P));
        PrintInorder(Right(P));
    }

    printf(")");
}

void PrintPostorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{

    printf("(");

    if (!IsTreeEmpty(P)){

        PrintPostorder(Left(P));
        PrintPostorder(Right(P));
        printf("%d", Akar(P));
    }

    printf(")");
}

void PrintTree (BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
{
    void PrintTree2(BinTree P, int h, int current_indent)
    {
        if (!IsTreeEmpty(P)){

            printf("%*s%d\n", current_indent, "", Akar(P));

            PrintTree2(Left(P), h, current_indent + h);
            PrintTree2(Right(P), h, current_indent + h);
        }
    }

    PrintTree2(P,h, 0);
}

/* *** Searching *** */
boolean SearchTree (BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    if (IsTreeEmpty(P)){
        return false;
    }
    else{
        if (Akar(P) == X){
            return true;
        }
        else{
            return SearchTree(Left(P), X) || SearchTree(Right(P), X);
        }
    }
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt (BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
    if (IsTreeEmpty(P)){
        return 0;
    }
    else {
        return NbElmt(Left(P)) + NbElmt(Right(P)) + 1 ;
    }
}

int NbDaun (BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
{
    if (IsTreeEmpty(P)){
        return 0;
    }
    else {
        if (IsTreeOneElmt(P)){
            return 1;
        }
        else{
            return NbDaun(Left(P)) + NbDaun(Right(P));
        }
    }
}

boolean IsSkewLeft (BinTree P)
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
{

    if (IsTreeEmpty(P)){
        return true;
    }
    else if (IsTreeOneElmt(P)){
        return true;
    }
    else{
        return IsSkewLeft(Left(P)) && (Right(P) == Nil);
    }
}

boolean IsSkewRight (BinTree P)
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
{
    if (IsTreeEmpty(P)){
        return true;
    }
    else if (IsTreeOneElmt(P)){
        return true;
    }
    else{
        return IsSkewRight(Right(P)) && (Left(P) == Nil);
    }
}

int Level (BinTree P, infotype X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
{
    if (SearchTree(Left(P), X)){
        return 1 + Level(Left(P), X);
    }

    else if (SearchTree(Right(P), X)){
        return 1 + Level(Right(P), X);
    }

    /* Akar(P) == X */
    else {
        return 1;
    }
}

int Tinggi (BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
{
   if (IsTreeEmpty(P)){
        return 0;
   }
   else{
        int Tinggi_l = Tinggi(Left(P));
        int Tinggi_r = Tinggi(Right(P));

        if (Tinggi_l > Tinggi_r){
            return Tinggi_l + 1;
        }
        else{
            return Tinggi_r + 1;
        }
   }
}

/* *** Operasi lain *** */
void AddDaunTerkiri (BinTree *P, infotype X)    /* 37 - 38 */
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{

    if (IsTreeEmpty(*P)){
        *P = Tree(X, Nil, Nil);
    }
    else{
        AddDaunTerkiri(&Left(*P), X);
    }
}

void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri) /* 39 - 40 */
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
{
    if (IsTreeOneElmt(*P) && Akar(*P) == X){

        if (Kiri){
            Left(*P) = Tree(Y, Nil, Nil);
        }
        else{
            Right(*P) = Tree(Y, Nil, Nil);
        }
    }

    /* Kalau daun bukan X */
    else{
        if (SearchTree(Left(*P), X)){
            AddDaun(&Left(*P), X, Y, Kiri);
        }
        else if (SearchTree(Right(*P), X)){
            AddDaun(&Right(*P), X, Y, Kiri);
        }
    }
}

void DelDaunTerkiri (BinTree *P, infotype *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
{
    if (IsTreeOneElmt(*P)){
        *X = Akar(*P);
        addrNode temp = *P;
        *P = Nil;
        DealokNode(temp);
    }
    else{
        if (IsUnerRight(*P)){
            DelDaunTerkiri(&Right(*P), X);
        }
        else{
            DelDaunTerkiri(&Left(*P), X);
        }
    }
}

void DelDaun (BinTree *P, infotype X)       /* 43 - 44 */
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
{

    if (!IsTreeEmpty(*P)){

        if (IsTreeOneElmt(*P) && Akar(*P) == X){
            addrNode temp = *P;
            *P = Nil;
            DealokNode(temp);
        }

        else {

            DelDaun(&Left(*P), X);
            DelDaun(&Right(*P), X);
        }
    }
}

List MakeListDaun (BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{

    if (IsTreeEmpty(P)){
        return Nil;
    }

    else if (IsTreeOneElmt(P)){
        return Alokasi(Akar(P));
    }

    else{

        List Left_l = MakeListDaun(Left(P));
        List Right_l = MakeListDaun(Right(P));
        return Concat(Left_l, Right_l);
    }

}

List MakeListPreorder (BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   dengan urutan preorder, jika semua alokasi berhasil.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
   if (IsTreeEmpty(P)){
        return Nil;
   }
   else{

        List Left_l = MakeListPreorder(Left(P));
        List Right_l = MakeListPreorder(Right(P));

        return Concat(Konso(Akar(P), Left_l), Right_l);
   }
}

List MakeListLevel (BinTree P, int N)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   yang levelnya=N, jika semua alokasi berhasil.
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
    if (IsTreeEmpty(P)){
        return Nil;
    }

    else if (N == 1){
        return Alokasi(Akar(P));
    }

    else {

        List Left_l = MakeListLevel(Left(P), N-1);
        List Right_l = MakeListLevel(Right(P), N-1);

        return Concat(Left_l, Right_l);

    }
}
