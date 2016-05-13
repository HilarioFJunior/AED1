#include <stdio.h>
#include <stdlib.h>

typedef struct Celula *PonteiroCelula;

struct Celula{
    int x;
    PonteiroCelula prox;

};

typedef struct Celula Celula;

struct Lista{
    int tam;
    PonteiroCelula prim, ult;
};

typedef struct Lista Lista;

/**/

void ListaCria(Lista *l){
    l->tam = 0;
    l->prim = NULL;
    l->ult = NULL;
}

int ListaVazia(Lista *l){
    if(l->tam == 0)
        return 1;
    else
        return 0;
}

void ListaInsereInicio(Lista *l, int x){
    PonteiroCelula aux;
    aux = (Celula*) malloc(sizeof(Celula));
    aux->x = x;
    aux->prox=l->prim;
    l->tam++;
    l->prim = aux;
}

void ListaInsereFim(Lista *l, int x){
    PonteiroCelula aux;
    aux = (Celula*)malloc(sizeof(Celula));
    aux->x = x;

    l->ult->prox = aux;
    l->ult = aux;
    l->tam++;
}

void ListaInsere(Lista *l, int x, int i){


    PonteiroCelula aux, aux2, aux3;
    aux = (Celula*)malloc(sizeof(Celula));
    aux2 = (Celula*)malloc(sizeof(Celula));
    aux3 = (Celula*)malloc(sizeof(Celula));

    aux = l->prim;
    aux3->x= x;
    aux3->prox = NULL;

    int j;


       for(j=1;j<i;j++){
           if(j==i-1)
               aux2=aux;
           aux = aux->prox;
       }

       aux3->prox = aux2->prox;
       aux2->prox = aux3;



}

int main()
{
    printf("Hello world!\n");
    return 0;
}
