#include <stdio.h>
#include <fila_int.h>

//Inserir n elementos na fila.

//.Remover n elementos na fila.

//Reiniciar a fila

//Imprimir a fila.

//Sair

int main(void){

  int intBuffer=0;
  int userNumber=0;
  int user=0;
  cria_fila_int();

  while(1){

    //Application Menu
    printf("\nMENU:\n[1].Inserir n elementos na fila.\n[2].Remover n elementos na fila.\n[3].Reiniciar a fila.\n[4].Imprimir a fila.\n[5].Sair.\n");

    //read the use user choice
    scanf("%d",&intBuffer);

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

                    if((user<0)||(user>999)){printf("Os usuarios devem estar entre 0 e 999!\n");}

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
        imprime_fila();
    }

    //Sair.
    if(intBuffer==5){return 0;}

  }

}
