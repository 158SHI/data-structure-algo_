#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void SLPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SListNode* BuySLNode(const int x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		perror("BuySLNode::malloc");
		return NULL;
	}
	else
	{
		newNode->data = x;
		newNode->next = NULL;
		return newNode;
	}
}

void SLPushBack(SListNode** pphead, SListDataType x)
{
	SListNode* newNode = BuySLNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		SListNode* cur = *pphead;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

void SLPopBack(SListNode** pphead)
{
	assert(*pphead);
	SListNode* cur = *pphead;
	if (cur->next == NULL)
	{
		free(cur);
		*pphead = NULL;
	}
	else
	{
		while (cur->next->next)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void SLPushFront(SListNode** pphead, SListDataType x)
{
	SListNode* newNode = BuySLNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

void SLPopFront(SListNode** pphead)
{
	assert(*pphead);
	SListNode* nextNode = (*pphead)->next;
	free(*pphead);
	*pphead = nextNode;
}

SListNode* SListFind(SListNode* plist, SListDataType x)
{
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x) {
			return cur;
		}
	}
	return NULL;
}

/*
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);
// �����������
void SListDestroy(SList* plist);
*/