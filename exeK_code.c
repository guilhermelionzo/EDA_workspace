#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFERSIZE 1000

#define DEBUG_SESSION 1

#ifdef DEBUG_SESSION
    #define PRINT 1
#endif

#ifndef DEBUG_SESSION
    #define PRINT 0
#endif


char* getUserInput(void);

void rot13( char * str );

char* pReplace(char*string);

int main() {



    while(1)
    {
        //char* inputString=(char*)malloc(BUFFERSIZE);
        char* aux=(char*)malloc(BUFFERSIZE);
        //fgets(inputString, BUFFERSIZE , stdin);
        char* inputString = getUserInput();

        if(inputString==0){break;}

        aux=pReplace(inputString);
        //if(inputString==0){break;} // REACH THE EOF CASE

        //printf("%s\n",inputString);

        free(inputString);
    }

    return 0;
}

/*
FUCTION TO READ A USER INPUT
    IN CASE OF EOF SITUATION, RETURN -1
*/
char* getUserInput(void){

    char* inputValue=(char*)malloc(BUFFERSIZE); //ALOCATE A SPACE ON MEMORY

    char* buffer[BUFFERSIZE];

    if(DEBUG_SESSION){printf("Enter a message: \n");}

    if(!fgets(buffer, BUFFERSIZE , stdin)){return 0;} // EOF return -1

    strcpy(inputValue,buffer);

    return inputValue;
}

void rot13( char * str )
    {
        int i = 0;

        /* You do this until you find a '\0' */
        for( i = 0; str[ i ] != '\0' ; i++ ){

            /* Use the pointer notation if you passed a pointer. */
            /* If the letter is between a and m you can simply  sum it. */
            if( (*( str + i ) >= 'a' && *( str + i ) < 'n')||  //LOWERCASE
               (*( str + i ) >= 'A' && *( str + i ) < 'N'))    //UPPERCASE
                *( str + i ) += 13;

            /* If the letter is between the n and z you have to do the opposite.*/
            else if((*( str + i ) >= 'n' && *( str + i ) <= 'z')||  //LOWECASE
                    (*( str + i ) >= 'N' && *( str + i ) <= 'Z'))   //UPPERCASE
                *( str + i ) -= 13;
        }
}

char* pReplace(char*string){

    int length = (int)strlen(string);
    printf("%d\n", length);
	char* outPutChar  =(char*)malloc(BUFFERSIZE);

	int flagLoop =1;

    int j=0;
    int i=0;

	printf("%s\n", string);

	for( i = 0; i<length; i++ ){
    {
        printf("%d:%c\n",i,string[ i ]);

    	/*if(string[ i ]==' '){
    		outPutChar[j]=' ';
    		j++;
    	}else{
    		if(flagLoop){
    			outPutChar[j]=string[ i ];
    			j++;
    			flagLoop=0;
    		}else{
    			flagLoop=1;
    		}

        }*/
    }
    //printf("%s\n",outPutChar);
    return outPutChar;
    //strncpy(string,outPutChar,sizeof(outPutChar));
}
}
