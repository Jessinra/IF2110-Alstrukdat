/* MODUL TABEL INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan tabel integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori tabel statik */

/* NIM       : 13516112 */
/* Nama      : Jessin Donnyson */
/* Tanggal   : 9 September 2017 */
/* Topik     : ADT Collection */
/* Deskripsi : Array implisit */


#include "arraypos.h"
#include <stdio.h>

/*
#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999
#define ValUndef 0
*/

/* Definisi elemen dan koleksi objek */
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Indeks ke-0 tidak digunakan */

/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T[i] untuk mengakses elemen ke-i */\

/* Definisi :
   Tabel kosong: semua elemen bernilai ValUndef
   Definisi elemen pertama : T[i] dengan i=1 */


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{
	int i;

	for (i = IdxMin ; (i <= (IdxMax-IdxMin+1)) ; i++){
		Elmt(*T, i) = ValUndef;
	}
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
	IdxType i = IdxMin;

	while (i <= IdxMax + IdxMin - 1 && Elmt(T, i) != ValUndef) {
		i++;
	}

	return i - IdxMin;

}

int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return IdxMax - IdxMin + 1;
}


/* *** Selektor INDEKS *** */
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
	return NbElmt(T) + IdxMin - 1;
}
/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	return ((i >= IdxMin) && (i<= IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	return (i >= GetFirstIdx(T) && i <= GetLastIdx(T) );
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
	return (NbElmt(T) == 0);
}

boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	return (NbElmt(T) == MaxNbEl(T));
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
	IdxType i;

	MakeEmpty(T);

	do {
		scanf("%d", &N);
	} while ((N < 0) || (N > MaxNbEl(*T)));

	for (i = GetFirstIdx(*T); i <= N; i++) {
		scanf("%d",&Elmt(*T, i));
	}
/*
    if (!IsEmpty(*T)){
		scanf("%d",&num);
		Elmt(*T,N) = num;
	}
*/
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

    printf("[");
	for (i = GetFirstIdx(T); IsIdxEff(T, i); i++) {
		if (i != GetFirstIdx(T)) {
			printf(",");
		}
		printf("%d",Elmt(T,i));
	}
	printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{

    TabInt Tsum;
    int i;

    MakeEmpty(&Tsum);

    for ( i=IdxMin;(i<=NbElmt(T1));i++){
		if ((Elmt(T1,i) != ValUndef) && (Elmt(T2,i) != ValUndef)){
			if (plus){
				Elmt(Tsum,i) = Elmt(T1,i) + Elmt(T2,i);
			}
			else{
				Elmt(Tsum,i) = Elmt(T1,i) - Elmt(T2,i);
			}
		}
    }

    return Tsum;

}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
    int i;

    if (NbElmt(T1) != NbElmt(T2)){
        return false;
    }
    else{
        for ( i = IdxMin;(i<= NbElmt(T1));i++){
			if ((Elmt(T1,i) != ValUndef) && (Elmt(T2,i) != ValUndef)){
				if (Elmt(T1,i) != Elmt(T2,i)) {
					return false;
				}
			}
        }
    }

    /* if the array is exactly the same */
    return true;
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
    int i;
    for ( i = IdxMin;(i<= NbElmt(T));i++){
            if (Elmt(T,i) == X){
                /* if X is found */
                return i;
            }
        }

    /* only execute if X is not found */
    return IdxUndef;
}

boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
    int i;

    for ( i = IdxMin;(i<= NbElmt(T));i++){
            if (Elmt(T,i) == X){
                return true;
            }
        }
    return false;
}


/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    *Max = -32600;
    *Min = 32600;
    int i;

    for ( i = IdxMin; (i <= NbElmt(T)); i++){
		if (Elmt(T,i) != ValUndef){

			if (Elmt(T,i) > *Max) {
				*Max = Elmt(T,i);
			}
			if (Elmt(T,i) < *Min) {
				*Min = Elmt(T,i);
			}
		}
    }
}
/* ********** OPERASI LAIN ********** */
ElType SumTab (TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
	int sum = 0;
	int i;

	for (i = IdxMin; i <= IdxMax ; i++){
		if (Elmt(T,i) != ValUndef){
			sum += Elmt(T,i);
		}

	}
	return sum;
}



int CountX (TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
	int count = 0;
	int i;

	for (i = IdxMin; i <= IdxMax ; i++){
		if (Elmt(T,i) == X){
			count += 1;
		}

	}
	return count;
}

boolean IsAllGenap (TabInt T)
/* Menghailkan true jika semua elemen T genap */
{
	int i;

	for (i = IdxMin; i <= IdxMax ; i++){
		if ((Elmt(T,i) % 2) != 0){
			return false;
		}
	}
	return true;
}


/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
	int i, j, flag, temp;

    flag = GetFirstIdx(*T);

    if (NbElmt(*T) > 1){
        for (j = IdxMin; j <= GetLastIdx(*T)-1; j++){
            flag = j;
            for (i = j+1 ; i <= GetLastIdx(*T); i++){

				if (asc){
					if (Elmt(*T,i) < Elmt (*T,flag)){
						flag = i;
					}
                }
                else{
					if (Elmt(*T,i) > Elmt (*T,flag)){
						flag = i;
					}
				}

            }

            temp = Elmt(*T,flag);
            Elmt(*T, flag) = Elmt(*T, j);
            Elmt(*T,j) = temp;
        }
    }
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

{

    Elmt(*T,GetLastIdx(*T)+1) = X;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	*X = Elmt(*T,GetLastIdx(*T));
    Elmt(*T, GetLastIdx(*T)) = ValUndef;
}
