/* File: jam.c */
/* Tanggal: 28 Agustus 2016 */
/* Definisi ADT JAM */

#include "jam.h"
#include <stdio.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    {
        return ((H <= 23 && H >= 0) && (M <= 59 && M >= 0) && (S <= 59 && S >= 0));
    }


/* *** Konstruktor *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
    {
        JAM J1;
        Hour(J1) = HH;
        Minute(J1) = MM;
        Second(J1) = SS;
        return J1;
    }

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM *J)
    {
        int HH, MM, SS;

        while (1) {
            scanf("%d %d %d", &HH, &MM, &SS);
            if (IsJAMValid(HH, MM, SS)){
                break;
            }
            else {
                printf("Jam tidak valid\n");
            }
        }
        *J = MakeJAM(HH, MM, SS);

    }


void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
   {
       printf("%02d:%02d:%02d", Hour(J), Minute(J), Second(J));
   }

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
    {
        return(3600 * Hour(J) + 60 * Minute(J) + Second(J));
    }

JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
   {
        int sisa;
        JAM JOut;

        // Mencegah minus (optional)
        if (N < 0){
            N = N + 86400;
        }

        N = N % 86400;

        Hour(JOut) = N / 3600;
        sisa = N % 3600;
        Minute(JOut) = sisa / 60;
        Second(JOut) = sisa % 60;
        return JOut;
   }

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
    {
        return (JAMToDetik(J1) == JAMToDetik(J2));
    }
boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
    {
        return (!(JAMToDetik(J1) == JAMToDetik(J2)));
    }
boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
    {
        return (JAMToDetik(J1) < JAMToDetik(J2));
    }
boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
    {
        return (JAMToDetik(J1) > JAMToDetik(J2));
    }

/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
    {
        long sekarang = JAMToDetik(J);

        return DetikToJAM(sekarang + 1);
    }

JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
    {
        long sekarang = JAMToDetik(J);

        return DetikToJAM(sekarang + N);
    }
JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
    {
        long sekarang = JAMToDetik(J);

        return DetikToJAM(sekarang - 1);
    }
JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
    {
        long sekarang = JAMToDetik(J);

        return DetikToJAM(sekarang - N);
    }

/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
    {
        long selisih = JAMToDetik(JAkh) - JAMToDetik(JAw);
        if (selisih < 0) {
            selisih = selisih + 86400;
        }
        return selisih;
    }
