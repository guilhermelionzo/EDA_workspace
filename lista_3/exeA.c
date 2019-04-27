/*
Notas
O professor Arquimedes precisa da sua ajuda para descobrir qual é a nota mais frequente entre
as notas que os alunos dele tiraram na última prova. A turma tem N alunos e seu programa deve
imprimir a nota que aparece mais vezes na lista de N notas. Se houver mais de uma nota mais
frequente, você deve imprimir a maior delas! Por exemplo, se a turma tiver N = 10 alunos e as
notas forem [20, 25, 85, 40, 25, 90, 25, 40, 55, 40], as notas mais frequentes são 25 e 40,
ocorrendo três vezes cada. Seu programa, então, deve imprimir 40.
Entrada
A entrada consiste de duas linhas. A primeira linha contém um número inteiro N , o número de
alunos na turma. A segunda linha contém N inteiros, que é a lista de notas dos alunos.
Saída
Seu programa deve imprimir apenas uma linha contendo apenas um número, a nota mais
frequente da lista.
Restrições
• 1 ≤ N ≤ 200
• O valor de todas as notas é um inteiro entre 0 e 100, inclusive
Exemplos
Entrada
10
20 25 85 40 25 90 25 40 55 40
Saída
40
Entrada
12
45 0 33 70 12 55 70 70 90 55 70 100
Saída
70
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 1000000

#define DEBUG_SESSION 1

#ifdef DEBUG_SESSION
    #define PRINT 1
#endif

#ifndef DEBUG_SESSION
    #define PRINT 0
#endif

int main()
{
    int numberOfVectorPositions;
    char buffer[BUFFERSIZE];

    while(1){

        //VECTOR NUMBER INPUT
        if(DEBUG_SESSION){printf("Digite o numero de valores do vetor:\n");}
        scanf("%d",&numberOfVectorPositions);

        if(numberOfVectorPositions==NULL){break;} //in case of EOF, break

        //VECTOR VALUES INPUT
        if(DEBUG_SESSION){printf("Digite os valores do vetor:\n");}
        scanf("%s",&buffer);



        int *gradesVector;

        gradesVector=malloc(numberOfVectorPositions*sizeof(int));

        //for(int i=0;i<gradesVector;i++){


        //}

        if(DEBUG_SESSION){printf("%s\n",buffer);}


    if(DEBUG_SESSION){printf("Digite o numero de vetores:\n");}

    }

    return 0;
}
