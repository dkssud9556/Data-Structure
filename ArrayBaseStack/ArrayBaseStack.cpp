#include "ArrayBaseStack.h"
#include <stdio.h>

void StackInit(Stack* pstack) {
	pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack) {
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) {
	if (pstack->topIndex > STACK_LEN) {
		printf("Stack is Full");
		exit(1);
	}
	(pstack->topIndex)++;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack) {
	if (SIsEmpty(pstack))
	{
		printf("Stack is Empty");
		exit(1);
	}
	Data data = pstack->stackArr[pstack->topIndex];
	(pstack->topIndex)--;
	return data;
}

Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack))
	{
		printf("Stack is Empty");
		exit(1);
	}
	return pstack->stackArr[pstack->topIndex];
}