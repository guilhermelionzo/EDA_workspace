#include <stdio.h>
#include "fila_resize.h"

static int *fila;
static int p, u;
static int N;

void cria_fila() {

    N = 10;
    fila = malloc( N * sizeof(int) );

    p = 0;
    u = 0;
}

int enfileira(int y) {

    if(fila_cheia()){
        if(!redimensiona()){return -1;}
    }
    fila[u++]=y;

    if(u==N) u=0;
    return 0;

    /*
    int ret = 1;

    if ( u == N-1 ) ret = redimensiona();

    if ( ret ) fila[u++] = y;

    return ret;
*/
}

int desenfileira(int *i) {

    if ( !fila_vazia() ) {
        *i = fila[p++];

        if (p == N) p = 0;
            return 1;
    }

    return 0;
}

int fila_vazia() {
  if ( p == u ) cria_fila();
  return p == u;

}

int fila_cheia() {

  return (u+1)%N == p;

}

int tam_fila() {
    int total = u-p;

    if ( p > u ) total = N + total;

    return total;
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

int redimensiona() {

    int i, j;

    fila = realloc( fila, 2 * N * sizeof(int) );

    if ( fila == NULL ) return 0;

    /* Caso 2 */
    if(p<=u){

    }
    else if ( u-1 < N-p ) {
        for ( i = N, j = 0; j < u; i++, j++ ) {
            fila[i] = fila[j];
        }
        u = N+u;
    }
    /* Caso 3 */

    else {
        for ( i = p, j = N+p; i < N; i++, j++ ) {
            fila[j] = fila[i];
        }
        p = N+p;
    }

    N *= 2;

    return 1;
}

void libera_fila() {
    u=0;
    p=0;
    free(fila);
}

void cabecalho(void){
    printf("\n****FILA CIRCULAR COM REDIMENSIONAMENTO****");
}