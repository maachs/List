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

    ListPush(&list, 0, 10);
    ListPush(&list, 1, 20);
    ListPush(&list, 2, 30);
    //ListPop(&list, 1);
    ListPush(&list, 3, 40);
    //ListPop(&list, 2);

    ListDump(&list, argv);

    ListDtor(&list);

    return 0;
}
