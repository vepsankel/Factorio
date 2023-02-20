//
// Created by evghe on 2/19/2023.
//

#ifndef FACTORIO_RSCMAIN_H
#define FACTORIO_RSCMAIN_H

#include "../../util/inc/list.h"
#include <string.h>
#include <stdio.h>

extern List * rscList;

typedef struct {
    const char * name;
} Rsc;

extern int rscInit(char * filename);
extern int rscNewResource(char * name);
extern int rscPrintResource(void * data);
extern int rscCmpResource(void * data1, void * data2, bool * r);

#endif //FACTORIO_RSCMAIN_H
