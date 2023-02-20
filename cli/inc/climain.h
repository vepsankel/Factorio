//
// Created by Sandu on 2/20/2023.
//

#ifndef FACTORIO_CLIMAIN_H
#define FACTORIO_CLIMAIN_H

#define BUFF_SIZE 256
#define WORDS_IN_COMMAND 32

#include <stdio.h>
#include <string.h>
#include "consts.h"

extern unsigned int cliWordsInCommand;
extern char cliBuff[BUFF_SIZE];
extern const char * cliWords[WORDS_IN_COMMAND];
extern int cliMain();

#endif //FACTORIO_CLIMAIN_H
