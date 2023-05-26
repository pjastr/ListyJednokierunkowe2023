#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element *next;
};

void dodajk(struct element *Lista, int a)
{
    struct element *wsk = Lista;
    while (wsk->next != NULL)
    {
        wsk = wsk->next;
    }
    wsk->next = malloc(sizeof(struct element));
    wsk->next->i = a;
    wsk->next->next = NULL;
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
    printf("\n");
    printf("---\n");
}

int main()
{
    // przypadek pustej listy
    struct element * lista = malloc(sizeof(struct element));
    lista->next = NULL;
    wyswietlListeZGlowa(lista);
    dodajk(lista, 1);
    wyswietlListeZGlowa(lista);
    //przypadek listy dwuelementowej
    struct element * lista2 = malloc(sizeof(struct element));
    lista2->next = malloc(sizeof(struct element));
    lista2->next->i = -4;
    lista2->next->next = malloc(sizeof(struct element));
    lista2->next->next->i = 2;
    lista2->next->next->next = NULL;
    wyswietlListeZGlowa(lista2);
    dodajk(lista2, 3);
    wyswietlListeZGlowa(lista2);
}
