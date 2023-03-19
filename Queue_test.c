#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void test1(void)
{
	Queue newQueue;
	QueueInit(&newQueue);
	QueuePush(&newQueue, 1);
	QueuePush(&newQueue, 2);
	QueuePush(&newQueue, 3);
	QueuePush(&newQueue, 4);
	QueuePush(&newQueue, 5);
	printf("%d\n", QueueSize(&newQueue));
	while (!QueueEmpty(&newQueue))
	{
		printf("%d ", QueueFront(&newQueue));
		//printf("%d ", QueueBack(&newQueue));
		QueuePop(&newQueue);
	}
	printf("\n");
	printf("%d\n", QueueSize(&newQueue));
	QueueDestory(&newQueue);
}

int main()
{
	test1();
	return 0;
}