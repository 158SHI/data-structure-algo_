#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void test1(void)
{
	Heap newHp;
	int arr[] = { 35, 47, 29, 53, 21, 50 };
	int sz = sizeof(arr) / sizeof(int);
	HeapCreate(&newHp, arr, sz);

	HeapPop(&newHp);
	HeapPop(&newHp);

	HeapPush(&newHp, 49);
	HeapPush(&newHp, 92);

	HeapDestory(&newHp);
}

void test2(void)
{
	Heap newHp;
	int arr[] = { 35, 47, 29, 53, 92, 50 };
	int sz = sizeof(arr) / sizeof(int);
	HeapCreate(&newHp, arr, sz);

	HeapPush(&newHp, 59);
	HeapPush(&newHp, 39);
	HeapPush(&newHp, 33);
	HeapPush(&newHp, 92);

	int k = 5;
	while (!HeapEmpty(&newHp) && k--)
	{
		printf("%d ", HeapTop(&newHp));
		HeapPop(&newHp);
	}
	HeapDestory(&newHp);
}

void test3(void)
{
	int arr[] = { 35, 47, 29, 53, 92, 50 };
	int sz = sizeof(arr) / sizeof(int);
	PrintTopK(arr, sz, 3);
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}