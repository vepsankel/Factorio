//
// Created by evghe on 2/19/2023.
//

#include "../inc/rsccmd.h"

char buff[BUFF_SIZE];

unsigned int wordCount;
const char * words[WORDS_IN_COMMAND];

void printHelp() {
    printf("Manage resources:"
           "add *resource name* - Adds Resource;"
           "print - Prints Resources;"
           "delete - deletes Resources;\r\n");
}

int rscCmdMain() {

}

