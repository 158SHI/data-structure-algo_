#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void SLTest1(void)
{
	SListNode* plist = NULL;

	SLPrint(plist);

	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPrint(plist);
	SLPushBack(&plist, 4);
	SLPushBack(&plist, 5);
	SLPrint(plist);

	SLPopBack(&plist);
	SLPopBack(&plist);
	SLPopBack(&plist);
	SLPrint(plist);

	SLPopBack(&plist);
	SLPopBack(&plist);
	SLPrint(plist);

	SLPopBack(&plist);
}

void SLTest2(void)
{
	SListNode* plist = NULL;

	SLPushFront(&plist, 1);
	SLPushFront(&plist, 2);
	SLPushFront(&plist, 3);
	SLPushFront(&plist, 4);
	SLPushFront(&plist, 5);

	SLPrint(plist);

	SLPopFront(&plist);
	SLPopFront(&plist);
	SLPopFront(&plist);
	SLPopFront(&plist);
	SLPrint(plist);
	
	SLPopFront(&plist);
	SLPrint(plist);
	
	SLPopFront(&plist);
}

void SLTest3(void)
{
	SListNode* plist = NULL;

	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLPushBack(&plist, 5);

	SListNode* pos = NULL;
	if ((pos = SListFind(plist, 3)) != NULL)
	{

	}
}

int main()
{
	//SLTest1();
	//SLTest2();
	SLTest3();
	return 0;
}