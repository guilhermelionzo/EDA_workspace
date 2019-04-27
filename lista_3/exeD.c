/*
Fila
Com a proximidade da Copa do Mundo, o fluxo de pessoas nas filas para compra de ingressos
aumentou consideravelmente. Como as filas estão cada vez maiores, pessoas menos pacientes
tendem a desistir da compra de ingressos e acabam deixando as filas, liberando assim vaga
para outras pessoas. Quando uma pessoa deixa a fila, todas as pessoas que estavam atrás dela
dão um passo a frente, sendo assim nunca existe um espaço vago entre duas pessoas. A fila
inicialmente contém N pessoas, cada uma com um identificador diferente. Joãozinho sabe o
estado inicial dela e os identificadores em ordem das pessoas que deixaram a fila. Sabendo que
após o estado inicial nenhuma pessoa entrou mais na fila, Joãozinho deseja saber o estado final
da fila.
Entrada
A primeira linha contém um inteiro N representando a quantidade de pessoas inicialmente na
fila. A segunda linha contém N inteiros representando os identificadores das pessoas na fila. O
primeiro identificador corresponde ao identificador da primeira pessoa na fila. É garantido que
duas pessoas diferentes não possuem o mesmo identificador. A terceira linha contém um inteiro
M representando a quantidade de pessoas que deixaram a fila. A quarta linha contém M inteiros
representando os identificadores das pessoas que deixaram a fila, na ordem em que elas
saíram. É garantido que um mesmo identificador não aparece duas vezes nessa lista.
Saída
Seu programa deve imprimir uma linha contendo N − M inteiros com os identificadores das
pessoas que permaneceram na fila, em ordem de chegada.
Restrições
• 1 ≤ N ≤ 50000
• 1 ≤ M ≤ 50000 e M < N
• Cada identificador está entre 1 e 100000
Exemplos
Entrada
8
5 100 9 81 70 33 2 1000
3
9 33 5
Saída
100 81 70 2 1000
Entrada
4
10 9 6 3
1
3
Saída
10 9 6
*/

#include <stdio.h>
#include <stdlib.h>

void *mallocc(size_t tam){

    void *ptr;

    ptr = malloc(tam);

    if(ptr==NULL){
            exit(EXIT_FAILURE);
    }

    return ptr;
}

int main()
{
    int qtdPessoa,qtdSaida,pessoa,k=0;
    int *fila;

    scanf("%d", &qtdPessoa);

    fila=mallocc(qtdPessoa*sizeof(int));

    for(int i=0;i<qtdPessoa;i++){
        scanf("%d",&fila[i]);
    }

    scanf("%d",&qtdSaida);

    for(int i=0;i<qtdSaida;i++){

        scanf("%d",&pessoa);    // get the value that exit from the vector

        for(int j=0;j<qtdPessoa&&fila[j]!=pessoa;j++){k++;};  //go through the vector fila until find the value to substitute

        fila[k]=0;      // substitute the value by zero
    }

    //PRINT THE VALUES OF THE VECTOR
    for(int i=0;i<qtdPessoa;i++){

        if(fila[i]!=0){printf("%d ",fila[i]);}
    }

    free(fila);

    return 0;
}
