/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    string reverseStr(string s, int k)
    {
        int index = 0;
        while (index < s.size())
        {
            reverse(s.begin() + index, s.begin() + index + k > s.end() ? s.end() : s.begin() + index + k);
            index += 2 * k;
        }
        return s;
    }

    // descp mine
    // string reverseStr(string s, int k)
    // {
    //     int n = s.size(), l, r, d = k * 2;
    //     char t;
    //     for (int i = 0; i < n; i += d)
    //     {
    //         l = i;
    //         r = i + k > n ? n - 1 : i + k - 1;
    //         while (l < r)
    //         {
    //             t = s[l];
    //             s[l] = s[r];
    //             s[r] = t;
    //             l++;
    //             r--;
    //         }
    //     }
    //     return s;
    // }
};
// @lc code=end
