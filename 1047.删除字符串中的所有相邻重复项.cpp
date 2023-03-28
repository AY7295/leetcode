/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string removeDuplicates(string s)
    {
        string ans(s.begin(), s.begin() + 1);
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == ans.back())
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        if (ans.find("t") == ans.npos)
        {
            bool b = ans.ends_with("t");
        }
        ans.append("k");
        return ans;
    }
};
// @lc code=end
