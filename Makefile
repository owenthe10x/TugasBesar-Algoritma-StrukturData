CC = gcc
CFLAGS = -Wall -Werror -std=c11

SRC_MESINKAR = General/charmachine.c
OBJ_MESINKAR = $(SRC_MESINKAR:.c=.o)

SRC_MESINKARFILE = muatsimpan/charmachinefile.c
OBJ_MESINKARFILE = $(SRC_MESINKARFILE:.c=.o)

SRC_MESINWORD = General/wordmachine.c
OBJ_MESINWORD = $(SRC_MESINWORD:.c=.o)

SRC_MESINWORDFILE = muatsimpan/wordmachinefile.c
OBJ_MESINWORDFILE = $(SRC_MESINWORDFILE:.c=.o)

SRC_MESINSENTENCE = General/sentenceMachine.c
OBJ_MESINSENTENCE = $(SRC_MESINSENTENCE:.c=.o)

SRC_TIME_ADT = General/time_adt.c
OBJ_TIME_ADT = $(SRC_TIME_ADT:.c=.o)

SRC_DATETIME = General/datetime.c
OBJ_DATETIME = $(SRC_DATETIME:.c=.o)

SRC_LISTDINAMIS = General/listDinamis.c
OBJ_LISTDINAMIS = $(SRC_LISTDINAMIS:.c=.o)

SRC_INISIALISASI = Inisialisasi/inisialisasi.c
OBJ_INISIALISASI = $(SRC_INISIALISASI:.c=.o)

SRC_MUAT = muatsimpan/newMuat.c
OBJ_MUAT = $(SRC_MUAT:.c=.o)

SRC_SIMPA = muatsimpan/simpan.c
OBJ_SIMPA = $(SRC_SIMPA:.c=.o)

SRC_FOTOPROFIL = FotoProfil/fotoProfil.c
OBJ_FOTOPROFIL = $(SRC_FOTOPROFIL:.c=.o)

SRC_BALASAN = Balasan/balasan.c
OBJ_BALASAN = $(SRC_BALASAN:.c=.o)

SRC_CMDBALASAN = Balasan/commandBalasan.c
OBJ_CMDBALASAN = $(SRC_CMDBALASAN:.c=.o)

SRC_UTAS = Utas/utas.c
OBJ_UTAS = $(SRC_UTAS:.c=.o)

SRC_TABUTAS = Utas/tabUtas.c
OBJ_TABUTAS = $(SRC_TABUTAS:.c=.o)

SRC_CMDUTAS = Utas/commandUtas.c
OBJ_CMDUTAS = $(SRC_CMDUTAS:.c=.o)

SRC_KICAUAN = Kicauan/kicauan.c
OBJ_KICAUAN = $(SRC_KICAUAN:.c=.o)

SRC_TABKICAUAN = Kicauan/tabKicauan.c
OBJ_TABKICAUAN = $(SRC_TABKICAUAN:.c=.o)

SRC_CMDKICAUAN = Kicauan/commandKicauan.c
OBJ_CMDKICAUAN = $(SRC_CMDKICAUAN:.c=.o)

SRC_DRAFKICAUAN = DrafKicauan/draf.c
OBJ_DRAFKICAUAN = $(SRC_DRAFKICAUAN:.c=.o)

SRC_CMDDRAFKICAUAN = DrafKicauan/commandDraf.c
OBJ_CMDDRAFKICAUAN = $(SRC_CMDDRAFKICAUAN:.c=.o)

SRC_TEMAN = Teman/teman.c
OBJ_TEMAN = $(SRC_TEMAN:.c=.o)

SRC_CMDTEMAN = Teman/commandTeman.c
OBJ_CMDTEMAN = $(SRC_CMDTEMAN:.c=.o)

SRC_PERMTMAN = PermintaanTeman/permintaanTeman.c
OBJ_PERMTMAN = $(SRC_PERMTMAN:.c=.o)

SRC_CMDPERMTMAN = PermintaanTeman/commandPermintaanTeman.c
OBJ_CMDPERMTMAN = $(SRC_CMDPERMTMAN:.c=.o)

SRC_CMDPENGGUNA = Pengguna/commandPengguna.c
OBJ_CMDPENGGUNA = $(SRC_CMDPENGGUNA:.c=.o)

SRC_TABPENGGUNA = Pengguna/tabPengguna.c
OBJ_TABPENGGUNA = $(SRC_TABPENGGUNA:.c=.o)

SRC_GLOBAL = global.c
OBJ_GLOBAL = $(SRC_GLOBAL:.c=.o)

SRC_MAIN = main.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)

.PHONY: all clean test

all: main

main: $(OBJ_MESINKAR) $(OBJ_MESINKARFILE) $(OBJ_MESINWORD) $(OBJ_MESINWORDFILE) $(OBJ_MESINSENTENCE) $(OBJ_TIME_ADT) $(OBJ_DATETIME) $(OBJ_LISTDINAMIS) $(OBJ_INISIALISASI) $(OBJ_MUAT) $(OBJ_SIMPA) $(OBJ_FOTOPROFIL) $(OBJ_BALASAN) $(OBJ_CMDBALASAN) $(OBJ_UTAS) $(OBJ_TABUTAS) $(OBJ_CMDUTAS) $(OBJ_KICAUAN) $(OBJ_TABKICAUAN) $(OBJ_CMDKICAUAN) $(OBJ_DRAFKICAUAN) $(OBJ_CMDDRAFKICAUAN) $(OBJ_TEMAN) $(OBJ_CMDTEMAN) $(OBJ_PERMTMAN) $(OBJ_CMDPERMTMAN) $(OBJ_CMDPENGGUNA) $(OBJ_PENGGUNA) $(OBJ_TABPENGGUNA) $(OBJ_GLOBAL) $(OBJ_MAIN)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main *.o $(OBJ_MESINKAR) $(OBJ_MESINKARFILE) $(OBJ_MESINWORDFILE) $(OBJ_MESINWORD) $(OBJ_MESINSENTENCE) $(OBJ_TIME_ADT) $(OBJ_DATETIME) $(OBJ_LISTDINAMIS) $(OBJ_INISIALISASI) $(OBJ_MUAT) $(OBJ_SIMPA) $(OBJ_FOTOPROFIL) $(OBJ_BALASAN) $(OBJ_CMDBALASAN) $(OBJ_UTAS) $(OBJ_TABUTAS) $(OBJ_CMDUTAS) $(OBJ_KICAUAN) $(OBJ_TABKICAUAN) $(OBJ_CMDKICAUAN) $(OBJ_DRAFKICAUAN) $(OBJ_CMDDRAFKICAUAN) $(OBJ_TEMAN) $(OBJ_CMDTEMAN) $(OBJ_PERMTMAN) $(OBJ_CMDPERMTMAN) $(OBJ_CMDPENGGUNA) $(OBJ_PENGGUNA) $(OBJ_TABPENGGUNA) $(OBJ_GLOBAL) $(OBJ_MAIN)