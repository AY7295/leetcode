/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); //关键
        vector<vector<int>> ans;
        int n = nums.size(), now, sum, i, j, k;

        for (i = 0; i < n - 2; ++i)
        {
            now = nums[i];

            if (i && now == nums[i - 1])
                continue; // 跳过重复数字
            if (now + nums[i + 1] + nums[i + 2] > 0)
                break; // 优化一
            if (now + nums[n - 2] + nums[n - 1] < 0)
                continue; // 优化二

            j = i + 1, k = n - 1;
            while (j < k)
            {
                sum = now + nums[j] + nums[k];
                if (sum > 0)
                    --k;
                else if (sum < 0)
                    ++j;
                else
                {
                    ans.push_back({now, nums[j], nums[k]});
                    for (++j; j < k && nums[j] == nums[j - 1]; ++j)
                        ; // 跳过重复数字
                    for (--k; k > j && nums[k] == nums[k + 1]; --k)
                        ; // 跳过重复数字
                }
            }
        }
        return ans;
    }
};
// @lc code=end
