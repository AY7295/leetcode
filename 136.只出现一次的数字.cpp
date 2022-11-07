/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (auto x : nums)
            ans ^= x;
        return ans;
    }

    // descp mine
    // int singleNumber(vector<int> &nums)
    // {
    //     sort(nums.begin(), nums.end());
    //     int i = 0, len = nums.size();
    //     while (i < len - 1)
    //     {
    //         if (nums[i] != nums[i + 1])
    //             return nums[i];

    //         i += 2;
    //     }
    //     return nums[len - 1];
    // }
};
// @lc code=end
