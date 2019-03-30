#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRING_LENGHT 1000

int main(void)
{
    //char* c = source;

    char string[1000];
    bool flagLoop = false;
    char outPutChar[STRING_LENGHT]="";
    char blancChar[1] =" ";
    int j =0;

    //printf("Enter a string\n");
    gets(string);

    int length = (int)strlen(string);
    
    //printf("%s\n", outPutChar);
    
    for (int i = 0; i < length; i++) 
    {   
        if(string[i]=='o'){
            j++;

        }
    }
    
    printf("%d\n",j);
    
    //gets(string);

    return 0;
}