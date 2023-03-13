/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size(), i, k, temp, l, r, temp2;
        for (i = 0; i < n - 3; i++)
        {
            if (nums[i] > target && nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (k = i + 1; k < n - 2; k++)
            {
                temp = nums[i] + nums[k];
                if (temp > target && temp > 0)
                {
                    break;
                }
                if (k > i + 1 && nums[k] == nums[k - 1])
                {
                    continue;
                }
                l = k + 1;
                r = n - 1;
                while (l < r)
                {
                    temp2 = target - nums[l++] - nums[r--]; // 边界缩进
                    if (temp2 < temp)
                    {
                        l--; // 左边界回退
                    }
                    else if (temp2 > temp)
                    {
                        r++; // 右边界回退
                    }
                    else
                    {
                        ans.emplace_back(vector<int>{nums[i], nums[k], nums[l - 1], nums[r + 1]});
                        while (l < r && nums[l] == nums[l - 1])
                            l++;
                        while (l < r && nums[r] == nums[r + 1])
                            r--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
