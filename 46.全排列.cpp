/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;

        // Backtracking
        function<void(vector<int> &, int, int)> permutation = [&](vector<int> &nums, int i, int n)
        {
            if (i == n)
            {
                result.push_back(nums);
                return;
            }

            for (int j = i; j <= n; j++)
            {
                swap(nums[i], nums[j]);
                permutation(nums, i + 1, n);
                swap(nums[i], nums[j]);
            }
        };
        permutation(nums, 0, nums.size() - 1);

        return result;
    }
};
// @lc code=end
