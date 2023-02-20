//
// Created by evghe on 2/19/2023.
//

#include "../inc/rscmain.h"

List * rscList = NULL;

int rscPrintResource(void * data) {
    Rsc * rsc = (Rsc*) data;
    if (printf("Name: %s\r\n",rsc->name) < 0) {
        printf("Could not print resource\r\n");
        return FAILURE;
    }
    return SUCCESS;
}

int rscCmpResource(void * data1, void * data2, bool * r) {
    Rsc * rsc1 = (Rsc*) data1;
    Rsc * rsc2 = (Rsc*) data2;

    *r = strcmp(rsc1->name, rsc2->name);
    return SUCCESS;
}

int rscInit(char * filename) {
    printf("Should read from %s. Ignoring...\r\n",filename);

    if (newList(&rscList) != SUCCESS) {
        printf("Could not initialise resources\r\n");
        return FAILURE;
    }

    rscList->toString = rscPrintResource;
    rscList->comparedTo = rscCmpResource;

    return SUCCESS;
}

int rscNewResource(char * name) {
    if (addData(rscList, name) != SUCCESS) {
        printf("Could not add resource\r\n");
        return FAILURE;
    }

    return SUCCESS;
}