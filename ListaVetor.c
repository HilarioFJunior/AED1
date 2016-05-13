#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int x[10];
    int tam, pri, ult;
};

typedef struct Lista Lista;

/**/

void ListaCria(Lista *l){
    l->tam=0;
    l->pri = 0;
    l->ult=0;
}

int ListaVazia(Lista *l){
    if(l->tam==0)
        return 1;
    else
        return 0;
}

void Listar(Lista *l, int x, int i){
    int j;


    if(ListaVazia(l) == 0){
        for(j=l->tam;j>i;j--){
            l->x[j] =  l->x[j-1];
        }
        l->x[i]=x;
        l->ult++;

    }
    else{
        l->x[0]=x;
    }
    l->tam++;

}

int Desenlistar(Lista *l, int i){
    int x, j;
    x = l->x[i];
    for(j=i;j<l->tam-1;j++){
        l->x[j]=l->x[j+1];
    }
    l->ult--;
    l->tam--;

    return x;
}

void ListaImprime(Lista *l){
    int i;
    for(i=0;i<l->tam;i++){
        printf("x[%d] = %d\n", i, l->x[i]);

    }
    printf("tam = %d\n", l->tam);
    printf("prim = %d\n", l->pri);
    printf("ult = %d\n", l->ult);
}



int main()
{
    Lista l;
    ListaCria(&l);

    Listar(&l, 2, 0);
    ListaImprime(&l);
    Listar(&l, 3, 1);
    ListaImprime(&l);
    Listar(&l, 5, 2);
    ListaImprime(&l);
    Desenlistar(&l, 1);
    ListaImprime(&l);

    return 0;
}
