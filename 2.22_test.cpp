#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int main()
//{
//	vector<vector<int>> res;
//	int i = 1;
//	int j = 2;
//	int k = 3;
//	res.push_back({ i,j,k });
//	res.push_back({ 4,5,6 });
//
//	vector<int> v{ 1, 3, 5, 2, 4 };
//	sort(v.begin(), v.end());
//	return 0;
//}

//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums)
//    {
//        vector< vector<int> > res;
//        sort(nums.begin(), nums.end());
//        for (int k = 0; k < nums.size() - 2; k++)
//        {
//            if (nums[k] > 0)
//            {
//                break;
//            }
//            if ((k > 0) && (nums[k] == nums[k - 1]))
//            {
//                continue;
//            }
//            int i = k + 1;
//            int j = nums.size() - 1;
//
//            while (i < j)
//            {
//                int sum = nums[k] + nums[i] + nums[j];
//                if (sum == 0)
//                {
//                    res.push_back({ nums[k] , nums[i], nums[j] });
//                    while ((i < j) && (nums[i] == nums[i + 1]))
//                    {
//                        i++;
//                    }
//                    while ((i < j) && (nums[j] == nums[j - 1]))
//                    {
//                        j--;
//                    }
//                }
//                else if (sum < 0)
//                {
//                    while ((i < j) && (nums[i] == nums[++i]))
//                    {
//                        ;
//                    }
//                }
//                else
//                {
//                    while ((i < j) && (nums[j] == nums[++j]))
//                    {
//                        ;
//                    }
//                }
//            }
//        }
//        return res;
//    }
//};

//int main()
//{
//    Solution s;
//    vector<int> v{ -1,0,1,2,-1,-4 };
//    s.threeSum(v);
//}

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int best = 3001;//记录最接近target的三元组和
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size() - 2; k++)
        {
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            int i = k + 1;
            int j = nums.size() - 1;
            while (i < j)
            {
                int sum = nums[k] + nums[i] + nums[j];
                if (sum == target)
                {
                    return sum;
                }

                if (abs(sum - target) < abs(best - target))
                {
                    best = sum;
                }

                if (sum > target)
                {
                    while (i < j && nums[j] == nums[--j]);
                }
                else
                {
                    while (i < j && nums[i] == nums[++i]);
                }
            }
        }
        return best;
    }
};

int main()
{
    Solution s;
    vector<int> v{ -1,2,1,-4 };
    s.threeSumClosest(v, 1);
    return 0;
}