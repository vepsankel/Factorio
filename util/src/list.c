//
// Created by evghe on 2/19/2023.
//

#include "../inc/list.h"
#include <stdlib.h>
#include <stdio.h>

int newList(List ** l) {
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
    return SUCCESS;
}

int newElem(Element * e) {
    e = (Element *)malloc(sizeof(Element));

    if (e == NULL) {
        printf("Could not create Element: Memory Allocation Failure.\r\n");
        return FAILURE;
    }

    e->next = NULL;
    e->data = NULL;
    return SUCCESS;
}

int addElem(List * l, Element * element) {
    if (l == NULL) {
        printf("List is uninitialized.\r\n");
        return FAILURE;
    }

    if (element == NULL) {
        printf("Element is uninitialized.\r\n");
        return FAILURE;
    }

    if (l->last == NULL) {
        l->first = element;
    } else {
        l->last->next = element;
    }
    l->last = element;
    l->size++;

    return SUCCESS;
}

int addData(List * l, void * d) {
    Element * e = NULL;

    if (newElem(e) != SUCCESS) {
        printf("Could not create Element\r\n");
        return FAILURE;
    }

    e->data = d;
    e->next = NULL;

    if (addElem(l, e) != SUCCESS) {
        printf("Could not add Element\r\n");
        return FAILURE;
    }

    return SUCCESS;
}

int removeElem(List * l, Element * element) {
    if (l == NULL) {
        printf("List is uninitialized.\r\n");
        return FAILURE;
    }

    if (element == NULL) {
        printf("Element is uninitialized.\r\n");
        return FAILURE;
    }

    Element * iter = l->first;

    if (iter == element) {
        l->first = element;
        l->size--;
        return SUCCESS;
    }

    while (iter != NULL) {
        if (iter->next != NULL && iter->next == element) {
            iter->next = iter->next->next;
            if (iter->next == NULL)
                l->last = iter;
            l->size--;
            return SUCCESS;
        }
        iter = iter->next;
    }

    return SUCCESS;
}

int contains(List * l, Element * e, bool * r){
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

int printList(List *l) {
    if (l == NULL) {
        printf("List is uninitialized.\r\n");
        return FAILURE;
    }

    if (l->toString == NULL) {
        printf("No print function for this list.\r\n");
        return FAILURE;
    }

    Element * iter = l->first;
    while (iter != NULL) {
        if (l->toString(iter->data) == FAILURE) {
            printf("toString function failed.\r\n");
            return FAILURE;
        }
        iter = iter->next;
    }

    return SUCCESS;
}