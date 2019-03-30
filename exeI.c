/*STRING5
=======
Escreva um programa que leia um conjunto de strings onde cada string tem no
máximo um tamanho T ( 1 <= T <= 100 ). O conjunto de strings possui um
tamanho indeterminado, termina com EOF. O seu programa deverá imprimir a
quantidade de caracteres 'o' (o minúsculo) lidos.

Entrada
-------

A entrada é composta com um único caso de teste. A entrada possui um número
indeterminado de strings, cada string tem no máximo um tamanho T (1<= T <= 100).

Saída
-----

A saída deverá conter uma única linha contendo o número de caracteres 'o'
lidos.

Exemplo:
-------

Entrada:
Oi aqui eh o seu professor
Diga o que voce quer de natal hoje
praca, maca, bacana, alho, cebola

Saída:
8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMUM_VALUE 100000
int main()
{
    char string[101];

    int j =0;

    gets(string);

    int length = (int)strlen(string);
    
    for (int i = 0; i < length; i++) 
    {   
        if(string[i]=='o'){
            j++;

        }
    }
    
    printf("%d\n",j);

    return 0;
}
/*
a-0
b-1
c-2
d-3
e-4
f-5
g-6
h-7
i-8
...
*/