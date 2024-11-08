#include "ListFunc.h"

int ListDump(List_t* list, char** argv)
{

    list->dump = fopen(argv[1], "w");

    if (list->dump == NULL)
    {
        printf("cannot open file\n");
        return -1;
    }

    fprintf(list->dump, "digraph G\n{\n   rankdir=LR;\n");

    fprintf(list->dump, "   info [shape = Mrecord,  label = \"capacity = %3d | size = %3d | free = %3d\" ];\n",
            list->capacity, list->size, list->free);

    int index = list->data[0].next;

    while (index != 0)
    {
        fprintf(list->dump, "%4d [shape = Mrecord, style = \"filled\", fillcolor = \"darkseagreen1\","
                "label = \"%3d | data = %7d | prev = %3d | next = %3d\" ];\n",
                index, index, list->data[index].elem, list->data[index].prev, list->data[index].next);

        index = list->data[index].next;
    }

    fprintf(list->dump, "%4d [shape = Mrecord, style = \"filled\", fillcolor = \"khaki1\","
            "label = \"%3d | data = %7d | prev = %3d | next = %3d\" ];\n",
            index, index, list->data[index].elem, list->data[index].prev, list->data[index].next);

    index = list->free;

    while (index != 0)
    {
        fprintf(list->dump, "%4d [shape = Mrecord, style = \"filled\", fillcolor = \"pink\","
                "label = \"%3d | data = %7d | prev = %3d | next = %3d\" ];\n",
                index, index, list->data[index].elem, list->data[index].prev, list->data[index].next);

        index = list->data[index].next;
    }

    fprintf(list->dump, "info -> %d;\n", list->free);

    fprintf(list->dump, "   edge[color=\"forestgreen\"];\n");

    for (int i = 0; i < list->capacity; ++i)
    {
        fprintf(list->dump, "%4d -> %d;\n", i, list->data[i].next);
    }

    fprintf(list->dump, "   edge[color=\"firebrick4\"];\n");

    for (int i = 0; i < list->capacity; ++i)
    {
        if (list->data[i].prev == -1) continue;
        fprintf(list->dump, "%4d -> %d;\n", i, list->data[i].prev);
    }

    fprintf(list->dump, "}\n");

    fclose(list->dump);

    system("dot Dump.dot -Tpng -o Dump.png");

    return 0;
}
