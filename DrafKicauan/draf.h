/* File: Draflinked.h */

#ifndef DrafLINKED_H
#define DrafLINKED_H

#include "../Kicauan/kicauan.h"

#define NIL NULL
/* Deklarasi infotype */
/* Draf dengan representasi berkait dengan pointer */
typedef struct node_draf *Address_draf;
typedef struct node_draf {
    Kicauan info;
    Address_draf next;
} Node_draf;

/* Type Draf dengan ciri Top: */
typedef struct
{
    Address_draf addrTop; /* alamat Top: elemen puncak */
} Draf;

/* Selektor */
#define NEXT_DRAF(p) (p)->next
#define INFO_DRAF(p) (p)->info
#define ADDR_TOP_DRAF(s) (s).addrTop
#define INFO_TOP_DRAF(s) (s).addrTop->info

/* Prototype manajemen memori */
Address_draf newNodeDraf(Kicauan k);
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x,
   atau
   NULL jika alokasi gagal */

/* ********* PROTOTYPE REPRESENTASI LOJIK Draf ***************/
boolean isEmptyDraf(Draf s);
/* Mengirim true jika Draf kosong: TOP(s) = NIL */

int lengthDraf(Draf s);
/* Mengirimkan banyaknya elemen Draf. Mengirimkan 0 jika Draf s kosong */

void CreateDraf(Draf *s);
/* I.S. sembarang */
/* F.S. Membuat sebuah Draf s yang kosong */

/* Proses : Menuliskan isi Draf, ditulis di antara kurung siku; antara dua elemen
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah,
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1 (TOP), 20, 30 akan dicetak: [1,20,30] */
/* Jika Draf kosong : menulis [] */

void pushDraf(Draf *s, Kicauan k);
/* Menambahkan x sebagai elemen Draf s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */

void popDraf(Draf *s, Kicauan *k);
/* Menghapus Top dari Draf s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */
// void BUAT_DRAF();
// void LIHAT_DRAF();
#endif