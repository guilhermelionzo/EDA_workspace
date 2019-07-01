#ifndef _fila_encadeada_h
#define _fila_encadeada_h

void cria_fila();
int enfileira(int v);
int desenfileira(int *elem);
int fila_cheia();
int fila_vazia(void);
int fila_tamanho();
void imprime_fila();
void libera_fila();
typedef struct fila Fila;
void cabecalho(void);

#endif
