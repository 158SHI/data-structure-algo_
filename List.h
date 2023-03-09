#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

//�п�
bool ListEmpty(ListNode* pHead);

// ��ʼ��
ListNode* LTInit(void);
// ����
void ListDestory(ListNode* pHead);

// ��ӡ
void ListPrint(ListNode* pHead);
// β��
void ListPushBack(ListNode* pHead, LTDataType x);
// βɾ
void ListPopBack(ListNode* pHead);
// ͷ��
void ListPushFront(ListNode* pHead, LTDataType x);
// ͷɾ
void ListPopFront(ListNode* pHead);

// ����
ListNode* ListFind(ListNode* pHead, LTDataType x);
// ��pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
