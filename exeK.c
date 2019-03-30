#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 1000

#define DEBUG_SESSION 1

#ifdef DEBUG_SESSION
    #define PRINT 1
#endif

#ifndef DEBUG_SESSION
    #define PRINT 0
#endif


char* getUserInput(void);

char* rot13(char* letterToSwitch);

int main() {

    char* inputString;

    while(1)
    {

        inputString = getUserInput();

        if(inputString==-1){break;} // REACH THE EOF CASE

        for(int i=0;i<strlen(inputString)-1;i++){
            printf("%c\n",inputString[i]-13);
        /*if(DEBUG_SESSION){printf("%c.",inputString[i]);}

            if((inputString[i]>='a'&&inputString[i]<'n')|| // COMPARE IN LOWERCASE
               (inputString[i]>='A'||inputString[i]<'N')){ // COMPARE IN UPPERCASE

                //printf("%c\n",inputString[i]-13);

               }
            else if((inputString[i]>='n'&&inputString[i]<'z')|| // COMPARE IN LOWERCASE
                    (inputString[i]>='N'||inputString[i]<'Z')){ // COMPARE IN UPPERCASE

                //printf("%c\n",inputString[i]+13);

               }*/


        }

    }

    return 0;
}

char* rot13(char* letterToSwitch){

    for(int i=0;i<strlen(letterToSwitch);i++){



    }


}

/*
FUCTION TO READ A USER INPUT
    IN CASE OF EOF SITUATION, RETURN -1
*/
char* getUserInput(void){

    char* inputValue,buffer[BUFFERSIZE];

    if(DEBUG_SESSION){printf("Enter a message: \n");}

    if(!fgets(buffer, BUFFERSIZE , stdin)){return -1;} // EOF return -1

    strcpy(inputValue,buffer);

    return  inputValue;
}
