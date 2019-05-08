#include <stdio.h>
#include <int_fila.h>

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
    printf("MENU:\n[1].Inserir n elementos na fila.\n[2].Remover n elementos na fila.\n[3].Reiniciar a fila.\n[4].Imprimir a fila.\n[5].Sair.\n");
    
    //read the use user choice
    scanf("%d",&intBuffer);
    
    if(intBuffer==5){return 0;}
    
    if(intBuffer==1){
        
        printf("Digite quantos elementos você deseja inserir:\n");
        scanf("%d",&userNumber);
        
        for(int i=0;i<userNumber;i++){
            
            if(fila_int_cheia()){
                printf("A fila esta cheia. Por favor, remova alguns elementos para adicionar novos\n");
                break;
            }
            else{
                printf("Digite o %d° usuario:\n",i+1);
                scanf("%d",&user);
                enfileira_int(y);
            }
            
        }
        
    }
    //return 0;
  }
  
}
