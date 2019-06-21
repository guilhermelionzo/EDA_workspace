#ifndef _fila_encadeada_h
#define _fila_encadeada_h

int cria_fila_enc();
int enfileira_enc(int v);
int desenfileira_enc(int *elem);
int fila_cheia_enc();
int fila_vazia_enc(void);
int fila_tamanho_enc();
void imprime_fila_enc();
void libera_fila_enc();
typedef struct fila Fila;

#endif
