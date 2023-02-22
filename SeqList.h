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

// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps);
void SeqListDestroy(SeqList* ps);

void SeqListPrint(const SeqList* ps);
void SeqListPushBack(SeqList* ps, const SLDateType x);
void SeqListPushFront(SeqList* ps, const SLDateType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);

// ˳������
int SeqListFind(SeqList* ps, const SLDateType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, const int pos, const SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, const int pos);