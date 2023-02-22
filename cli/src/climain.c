//
// Created by Sandu on 2/20/2023.
//

#include "../inc/climain.h"

char cliBuff[BUFF_SIZE];
unsigned int cliWordsInCommand;
const char * cliWords[WORDS_IN_COMMAND];

void clearBuf() {
    memset(cliBuff, '\0', BUFF_SIZE);
    memset(cliWords, 0, WORDS_IN_COMMAND);
}

int fillCommandWords() {
    char * token = strtok(cliBuff, " ");
    unsigned int wordCountLocal = 0;

    while (token != NULL) {
        if (wordCountLocal >= WORDS_IN_COMMAND) {
            printf("Command is too long!\r\n");
            clearBuf();
            return SUCCESS;
        }

        cliWords[wordCountLocal++] = token;
        token = strtok(NULL, " ");
    }

    cliWordsInCommand = wordCountLocal;
    return SUCCESS;
}

int cmdHelp() {
#ifdef FACTORIO_RSCCMD_H
    printf("==================== HELP ====================\r\n");
    printf("resource\t\t\tGo to resources menu\r\n");
#endif

    return SUCCESS;
}

int CliCmd(const char ** cliWords, unsigned int cliWordsInCommand) {
    if (strncmp(cliWords[0],"help",4) == 0)
        return cmdHelp();

#ifdef FACTORIO_RSCCMD_H
    if (strncmp(cliWords[0],"resource",8) == 0)
        return rscCmd(&cliWords[1], cliWordsInCommand-1);
#endif

    return SUCCESS;
}

int cliMain() {

    while (strncmp(cliBuff, "exit", 4) != 0) {
        clearBuf();
        printf("global:");

        if (fgets(cliBuff, BUFF_SIZE - 1, stdin) == NULL) {
            printf("Fgets terminated\r\n");
            return FAILURE;
        }

        if (cliBuff[strlen(cliBuff) - 1] == '\n') {
            cliBuff[strlen(cliBuff) - 1] = '\0';
        }

        if (fillCommandWords() == FAILURE)
            return FAILURE;

//        printf("You entered:\r\n");
//        for (int i = 0 ; i < cliWordsInCommand ; i++) {
//            printf("Word: %s\r\n", cliWords[i]);
//        }

        CliCmd(cliWords, cliWordsInCommand);
    }

    return SUCCESS;
}