//
// Created by evghe on 2/19/2023.
//

#ifndef FACTORIO_LIST_H
#define FACTORIO_LIST_H

#include "../inc/consts.h"

typedef struct Elem Elem;

typedef struct Elem {
    void * data;
    Elem * next;
} Element;

typedef struct {
    int size;
    Elem * first;
    Elem * last;

    // cool functions
    int (*toString)(void *);
    int (*comparedTo)(void *, void *, bool *);
} List;

int newList(List ** l);
int newElem(Elem * e);
int addElem(List * l, Element * e);
int addData(List * l, void * d);
int removeElem(List * l, Element * e);

int contains(List * l, Element * e, bool * r);
int printList(List *l);

#endif //FACTORIO_LIST_H
