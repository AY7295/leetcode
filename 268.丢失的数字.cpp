/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int missingNumber(vector<int> nums)
    { // xor
        int res = nums.size(), n = res;
        for (int i = 0; i < n; i++)
        {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};
// @lc code=end
