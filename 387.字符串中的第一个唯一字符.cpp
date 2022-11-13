/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    int firstUniqChar(string s)
    {
        vector<int> v(26, 0);
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            v[s[i] - 'a']++;
        }
        for (int i = 0; i < len; i++)
        {
            if (v[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};
// @lc code=end
