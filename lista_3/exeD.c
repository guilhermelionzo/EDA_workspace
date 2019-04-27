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
    int qtdPessoa,qtdSaida,pessoa;
    int *fila;

    scanf("%d", &qtdPessoa);

    fila=mallocc(qtdPessoa*sizeof(int));

    for(int i=0;i<qtdPessoa;i++){
        scanf("%d",&fila[i]);
    }

    scanf("%d",&qtdSaida);

    for(i=0;i<qtdSaida;i++){

        scanf("%d",&pessoa);    // get the value that exit from the vector

        for(int j=0;j<qtdPessoa&&fila[j]!=pessoa;j++);  //go through the vector fila until find the value to substitute

        fila[j]=0;      // substitute the value by zero
    }

    return 0;
}
