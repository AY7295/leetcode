/*
 * @lc app=leetcode.cn id=831 lang=cpp
 *
 * [831] 隐藏个人信息
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
    string hanldeEmail(string s)
    {
        auto n = s.find("@");
        s[0] = tolower(s[0]);
        for (int i = s.size() - 1; i > n - 2; i--)
        {
            s[i] = tolower(s[i]);
        }
        return s.substr(0, 1) + "*****" + s.substr(n - 1);
    }
    string handlePhone(string s)
    {
        string ans;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (isdigit(s[i]))
            {
                ans = (ans.size() > 3 ? '*' : s[i]) + ans;
            }
        }
        for (int i = 1; i * 4 < ans.size(); i++)
        {
            ans.insert(ans.size() - 4 * i, "-");
        }
        if (ans.size() - (ans.size() / 4 - 1) > 10)
        {
            ans = "+" + ans;
        }

        return ans;
    }

public:
    string maskPII(string s)
    {
        if (s.find("@") == s.npos)
        {
            return handlePhone(s);
        }
        return hanldeEmail(s);
    }
};
// @lc code=end
