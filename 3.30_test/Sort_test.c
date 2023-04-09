#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

void TestInsertSort(void)
{
	int arr[] = { 9,8,7,6,5,4,3,2,0,1,1,-1,-2,-3,-3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, sz);
	PrintArr(arr, sz);
}

void TestShellSort(void)
{
	int arr[] = { 9,8,7,6,5,4,3,2,0,1,1,-1,-2,-3,-3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, sz);
	PrintArr(arr, sz);
}

void TestSelectSort(void)
{
	int arr[] = { 9,8,7,6,5,4,3,2,0,1,1,-1,-2,-3,-3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, sz);
	PrintArr(arr, sz);
}

void TestHeapSort(void)
{
	int arr[] = { 9,8,7,6,5,4,3,2,0,1,1,-1,-2,-3,-3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, sz);
	PrintArr(arr, sz);
}

void TestBubbleSort(void)
{
	int arr[] = { 9,8,7,6,5,4,3,2,0,1,1,-1,-2,-3,-3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	PrintArr(arr, sz);
}

void TestQuickSort(void)
{
	int arr[] = { 9,8,7,6,5,4,3,2,0,1,1,-1,-2,-3,-3 };
	//int arr[] = { 6,4,2,1,8,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, sz - 1);
	PrintArr(arr, sz);
}

void TestQuickSortNonR(void)
{
	int arr[] = { 9,8,7,6,5,4,3,2,0,1,1,-1,-2,-3,-3 };
	//int arr[] = { 6,4,2,1,8,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSortNonR(arr, 0, sz - 1);
	PrintArr(arr, sz);
}

int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	TestQuickSort();
	TestQuickSortNonR();
	return 0;
}