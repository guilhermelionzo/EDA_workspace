#include <stdio.h>
#include "fila_encadeada.h"
#define N 10

int u,p;

typedef struct elem{

    int dado;
    struct elem *prox;

}celula;

celula *fila_enc;

int cria_fila_enc(){

    u=0;
    p=0;

    //celula *fila_enc;
    fila_enc = malloc(sizeof(celula));

    if(fila_enc=NULL){return 0;}

    fila_enc->prox=NULL;//fila_enc;

  return 1;
}

int desenfileira_enc(int *elem){

    celula *temp;

    if(!fila_vazia_enc()){

        temp=fila_enc->prox;

        *elem=temp->dado;

        fila_enc->prox=temp->prox;

        free(temp);

        return 1;
        p++;
    }

    return 0;

}

int enfileira_enc(int elem){

    celula *nova;

    u++;

    nova=malloc(sizeof(celula));

    if(nova==NULL){return 0;}

    nova->prox=fila_enc->prox;

    fila_enc->prox=nova;

    fila_enc->dado=elem;

    fila_enc=nova;

    return 1;
}

int fila_cheia_enc(){

    return 0;

}

int fila_vazia_enc(void){

    return (u=p);
}

int fila_tamanho_enc(){

    return (u-p);
}

void imprime_fila_enc(){

    if(fila_vazia_enc()){printf("Fila vazia!\n");return 0;}

    int i=0;

    printf("\n");
    for(i=p;i<u;i++){printf("----");}
    printf("\n");

    celula *temp,*temp_enc;
    temp=malloc(sizeof(celula));
    temp_enc=malloc(sizeof(celula));
    temp_enc=fila_enc;

    for(i=p;i<u;i++){

        temp=temp_enc;

        printf("%d | ",temp->dado);

        temp= fila_enc->prox;
    }

    printf("\n");
    for(i=p;i<u;i++){printf("----");}
    printf("\n");

    for(i=p;i<u;i++){
        if(i==p){
            printf("p   ");
        }

        else if(i==u-1){
            printf("u");
        }
        else{
           printf("    ");
        }
    }
    printf("\n\n");

}

