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

void TestPartSort1(void)
{
	int arr[] = { 9,8,7,6,5,4,3,2,0,1,1,-1,-2,-3,-3 };
	//int arr[] = { 6, 3,7,9,5,1,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	PartSort1(arr, 0, sz - 1);
	PrintArr(arr, sz);
}

int main()
{
	TestInsertSort();
	TestShellSort();
	TestSelectSort();
	TestHeapSort();
	TestBubbleSort();
	TestPartSort1();
	return 0;
}