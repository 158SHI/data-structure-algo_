#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

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

int findKthLargest(int* nums, int numsSize, int k)
{
    for (int i = (numsSize - 2) / 2; i >= 0; i--) {
        AdjustDown(nums, numsSize, i);
    }
    int end = numsSize - 1;
    while (--k)
    {
        Swap(&nums[0], &nums[end]);
        AdjustDown(nums, end, 0);
        end--;
    }
    return nums[0];
}

int main()
{
    int arr[] = { 3,2,3,1,2,4,5,5,6 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    findKthLargest(arr, sz, 4);
    return 0;
}