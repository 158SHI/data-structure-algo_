#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void test1(void)
{
	SeqList sl = { 0 };
	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);

	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void test2(void)
{
	SeqList sl = { 0 };
	SeqListInit(&sl);

	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);

	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 1);

	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);

	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void test3(void)
{
	SeqList sl = { 0 };
	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);

	SeqListPrint(&sl);

	int pos = SeqListFind(&sl, 3);
	if (pos != -1)
	{
		SeqListInsert(&sl, pos, 6);
		SeqListInsert(&sl, pos, 7);
	}

	SeqListPrint(&sl);

	SeqListErase(&sl, 2);
	SeqListErase(&sl, 2);

	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void test4(void)
{
	SeqList sl = { 0 };
	SeqListInit(&sl);

	SeqListInsert(&sl, sl.size, 1);
	SeqListInsert(&sl, sl.size, 2);
	SeqListInsert(&sl, sl.size, 3);
	SeqListInsert(&sl, sl.size, 4);
}

int main()
{
	//test1();
	//test2();
	test3();
	//test4();
	return 0;
}