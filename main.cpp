#include "ListFunc.h"

int main(int argc, char** argv)
{
    struct List_t list = {};

    if (argc != 2)
    {
        printf("argc error\n");
        return -1;
    }

    FILE* output = fopen(argv[1], "w");
    if (output == NULL)
    {
        printf("cannot open file");
        return -1;
    }

    if (InitList(&list) != 0)
    {
        printf("init error\n");
        return -1;
    }

    ListPush(&list, 0, 10);
    ListPush(&list, 1, 20);
    ListPush(&list, 2, 30);
    ListPop(&list, 1);
    ListPush(&list, 3, 40);
    ListPop(&list, 2);

    fprintf(output, "     ");
    for(int i = 0; i < CAPACITY_MIN; i++)
    {
        fprintf(output, "%4d ", i);
    }

    fprintf(output, "\ndata:");
    for(int i = 0; i < CAPACITY_MIN; i++)
    {
        fprintf(output, "%4d ", list.data[i].elem);
    }

    fprintf(output, "\n\nnext:");

    for(int i = 0; i < CAPACITY_MIN; i++)
    {
        fprintf(output, "%4d ", list.data[i].next);
    }

    fprintf(output, "\n\nprev:");

    for(int i = 0; i < CAPACITY_MIN; i++)
    {
        fprintf(output, "%4d ", list.data[i].prev);
    }

    fprintf(output, "\n\nfree = %3d\nsize = %3d\n\ncapacity = %3d\n", list.free, list.size, list.capacity);

    ListDtor(&list);

    fclose(output);

    return 0;
}

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

