#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution_1 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }
        for (int m = 0; m < nums.size() - 3; m++)
        {
            //固定指针 m
            if (m > 0 && nums[m] == nums[m - 1]) {
                continue;
            }
            //三数之和
            for (int n = m + 1; n < nums.size() - 2; n++)
            {
                if ((n > 1) && (nums[n] == nums[n - 1]) && (n - m > 1)) {
                    continue;
                }
                int i = n + 1;
                int j = nums.size() - 1;
                while (i < j)
                {
                    long long sum = (long long)nums[m] + (long long)nums[n] +
                        (long long)nums[i] + (long long)nums[j];
                    if (sum == target)
                    {
                        res.push_back({ nums[m], nums[n], nums[i], nums[j] });
                        while (i < j && nums[i] == nums[++i]);
                        while (i < j && nums[j] == nums[--j]);
                    }
                    else if (sum < target) {
                        while (i < j && nums[i] == nums[++i]);
                    }
                    else {
                        while (i < j && nums[j] == nums[--j]);
                    }
                }
            }
        }
        return res;
    }
};

class Solution_2 {
public:
    void nextPermutation(vector<int>& nums)
    {
        int indexSmall = nums.size() - 2; //记录最靠右的较小值索引
        int indexBig = nums.size() - 1; //记录最靠右的较大值索引
        while (indexSmall >= 0 && nums[indexSmall] >= nums[indexSmall + 1])
        {
            indexSmall--;
        }
        //若不存在较小值，则跳过 寻找较大值 和 交换 的步骤
        if (indexSmall >= 0)
        {
            while (indexBig >= 0 && nums[indexBig] <= nums[indexSmall])
            {
                indexBig--;
            }
            swap(nums[indexSmall], nums[indexBig]);
        }
        //排序后侧数组以使后侧数组升序排列，以使该排列字典序增加最少
        //由于可证此时后侧数组必定是降序排列的，所以只需要逆置数组即可
        reverse(nums.begin() + indexSmall + 1, nums.end());
    }
};

int main()
{

	return 0;
}