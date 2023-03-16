#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

int main()
{
	Stack ST = { 0 };
	StackInit(&ST);
	StackPush(&ST, 1);
	StackPush(&ST, 2);
	StackPush(&ST, 3);
	StackPush(&ST, 4);
	StackPush(&ST, 5);

	while (!StackEmpty(&ST))
	{
		printf("%d ", StackTop(&ST));
		StackPop(&ST);
	}
	printf("\n");
	return 0;
}