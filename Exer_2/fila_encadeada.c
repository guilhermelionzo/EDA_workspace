#include <stdio.h>
#include "fila_encadeada.h"
#define N 100

static int fila_enc[N];
static int p, u;

void cria_fila_enc() {
  p = 0;
  u = 0;
}

void enfileira_enc(int y) {
  fila_enc[u++]= y;
}

int desenfileira_enc() {
  return fila_enc[p++];
}

int fila_enc_vazia() {
  if ( p == u ) cria_fila_enc();
  return p == u;

}

int fila_enc_cheia() {
  return u == N;

}
void imprime_fila_enc(){

    if(fila_enc_vazia()){printf("Fila vazia!\n");return 0;}

    int i=0;

    printf("\n");
    for(i=p;i<u;i++){printf("----");}
    printf("\n");

    for(i=p;i<u;i++){

        printf("%d | ",fila_enc[i]);

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
