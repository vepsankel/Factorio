#include <stdio.h>

#include "resources/inc/rsccmd.h"
#include "resources/inc/rscmain.h"
#include "util/inc/consts.h"
#include "util/inc/list.h"

int main(void) {

#ifdef FACTORIO_RSCMAIN_H
    rscInit("");
    rscCmdMain();
#endif

    return 0;
}
