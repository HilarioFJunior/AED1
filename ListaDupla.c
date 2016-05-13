#include <stdio.h>
#include <stdlib.h>

typedef struct Celula *PonteiroCelula;

struct Celula{
    char c;
    PonteiroCelula prox, ant;
};

typedef struct Celula Celula;

struct Lista{
    PonteiroCelula ult;
    int tam;
};

typedef struct Lista Lista;

/**/

void ListaCria(Lista *l){
    PonteiroCelula aux;
    aux = (Celula*)malloc(sizeof(Celula));

    aux->prox = aux;
    aux->ant=aux;

    l->tam =0;
    l->ult = aux;
}

void ListaInsere(Lista *l, char c, int i){
    PonteiroCelula aux, anterior, novo;
    int j;

    aux = (Celula*)malloc(sizeof(Celula));
    anterior = (Celula*)malloc(sizeof(Celula));
    novo = (Celula*)malloc(sizeof(Celula));

    if(l->tam == 0){
        novo->c = c;
        novo->prox=l->ult;
        novo->ant = l->ult;
        l->ult->prox= novo;
        l->ult->ant=novo;
    }
    if(l->tam == 1){
        if(i==1){
            aux=l->ult;
            novo->c=c;
            novo->prox = l->ult->prox;
            novo->ant = l->ult;
            aux->prox=novo;
            novo->prox->ant=novo;
        }
        if(i==2){
            novo->c=c;
            novo->prox=l->ult;
            aux = l->ult->prox;
            aux->prox=novo;
            novo->ant = aux;


        }
    }
    if(l->tam > 1){
        if(i>1){
            aux=l->ult;
            for(j=1;j<=i;j++){
                aux=aux->prox;
                if(j==i-1)
                    anterior=aux;
            }
            novo->c=c;
            novo->prox = aux;
            novo->ant = anterior;
            anterior->prox=novo;
            aux->ant = novo;
        }
        if(i==1){
            anterior=l->ult;
            aux=l->ult->prox;
            novo->c=c;
            novo->prox=aux;
            novo->ant=anterior;

            anterior->prox=novo;
            aux->ant=novo;
        }

    }
    l->tam++;

}

char ListaRetorna(Lista* l, int i){
    char c;
    int j;

    PonteiroCelula aux;

    aux=(Celula*)malloc(sizeof(Celula));


    aux=l->ult;



    for(j=1;j<=i;j++){
        aux = aux->prox;
    }

    c = aux->c;
    return c;
}

void Imprime(Lista *l){
    printf("tam = %d\n", l->tam);
    int i;
    if(l->tam > 0){
        for(i=1;i<=l->tam;i++){
        printf("c[%d] = %c\n",i, ListaRetorna(l, i));
        }
    }
}


int main()
{
    Lista l;
    ListaCria(&l);


    Imprime(&l);

    ListaInsere(&l, 'c', 1);
    Imprime(&l);

    ListaInsere(&l, 'd', 2);
    Imprime(&l);

    ListaInsere(&l, 'f', 1);
    Imprime(&l);

    return 0;
}
