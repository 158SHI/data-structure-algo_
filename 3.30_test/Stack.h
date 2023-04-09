#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int StackDataType;

typedef struct Stack
{
	StackDataType* data;
	int capacity;
	int top;
}Stack;

void StackInit(Stack* ps);
void StackDestroy(Stack* ps);

void StackPush(Stack* ps, StackDataType x);
void StackPop(Stack* ps);
int StackSize(Stack* ps);
bool StackEmpty(Stack* ps);
StackDataType StackTop(Stack* ps);