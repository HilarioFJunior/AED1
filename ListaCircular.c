#include <stdio.h>
#include <stdlib.h>

typedef struct Celula *PonteiroCelula;

struct Celula{
    char c;
    PonteiroCelula prox;
};

typedef struct Celula Celula;

struct Lista{
    int tam;
    PonteiroCelula ult;
};

typedef struct Lista Lista;

/**/

void ListaCria(Lista *l){
    PonteiroCelula aux;
    aux = (Celula*)malloc(sizeof(Celula));

    aux->prox = aux;

    l->ult = aux;
    l->tam = 0;
}

int ListaVazia(Lista *l){
    if(l->tam == 0)
        return 1;
    else
        return 0;
}


void ListaInsere(Lista *l, char c, int i){
    PonteiroCelula aux, anterior, novo;

    aux = (Celula*)malloc(sizeof(Celula));
    anterior = (Celula*)malloc(sizeof(Celula));
    novo = (Celula*)malloc(sizeof(Celula));

    int j;

    if(l->tam == 0){

        novo->c = c;
        printf("novo->c = %c, c = %c\n", novo->c, c);
        novo->prox = l->ult;
        l->ult->prox = novo;
    }
    if(l->tam == 1){
        novo->c=c;
        if(i==2){
            novo->prox=l->ult;
            aux = l->ult->prox;
            aux->prox = novo;
            }
        if(i==1){
            aux=l->ult->prox;
            l->ult->prox = novo;
            novo->prox=aux;
        }
    }
    if(l->tam > 1){

        aux=l->ult;

        novo->c = c;

        for(j=1;j<=i;j++){
            aux = aux->prox;
            if(j==i-1){
                anterior = aux;
                novo->prox = aux->prox;
            }
        }

        anterior->prox = novo;
    }
    l->tam++;
}

char ListaRemove(Lista *l, int i){
    char c;
    int j;

    PonteiroCelula aux, anterior;

    aux=(Celula*)malloc(sizeof(Celula));
    anterior=(Celula*)malloc(sizeof(Celula));

    aux = l->ult;

    for(j=1;j<=i;j++){
        aux = aux->prox;
        if(j==i-1)
            anterior = aux;
    }

    anterior->prox = aux->prox;

    c = aux->c;

    //free(anterior);
    //free(aux);
    l->tam--;
    return c;
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

    ListaInsere(&l, 'd', 1);
    Imprime(&l);






    return 0;
}
