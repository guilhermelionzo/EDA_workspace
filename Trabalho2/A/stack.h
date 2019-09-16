#ifndef _fila_h
#define _fila_h

void push(char ch);		// Insert character ch on the top of the stack
int pop(char *value);				// remove and return the top character on the stack
int isEmpty();			// return whether or not the stack is empty
int isFull();			// return whether or not the stack is full
int print();

#endif
