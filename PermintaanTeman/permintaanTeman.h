#ifndef PERMINTAAN_TEMAN_H
#define PERMINTAAN_TEMAN_H

#include "../General/boolean.h"
#include "../Pengguna/pengguna.h"

#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */
#define MaxPermintaan 20
/* Definisi elemen dan address */
typedef struct
{
    int prio;      /* popularitas pengguna */
    Pengguna info; /* pengguna */
} AnggotaTeman;
typedef int address; /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueueChar : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */

typedef struct
{
    Pengguna *T;  /* tabel penyimpan elemen */
    address HEAD; /* alamat penghapusan */
    address TAIL; /* alamat penambahan */
} PermintaanTeman;
/* Definisi PrioQueueChar kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah AnggotaTeman dan Q adalah PrioQueueChar, maka akses elemen : */
#define Prio(e) (e).prio
#define Info(e) (e).info
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl
#define Elmt(Q, i) (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsPermintaanTemanEmpty(PermintaanTeman Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsPermintaanTemanFull(PermintaanTeman Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int BanyakPermintaanTeman(PermintaanTeman Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreatePermintaanTeman(PermintaanTeman *Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DealokasiPermintaanTeman(PermintaanTeman *Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void EnqueuePermintaanTeman(PermintaanTeman *Q, AnggotaTeman X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void DequeuePermintaanTeman(PermintaanTeman *Q, AnggotaTeman *X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void CetakPermintaanTeman(PermintaanTeman Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
#endif