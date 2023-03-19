#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QueueDataType;

typedef struct QueueNode
{
	QueueDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* front;
	QueueNode* back;
	int size;
}Queue;

void QueueInit(Queue* pQ);
void QueueDestory(Queue* pQ);

void QueuePush(Queue* pQ, QueueDataType x);
void QueuePop(Queue* pQ);
bool QueueEmpty(Queue* pQ);
int QueueSize(Queue* pQ);
QueueDataType QueueFront(Queue* pQ);
QueueDataType QueueBack(Queue* pQ);