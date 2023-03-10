/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;
        ans.reserve(s.size());
        for (auto &&i : nums2)
        {
            if (s.count(i) != 0)
            {
                ans.emplace_back(i);
                s.erase(i);
            }
        }
        return ans;
    }
};
// @lc code=end
