#include "../global.h"

void deleteValListDin(ListDin *l, int val){
    int idx = indexOfListDin(*l, val);
    int i;
    for (i = idx+1; i < NEFF_LIST_DIN(*l)-1; i++){
        ELMT_LIST_DIN(*l, i-1) = ELMT_LIST_DIN(*l, i);
    }
    NEFF_LIST_DIN(*l)--;
}

void CreateListDin(ListDin *l, int capacity)
{
    CAPACITY_LIST_DIN(*l) = capacity;
    NEFF_LIST_DIN(*l) = 0;
    BUFFER_LIST_DIN(*l) = (int *)malloc(capacity * sizeof(int));
};
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateListDin(ListDin *l)
{
    free(BUFFER_LIST_DIN(*l));
    CAPACITY_LIST_DIN(*l) = 0;
    NEFF_LIST_DIN(*l) = 0;
};
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY_LIST_DIN(l)=0; NEFF_LIST_DIN(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthListDin(ListDin l)
{
    return NEFF_LIST_DIN(l);
};
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
int getFirstIdxListDin(ListDin l)
{
    return IDX_MIN_LIST_DIN;
};
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
int getLastIdxListDin(ListDin l)
{
    return NEFF_LIST_DIN(l) - 1;
};
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListDin(ListDin l, int i)
{
    return (i < (CAPACITY_LIST_DIN(l)) && i >= IDX_MIN_LIST_DIN);
};

boolean isEmptyListDin(ListDin l)
{
    return (NEFF_LIST_DIN(l) == 0);
};
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullListDin(ListDin l)
{
    return (NEFF_LIST_DIN(l) == CAPACITY_LIST_DIN(l));
};
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListDin(ListDin *l)
{
    int N, i, a;
    do
    {
        scanf("%d", &N);
    } while (N < 0 || N > CAPACITY_LIST_DIN(*l));
    for (i = IDX_MIN_LIST_DIN; i < N; i++)
    {
        scanf("%d", &a);
        ELMT_LIST_DIN(*l, i) = a;
    }
    NEFF_LIST_DIN(*l) = N;
};
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY_LIST_DIN(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY_LIST_DIN(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printListDin(ListDin l)
{
    int i;
    printf("[");
    for (i = IDX_MIN_LIST_DIN; i < listLengthListDin(l); i++)
    {
        if (i == listLengthListDin(l) - 1)
        {
            printf("%d", ELMT_LIST_DIN(l, i));
        }
        else
        {
            printf("%d,", ELMT_LIST_DIN(l, i));
        }
    }
    printf("]");
};
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusListDin(ListDin l1, ListDin l2, boolean plus)
{
    ListDin L;
    CreateListDin(&L, NEFF_LIST_DIN(l1));
    int i;
    for (i = IDX_MIN_LIST_DIN; i < NEFF_LIST_DIN(l1); i++)
    {
        if (plus == true)
        {
            ELMT_LIST_DIN(L, i) = ELMT_LIST_DIN(l1, i) + ELMT_LIST_DIN(l2, i);
        }
        else
        {
            ELMT_LIST_DIN(L, i) = ELMT_LIST_DIN(l1, i) - ELMT_LIST_DIN(l2, i);
        }
    }
    NEFF_LIST_DIN(L) = NEFF_LIST_DIN(l1);
    return L;
};
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqualListDin(ListDin l1, ListDin l2)
{
    int i;
    if (NEFF_LIST_DIN(l1) != NEFF_LIST_DIN(l2))
    {
        return false;
    }
    else
    {
        for (i = IDX_MIN_LIST_DIN; i < NEFF_LIST_DIN(l1); i++)
        {
            if (ELMT_LIST_DIN(l1, i) != ELMT_LIST_DIN(l2, i))
            {
                return false;
            }
        }
        return true;
    }
};
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
int indexOfListDin(ListDin l, int val)
{
    int i;
    for (i = IDX_MIN_LIST_DIN; i < NEFF_LIST_DIN(l); i++)
    {
        if (ELMT_LIST_DIN(l, i) == val)
        {
            return i;
        }
    }
    return IDX_UNDEF_LIST_DIN;
};
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValuesListDin(ListDin l, int *max, int *min)
{
    int i;
    *max = ELMT_LIST_DIN(l, IDX_MIN_LIST_DIN);
    *min = ELMT_LIST_DIN(l, IDX_MIN_LIST_DIN);
    for (i = IDX_MIN_LIST_DIN; i < NEFF_LIST_DIN(l); i++)
    {
        if (ELMT_LIST_DIN(l, i) > *max)
        {
            *max = ELMT_LIST_DIN(l, i);
        }
        if (ELMT_LIST_DIN(l, i) < *min)
        {
            *min = ELMT_LIST_DIN(l, i);
        }
    }
};
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyListDin(ListDin lIn, ListDin *lOut)
{
    int i;
    CreateListDin(lOut, CAPACITY_LIST_DIN(lIn));
    for (i = 0; i < NEFF_LIST_DIN(lIn); i++)
    {
        ELMT_LIST_DIN(*lOut, i) = ELMT_LIST_DIN(lIn, i);
    }
    NEFF_LIST_DIN(*lOut) = NEFF_LIST_DIN(lIn);
};
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
int sumListDin(ListDin l)
{
    int i;
    int jumlah = 0;
    for (i = 0; i < NEFF_LIST_DIN(l); i++)
    {
        jumlah += ELMT_LIST_DIN(l, i);
    }
    return jumlah;
};
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countValListDin(ListDin l, int val)
{
    int i, total = 0;
    for (i = 0; i < NEFF_LIST_DIN(l); i++)
    {
        if (ELMT_LIST_DIN(l, i) == val)
        {
            total += 1;
        }
    }
    return total;
};
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sortListDin(ListDin *l, boolean asc)
{
    int i, j;
    int temp;
    if (asc == true)
    {
        for (i = IDX_MIN_LIST_DIN; i < listLengthListDin(*l); i++)
        {
            for (j = i + 1; j < listLengthListDin(*l); j++)
            {
                if (ELMT_LIST_DIN(*l, j) < ELMT_LIST_DIN(*l, i))
                {
                    temp = ELMT_LIST_DIN(*l, i);
                    ELMT_LIST_DIN(*l, i) = ELMT_LIST_DIN(*l, j);
                    ELMT_LIST_DIN(*l, j) = temp;
                }
            }
        }
    }
    else
    {
        for (i = IDX_MIN_LIST_DIN; i < listLengthListDin(*l); i++)
        {
            for (j = i + 1; j < listLengthListDin(*l); j++)
            {
                if (ELMT_LIST_DIN(*l, j) > ELMT_LIST_DIN(*l, i))
                {
                    temp = ELMT_LIST_DIN(*l, i);
                    ELMT_LIST_DIN(*l, i) = ELMT_LIST_DIN(*l, j);
                    ELMT_LIST_DIN(*l, j) = temp;
                }
            }
        }
    }
};
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDin(ListDin *l, int val)
{
    ELMT_LIST_DIN(*l, NEFF_LIST_DIN(*l)) = val;
    NEFF_LIST_DIN(*l) += 1;
};
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDin(ListDin *l, int *val)
{
    *val = ELMT_LIST_DIN(*l, NEFF_LIST_DIN(*l) - 1);
    NEFF_LIST_DIN(*l) -= 1;
};
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDin(ListDin *l, int num)
{
    ListDin l1;
    int cap1, nEff1, i;

    copyListDin(*l, &l1);
    cap1 = CAPACITY_LIST_DIN(*l) + num;
    nEff1 = NEFF_LIST_DIN(*l);

    dealocateListDin(l);

    CreateListDin(l, cap1);
    NEFF_LIST_DIN(*l) = nEff1;

    for (i = 0; i < listLengthListDin(*l); i++)
    {
        ELMT_LIST_DIN(*l, i) = ELMT_LIST_DIN(l1, i);
    }
    dealocateListDin(&l1);
};
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkListDin(ListDin *l, int num)
{
    ListDin l1;
    int cap1, nEff1, i;

    copyListDin(*l, &l1);
    cap1 = CAPACITY_LIST_DIN(*l) - num;
    nEff1 = NEFF_LIST_DIN(*l);

    dealocateListDin(l);

    CreateListDin(l, cap1);
    NEFF_LIST_DIN(*l) = nEff1;

    for (i = 0; i < listLengthListDin(*l); i++)
    {
        ELMT_LIST_DIN(*l, i) = ELMT_LIST_DIN(l1, i);
    }
    dealocateListDin(&l1);
};
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressListDin(ListDin *l)
{
    ListDin l1;
    int nEff1, i;

    copyListDin(*l, &l1);
    nEff1 = NEFF_LIST_DIN(*l);

    dealocateListDin(l);

    CreateListDin(l, nEff1);
    NEFF_LIST_DIN(*l) = nEff1;

    for (i = 0; i < listLengthListDin(*l); i++)
    {
        ELMT_LIST_DIN(*l, i) = ELMT_LIST_DIN(l1, i);
    }
    dealocateListDin(&l1);
};
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */
