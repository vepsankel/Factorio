//
// Created by evghe on 2/19/2023.
//

#ifndef FACTORIO_RSCCMD_H
#define FACTORIO_RSCCMD_H

#include <string.h>
#include <stdio.h>
#include "../../util/inc/consts.h"

#define BUFF_SIZE 256
#define WORDS_IN_COMMAND 10

extern char buff[BUFF_SIZE];
extern const char * words[WORDS_IN_COMMAND];
extern int rscCmdMain();

#endif //FACTORIO_RSCCMD_H
