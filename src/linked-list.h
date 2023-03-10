#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#incude <stdio.h>

struct node {
    int data;
    struct node *next;
};

void foo(int n) 
{
    for (int i=0; i < n; ++i) {
        if (i & 1)
            printf("Hello there %d!\n", i);
    }
}

#endif
