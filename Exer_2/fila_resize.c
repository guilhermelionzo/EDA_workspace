#include <stdio.h>
#include "fila_resize.h"
#define N 100

static int fila_rsz[N];
static int p, u;

void cria_fila_rsz() {
  p = 0;
  u = 0;
}

void enfileira_rsz(int y) {
  fila_rsz[u++]= y;
}

int desenfileira_rsz() {
  return fila_rsz[p++];
}

int fila_rsz_vazia() {
  if ( p == u ) cria_fila_rsz();
  return p == u;

}

int fila_rsz_cheia() {
  return u == N;

}
void imprime_fila_rsz(){

    if(fila_rsz_vazia()){printf("Fila vazia!\n");return 0;}

    int i=0;

    printf("\n");
    for(i=p;i<u;i++){printf("----");}
    printf("\n");

    for(i=p;i<u;i++){

        printf("%d | ",fila_rsz[i]);

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
