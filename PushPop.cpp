#include "ListFunc.h"

int ListPush(List_t* list, int index, int value)
{
    assert(list);
    assert(list->data);

    if (index < 0 || index > list->size)
    {
        printf("incorrect index for push");
        return -1;
    }

    list->size++;

    int free_addr = list->free;

    list->free = list->data[free_addr].next;

    list->data[free_addr].elem = value;

    list->data[free_addr].next = list->data[index].next;

    list->data[free_addr].prev = index;

    list->data[list->data[index].next].prev = free_addr;

    list->data[index].next = free_addr;

    return 0;

}

int ListPop(List_t* list, int index)
{
    assert(list);
    assert(list->data);

    if (index > list->size)
    {
        printf("wrong index for pop\n");
        return -1;
    }

    int free_addr = list->free;

    list->data[index].elem = POISON;

    list->data[list->data[index].next].prev = list->data[index].prev;

    list->data[list->data[index].prev].next = list->data[index].next;

    list->data[index].next = free_addr;

    list->free = index;

    list->data[index].prev = -1;

    return 0;
}
