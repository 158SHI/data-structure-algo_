#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void PrintArr(int* nums, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//void ShellSort(int* a, int n)
//{
//	int gap = n / 2;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int j = 0; j < gap; j++)
//		{
//			for (int i = j; i < n - gap; i += gap)
//			{
//				int end = i;
//				int tmp = a[i + gap];
//				while (end >= 0)
//				{
//					if (tmp < a[end])
//					{
//						a[end + gap] = a[end];
//						end -= gap;
//					}
//					else {
//						break;
//					}
//				}
//				a[end + gap] = tmp;
//			}
//		}
//	}
//}

void ShellSort(int* a, int n)
{
	int gap = n / 2;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
		{
			int end = i - gap;
			int tmp = a[i];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

//÷±Ω”—°‘Ò≈≈–Ú
void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int mini = left;
		int maxi = left;
		for (int i = left; i <= right; i++)
		{
			mini = a[i] < a[mini] ? i : mini;
			maxi = a[i] > a[maxi] ? i : maxi;
		}
		
		Swap(a + mini, a + left);
		if (maxi == left) {
			maxi = mini;
		}
		Swap(a + maxi, a + right);

		left++;
		right--;
	}
}

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if ((child + 1 < n) && (a[child + 1] > a[child])) {
			child++;
		}

		if (a[parent] < a[child])
		{
			Swap(a + parent, a + child);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

//∂—≈≈–Ú
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(a + 0, a + end);
		AdjustDown(a, end, 0);
		end--;
	}
}

//√∞≈›≈≈–Ú
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		bool exchange = false;
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i]) {
				Swap(a + i - 1, a + i);
				exchange = true;
			}
		}
		if (!exchange) {
			break;
		}
	}
}

// øÏÀŸ≈≈–Úhoare∞Ê±æ
void PartSort1(int* a, int left, int right)
{
	int begin = left;
	int end = right;
	if (begin >= end) {
		return;
	}

	int keyi = begin;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi]) {
			right--;
		}
		while (left < right && a[left] <= a[keyi]) {
			left++;
		}
		Swap(a + left, a + right);
	}
	Swap(a + keyi, a + right);

	PartSort1(a, begin, left - 1);
	PartSort1(a, left + 1, end);
}