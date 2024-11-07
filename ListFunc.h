#ifndef LIST_FUNC_
#define LIST_FUNC_

#include "List.h"

int ListPush(List_t* list, int index, int value);

int ListPop(List_t* list, int index);

int InitList(List_t* list);

int ListDtor(List_t* list);

#endif
