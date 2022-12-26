/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int i = 0, j = 0, maxi = 0;
        unordered_map<char, int> mp;
        int ans = -1;
        while (j < n)
        {
            mp[s[j]]++;
            maxi = max(maxi, mp[s[j]]);
            if ((j - i + 1) - maxi > k)
            {
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, (j - i + 1));
            j++;
        }
        return ans;
    }
};
// @lc code=end
