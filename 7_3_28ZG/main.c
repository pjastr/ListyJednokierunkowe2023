#include <stdio.h>
#include <stdlib.h>

//wersja dla listy z g³owa
struct element
{
    int i;
    struct element *next;
};

int maks_rozn(struct element *lista)
{
    // to mo¿liwe bo lista jest conajmniej dwuelementowa
    int max = abs(lista->next->next->i - lista->next->i);
    //tworze dwa tymczasowe wskazniki po ktorych bêde iterowa³ wszystkie mo¿liwe pary (tu ró¿nica w wersji z g³ow¹)
    struct element *wsk = lista->next;
    struct element * wsk2 = lista->next;
    // podwójna pêtla - odpowiednik gdybyœmy szukali to po tablicy jednowymiarowej, ale tu jest lista z g³ow¹
    while(wsk != NULL)
    {
        while (wsk2 != NULL)
        {
            if (abs(wsk->i - wsk2->i) > max)
            {
                max = abs(wsk->i - wsk2->i);
            }
            wsk2 = wsk2->next;
        }
        //przechodzê na kolejny element na wsk
        wsk = wsk->next;
        // ustawiam wsk2 na wsk by sprawdzaæ dalsze elementy (nie muszê ustawiaæ listy na pocz¹tku z uwagi na symetrycznoœæ)
        wsk2 = wsk;
    }
    return max;
}

int main()
{
    //lista 5-elementowa z g³ow¹ dla testów (na kolokwium nie musi byæ taka du¿a)
    struct element *lista = malloc(sizeof(struct element));
    lista->next = malloc(sizeof(struct element));
    lista->next->i = 5;
    lista->next->next = malloc(sizeof(struct element));
    lista->next->next->i = -15;
    lista->next->next->next = malloc(sizeof(struct element));
    lista->next->next->next->i = 20;
    lista->next->next->next->next = malloc(sizeof(struct element));
    lista->next->next->next->next->i = 25;
    lista->next->next->next->next->next = malloc(sizeof(struct element));
    lista->next->next->next->next->next->i = -30;
    lista->next->next->next->next->next->next = NULL;
    printf("%d", maks_rozn(lista));
}
