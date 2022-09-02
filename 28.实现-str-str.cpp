/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++)
        {
            int j = 0;
            for (; j < n; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }
            if (j == n)
            {
                return i;
            }
        }
        return -1;
    }

    // descp mine
    //  int strStr(string haystack, string needle)
    //  {

    //     int lenn = needle.size();
    //     int sub = haystack.size() - lenn;
    //     for (int h = 0; h <= sub; h++)
    //     {
    //         if (haystack.substr(h, lenn) == needle)
    //             return h;
    //     }

    //     return -1;
    // }
};
// @lc code=end
