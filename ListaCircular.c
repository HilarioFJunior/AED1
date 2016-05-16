#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50001

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

        if(i>1){
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
        if(i==1){
            novo->c=c;
            anterior=l->ult;
            aux=l->ult->prox;
            novo->prox=aux;
            anterior->prox=novo;

        }


    }
    l->tam++;
}

char ListaRemove(Lista *l, int i){
    char c;
    int j;

    PonteiroCelula aux, anterior;

    aux=(Celula*)malloc(sizeof(Celula));
    anterior=(Celula*)malloc(sizeof(Celula));

    if(i==1){
        aux=l->ult->prox;
        c=l->ult->prox->c;
        l->ult->prox=aux->prox;
    }
    else{
    aux = l->ult;

    for(j=1;j<=i;j++){
        aux = aux->prox;
        if(j==i-1)
            anterior = aux;
    }

    anterior->prox = aux->prox;

    c = aux->c;
    }


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

void Imprime(Lista *l){
    int i;
    for(i=1;i<=l->tam;i++){
        printf("%c",ListaRetorna(l,i));
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
