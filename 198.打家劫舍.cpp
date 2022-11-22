/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    // int rob(vector<int> &nums)
    // {
    //     if (nums.size() == 0)
    //         return 0;
    //     int n = nums.size();
    //     vector<int> dp(n + 1, 0);
    //     dp[1] = nums[0];
    //     for (int i = 2; i <= n; i++)
    //     {
    //         dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    //     }
    //     return dp[n];
    // }

    // descp advanced
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int n = nums.size(), now = nums[0], pre = 0, prepre = 0;

        for (auto &&i : nums)
        {
            now = max(pre, prepre + i);
            prepre = pre;
            pre = now;
        }
        return now;
    }
};
// @lc code=end
