#include "ListFunc.h"

int main(int argc, char** argv)
{
    struct List_t list = {};

    if (argc != 2)
    {
        printf("argc error\n");
        return -1;
    }


    if (InitList(&list) != 0)
    {
        printf("init error\n");
        return -1;
    }

    LIST_PUSH(0, 10);
    LIST_PUSH(1, 20);
    LIST_PUSH(2, 30);
    LIST_PUSH(3, 40);
    LIST_POP(1);
    LIST_POP(2);

    ListDump(&list, argv);

    ListDtor(&list);

    return 0;
}
