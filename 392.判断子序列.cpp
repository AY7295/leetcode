/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */
#include <string>
// #include<>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    bool isSubsequence(string s, string t)
    {
        int si = 0, len = s.size();
        if (len == 0)
        {
            return true;
        }
        for (auto &&i : t)
        {
            if (i == s[si])
            {
                si++;
            }
            if (si == len)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
