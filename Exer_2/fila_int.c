#include <stdio.h>
#include "fila_int.h"
#define N 10

static int fila_int[N];
static int p, u;

void cria_fila_int() {
  p = 0;
  u = 0;
}

void enfileira_int(int y) {
  fila_int[u++]= y;
}

int desenfileira_int() {

  return fila_int[p++];
}

int fila_int_vazia() {
  if ( p == u ) cria_fila_int();
  return p == u;

}

int fila_int_cheia() {
  return (u-p)== N;

}
void imprime_fila_int(){

    if(fila_int_vazia()){printf("Fila vazia!\n");return 0;}

    int i=0;

    printf("\n");
    for(i=p;i<u;i++){printf("----");}
    printf("\n");

    for(i=p;i<u;i++){

        printf("%d | ",fila_int[i]);

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
