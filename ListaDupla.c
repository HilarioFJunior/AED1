#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50001

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
            l->ult->ant=novo;


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

char ListaRemove(Lista *l, int i){
    PonteiroCelula aux, anterior;
    char c;
    int j;
    aux = (Celula*)malloc(sizeof(Celula));
    anterior=(Celula*)malloc(sizeof(Celula));

    if(i==1){
        aux=l->ult->prox;
        c=l->ult->prox->c;
        l->ult->prox=aux->prox;
        aux->prox->ant = l->ult;
    }
    else{
        aux=l->ult;
        for(j=1;j<=i;j++){
            aux=aux->prox;
            if(j==i-1){
                anterior = aux;
            }
        }
        anterior->prox=aux->prox;
        aux->prox->ant=anterior;
    }


    l->tam--;
    return c;
}

void Imprime(Lista *l){
    int i;
    for(i=1;i<=l->tam;i++){
        printf("%c",ListaRetorna(l,i));
    }
}

void LiberaLista(Lista *l){
    PonteiroCelula temp;
    PonteiroCelula aux;

    aux=l->ult;
    int i;
    for(i=0;i<=l->tam;i++){
        temp = aux;
        aux=aux->prox;
        free(temp);
    }

}


int main()
{
    Lista l;
    ListaCria(&l);

    char c[MAX];
    int j;

    scanf(" %[^\n]", c);

    j=1;

    char* ponteiro;

    for(ponteiro=c ;ponteiro<c+strlen(c);ponteiro++){
        switch(*ponteiro){
            case '-':
                if(j!=1){
                    j--;
                    ListaRemove(&l,j);
                }

                break;
            case '<':
                if(j>1)
                    j--;
                break;
            case '>':
                if(j<l.tam)
                    j++;
                break;
            case '[':
                j=1;
                break;
            case ']':
                j=l.tam+1;
                break;
            default:

                ListaInsere(&l,*ponteiro, j);
                j++;
                break;
        }

    }





    Imprime(&l);

    LiberaLista(&l);


    return 0;
}
