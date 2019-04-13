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
    /*
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
    */

    //THIRD PART OF THE CLASS
    /*
    int var;
    char *ptr;
    ptr = &var;

    ptr[0] = 's';
    ptr[1] = 'o';
    ptr[2] = 'l';
    ptr[3] = '\0';

    printf("%s ... var = %d\n\n",(char*)ptr,var);       // print the value in ASCII and the value in decimal(little endian)
    var = var+2;                                        // jump the 's' to 'u' | ptr[0] = 73 +2;
    printf("%s ... var = %d\n\n",(char*)ptr,var);       // print the value in ASCII and the value in decimal(little endian)
    */
    //FOURFTH PART OF THE CLASS
    /*there is two ways to allocate memory
    -static: variable declaration
            char c;
    -dynamic: use pointers
            char *ptr;
            ptr = malloc(1);                // alocate one byte

            if(ptr == NULL){                //certificating that the ptr isn't allocated as NULL.
                printf("ERROR!\nSystem exceed the memory limit");
                exit(EXIT_FAILURE);         // finish immediately the code
            }
    at the end of the code we need to clear the memory space.
            free(ptr);
    */

    return 0;
}
