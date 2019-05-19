#include <stdio.h>
#include <stdlib.h>

//STRUCT DE COOREDENADAS E LISTA ENCADEADA
typedef struct ponto{
    int x,y;
    struct ponto *proximo;
}t_ponto;


int main(void){

    t_ponto *pontoInicial;      //PONTEIRO INICIAL DA FILA
    t_ponto *proximoPonto;      //PROXIMO PONTEIRO DA FILA

    pontoInicial = (t_ponto*) (malloc(sizeof(t_ponto)));    //CRIA O PRIMEIRO ELEMENTO DA FILA

    if(pontoInicial==NULL){exit(0);}                        //CASO SEJA NULL FECHAR O PROGRAMA "NAO HA ESPAÇO NA MEMORIA"

    proximoPonto=pontoInicial;                              // PROXIMO VALOR RECEBE O PONTO INICIAL

    while(1){

        int aux=0;

        printf("Digite o valor de x: ");
        scanf("%d",&proximoPonto->x);           // PONTO RECEBE O VALOR DE X

        printf("Digite o valor de y: ");        // PONTO RECEBE O VALORE DE Y
        scanf("%d",&proximoPonto->y);

        printf("0 para finalizar: ");
        scanf("%d",&aux);                       // CASO 0, SAIR DO LOOP

        if(aux==0){break;}

        proximoPonto->proximo = (t_ponto*) (malloc(sizeof(t_ponto)));   //CRIA NOVO ELEMENTO NA LISTA

        proximoPonto=proximoPonto->proximo;                             //ATUALIZA O ENEDEREÇO DE MEMORIA PARA O NOVO ELEMENTO DA LISTA

    }

    proximoPonto=pontoInicial;                  // APONTA O INDEX DA LISTA PARA O PONTO INICIAL

    while(proximoPonto!=NULL){

        printf("X:%d,Y:%d\n",proximoPonto->x,proximoPonto->y);  // PRINTA OS VALORES DA LISTAS

        proximoPonto=proximoPonto->proximo;

    }


    return 0;
}
