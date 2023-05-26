#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element *next;
};

struct element *utworz()
{
    return NULL;
}

int main()
{
    struct element *lista = utworz();
    printf("%p", lista);
    return 0;
}
