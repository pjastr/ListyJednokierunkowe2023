#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element *next;
};

struct element *znajdz(struct element * lista, int a)
{
    struct element *wsk = lista;
    while (wsk != NULL)
    {
        if (wsk->i == a)
        {
            return wsk;
        }
        wsk = wsk->next;
    }
    return NULL;
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
    printf("%p\n", znajdz(lista, -72));
    printf("%p\n", znajdz(lista, 44));
}
