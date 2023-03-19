#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void QueueInit(Queue* pQ)
{
	assert(pQ);
	pQ->front = NULL;
	pQ->back = NULL;
	pQ->size = 0;
}

void QueueDestory(Queue* pQ)
{
	assert(pQ);
	while (pQ->front)
	{
		QueueNode* nextNode = pQ->front->next;
		free(pQ->front);
		pQ->front = nextNode;
	}
	pQ->front = NULL;
	pQ->back = NULL;
	pQ->size = 0;
}

void QueuePush(Queue* pQ, QueueDataType x)
{
	assert(pQ);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newNode);
	newNode->data = x;
	newNode->next = NULL;
	if (pQ->front == NULL)
	{
		assert(pQ->back == NULL);
		pQ->front = newNode;
		pQ->back = newNode;
	}
	else
	{
		pQ->back->next = newNode;
		pQ->back = newNode;
	}
	pQ->size++;
}

bool QueueEmpty(Queue* pQ)
{
	return pQ->size == 0;
}

void QueuePop(Queue* pQ)
{
	assert(pQ);
	assert(!QueueEmpty(pQ));
	QueueNode* nextNode = pQ->front->next;
	free(pQ->front);
	pQ->front = nextNode;
	if (pQ->front == NULL) {
		pQ->back = NULL;
	}
	pQ->size--;
}

int QueueSize(Queue* pQ)
{
	assert(pQ);
	return pQ->size;
}

QueueDataType QueueFront(Queue* pQ)
{
	assert(pQ);
	return pQ->front->data;
}

QueueDataType QueueBack(Queue* pQ)
{
	assert(pQ);
	return pQ->back->data;
}