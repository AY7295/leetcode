/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    string longestCommonPrefix(vector<string> &str)
    {
        int n = str.size();
        if (n == 0)
            return "";

        string ans = "";
        sort(begin(str), end(str)); // tip 字典顺序排序
        string a = str[0];
        string b = str[n - 1];

        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == b[i])
            {
                ans = ans + a[i];
            }
            else
            {
                break;
            }
        }

        return ans;
    }

    // descp mine
    // string longestCommonPrefix(vector<string> &strs)
    // {
    //     int minestStrIndex = 0;
    //     for (int i = 0; i < strs.size(); i++)
    //     {
    //         if (strs[i].size() < strs[minestStrIndex].size())
    //         {
    //             minestStrIndex = i;
    //         }
    //     }
    //     string minestStr = strs[minestStrIndex];
    //     int index = minestStr.size();

    //     for (auto &&s : strs)
    //     {
    //         for (int i = 0; i < index; i++)
    //         {
    //             if (s[i] != minestStr[i])
    //             {
    //                 index = i;
    //                 break;
    //             }
    //         }
    //     }

    //     return minestStr.substr(0, index);
    // }
};
// @lc code=end
