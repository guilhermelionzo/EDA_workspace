#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 100000
#define LOOP_EXIT 0

int main()
{
    char numberOfTimesPlayed[MAX_STRING_LEN];
    
    int flagComp_1,flagComp2_1 =0;
    int flagComp_0,flagComp2_0 =0;
    
    int interator,lenghtVector,flagComp =0;

    while(1){
        int aliceWin=0;
        int betoWin=0;

    	//printf("Digite o numero de vezes jogadas:");
        fgets(numberOfTimesPlayed, 20, stdin);

		flagComp = strcmp(numberOfTimesPlayed,"0\n");

        if(!flagComp){
        	break;
        }

        char auxInput[MAX_STRING_LEN];
        //printf("Enter the sequence:");
        fgets(auxInput, MAX_STRING_LEN, stdin);
        
        char *ptr = strtok(auxInput, " ");
 
        while (ptr != NULL)
		{
			//printf("%s", ptr);
           
            flagComp_1  = strcmp(ptr,"1");
            flagComp2_1 = strcmp(ptr,"1\n");

            flagComp_0  = strcmp(ptr,"0");
            flagComp2_0 = strcmp(ptr,"0\n");

            //SE FOR 1, BETO GANHA
            if(!flagComp2_1||!flagComp_1){
                betoWin++;
            //SE FOR 0, ALICE GANHA
            }if(!flagComp2_0||!flagComp_0){
                aliceWin++;
            }

			ptr = strtok(NULL, " ");

		}

        //PRINTA OS VALORES DO RESULTADO DOS JOGOS
        printf("Alice ganhou %d e Beto ganhou %d\n",aliceWin,betoWin);

     }

    return 0;
}