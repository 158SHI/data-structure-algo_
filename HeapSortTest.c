#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
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

		if (a[child] > a[parent])
		{
			Swap(a + child, a + parent);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

// 对数组进行堆排序
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(a, a + end);
		AdjustDown(a, end, 0);
		end--;
	}
}

void HeapSortTest(void)
{
	int arr[] = { -3, 20, 53, 74, 22, -5, 41, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, sz);
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	HeapSortTest();
	return 0;
}