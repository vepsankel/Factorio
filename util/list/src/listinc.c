//
// Created by evghe on 2/19/2023.
//

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int listNew(List ** l) {
    *l = (List *)malloc(sizeof(List));

    if (*l == NULL) {
        printf("Could not create List: Memory Allocation Failure.\r\n");
        return FAILURE;
    }

    (*l)->size = 0;
    (*l)->first = NULL;
    (*l)->last = NULL;

    (*l)->comparedTo = NULL;
    (*l)->toString = NULL;

    (*l)->arrayList = NULL;
    (*l)->isSorted = FALSE;
    return SUCCESS;
}

int listNewElement(Element ** e) {
    if (LIST_DEBUG) {
        printf("LIST_DEBUG: entered listNewElement function\r\n");
    }

    *e = (Element *)malloc(sizeof(Element));

    if (*e == NULL) {
        printf("Could not create Element: Memory Allocation Failure.\r\n");
        return FAILURE;
    }

    (*e)->next = NULL;
    (*e)->data = NULL;

    if (LIST_DEBUG) {
        printf("LIST_DEBUG: exited listNewElement function\r\n");
    }
    return SUCCESS;
}

int listAddElement(List * l, Element * e) {
    if (l == NULL) {
        printf("List is uninitialized.\r\n");
        return FAILURE;
    }

    if (e == NULL) {
        printf("Element is uninitialized.\r\n");
        return FAILURE;
    }

    if (l->last == NULL) {
        l->first = e;
    } else {
        l->last->next = e;
    }
    l->last = e;
    l->size++;

    l->isSorted = FALSE;
    l->isArrayList = FALSE;

    return SUCCESS;
}

int listAddData(List * l, void * d) {
    if (LIST_DEBUG) {
        printf("LIST_DEBUG: entered listAddData function\r\n");
    }

    Element *e = NULL;

    if (listNewElement(&e) != SUCCESS) {
        printf("Could not create Element\r\n");
        return FAILURE;
    }

    e->data = d;
    e->next = NULL;

    if (listAddElement(l, e) != SUCCESS) {
        printf("Could not add Element\r\n");
        return FAILURE;
    }

    l->isSorted = FALSE;
    l->isArrayList = FALSE;

    if (LIST_DEBUG) {
        printf("LIST_DEBUG: exited listAddData function\r\n");
    }
    return SUCCESS;
}

int listSetToString(List *l, int (*toString)(void *)) {
    if (l == NULL) {
        printf("List is null!\r\n");
        return FAILURE;
    }

    l->toString = toString;
    return SUCCESS;
}

int listSetComparedTo(List *l, int (*compare)(void *, void *, int * r)) {
    if (l == NULL) {
        printf("List is null!\r\n");
        return FAILURE;
    }

    l->comparedTo = compare;
    return SUCCESS;
}

int listRemoveElement(List * l, Element * e) {
    if (l == NULL) {
        printf("List is uninitialized.\r\n");
        return FAILURE;
    }

    if (e == NULL) {
        printf("Element is uninitialized.\r\n");
        return FAILURE;
    }

    Element * iter = l->first;

    if (iter == e) {
        l->first = e;
        l->size--;
        return SUCCESS;
    }

    while (iter != NULL) {
        if (iter->next != NULL && iter->next == e) {
            iter->next = iter->next->next;
            if (iter->next == NULL)
                l->last = iter;
            l->size--;
            return SUCCESS;
        }
        iter = iter->next;
    }

    l->isSorted = FALSE;
    l->isArrayList = FALSE;

    return SUCCESS;
}

int listContainsElement(const List * l, Element * e, bool * r){
    bool result = FALSE;

    if (l == NULL) {
        printf("List is uninitialized.\r\n");
        return FAILURE;
    }

    if (e == NULL) {
        printf("Element is uninitialized.\r\n");
        return FAILURE;
    }

    if (l->comparedTo == NULL) {
        printf("No compare function for this list.\r\n");
        return FAILURE;
    }

    Element * iter = l->first;
    while (iter != NULL) {
        if (l->comparedTo(iter, e, &result) == SUCCESS) {
            if (result == TRUE) {
                *r = TRUE;
                return SUCCESS;
            }
        } else {
            printf("Compare function failed.\r\n");
            return FAILURE;
        }
        iter = iter->next;
    }

    *r = FALSE;
    return SUCCESS;
}

int listPrint(const List *l) {
    if (LIST_DEBUG) {
        printf("LIST_DEBUG: entered listNewElement function\r\n");
    }

    if (l == NULL) {
        printf("List is uninitialized.\r\n");
        return FAILURE;
    }

    if (l->toString == NULL) {
        printf("No print function for this list.\r\n");
        return FAILURE;
    }

    printf("[");

    Element * iter = l->first;
    while (iter != NULL) {
        if (l->toString(iter->data) == FAILURE) {
            printf("toString function failed.\r\n");
            return FAILURE;
        }

        iter = iter->next;

        if (iter != NULL)
            printf(",");
    }

    printf("]\r\n");

    if (LIST_DEBUG) {
        printf("LIST_DEBUG: exited listNewElement function\r\n");
    }
    return SUCCESS;
}