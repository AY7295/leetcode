/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        mp[sum] = 1;
        for (auto it : nums)
        {
            sum += it;
            int find = sum - k;
            if (mp.find(find) != mp.end())
            {
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
    }
};
// @lc code=end
