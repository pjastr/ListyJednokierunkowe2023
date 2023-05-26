#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element *next;
};

struct element* dodajw(struct element * lista, struct element *elem, int a)
{
    struct element *wsk =malloc(sizeof(struct element));
    wsk->i=a;
    if(elem==NULL)
    {
        wsk->next=lista;
        lista=wsk;
    }
    else
    {
        wsk->next=elem->next;
        elem->next=wsk;
    }
    return lista;
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
        printf("%d:%p\n", wsk->i, wsk);
        wsk = wsk->next;
    }
    printf("---\n");
}

int main()
{
    struct element *lista = malloc(sizeof(struct element));
    lista->i = 1;
    lista->next = malloc(sizeof(struct element));
    lista->next->i = -72;
    lista->next->next = malloc(sizeof(struct element));
    lista->next->next->i = 3;
    lista->next->next->next = NULL;
    wyswietlListeBezGlowy(lista);
    lista = dodajw(lista, NULL, -4);
    wyswietlListeBezGlowy(lista);
    lista = dodajw(lista, lista->next, 5);
    wyswietlListeBezGlowy(lista);
}
