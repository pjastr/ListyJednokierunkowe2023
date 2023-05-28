#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element *next;
};

void dodaj(struct element* lista,int a)
{
    struct element*wsk=malloc(sizeof(struct element));
    wsk->i=a;
    wsk->next=lista->next;
    lista->next=wsk;
}

void wyswietlListeZGlowa(struct element * lista)
{
    if (lista->next == NULL)
    {
        printf("Lista jest pusta\n---\n");
        return;
    }
    struct element * wsk = lista->next;
    while (wsk != NULL)
    {
        printf("%d\n", wsk->i);
        wsk = wsk->next;
    }
    printf("---\n");
}

int main()
{
    struct element *lista = malloc(sizeof(struct element));
    lista->next = NULL;
    dodaj(lista, 5);
    dodaj(lista, 6);
    dodaj(lista, 7);
    wyswietlListeZGlowa(lista);
    return 0;
}
