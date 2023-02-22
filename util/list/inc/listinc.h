//
// Created by evghe on 2/19/2023.
//

#ifndef FACTORIO_LISTINC_H
#define FACTORIO_LISTINC_H

#ifndef DEBUG
#define LIST_DEBUG TRUE
#endif

// structures declaration
typedef struct List List;
typedef struct Elem Elem;

#include "../../global.h"

// Element definition
typedef struct Elem {
    void * data;
    Elem * next;
} Element;

int listNew(List ** l);
int listNewElement(Elem ** e);
int listAddElement(List * l, Element * e);
int listRemoveElement(List * l, Element * e);
int listAddData(List * l, void * d);

int listSetToString(List *l, int (*toString)(void *));
int listSetComparedTo(List *l, int (*compare)(void *, void *, int * r));

int listContainsElement(const List * l, Element * e, bool * r);
//int containsData(const List * l, void * d, bool * r);
int listPrint(const List *l);

#endif //FACTORIO_LISTINC_H
