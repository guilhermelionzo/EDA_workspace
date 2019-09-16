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

struct Stack* createStack(unsigned size);
int isEmpty(struct Stack* stack);
char peek(struct Stack* stack);
char pop(struct Stack* stack);
void push(struct Stack* stack, char operator);
int isOperand(char character);
int checkPriority(char character);
char* infixToPostFix(char* expression);

struct Stack {
	int top;
	unsigned size;
	int* element;
};

int main() {
	char buffer[501] = { '\0' };
#if DEBUG
	printf("Digite the expression:\n");
	fflush(stdout);
#endif

	//READ THE EXPRESSION
	scanf("%s", buffer);
	//char buffer[501] ="A+(B*(C-D*(E-F)))-G*H-I*K";

	infixToPostFix(buffer);

	return 1;
}

/*
 * CREATING A STACK
 */
struct Stack* createStack(unsigned size) {
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

int isEmpty(struct Stack* stack) {
	return stack->top == -1;
}

char peek(struct Stack* stack) {
	return stack->element[stack->top];
}

char pop(struct Stack* stack) {
	if (!isEmpty(stack))
		return stack->element[stack->top--];
	return -1;
}

void push(struct Stack* stack, char operator) {
	stack->element[++stack->top] = operator;
}

int isOperand(char character) {
	return (character >= 'A' && character <= 'Z');
}

/*
 * CHECK THE CHARACTER PRIORITY
 */
int checkPriority(char character) {
	switch (character) {
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
char* infixToPostFix(char* expression) {
	int i, k;

	struct Stack* stack = createStack(strlen(expression));
	if (!stack)
		return -1;

	for (i = 0, k = -1; expression[i]; ++i) {

		if (isOperand(expression[i]))
			expression[++k] = expression[i];

		else if (expression[i] == '(')
			push(stack, expression[i]);

		else if (expression[i] == ')') {
			if (isEmpty(stack)) {
				printf("incorretamente parentizada\n");
				free(stack);
				return -1;
			}
			while (!isEmpty(stack) && peek(stack) != '(') {
				expression[++k] = pop(stack);
			}

			if (!isEmpty(stack) && peek(stack) != '(') {
				printf("incorretamente parentizada\n");
				free(stack);
				return -1;
			} else
				pop(stack);
		} else {
			while (!isEmpty(stack)
					&& checkPriority(expression[i])
							<= checkPriority(peek(stack)))
				expression[++k] = pop(stack);
			push(stack, expression[i]);
		}

	}

	while (!isEmpty(stack)) {
		char temp = pop(stack);

		if (temp == '(' || temp == ')') {
			printf("incorretamente parentizada\n");
			free(stack);
			return -1;
		}
		expression[++k] = temp;
	}

	expression[++k] = '\0';
	printf("%s\n", expression);

	free(stack);

}
