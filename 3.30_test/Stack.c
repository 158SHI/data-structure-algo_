#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->data = (StackDataType*)malloc(sizeof(StackDataType) * 20);
	assert(ps->data);
	ps->capacity = 20;
	ps->top = 0;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}

void StackPush(Stack* ps, StackDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		StackDataType* tmp = NULL;
		tmp = (StackDataType*)realloc(ps->data,
			sizeof(StackDataType) * (2 * ps->capacity));
		if (tmp != NULL) {
			ps->data = tmp;
			ps->capacity *= 2;
		}
		else {
			perror("StackPush::realloc");
		}
	}
	(ps->data)[ps->top] = x;
	ps->top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

int StackSize(Stack* ps)
{
	return ps->top;
}

StackDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return (ps->data)[ps->top - 1];
}