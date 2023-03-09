/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;
        while (r < n)
        {
            sum += nums[r++];
            while (sum >= s)
            {
                len = min(len, r - l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }

    // descp mine
    // int minSubArrayLen(int target, vector<int> &nums)
    // {
    //     int ans = 100001, l = 0, r = 1, n = nums.size(), sum = nums[0];
    //     while (r <= n)
    //     {
    //         if (sum < target)
    //         {
    //             if (r == n)
    //             {
    //                 return ans == 100001 ? 0 : ans;
    //             }
    //             sum += nums[r++];
    //         }
    //         else
    //         {
    //             ans = min(ans, r - l);
    //             sum -= nums[l++];
    //         }
    //     }
    //     return ans == 100001 ? 0 : ans;
    // }
};
// @lc code=end
