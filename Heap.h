#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

// �ѵĹ���
void HeapCreate(Heap* pHp, HPDataType* a, int n);
// �ѵ�����
void HeapDestory(Heap* pHp);
// �ѵĲ���
void HeapPush(Heap* pHp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* pHp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* pHp);
// �ѵ����ݸ���
int HeapSize(Heap* pHp);
// �ѵ��п�
bool HeapEmpty(Heap* pHp);

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k);
