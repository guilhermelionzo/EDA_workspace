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

#define DEBUG_SESSION 0

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
    int notas[101]={0};

        int g,a,i,G[20],A[20],maior,mm;

        //VECTOR NUMBER INPUT
        if(DEBUG_SESSION){printf("Digite o numero de valores do vetor:\n");}
        convert_input(G,gets(buffer));
        numberOfVectorPositions=G[0];

        if(numberOfVectorPositions==NULL){return 0;} //in case of EOF, break

        //VECTOR VALUES INPUT
        if(DEBUG_SESSION){printf("Digite os valores do vetor:\n");}
        gets(buffer);

        g=convert_input(G,buffer);
        i=0;

        while(i<g+1){

            //if(DEBUG_SESSION){printf("%d\n",G[i]);}
            notas[G[i]]++;
            i++;
        }

        i=0;
        maior=0;
        mm=0;

        while(i<=100){

            if(maior<notas[i]){
                maior = notas[i];
                mm=i;
            }
            //if(DEBUG_SESSION){printf("%d\n",notas[i]);}
            i++;
        }

        printf("%d",mm);

    return 0;
}

int convert_input(int K[],char string[200])
{
    int j=0,i=0,temp=0;

    while(string[i]!='\0')
    {
        temp=0;
        while(string[i]!=' ' && string[i]!='\0')
            temp=temp*10 + (string[i++]-'0') ;
        if(string[i]==' ')
            i++;
        K[j++]=temp;
    }

    return j-1;
}



