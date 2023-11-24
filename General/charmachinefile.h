#ifndef __CHAR_MACHINE_FILE_H__
#define __CHAR_MACHINE_FILE_H__

#include "boolean.h"
#include "charmachine.h"
#include <stdio.h>

#define MARK_FILE "\r\n"

/* Char Engine State*/
extern char currentCharFile;
extern boolean eotFile;

void STARFILE(char namaFile[]);

void ADVFILE();

void ENDFILE();

#endif