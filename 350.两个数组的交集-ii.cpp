/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> m;
        for (auto &&i : nums1)
        {
            m[i]++;
        }

        vector<int> res;
        res.reserve(nums2.size());
        for (auto &&i : nums2)
        {
            if (m.find(i) != m.end() && m[i] != 0)
            {
                res.push_back(i);
                m[i]--;
            }
        }

        return res;
    }
};
// @lc code=end
