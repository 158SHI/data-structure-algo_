#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int SLDateType;

#define INIT_CAPACITY 5

typedef struct SeqList
{
	SLDateType* a;
	int size;
	int capacity;
}SeqList;

// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps);
void SeqListDestroy(SeqList* ps);

void SeqListPrint(const SeqList* ps);
void SeqListPushBack(SeqList* ps, const SLDateType x);
void SeqListPushFront(SeqList* ps, const SLDateType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);

// 顺序表查找
int SeqListFind(SeqList* ps, const SLDateType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, const int pos, const SLDateType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, const int pos);