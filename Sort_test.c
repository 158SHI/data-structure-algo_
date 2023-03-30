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

int main()
{
	TestInsertSort();
	TestShellSort();
	return 0;
}