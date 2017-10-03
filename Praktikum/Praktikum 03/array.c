

/* Tugas ADT ALSTRUKDAT 03 */

/* 5 Sept 2017 */
/* Jessin Donnyson */
/* 13516112 */

/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#include "array.h"
#include <stdio.h>

/*

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999

*/

/*
typedef int IdxType;
typedef int ElType;
typedef struct {
	ElType TI[IdxMax+1];
	int Neff;  >=0, banyaknya elemen efektif
} TabInt; */

/* Indeks yang digunakan [IdxMin..IdxMax] */

/* Definisi :
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */


/* ********** SELEKTOR ********** */

/*
#define Neff(T)   (T).Neff
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)]
*/


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    Neff(*T) = 0;
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    return Neff(T);
}

int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
{
    return IdxMax;
}

IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return Neff(T);
}


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i >= IdxMin)&&(i <= IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return ((i >= GetFirstIdx(T))&&(i <= GetLastIdx(T)));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (Neff(T)==0);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (Neff(T)==(IdxMax-IdxMin+1));
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    int N;
    int num;
    int i;

    do {
        scanf("%d",&N);
    }
    while (!((N>=0) && (N <= MaxNbEl(*T))));

    if (N ==0 ){
        MakeEmpty(&T);
    }

    Neff(*T) = N;
    for ( i = IdxMin;(i< N);i++){
        scanf("%d\n",&num);
        Elmt(*T,i) = num;
    }

    if (!IsEmpty(*T)){
    scanf("%d",&num);
    Elmt(*T,Neff(*T)) = num;}
}

void BacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
    int num;
    int i = IdxMin;

    while(1){


        if(i > IdxMax){
                /* Just in case filled up until 100 and not yet a single -9999 */
            break;
            }

        scanf("%d",&num);

        if (num == (-9999)){
            break;
        }

        else{
            Elmt(*T,i) = num;
            i += 1;
        }
    }
    Neff(*T) = i-1;

    if (IsEmpty(*T)){
        MakeEmpty(&T);
    }

}

void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
    int i;

    if (IsEmpty(T)){
        printf("Tabel kosong\n");
    }
    else {
        for ( i = IdxMin;(i <= Neff(T));i++){
            printf("[%d]%d\n",i,Elmt(T,i));
        }

    }
}

void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    int i;

    if (IsEmpty(T)){
        printf("[]"); /* no 32 */
    }
    else{
        printf("[");
        for ( i = IdxMin;(i < Neff(T));i++){
            printf("%d,",Elmt(T,i));
        }
        printf("%d]",Elmt(T,Neff(T)));
    }
}



/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
    TabInt Tsum;
    int i;

    for ( i=IdxMin;(i<=Neff(T1));i++){
        Elmt(Tsum,i) = Elmt(T1,i) + Elmt(T2,i);
    }
    Neff(Tsum) = Neff(T1);

    return Tsum;
}

TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    TabInt Tdim;
    int i;

    for ( i=IdxMin;(i<=Neff(T1));i++){
        Elmt(Tdim,i) = Elmt(T1,i) - Elmt(T2,i);
    }
    Neff(Tdim) = Neff(T1);

    return Tdim;
}

TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
    TabInt Ttim;
    int i;

    for ( i=IdxMin;(i<=Neff(T1));i++){
        Elmt(Ttim,i) = Elmt(T1,i) * Elmt(T2,i);
    }
    Neff(Ttim) = Neff(T1);

    return Ttim;
}
TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
    TabInt Ttim;
    int i;

    for ( i=IdxMin;(i<=Neff(Tin));i++){
        Elmt(Ttim,i) = Elmt(Tin,i) * c;
    }
    Neff(Ttim) = Neff(Tin);

    return Ttim;
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
    int i;

    if (Neff(T1) != Neff(T2)){
        return false;
    }
    else{
        for ( i = IdxMin;(i<= Neff(T1));i++){
            if (Elmt(T1,i) != Elmt(T2,i)) {
                return false;
            }
        }
    }

    /* if the array is exactly the same */
    return true;
}

boolean IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < 'Badu'; maka [0, 1] < [2, 3] */
{
    int i;


    if (IsEQ(T1, T2)){ // check equal ?
        return false;
    }

    else{
        for ( i = IdxMin;(i <= Neff(T1));i++){
            if (Elmt(T1,i) > Elmt(T2,i)) {
                return false;
            }
            else if (Elmt(T1,i) < Elmt(T2,i)) {
                    return true;
            }
        }
    }
    if (Neff(T1) > Neff(T2)){
        return false;
    }

    /* if the T1 is less than T2 */
    return true;
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
    /* no 53 - 59 */

    int i;
    for ( i = IdxMin;(i<= Neff(T));i++){
            if (Elmt(T,i) == X){
                /* if X is found */
                return i;
            }
        }

    /* only execute if X is not found */
    return IdxUndef;
}

IdxType Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
    boolean Found = false;
    int i;

    for ( i = IdxMin;(i<= Neff(T));i++){
            if (Elmt(T,i) == X){
                Found = true;
                break;
            }
        }

    if (Found){
        return i;
    }
    else{
        return IdxUndef;
    }

}

boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
    boolean Found = false;
    int i;

    for ( i = IdxMin;(i<= Neff(T));i++){
            if (Elmt(T,i) == X){
                Found = true;
                break;
            }
        }

    return Found;
}

boolean SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C
   yang tidak dipakai dalam definisi tabel */
{
    Elmt(T,0) = X;
    int i;

    for ( i = Neff(T);(i>=0);i--){
            if (Elmt(T,i) == X){
                if (i != 0){
                    return true;
                }
            }
        }

    return false;
}


