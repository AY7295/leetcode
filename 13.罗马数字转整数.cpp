/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include <string>
#include <unordered_map>

// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int romanToInt(std::string s)
    {
        std::unordered_map<char, int> mp = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int res = mp[s.back()];
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (mp[s[i]] < mp[s[i + 1]])
                res -= mp[s[i]];
            else
                res += mp[s[i]];
        }
        return res;
    }

    // descp mine
    // int romanToInt(std::string s)
    // {
    //     std::unordered_map<std::string, int> sm = {{"IV", 2}, {"IX", 2}, {"XL", 20}, {"XC", 20}, {"CD", 200}, {"CM", 200}};
    //     std::unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    //     int res = 0;
    //     for (auto &&c : s)
    //         res += m[c];

    //     char pre = s[0];
    //     for (int i = 1; i < s.size(); i++)
    //     {

    //         std::string ss = std::string(1, pre) + s[i];
    //         if (sm.find(ss) != sm.end())
    //         {
    //             res -= sm[ss];
    //             if (i != s.size() - 1)
    //             {
    //                 i++;
    //             }
    //         }
    //         pre = s[i];
    //     }
    //     return res;
    // }
};
// @lc code=end
//
