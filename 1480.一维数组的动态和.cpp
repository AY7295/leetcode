/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    vector<int> runningSum(vector<int> &nums)
    {
        auto ans = nums;
        int len = ans.size();
        for (int i = 1; i < len; i++)
        {
            ans[i] += ans[i - 1];
        }

        return ans;
    }
};
// @lc code=end
