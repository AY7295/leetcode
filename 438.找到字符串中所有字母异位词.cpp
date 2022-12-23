/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    vector<int> findAnagrams(string s, string p)
    {
        int ls = s.size(), lp = p.size();
        if (lp > ls)
        {
            return {};
        }
        vector<int> ans, temp(26, 0), vp(26, 0);
        for (int i = 0; i < lp; i++)
        {
            vp[p[i] - 'a']++;
            temp[s[i] - 'a']++;
        }

        for (int i = 0; i < ls - lp; i++)
        {
            if (temp == vp)
            {
                ans.emplace_back(i);
            }
            temp[s[i] - 'a']--;
            temp[s[i + lp] - 'a']++;
        }
        if (temp == vp)
        {
            ans.emplace_back(ls - lp);
        }
        return ans;
    }
};
// @lc code=end
