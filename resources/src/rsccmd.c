//
// Created by evghe on 2/19/2023.
//

#include "../inc/rsccmd.h"

int printHelp() {
    printf("==================== HELP ====================\r\n");
    printf(           "add *name*\t\tAdd Resource\r\n"
           "show\t\t\tShow Resources\r\n"
           "delete\t\t\tDelete Resource\r\n");

    return SUCCESS;
}

int rscAddResource(const char * name) {
    if (RSC_DEBUG) {
        printf("RSC_DEBUG: entered rscAddResource function\r\n");
    }
    return rscNewResource(name);
}

int rscShowResources() {
    if (RSC_DEBUG) {
        printf("RSC_DEBUG: entered rscShowResources function\r\n");
    }
    return rscPrintResources();
}

int rscCmd(const char ** cliWords, unsigned int cliWordsInCommand) {
    if (RSC_DEBUG) {
        printf("RSC_DEBUG: entered rscCmd function\r\n");
    }

    // below commands that require at least 0 words
    if (cliWordsInCommand == 0) {
        printf("Not implemented. resource help\r\n");
        return SUCCESS;
    }

    // below commands that require at least 1 word
    if (strncmp(cliWords[0], "help", 4) == 0){
        return printHelp();
    }

    if (strncmp(cliWords[0], "show", 4) == 0){
        return rscShowResources();
    }

    // below commands that require at least 2 words
    if (cliWordsInCommand < 2)
        return SUCCESS;

    if (strncmp(cliWords[0], "add", 3) == 0){
        rscAddResource(cliWords[1]);
    }
}