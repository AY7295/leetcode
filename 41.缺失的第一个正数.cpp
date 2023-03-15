/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // most voted solution
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        // mark all the negtive number to n+1
        for (int i = 0; i < n; i++)
            if (nums[i] <= 0)
                nums[i] = n + 1;

        // if |x| exists, mark the nums[|x|-1] to negtive
        for (int i = 0; i < n; i++)
            // use absolute value to avoid the value that has beed marked to negtive
            if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);

        // if nums[i] > 0, so the i+1 not exists
        for (int i = 0; i < n; i++)
            if (nums[i] > 0)
                return i + 1;

        return n + 1;
    }
};
// @lc code=end
