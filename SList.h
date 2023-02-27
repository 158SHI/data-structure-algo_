#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

void SLPrint(SListNode* phead);
void SLPushBack(SListNode** phead, SListDataType x);
void SLPopBack(SListNode** pphead);
void SLPushFront(SListNode** pphead, SListDataType x);
void SLPopFront(SListNode** pphead);
SListNode* SListFind(SListNode* plist, SListDataType x);
void SListInsertAfter(SListNode* pos, SListDataType x);
void SListEraseAfter(SListNode* pos);
void SListDestroy(SListNode* plist);