#include <stdio.h>

#define QUEUE_SIZED     0
#define QUEUE_RESIZED   1
#define QUEUE_CHAIN     2

/* TIPO DE FILA
    0->TAMANHO FIXO
    1->COM REDIMENSIONAMENTO
    2->ENCADEADA CIRCULAR
*/

#define QUEUE_TYPE QUEUE_SIZED

#if QUEUE_TYPE == QUEUE_SIZED
    #include "fila_int.h"

#elif QUEUE_TYPE == QUEUE_RESIZED
    #include "fila_resize.h"

#elif QUEUE_TYPE  == QUEUE_CHAIN
    #include "fila_encadeada.h"
#else
    #error Include not supported! Please, change the QUEUE_TYPE
#endif // QUEUE_TYPE

//Inserir n elementos na fila.

//.Remover n elementos na fila.

//Reiniciar a fila

//Imprimir a fila.

//Sair

void main_sized(void);
void main_resized(void);
void main_chain(void);

int main(void){

    if(QUEUE_TYPE==QUEUE_SIZED){
        main_sized();
    }
    else if(QUEUE_TYPE==QUEUE_RESIZED){
        main_resized();
    }

    if(QUEUE_TYPE==QUEUE_CHAIN){
        main_chain();
    }
}
/*
MAIN THAT USES SIZED QUEUE
*/
void main_sized(void){

    int intBuffer=0;
    int userNumber=0;
    int user=0;

    cria_fila_int();

    while(1){

    //Application Menu
    printf("\nMENU:\n[1].Inserir n elementos na fila.\n[2].Remover n elementos na fila.\n[3].Reiniciar a fila.\n[4].Imprimir a fila.\n[5].Sair.\n");

    //read the use user choice
    scanf("%d",&intBuffer);

    system("cls");

    //Inserir n elementos na fila.
    if(intBuffer==1){

        printf("Quantos elementos deseja inserir: ");
        scanf("%d",&userNumber);

        int i=0;

        for(i=0;i<userNumber;i++){

            if(fila_int_cheia()){
                printf("A fila esta cheia. Por favor, remova alguns elementos para adicionar novos!\n");
                break;
            }
            else{
                printf("Digite o usuario numero %d: ",i+1);
                user=-1;
                while((user<0)||(user>999)){
                    scanf("%d",&user);

                    if((user<0)||(user>999)){printf("Os usuarios devem estar entre 0 e 999!\n");printf("Digite o usuario numero %d: ",i+1);}

                    else{enfileira_int(user);}

                }
            }
        }
    }

    //Remover n elementos na fila.
    if(intBuffer==2){

        printf("Digite o numero de elementos a serem removidos: ");
        scanf("%d",&user);

        int i=0;

        for(i=0;i<user;i++){
            printf("Elemento removido: %d\n",desenfileira_int());
        }
    }

    //Reiniciar a fila.
    if(intBuffer==3){

        while(!fila_int_vazia()){
            desenfileira_int();
        }
        printf("Fila reiniciada com sucesso!\n");
    }

    //Imprimir a fila
    if(intBuffer==4){
        imprime_fila_int();
    }

    //Sair.
    if(intBuffer==5){return 0;}

  }

}