/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    int max = -32600;
    int i;

    for ( i = IdxMin; (i <= Neff(T)); i++){
        if (Elmt(T,i) > max) {
            max = Elmt(T,i);
        }
    }

    return max;
}
ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
    int min = 32600;
    int i;

    for ( i = IdxMin; (i <= Neff(T)); i++){
        if (Elmt(T,i) < min) {
            min = Elmt(T,i);
        }
    }

    return min;
}


/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
    int idx_max = IdxMin;
    int i;

    for ( i = IdxMin; (i <= Neff(T)); i++){
        if (Elmt(T,i) > Elmt(T,idx_max)) {
            idx_max = i;
        }
    }

    return idx_max;
}
IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{

    int idx_min = IdxMin;
    int i;
    for ( i = IdxMin; (i <= Neff(T)); i++){
        if (Elmt(T,i) < Elmt(T,idx_min)) {
            idx_min = i;
        }
    }

    return idx_min;
}


/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */

/* QUESTION : WHAT IF TOUT ALREADY HAVE MORE ARRAY ELEMENTS THAN TIN ?? */

{
    int i;
    Neff(*Tout) = Neff(Tin);
    for ( i = IdxMin; (i <= Neff(Tin)); i++){
        Elmt(*Tout,i) = Elmt(Tin,i);
    }
}

TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
    TabInt InvT;
    int i;

    if (IsEmpty(T)){
        return T;
    }

    Neff(InvT) = Neff(T);

    for ( i = IdxMin; (i <= Neff(T)); i++){
        Elmt(InvT, (Neff(InvT)+1-i) ) = Elmt(T,i);
    }

    return InvT;
}

boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
    int i;

    for (i = IdxMin; (i <= Neff(T)); i++){
        if ((Elmt(T,i)) != (Elmt(T,Neff(T)+1-i))){
            return false;
        }
    }

    return true;
}


/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
    int i, j, max_idx;

    if (!(IsEmpty(*T))){
        for (i = IdxMin; (i <= (Neff(*T)-1)); i++)
        {
            max_idx = i;
            for (j = i+1; j <= Neff(*T); j++){
              if ((Elmt(*T,j)) > (Elmt(*T,max_idx))){
                   max_idx = j;
                   }
            }


            int Temp = Elmt(*T,max_idx);
            Elmt(*T,max_idx) = Elmt(*T, i);
            Elmt(*T, i) = Temp;

        }
    }

    /*ElType temp;
    IdxType i, iMax, step;
    iMax = GetFirstIdx(*T);
    if (Neff(*T) > 1){
        for (step = 1; step <= GetLastIdx(*T)-1; step++){
            iMax = step;
            for (i = step+1 ; i <= GetLastIdx(*T); i++){
                if (Elmt(*T,i) > Elmt (*T,iMax)){
                    iMax = i;
                }
            }

            temp = Elmt(*T,iMax);
            Elmt(*T, iMax) = Elmt(*T, step);
            Elmt(*T,step) = temp;
        }
    }
    */

}

void InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */

/*          tanpa menggunakan tabel kerja */
{

    int i, key, j;
    if (Neff(*T) > 1){
        for (i = IdxMin+1; (i <= Neff(*T)); i++){
           key = Elmt(*T,i);
           j = i-1;

           while ((j >= IdxMin) && (Elmt(*T,j) > key))
           {
               Elmt(*T,j+1) = Elmt(*T,j);
               j = j-1;
           }
           Elmt(*T,j+1) = key;
       }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    Neff(*T) += 1;
    Elmt(*T,Neff(*T)) = X;
}

void AddEli (TabInt * T, ElType X, IdxType i)   // or maybe this one ?
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{

    int j;

    Neff(*T) += 1;
    for ( j = Neff(*T) ; (j > i); j--){
        Elmt(*T, j) = Elmt(*T, j-1);
        }
    Elmt(*T, i) = X;
}


/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    *X = Elmt(*T, GetLastIdx(*T));
    Neff(*T) -= 1;

    // is this X causing 104 - 107 ?? //
}

void DelEli (TabInt * T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
    int j;

    Neff(*T) -= 1;
    for ( j = i; (j <= Neff(*T)); j++){
        Elmt(*T, j) = Elmt(*T, j+1);
        }
}


/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
        jika belum ada elemen yang bernilai X.
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
    boolean found = false;
    int i;

    /* set sentinel, I suppose */
    Elmt(*T, 0) = X;

    if (IsEmpty(*T)){
        Elmt(*T, IdxMin) = X;
        Neff(*T) = 1;
    }
    else{
        for (i = IdxMin;(i<= Neff(*T));i++){
            if (Elmt(*T, i) == Elmt(*T,0)){
                found = true;
                printf("nilai sudah ada\n");
                break;
            }
        }

        if (!(found)){
            Elmt(*T,Neff(*T)+1) = Elmt(*T,0);
            Neff(*T) += 1;
        }
    }
}


/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
    int i;

    for (i = IdxMin; ( (i<= Neff(T)) && (Elmt(T,i)<= X) ); i++){
            if (Elmt(T, i) == X){
                return i;
            }
        }

    return IdxUndef;
}

ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
    return Elmt(T, Neff(T));
}

ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
    return Elmt(T, IdxMin);
}

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    *Max = MaxUrut(T);
    *Min = MinUrut(T);
}

void Add1Urut (TabInt * T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
    if (Neff(*T) < IdxMax){
        Elmt(*T, Neff(*T)+1) = X;
        Neff(*T) += 1;
        InsSortAsc(T);
    }
}

void Del1Urut (TabInt * T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
        int found_index = Search1(*T, X);

        if (found_index != IdxUndef){
            DelEli(T, found_index, &X);
        }
}


/* END OF CODE */
