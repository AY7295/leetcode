/*
 * @lc app=leetcode.cn id=2131 lang=cpp
 *
 * [2131] 连接两字母单词得到的最长回文串
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        int ans = 0, doubleChar = 0;
        string rev = "--";
        unordered_map<string, int> mp;
        for (auto &&w : words)
        {
            if (w[0] != w[1])
            {
                mp[w]++;

                rev[0] = w[1];
                rev[1] = w[0];
                if (mp.find(rev) != mp.end() && mp[rev] > 0)
                {
                    ans += 4;
                    mp[rev]--;
                    mp[w]--;
                }
            }
            else
            {
                doubleChar++;
                mp[w]++;
                if (mp[w] > 1)
                {
                    mp[w] -= 2;
                    ans += 4;
                    doubleChar -= 2;
                }
            }
        }
        if (doubleChar > 0)
        {
            ans += 2;
        }

        return ans;
    }
};
// @lc code=end
