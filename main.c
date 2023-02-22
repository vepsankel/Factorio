#include <stdio.h>

#include "global.h"

int main(void) {


#ifdef FACTORIO_RSCMAIN_H
    rscInit("");
#endif

    cliMain();

    return 0;
}
