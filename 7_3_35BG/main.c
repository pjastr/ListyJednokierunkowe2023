// wersja dla listy bez glowy
#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element *next;
};



struct element * sortuj(struct element *lista)
{
    if (lista == NULL || lista->next == NULL)
        return lista;

    struct element *biezacy = lista;
    struct element *nowa_lista = NULL;

    while (biezacy != NULL)
    {
        struct element *wsk = biezacy->next;

        if (nowa_lista == NULL || biezacy->i < nowa_lista->i)
        {
            biezacy->next = nowa_lista;
            nowa_lista = biezacy;
        }
        else
        {
            struct element *wsk2 = nowa_lista;
            while (wsk2->next != NULL && biezacy->i >= wsk2->next->i)
            {
                wsk2 = wsk2->next;
            }
            biezacy->next = wsk2->next;
            wsk2->next = biezacy;
        }

        biezacy = wsk;
    }
    return nowa_lista;
}

void wyswietlListeBezGlowy(struct element *lista)
{
    if (lista == NULL)
    {
        printf("Lista jest pusta.\n---\n");
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
    // lista dwuelementowa
    struct element *lista = malloc(sizeof(struct element));
    lista->i = 22;
    lista->next = malloc(sizeof(struct element));
    lista->next->i = -8;
    lista->next->next = NULL;
    wyswietlListeBezGlowy(lista);
    lista = sortuj(lista);
    wyswietlListeBezGlowy(lista);
    // lista trzy elementowa
    struct element *lista2 = malloc(sizeof(struct element));
    lista2->i = -22;
    lista2->next = malloc(sizeof(struct element));
    lista2->next->i = 8;
    lista2->next->next = malloc(sizeof(struct element));
    lista2->next->next->i = 5;
    lista2->next->next->next = NULL;
    wyswietlListeBezGlowy(lista2);
    lista2 = sortuj(lista2);
    wyswietlListeBezGlowy(lista2);
}
