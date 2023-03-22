#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(a + parent, a + child);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

void HeapPush(Heap* pHp, HPDataType x)
{
	assert(pHp);
	if (pHp->size == pHp->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(pHp->a,
			sizeof(HPDataType) * pHp->capacity * 2);
		if (tmp == NULL) {
			perror("HeapPush::realloc");
			return;
		}
		else {
			pHp->a = tmp;
			pHp->capacity *= 2;
		}
	}
	(pHp->a)[pHp->size++] = x;
	AdjustUp(pHp->a, pHp->size - 1);
}

void HeapCreate(Heap* pHp, HPDataType* a, int n)
{
	assert(pHp);
	pHp->size = 0;
	pHp->capacity = n;
	pHp->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	assert(pHp->a);
	for (int i = 0; i < n; i++) {
		HeapPush(pHp, a[i]);
	}
}

void HeapDestory(Heap* pHp)
{
	assert(pHp);
	free(pHp->a);
	pHp->capacity = 0;
	pHp->size = 0;
}

void AdjustDown(Heap* pHp, int n, int root)
{
	int parent = root;
	int maxChild = parent * 2 + 1;
	while (maxChild < n)
	{
		if (maxChild + 1 < n && (pHp->a)[maxChild + 1] > (pHp->a)[maxChild]) {
			maxChild++;
		}

		if (pHp->a[maxChild] > pHp->a[parent])
		{
			Swap(pHp->a + parent, pHp->a + maxChild);
			parent = maxChild;
			maxChild = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void HeapPop(Heap* pHp)
{
	assert(pHp);
	Swap(pHp->a, pHp->a + pHp->size - 1);
	pHp->size--;
	AdjustDown(pHp, pHp->size, 0);
}

HPDataType HeapTop(Heap* pHp)
{
	assert(pHp);
	return (pHp->a)[0];
}

int HeapSize(Heap* pHp)
{
	assert(pHp);
	return pHp->size;
}

bool HeapEmpty(Heap* pHp)
{
	assert(pHp);
	return pHp->size == 0;
}

void PrintTopK(int* a, int n, int k)
{
	Heap newHP;
	HeapCreate(&newHP, a, n);
	while (!HeapEmpty(&newHP) && k--)
	{
		printf("%d ", HeapTop(&newHP));
		HeapPop(&newHP);
	}
	HeapDestory(&newHP);
}