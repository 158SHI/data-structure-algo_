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
            //�̶�ָ�� m
            if (m > 0 && nums[m] == nums[m - 1]) {
                continue;
            }
            //����֮��
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
        int indexSmall = nums.size() - 2; //��¼��ҵĽ�Сֵ����
        int indexBig = nums.size() - 1; //��¼��ҵĽϴ�ֵ����
        while (indexSmall >= 0 && nums[indexSmall] >= nums[indexSmall + 1])
        {
            indexSmall--;
        }
        //�������ڽ�Сֵ�������� Ѱ�ҽϴ�ֵ �� ���� �Ĳ���
        if (indexSmall >= 0)
        {
            while (indexBig >= 0 && nums[indexBig] <= nums[indexSmall])
            {
                indexBig--;
            }
            swap(nums[indexSmall], nums[indexBig]);
        }
        //������������ʹ��������������У���ʹ�������ֵ�����������
        //���ڿ�֤��ʱ�������ض��ǽ������еģ�����ֻ��Ҫ�������鼴��
        reverse(nums.begin() + indexSmall + 1, nums.end());
    }
};

int main()
{

	return 0;
}