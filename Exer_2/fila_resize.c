#include <stdio.h>
#include "fila_resize.h"

static int *fila_rsz;
static int p, u;
static int N;

void cria_fila_rsz() {

    N = 10;
    fila_rsz = malloc( N * sizeof(int) );

    p = 0;
    u = 0;
}

int enfileira_rsz(int y) {

    int ret = 1;

    if ( u == N-1 ) ret = redimensiona_rsz();

    if ( ret ) fila_rsz[u++] = y;

    return ret;

}

int desenfileira_rsz(int *i) {

    if ( !fila_rsz_vazia() ) {
        *i = fila_rsz[p++];

        if (p == N) p = 0;
            return 1;
    }

    return 0;
}

int fila_rsz_vazia() {
  if ( p == u ) cria_fila_rsz();
  return p == u;

}

int fila_rsz_cheia() {

  return (u+1)%N == p;

}

int tam_fila_rsz() {
    int total = u-p;

    if ( p > u ) total = N + total;

    return total;
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

int redimensiona_rsz() {

    int i, j;

    fila_rsz = realloc( fila_rsz, 2 * N * sizeof(int) );

    if ( fila_rsz == NULL ) return 0;

    /* Caso 2 */
    if(p<=u){

    }
    else if ( u-1 < N-p ) {
        for ( i = N, j = 0; j < u; i++, j++ ) {
            fila_rsz[i] = fila_rsz[j];
        }
        u = N+u;
    }
    /* Caso 3 */

    else {
        for ( i = p, j = N+p; i < N; i++, j++ ) {
            fila_rsz[j] = fila_rsz[i];
        }
        p = N+p;
    }

    N *= 2;

    return 1;
}

void libera_fila_rsz() {
    u=0;
    p=0;
    free(fila_rsz);
}
