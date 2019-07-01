/*
 * main.c
 *
 *  Created on: 30 de jun de 2019
 *      Author: Guilherme
 */

#include "stdio.h"
#include "stdlib.h"
//#include "stack.h"

#define BUFFER_SIZE		501
#define POP 			-1
#define DISMATCH		0
#define PUSH 			1
#define CHECK_NA		2

#define DEBUG			0
#define STACK_SIZE 501
#define EMPTY (-1)


char elements[ STACK_SIZE];	// The stack
int top = EMPTY;

char inCaracters[] = { '(', '[', '{' };
char outCaracters[] = { ')', ']', '}' };

int checkExpression(char textText);
int print();
int isFull();
int pop(char *value);
int isEmpty();
void push( char ch);


int main(void) {

	char buffer[BUFFER_SIZE] = { '\0' };

	#if DEBUG
	printf("Digite a value\n");
	fflush(stdout);
	#endif

	//READ THE EXPRESSION
	scanf("%s", buffer);

	int returnValue;
	int i = 0;

	//WHILE THE CODE DON'T REACHT THE FINAL ELEMENT, CHECK THE CONSISTENCY OF THE EXPRESSION
	while (buffer[i] != '\0') {

		returnValue = checkExpression(buffer[i]);	//CHECK EACH ELEMENT IN THE EXPRESSION

		if (returnValue == DISMATCH) {
			printf("nao\n");			//IF THERE IS ANY INCONSISTENCY IN THE EXPRESSION, PRINT 'nao'
			return DISMATCH;			//RETURN 0
		}
		i++;
	}

	isEmpty() ? printf("sim\n") : printf("nao\n");	//IF THE STACK IS EMPTY, RETURN 'sim', OTHERWISE 'nao'

	//free(buffer);

	return 0;
}
/*
 * CHECK WHETHER ELEMENT IS CONSISTNECY
 */
int checkExpression(char textText) {

	char temp;


	if ((textText == inCaracters[0]) || (textText == inCaracters[1])
			|| (textText == inCaracters[2])) {
		push(textText);
		return PUSH;
	}
	if ((textText == outCaracters[0]) || (textText == outCaracters[1])
			|| (textText == outCaracters[2])) {

		pop(&temp);

		if (temp == inCaracters[0] && textText == outCaracters[0]) {
			return POP;
		}
		if (temp == inCaracters[1] && textText == outCaracters[1]) {
			return POP;
		}
		if (temp == inCaracters[2] && textText == outCaracters[2]) {
			return POP;
		}
		return DISMATCH;
	}
	return CHECK_NA;
}

/*
 * PUT THE ELEMENT IN THE STACK
 */
void push( char ch)
{
	elements[ ++top] = ch;
}

/*
 * GET THE ELEMENT FROM THE STACK
 */
int pop(char *value)
{
	if(isEmpty()){
		return 0;
	}else{
		*value=elements[ top--];
	}
	return 1;
}
/*
 * CHECK WHETHER THE STACK IS EMPTY
 */
int isEmpty()
{
	return top == EMPTY;
}
/*
 * CHECK WHETHER THE STACK IS FULL
 */
int isFull()
{
	return top == STACK_SIZE - 1;
}
/*
 * PRINT THE STACK DATA
 */
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
