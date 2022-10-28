/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    void reverseString(vector<char> &s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            swap(s[l++], s[r--]);
        }
    }
};
// @lc code=end
