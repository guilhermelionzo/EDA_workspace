#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[20];
    char string[20];

    //tamanho dos tipos primitivos, em bytes
    /*printf("TAMANHOS:\n"
           "\t char....:%ld\n"
           "\t short....:%ld\n"
           "\t int....:%ld\n"
           "\t long....:%ld\n"
           "\t float....:%ld\n"
           "\t double....:%ld\n"
           "\t long double ....:%ld\n",sizeof(char),sizeof(short),sizeof(int),sizeof(long),sizeof(float),sizeof(long double));
*/

    int i =5;

    printf("&i (dec.) %ld\n", (long int)&i);    //decimal
    printf("&i (hexa.) %p\n", (long int)&i);    //hexadecimal


    //printf("Hello world!\n");
    return 0;
}
