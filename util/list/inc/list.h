//
// Created by Sandu on 2/22/2023.
//

#ifndef FACTORIO_LIST_H
#define FACTORIO_LIST_H

#include "listinc.h"

// List definition

typedef struct List {
    int size;
    Elem * first;
    Elem * last;

    // cool functions
    int (*toString)(void *);
    int (*comparedTo)(void *, void *, int *);

    // used for search optimization
    int isArrayList;
    int isSorted;
    Element ** arrayList;
} List;

#endif //FACTORIO_LIST_H
