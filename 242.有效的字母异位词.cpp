/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<int, int> mp;
        for (auto &&i : s)
        {
            mp[i]++;
        }
        for (auto &&i : t)
        {
            if (mp[i] == 0)
                return false;

            mp[i]--;
        }

        return true;
    }
};
// @lc code=end
