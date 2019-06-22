#include <stdio.h>
#include "fila_int.h"
#define N 10

static int fila[N];
static int p, u;

void cria_fila() {
  p = 0;
  u = 0;
}

int enfileira(int y) {
    if(fila_cheia()){return 0;}

    fila[u++]= y;
    return 1;
}

int desenfileira(int *y) {

    if(fila_vazia()){
        return 0;
    }

    *y=fila[p++];

    return 1;
}

int fila_vazia() {
  if ( p == u ) cria_fila();
  return p == u;

}

int fila_cheia() {
  return u== N;

}
void imprime_fila(){

    if(fila_vazia()){printf("Fila vazia!\n");return 0;}

    int i=0;

    printf("\n");
    for(i=p;i<u;i++){printf("----");}
    printf("\n");

    for(i=p;i<u;i++){

        printf("%d | ",fila[i]);

    }

    printf("\n");
    for(i=p;i<u;i++){printf("----");}
    printf("\n");

    if(p==(u-1)){
        printf("p/u");
    }
    else{

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
    }
    printf("\n\n");

}

void libera_fila(){


}
