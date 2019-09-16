#include <stdio.h>
#include "stack.h"

#define STACK_SIZE 500
#define EMPTY (-1)


char elements[ STACK_SIZE];	// The stack
int top = EMPTY;

void push( char ch)
{
	elements[ ++top] = ch;
}

int pop(char *value)
{
	if(isEmpty()){
		return 0;
	}else{
		*value=elements[ top--];
	}
	return 1;
}

int isEmpty()
{
	return top == EMPTY;
}

int isFull()
{
	return top == STACK_SIZE - 1;
}

int print(){

    if(isEmpty()){return 0;}

    int i=0;

    printf("\n");
    for(i=0;i<=top;i++){printf("----");}
    printf("\n");

    for(i=0;i<=top;i++){

        printf("%c | ",elements[i]);

    }
    printf("\n");
    for(i=0;i<=top;i++){{printf("----");}

    }
}
