#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//ÏûÊ§µÄÊı×Ö
int FindNum1(int* nums, int n)
{
	int val = 0;
	for (int i = 0; i < n; i++)
	{
		val ^= nums[i];
	}
	for (int i = 0; i < n + 1; i++)
	{
		val ^= i;
	}
	return val;
}

int FindNum2(int* nums, int n)
{
	int* hash = (int*)calloc(n + 1, sizeof(int));
	if (hash != NULL)
	{
		for (int i = 0; i < n; i++)
		{
			hash[nums[i]]++;
		}
		for (int i = 0; i < n + 1; i++)
		{
			if (hash[i] == 0)
			{
				return i;
			}
		}
	}
}

void test1(void)
{
	int arr[] = { 3, 0, 1, 4, 2, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = FindNum2(arr, sz);
	printf("ret = %d\n", ret);
}

int main()
{
	test1();
	return 0;
}