#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element *next;
};

struct element *polacz_listy(struct element *lista1, struct element *lista2)
{
    //mocno korzystam z zalozenia ze listy sa takiej samej dlugosci
    if (lista1 == NULL)
    {
        return NULL;
    }
    // nowa lista
    struct element * new_list = lista1;
    // wskaznik do przechodzenia po nowej liscie
    struct element * wsk = new_list;
    // wskazniki do przechodzenia po listach 1 i 2
    struct element * wsk1 = lista1;
    struct element * wsk2 = lista2;
    // teraz pêtla
    while(wsk1 != NULL)
    {
        wsk1 = wsk1->next;
        wsk->next = wsk2;
        wsk = wsk->next;
        wsk2 = wsk2->next;
        wsk->next = wsk1;
        wsk = wsk->next;
    }
    return new_list;
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
    struct element *lista1 = malloc(sizeof(struct element));
    lista1->i = 1;
    lista1->next = malloc(sizeof(struct element));
    lista1->next->i = 2;
    lista1->next->next = malloc(sizeof(struct element));
    lista1->next->next->i = 3;
    lista1->next->next->next = NULL;
    struct element *lista2 = malloc(sizeof(struct element));
    lista2->i = -5;
    lista2->next = malloc(sizeof(struct element));
    lista2->next->i = -6;
    lista2->next->next = malloc(sizeof(struct element));
    lista2->next->next->i = -7;
    lista2->next->next->next = NULL;
    wyswietlListeBezGlowy(lista1);
    wyswietlListeBezGlowy(lista2);
    struct element *lista3 = polacz_listy(lista1, lista2);
    wyswietlListeBezGlowy(lista3);
    // w tym zadaniu pierwotne listy nie sa juz przechowywane nigdzie w pamieci w pierwotnej kolejnosci
}

