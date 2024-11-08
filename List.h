#ifndef LIST_
#define LIST_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

const int CAPACITY_MIN = 10;

const int POISON       = -123;

struct List_Elem
{
    int elem;
    int next;
    int prev;
};

struct List_t
{
    List_Elem* data;
    int        size;
    int        capacity;
    int        free;
    FILE*      dump;
};

#define LIST_PUSH(var1, var2)           \
    if(ListPush(&list, var1, var2) != 0)\
    {                                   \
        return -1;                      \
    }

#define LIST_POP(var)           \
    if(ListPop(&list, var) != 0)\
    {                           \
        return -1;              \
    }

#endif
