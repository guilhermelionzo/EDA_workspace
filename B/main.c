/*
 * main.c
 *
 *  Created on: 30 de jun de 2019
 *      Author: Guilherme
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG 0
#define ERROR -1

struct Stack* createStack( unsigned size );
int isEmpty(struct Stack* stack);
char peek(struct Stack* stack);
char pop(struct Stack* stack);
void push(struct Stack* stack, char operator);
int isOperand(char character);
int checkPriority(char character);
char* infixToPostFix(char* expression);

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
int checkExpression_(char *textText);
int print_();
int isFull_();
int pop_(char *value);
int isEmpty_();
void push_( char ch);

struct Stack
{
    int top;
    unsigned size;
    int* element;
};


int main()
{
	//char buffer[501] = { '\0' };
#if DEBUG
	printf("Digite the expression:\n");
	fflush(stdout);
#endif

	//READ THE EXPRESSION
	//scanf("%s", buffer);
	char buffer[501] ="A+B*(C-D*(E-F)-G*H-I*K";
	int returnValue;
	int i = 0;

	//if(checkExpression_(buffer)){
		infixToPostFix(buffer);
	//}else{
	//	printf("incorretamente parentizada\n");
	//}

	return 1;
}


/*
 * CREATING A STACK
*/
struct Stack* createStack( unsigned size )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

    if (!stack)
        return -1;

    stack->top = -1;
    stack->size = size;

    stack->element = (int*) malloc(stack->size * sizeof(int));

    if (!stack->element)
        return -1;
    return stack;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}

char peek(struct Stack* stack)
{
    return stack->element[stack->top];
}

char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->element[stack->top--] ;
    return -1;
}

void push(struct Stack* stack, char operator)
{
    stack->element[++stack->top] = operator;
}

int isOperand(char character)
{
    return (character >= 'A' && character <= 'Z');
}

/*
 * CHECK THE CHARACTER PRIORITY
 */
int checkPriority(char character)
{
    switch (character)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return 0;
}

/*
 * CHECK THE CHARACTER PRIORITY
 */
char* infixToPostFix(char* expression)
{
    int i, k;

    struct Stack* stack = createStack(strlen(expression));
    if(!stack)
        return -1 ;

    for (i = 0, k = -1; expression[i]; ++i)
    {
    	if(!checkExpression(expression[i])){
    		printf("incorretamente parentizada\n");
    		return -1;
    	}
        if (isOperand(expression[i]))
            expression[++k] = expression[i];

        else if (expression[i] == '(')
            push(stack, expression[i]);

        else if (expression[i] == ')')
        {
        	if(isEmpty(stack)){
        		printf("incorretamente parentizada\n");
        		return -1;
        	}
            while (!isEmpty(stack) && peek(stack) != '('){
            	expression[++k] = pop(stack);
            }

            if (!isEmpty(stack) && peek(stack) != '('){
            	printf("incorretamente parentizada\n");
            	return -1;
            }
            else
                pop(stack);
        }
        else
        {
            while (!isEmpty(stack) && checkPriority(expression[i]) <= checkPriority(peek(stack)))
                expression[++k] = pop(stack);
            push(stack, expression[i]);
        }

    }

    while (!isEmpty(stack)){
    	char temp=pop(stack );

    	if(temp=="("||temp==")"){
        	printf("incorretamente parentizada\n");
        	return -1;
    	}
    	expression[++k] = temp;
    }

    expression[++k] = '\0';
    printf("%s\n", expression );

    free(stack);

}

int checkExpression_(char *textText) {

	int returnValue;
	int i = 0;

	while (textText[i] != '\0') {

		returnValue = checkExpression(textText[i]);	//CHECK EACH ELEMENT IN THE EXPRESSION

		if (returnValue == DISMATCH) {
			return DISMATCH;			//RETURN 0
		}
		i++;
	}

	if (isEmpty_()) {
		return 1;
	} else {
		return DISMATCH;
	}

}
int checkExpression(char textText) {

	char temp='\0';

	if ((textText == inCaracters[0]) || (textText == inCaracters[1])
			|| (textText == inCaracters[2])) {
		push_(textText);
		return PUSH;
	}
	if ((textText == outCaracters[0]) || (textText == outCaracters[1])
			|| (textText == outCaracters[2])) {

		pop_(&temp);

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

void push_( char ch)
{
	elements[ ++top] = ch;
}

/*
 * GET THE ELEMENT FROM THE STACK
 */
int pop_(char *value)
{
	if(isEmpty_()){
		return 0;
	}else{
		*value=elements[ top--];
	}
	return 1;
}
/*
 * CHECK WHETHER THE STACK IS EMPTY
 */
int isEmpty_()
{
	return top == EMPTY;
}
/*
 * CHECK WHETHER THE STACK IS FULL
 */
int isFull_()
{
	return top == STACK_SIZE - 1;
}
