#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element *next;
};

struct element* dodaj(struct element* lista,int a)
{
    struct element*wsk=malloc(sizeof(struct element));
    wsk->i=a;
    wsk->next=lista;
    return wsk;
}

void wyswietlListeBezGlowy(struct element *lista)
{
    if (lista == NULL)
    {
        printf("Lista jest pusta.\n---\n");
        return;
    }
    struct element *wsk = lista;
    while (wsk != NULL)
    {
        printf("%d\n", wsk->i);
        wsk = wsk->next;
    }
    printf("---\n");
}

int main()
{
    struct element *lista = NULL;
    lista = dodaj(lista, 5);
    lista = dodaj(lista, 10);
    lista = dodaj(lista, 15);
    wyswietlListeBezGlowy(lista);
    return 0;
}
