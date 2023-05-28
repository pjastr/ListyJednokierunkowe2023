#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element *next;
};

void zeruj(struct element *lista)
{
    struct element * wsk = lista->next;
    while(wsk != NULL)
    {
        wsk->i = 0;
        wsk = wsk->next;
    }
}

void wyswietlListeZGlowa(struct element *lista)
{
    if (lista->next == NULL)
    {
        printf("Lista jest pusta.\n---\n");
        return;
    }
    struct element *wsk = lista->next;
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
    lista->next = malloc(sizeof(struct element));
    lista->next->i = 1;
    lista->next->next = malloc(sizeof(struct element));
    lista->next->next->i = -3;
    lista->next->next->next = malloc(sizeof(struct element));
    lista->next->next->next->i = 5;
    lista->next->next->next->next = NULL;
    wyswietlListeZGlowa(lista);
    zeruj(lista);
    wyswietlListeZGlowa(lista);
    return 0;
}
