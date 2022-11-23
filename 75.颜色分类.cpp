/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp official
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for (int i = 0; i <= p2; ++i)
        {
            while (i <= p2 && nums[i] == 2)
            {
                swap(nums[i], nums[p2]);
                --p2;
            }
            if (nums[i] == 0)
            {
                swap(nums[i], nums[p0]);
                ++p0;
            }
        }
    }

    // descp mine
    // void sortColors(vector<int> &nums)
    // {
    //     int count0 = 0, count1 = 0, count2 = 0;
    //     for (auto &&i : nums)
    //     {
    //         if (i == 1)
    //             count1++;
    //         else if (i == 2)
    //             count2++;
    //         else
    //             count0++;
    //     }
    //     for (int i = 0; i < count0; i++)
    //         nums[i] = 0;
    //     for (int i = count0; i < count1 + count0; i++)
    //         nums[i] = 1;
    //     for (int i = count0 + count1; i < count1 + count0 + count2; i++)
    //         nums[i] = 2;
    // }
};
// @lc code=end
