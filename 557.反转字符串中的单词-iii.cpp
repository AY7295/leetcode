/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
class Solution
{

public:
    // descp mpst voted solution
    // string reverseWords(string &s)
    // {
    //     int i = 0;
    //     for (int j = 0; j < s.size(); ++j)
    //     {
    //         if (s[j] == ' ')
    //         {
    //             reverse(s.begin() + i, s.begin() + j);
    //             i = j + 1;
    //         }
    //     }
    //     reverse(s.begin() + i, s.end());
    //     return s;
    // }
    // descp mine
    string reverseWords(string s)
    {
        int len = s.size(), l = 0, r;
        for (size_t i = 0; i < len; i++)
        {
            if (s[i] == ' ')
            {
                r = i - 1;
                while (l < r)
                {
                    swap(s[l++], s[r--]);
                }
                l = i + 1;
            }
        }
        r = len - 1;
        while (l < r)
        {
            swap(s[l++], s[r--]);
        }

        return s;
    }
};
// @lc code=end
