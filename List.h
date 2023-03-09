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

//判空
bool ListEmpty(ListNode* pHead);

// 初始化
ListNode* LTInit(void);
// 销毁
void ListDestory(ListNode* pHead);

// 打印
void ListPrint(ListNode* pHead);
// 尾插
void ListPushBack(ListNode* pHead, LTDataType x);
// 尾删
void ListPopBack(ListNode* pHead);
// 头插
void ListPushFront(ListNode* pHead, LTDataType x);
// 头删
void ListPopFront(ListNode* pHead);

// 查找
ListNode* ListFind(ListNode* pHead, LTDataType x);
// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 删除pos位置的节点
void ListErase(ListNode* pos);
