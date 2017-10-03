
/*------------------*/
/* Jessin Donnyson  */
/*     13516112     */
/*   Praktikum 04   */
/*   12 Sept 2017   */
/*------------------*/


#include <stdio.h>
#include "matriks.h"

/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    //ElType *M.Mem[NB+1][NK+1];      /* !!!!!!!! check whether this need to be aplied !!!!!!!!!!! */
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}


/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return ((i >= BrsMin && i <= BrsMax) && (j >= KolMin && j <= KolMax));
}


/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return NBrsEff(M);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return NKolEff(M);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return ( ( i>= BrsMin) && (i <= NBrsEff(M)) && (j >= KolMin) && (j<= NKolEff(M)) );
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    return Elmt(M,i,i);
}


/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    indeks i,j;

    MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);
    for (i = BrsMin; i <= NBrsEff(MIn); i++){
        for (j = KolMin; j <= NKolEff(MIn); j++){
            Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
    indeks i, j;
    ElType num;

    MakeMATRIKS(NB, NK, M);

    for (i = BrsMin; i <= NBrsEff(*M); i++){
        for (j = KolMin; j <= NKolEff(*M); j++){
            scanf("%d",&num);
            Elmt(*M, i, j) = num;
        }
    }

}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    indeks i, j;
     for (i = BrsMin; i <= NBrsEff(M); i++){
        for (j = KolMin; j <= NKolEff(M); j++){
            printf("%d",Elmt(M, i, j));

            if (j < NKolEff(M)) {
                printf(" ");
            }
            else if ((j = NKolEff(M)) && (i != NBrsEff(M)) ) {
                printf("\n");
            }
        }
    }

}


/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
    indeks i, j;
    MATRIKS MHsl;

    MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &MHsl);

    for (i = BrsMin; i <= NBrsEff(M1); i++){
        for (j = KolMin; j <= NKolEff(M1); j++){

            Elmt(MHsl, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);

        }
    }

    return MHsl;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
    indeks i, j;
    MATRIKS MHsl;

    MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &MHsl);

    for (i = BrsMin; i <= NBrsEff(M1); i++){
        for (j = KolMin; j <= NKolEff(M1); j++){

            Elmt(MHsl, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);

        }
    }

    return MHsl;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
    indeks i, j, k;
    ElType sum;
    MATRIKS MHsl;

    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &MHsl);

    for (i = BrsMin; i <= NBrsEff(MHsl); i++){
        for (j = KolMin; j <= NKolEff(MHsl); j++){

            sum = 0;
            for (k = KolMin; k <= NKolEff(M1) ; k++){
                sum += Elmt(M1,i,k) * Elmt(M2,k, j);
            }

            Elmt(MHsl, i, j) = sum;

        }
    }

    return MHsl;
}


MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
    indeks i, j;
    MATRIKS MHsl;

    MakeMATRIKS(NBrsEff(M), NKolEff(M), &MHsl);

    for (i = BrsMin; i <= NBrsEff(M); i++){
        for (j = KolMin; j <= NKolEff(M); j++){

            Elmt(MHsl, i, j) = Elmt(M, i, j) * X ;
        }
    }

    return MHsl;
}

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{

    indeks i, j;

    for (i = BrsMin; i <= NBrsEff(*M); i++){
        for (j = KolMin; j <= NKolEff(*M); j++){

            Elmt(*M, i, j) *= K;

        }
    }
}


/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
    indeks i,j;

     if ( (NBrsEff(M1) != NBrsEff(M2)) || (NKolEff(M1) != NKolEff(M2)) ){
        return false;
     }
     else if ( (GetFirstIdxBrs(M1) != GetFirstIdxBrs(M2)) || (GetLastIdxKol(M1) != GetLastIdxKol(M2)) ){
        return false;
     }
     else{
        for (i = BrsMin; i <= NBrsEff(M1); i++){
            for (j = KolMin; j <= NKolEff(M1); j++){

                if ( Elmt(M1, i, j) != Elmt(M2, i, j) ){
                    return false;
                }
            }
        }
     }

     return true;

}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    return !(EQ(M1,M2));
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
    return ( (NBrsEff(M1) == NBrsEff (M2)) && (NKolEff (M1) == NKolEff (M2)) );
}


/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    return (NBrsEff(M)*NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    return (NBrsEff(M) == NKolEff(M));
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
    indeks i, j;

    if (!(IsBujurSangkar(M))){
        return false;
    }
    else {
        for (i = BrsMin; i <= NBrsEff(M); i++){
            for (j = KolMin; j <= NKolEff(M); j++){
                if (Elmt(M, i, j) != Elmt(M, j, i)){
                    return false;
                }
            }
        }
    }

    return true;

}

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
   indeks i, j;

    if (!(IsBujurSangkar(M))){
        return false;
    }
    else {
        for (i = BrsMin; i <= NBrsEff(M); i++){
            for (j = KolMin; j <= NKolEff(M); j++){
                if (i == j){
                    if (Elmt(M, i, j) != 1 ){
                        return false;
                    }
                }
                else{
                    if (Elmt(M, i, j) != 0 ){
                        return false;
                    }
                }

            }
        }
    }

    return true;
}


boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    indeks i,j;
    int counter = 0;
    int limit = NBrsEff(M) * NKolEff(M) * 0.05;

    for (i = BrsMin; i <= NBrsEff(M); i++){
            for (j = KolMin; j <= NKolEff(M); j++){
                if (Elmt(M, i, j) != 0){
                    counter += 1;
                }
            }
        }

    return (counter <= limit);    /*  !!!!!!!!!!!    check if <= or < only !!!!!!!!!!!    */
}


MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    return KaliKons(M, -1);
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
    int brsneff = NBrsEff(M);
    int kolneff = NKolEff(M);
    float Mcopy[brsneff+1][kolneff+1];

    indeks i, j;
    float det = 1;

    void swap_rows(float M[brsneff+1][kolneff+1], int a, int b, float * det){
    /* a dan b adalah baris yang akan ditukar */
        float Temp;
        indeks i;

        for (i = KolMin; i <= kolneff; i++){
            Temp = M[a][i];
            M[a][i] = M[b][i];
            M[b][i] = Temp;
        }

        *det = -(*det); /* setelah 2 baris ditukar, determinan menjadi -determinan */
    }

    void make_one(float M[brsneff+1][kolneff+1], int a, float * det){
    /* a,a adalah index element diagonal yang akan dibuat 1 */

        indeks i;
        int z = 1;

        float divider = M[a][a] ;

        /* tukar baris jika elemen diagonal determinannya sudah 0  */
        while ((divider == 0) && (a+z <= kolneff)){
            swap_rows(M, a, a+z, det);
            divider = M[a][a];
            z += 1;
        }

        if ((divider == 0) && (a+z > kolneff)){ /* matriks unsolvable */
            *det = 0;
            return;
        }

        for (i = a; i <= kolneff; i++){
            M[a][i]  = M[a][i]  / divider;
        }
        *det = *det * divider;
    }

    void make_zero(float M[brsneff+1][kolneff+1], int a){
    /* reduce column a to 0 */
        indeks i,j ;

        for (i = a+1; i <= brsneff; i++){
            for (j = kolneff; j >= a; j--){
                M[i][j] -= (M[i][a] * M[a][j] / M[a][a]);
            }
        }
    }



    /* copy matriks M ke matriks Mcopy */
    for (i = BrsMin; i <= brsneff; i++){
        for (j = KolMin; j <= kolneff; j++){
            Mcopy[i][j] = Elmt(M, i, j);
        }
    }

    /* untuk setiap kolom, lakukan operasi baris elementer */
    for (i = KolMin; i <= kolneff; i++){
        make_one(Mcopy,i, &det);  /* bagi Mcopy[i,i] sehingga menjadi 1 */


        if (det == 0){
            return 0.000000;
        }

        /*
        printf("\n\n");
        for (k = BrsMin; k <= brsneff; k++){
            for (j = KolMin; j <= kolneff; j++){
                printf("%.2f ",Mcopy[k][j]);
            }
            printf("\n");
        }*/

        make_zero(Mcopy,i); /* kurangi baris sisasnya hingga menjadi 0 */

        /*
        printf("\n\n");
        for (k = BrsMin; k <= brsneff; k++){
            for (j = KolMin; j <= kolneff; j++){
                printf("%.2f ",Mcopy[k][j]);
            }
            printf("\n");
        }
        */

    }
    return det;
}


void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    return PKaliKons(M, -1);
}


void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
    ElType temp;
    indeks i,j;

    for (i = BrsMin; i <= NBrsEff(*M); i++){
            for (j = i; j <= NKolEff(*M); j++){
                temp = Elmt(*M, i, j);
                Elmt(*M, i, j) = Elmt(*M, j, i);
                Elmt(*M, j, i) = temp;
            }
        }
}

float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
	float sum = 0;
	indeks j;
	
	for (j = KolMin; j <= NKolEff(M); j++){
		sum += Elmt(M,i,j);
	}
	
	return (sum / (NKolEff(M)));
}

float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
	float sum = 0;
	indeks i;
	
	for (i = BrsMin; i <= NBrsEff(M); i++){
		sum += Elmt(M,i,j);
	}
	
	return (sum / (NBrsEff(M)));
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
	*max = -9999;
	*min = 9999;
	indeks j;
	
	for (j = KolMin; j <= NKolEff(M); j++){
		if (Elmt(M,i,j) > *max) {
			*max = Elmt(M,i,j);
		}
		if (Elmt(M,i,j) < *min) {
			*min = Elmt(M,i,j);
		}
	}
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
	*max = -9999;
	*min = 9999;
	indeks i;
	
	for (i = BrsMin; i <= NBrsEff(M); i++){
		if (Elmt(M,i,j) > *max) {
			*max = Elmt(M,i,j);
		}
		if (Elmt(M,i,j) < *min) {
			*min = Elmt(M,i,j);
		}
	}
}

int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
	int counter = 0;
	indeks j;
	
	for (j = KolMin; j <= NKolEff(M) ; j++ ){
		if ( Elmt(M,i,j) == X){
			counter += 1;
		}
	}
	
	return counter;
}	

int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
	int counter = 0;
	indeks i;
	
	for (i = BrsMin; i <= NBrsEff(M) ; i++ ){
		if ( Elmt(M,i,j) == X){
			counter += 1;
		}
	}
	
	return counter;
}
