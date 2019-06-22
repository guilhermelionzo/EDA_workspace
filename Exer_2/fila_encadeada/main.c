#include <stdio.h>

#include "fila_encadeada.h"

#define SUCESSO     1
#define FALHA       0
#define FULL_MEMORY -1


#define LIST_SIZED     0
#define LIST_RESIZED   1
#define LIST_CHAIN     2

/* TIPO DE FILA
    0->TAMANHO FIXO
    1->COM REDIMENSIONAMENTO
    2->ENCADEADA CIRCULAR
*/

/******SELECT HERE******/
#define LIST_TYPE LIST_CHAIN
/***********************/

#if LIST_TYPE == LIST_SIZED
    #include "fila_int.h"

#elif LIST_TYPE == LIST_RESIZED
    #include "fila_resize.h"

#elif LIST_TYPE  == LIST_CHAIN
    #include "fila_encadeada.h"
#else
    #error Include not supported! Please, change the LIST_TYPE
#endif

// LIST_TYPE

//Inserir n elementos na fila.

//.Remover n elementos na fila.

//Reiniciar a fila

//Imprimir a fila.

//Sair


/*
MAIN ROUTINE
*/
int main(void){

    int intBuffer=0;
    int userNumber=0;
    int user=0;

    cria_fila();

    while(1){

    //Application Menu
    printf("\n****FILA DE VETOR COM TAMANHO FIXO****");
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

            if(fila_cheia()){
                printf("A fila esta cheia. Por favor, remova alguns elementos para adicionar novos!\n");
                break;
            }
            else{
                printf("Digite o usuario numero %d: ",i+1);
                user=-1;

                if(fila_cheia()){
                    printf("A fila esta cheia. Por favor, remova alguns elementos para adicionar novos!\n");
                    break;
                }
                while((user<0)||(user>999)){
                    scanf("%d",&user);

                    if((user<0)||(user>999)){printf("Os usuarios devem estar entre 0 e 999!\n");printf("Digite o usuario numero %d: ",i+1);}

                    else{enfileira(user);}

                }
            }
        }
    }

    //Remover n elementos na fila.
    if(intBuffer==2){
        if(fila_vazia()){printf("A fila esta vazia!\n");}

        else{
            printf("Digite o numero de elementos a serem removidos: ");
            scanf("%d",&user);

            int i=0;

            for(i=0;i<user;i++){
                int y;
                if(desenfileira(&y)){
                    printf("Elemento removido: %d\n",y);
                }else{
                    printf("Fila vazia!");
                    i=user;
                }

            }
        }
    }

    //Reiniciar a fila.
    if(intBuffer==3){

        while(!fila_vazia()){
            int dummy;

            desenfileira(&dummy);
        }
        printf("Fila reiniciada com sucesso!\n");
    }

    //Imprimir a fila
    if(intBuffer==4){
        imprime_fila();
    }

    //Sair.
    if(intBuffer==5){return 0;}

  }

  libera_fila();
}
