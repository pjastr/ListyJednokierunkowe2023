#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element *next;
};

void zeruj(struct element *lista)
{
    struct element * wsk = lista;
    while(wsk != NULL)
    {
        wsk->i = 0;
        wsk = wsk->next;
    }
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
    struct element *lista = malloc(sizeof(struct element));
    lista->i = 1;
    lista->next = malloc(sizeof(struct element));
    lista->next->i = 2;
    lista->next->next = malloc(sizeof(struct element));
    lista->next->next->i = 3;
    lista->next->next->next = NULL;
    wyswietlListeBezGlowy(lista);
    zeruj(lista);
    wyswietlListeBezGlowy(lista);
    return 0;
}
