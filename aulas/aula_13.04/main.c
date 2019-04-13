#include <stdio.h>
#include <stdlib.h>


void primos(int v[]){

    v[0]=1009;v[1]=1013;v[2]=1019;

}

int main()
{
    // FIRST PART OF THE CLASS
    /*
    int ptr[3];     // declaring the array variable with three positions

    primos(ptr);    // passing the pointer through the function

    for(int i=0; i<sizeof(ptr)/sizeof(int);i++){ printf("The value in ptr[%d] is %d.\n",i,ptr[i]);} // print the values of the array
    */


    //SECOND PART OF THE CLASS
    int b[5] = {1,2,3,4,5};
    int i;
    int *bPtr;

    bPtr =b;
    *(bPtr+2)+=10;

    bPtr = bPtr+2;

    for(i=0;i<5;i++)
        printf("b[%d] = %d\n", i,b[i]);

    printf("\n");

    for(i=0;i<5;i++)
        printf("bPtr[%d] = %d\n", i,bPtr[i]);

    return 0;
}
