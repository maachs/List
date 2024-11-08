#include "ListFunc.h"

int InitList(List_t* list)
{
    assert(list);

    list->data = (List_Elem*) calloc(CAPACITY_MIN, sizeof(List_Elem));

    if (list->data == NULL)
    {
        printf("calloc error");
        return -1;
    }

    list->free = 1;
    list->size = 0;

    list->capacity = CAPACITY_MIN - 1;

    list->data[0].elem = POISON;
    list->data[0].next = 0;
    list->data[0].prev = 0;

    for(int elem = 1; elem < CAPACITY_MIN; elem++)
    {
        list->data[elem].prev = -1;
        list->data[elem].elem = POISON;
        list->data[elem].next = (elem + 1) % CAPACITY_MIN;
    }

    return 0;

}

int ListDtor(List_t* list)
{
    assert(list);

    free(list->data);

    list->data = NULL;

    return 0;
}

