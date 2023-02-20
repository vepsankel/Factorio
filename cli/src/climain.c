//
// Created by Sandu on 2/20/2023.
//

#include "../inc/climain.h"

char cliBuff[BUFF_SIZE];
unsigned int cliWordsInCommand;
const char * cliWords[WORDS_IN_COMMAND];

int fillCommandWords() {
    char * token = strtok(cliBuff, " ");
    unsigned int wordCountLocal = 0;

    while (token != NULL) {
        if (wordCountLocal >= 10) {
            printf("Command is too long!\r\n");
            return FAILURE;
        }

        cliWords[wordCountLocal++] = token;
        token = strtok(NULL, " ");
    }

    cliWordsInCommand = wordCountLocal;
    return SUCCESS;
}

int cliMain() {

    while (strcmp(cliBuff, "exit") != 0) {
        fgets(cliBuff, BUFF_SIZE - 1, stdin);
        fillCommandWords();

        printf("You entered:\r\n");
        for (int i = 0 ; i < cliWordsInCommand ; i++) {
            printf("Word: %s\r\n", cliWords[i]);
        }
    }

    return SUCCESS;
}

void clearBuf() {
    memset(cliBuff, '\0', BUFF_SIZE);
    memset(cliWords, 0, WORDS_IN_COMMAND);
}