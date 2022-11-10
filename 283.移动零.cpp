/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp  mine
    void moveZeroes(vector<int> &nums)
    {
        int len = nums.size();
        int k = 0;
        for (int i = 0; i < len; i++)
        {
            if (nums[i] != 0)
                nums[k++] = nums[i];
        }
        while (k < len)
            nums[k++] = 0;
    }
};
// @lc code=end
