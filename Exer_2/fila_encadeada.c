#include <stdio.h>
#include "fila_encadeada.h"
#define N 10

int u,p;
Fila* f;

struct no
{
    int data;
    struct no* prox;
};
typedef struct no No;

struct fila
{
    No* ini;
    No* fim;
};

int cria_fila_enc(void)
{
    u=0;
    p=0;

    f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return 1;
}

/* função auxiliar: enfileira_enc no fim */
No* ins_fim(No* fim, int v)
{
    No* p = (No*) malloc(sizeof(No));
    p->data = v;
    p->prox = NULL;

    if (fim != NULL) /* verifica se lista não estava vazia */
        fim->prox = p;
    return p;
}
/* função auxiliar: retira do início */
No* desen_ini(No* ini)
{
    No* p = ini->prox;
    free(ini);
    return p;
}

int enfileira_enc(int v)
{
    f->fim = ins_fim(f->fim, v);
    if (f->ini == NULL) /* fila antes vazia? */
        f->ini = f->fim;
    u++;
    return 1;
}

int fila_vazia_enc()
{
    return (p==u);
}

int desenfileira_enc(int *v)
{
    if (fila_vazia_enc())
    {
        printf("Fila vazia.\n");
        exit(1); /* aborta programa */
    }
    *v = f->ini->data;
    f->ini = desen_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
        f->fim = NULL;

    p++;
    return 1;
}

int fila_cheia_enc(){

    return 0; // a fila nunca estará cheia, apenas se nao houver memoria para alocar os dados

}

void libera_fila_enc()
{
    No* q = f->ini;
    while (q != NULL)
    {
        No* t = q->prox;
        free(q);
        q = t;
    }
    u=0;
    p=0;

    free(f);
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

    No* q;

    for(q = f->ini;q != NULL; q = q->prox){

        printf("%d | ",q->data);

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

