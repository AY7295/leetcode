/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size(), p = 0;
        while (p + n - 1 < m)
        {
            if (haystack.substr(p, n) == needle)
            {
                return p;
            }
            while (p++ + n - 1 < m && haystack[p] != needle[0])
                ;
        }
        return -1;
    }
};
// @lc code=end
