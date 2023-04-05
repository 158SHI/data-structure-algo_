#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//void Swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//void AdjustDown(int* a, int n, int root)
//{
//	int parent = root;
//	int child = parent * 2 + 1;
//
//	while (child < n)
//	{
//		if (child + 1 < n && a[child + 1] < a[child]) {
//			child++;
//		}
//
//		if (a[child] < a[parent])
//		{
//			Swap(a + parent, a + child);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else {
//			break;
//		}
//	}
//}
//
//void HeapSort(int* a, int n)
//{
//	for (int i = (n - 2) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);
//	}
//
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(a + 0, a + end);
//		AdjustDown(a, end, 0);
//		end--;
//	}
//}
//
//int main()
//{
//	int arr[] = { 4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	HeapSort(arr, sz);
//	return 0;
//}

void Swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int GetMidI(int* nums, int left, int right)
{
    int mid = (left + right) / 2;
    if (nums[left] > nums[mid])
    {
        if (nums[mid] > nums[right]) {
            return mid;
        }
        else if (nums[right] > nums[left]) {
            return left;
        }
        else {
            return right;
        }
    }
    else //nums[left] <= nums[mid]
    {
        if (nums[mid] < nums[right]) {
            return mid;
        }
        else if (nums[right] < nums[left]) {
            return left;
        }
        else {
            return right;
        }
    }
}

void QuickSort(int* nums, int left, int right)
{
    int begin = left;
    int end = right;
    if (begin >= end) {
        return;
    }

    int midI = GetMidI(nums, left, right);
    Swap(nums + left, nums + midI);

    int keyi = left;
    while (left < right)
    {
        while (left < right && nums[right] >= nums[keyi]) {
            right--;
        }
        while (left < right && nums[left] <= nums[keyi]) {
            left++;
        }
        Swap(nums + left, nums + right);
    }
    Swap(nums + left, nums + keyi);
    keyi = left;

    QuickSort(nums, begin, keyi - 1);
    QuickSort(nums, keyi + 1, end);
}

int main()
{
    int arr[] = { 5,2,3,1 };
    QuickSort(arr, 0, 3);
    return 0;
}