// save_load.h

#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include "../Balasan/balasan.h"
#include "../Balasan/commandBalasan.h"

#include "../DrafKicauan/commandDraf.h"
#include "../DrafKicauan/draf.h"

#include "../FotoProfil/fotoProfil.h"
#include "../Kicauan/tabKicauan.h"

#include "../Pengguna/tabPengguna.h"

#include "../PermintaanTeman/commandPermintaanTeman.h"
#include "../PermintaanTeman/permintaanTeman.h"

#include "../Teman/commandTeman.h"
#include "../Teman/teman.h"

#include "../Utas/commandUtas.h"
#include "../Utas/tabUtas.h"
#include "../Utas/utas.h"

#include "charmachinefile.h"
#include "wordmachinefile.h"

Word writefilename(Word input1, Word input2);
void createFile(char *fullPath, char *filename);
void simpanPengguna(TabPengguna datapengguna, Word inputfile, AdjacencyMatrix mteman);
void simpanKicauan(Word inputfile,TabKicauan tabkicau);
void simpanBalasan(int jumlahKicauan, Word inputfile);
void simpanDraf(Word inputfile,TabPengguna datapengguna);
void simpanUtas(Word inputfile,TabUtas datautas);
void simpan(TabPengguna tabuser,AdjacencyMatrix matriksteman, TabKicauan tabkicau, TabUtas tabutas);

#endif