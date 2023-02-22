//
// Created by evghe on 2/19/2023.
//

#ifndef FACTORIO_RSCMAIN_H
#define FACTORIO_RSCMAIN_H

#include "rscinc.h"

extern List * rscList;

typedef struct {
    char * name;
} Rsc;

extern int rscInit(char * filename);
extern int rscNewResource(const char * name);
extern int rscPrintResource(void * data);
extern int rscPrintResources();
extern int rscCmpResource(void * data1, void * data2, bool * r);

#endif //FACTORIO_RSCMAIN_H
