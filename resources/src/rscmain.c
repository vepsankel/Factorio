//
// Created by evghe on 2/19/2023.
//

#include "../inc/rscmain.h"

List * rscList = NULL;

int rscPrintResource(void * data) {
    if (RSC_DEBUG) {
        printf("RSC_DEBUG: entered rscPrintResource function\r\n");
    }

    Rsc * rsc = (Rsc*) data;
    if (printf("\r\n{\r\nName: %s\r\n}",rsc->name) < 0) {
        printf("Could not print resource\r\n");
        return FAILURE;
    }

    if (RSC_DEBUG) {
        printf("RSC_DEBUG: exited rscPrintResource function\r\n");
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

    if (listNew(&rscList) != SUCCESS) {
        printf("Could not initialise resources\r\n");
        return FAILURE;
    }

    listSetComparedTo(rscList, rscCmpResource);
    listSetToString(rscList, rscPrintResource);

    return SUCCESS;
}

int rscNewResource(const char * name) {
    if (RSC_DEBUG) {
        printf("RSC_DEBUG: entered rscNewResource function with name = %s\r\n", name);
    }

    Rsc * resource = malloc(sizeof(Rsc));

    if (resource == NULL) {
        printf("Could not allocate memory for resource!\r\n");
        return FAILURE;
    }

    resource->name = (char *)malloc(strlen(name) + 1);
    memcpy((void *) resource->name, name, strlen(name) + 1);

    if (resource->name == NULL) {
        printf("Could not allocate memory for name copy!\r\n");
        return FAILURE;
    }

    if (listAddData(rscList, resource) != SUCCESS) {
        printf("Could not add resource\r\n");
        return FAILURE;
    }

    if (RSC_DEBUG) {
        printf("RSC_DEBUG: exited rscNewResource function\r\n");
    }

    return SUCCESS;
}

int rscPrintResources() {
    return listPrint(rscList);
}