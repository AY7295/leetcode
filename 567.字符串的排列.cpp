/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;

        vector<int> H_S1(26, 0);
        vector<int> H_S2(26, 0);

        for (int i = 0; i < s1.size(); ++i)
        {
            H_S1[s1[i] - 'a']++;
            H_S2[s2[i] - 'a']++;
        }
        if (H_S1 == H_S2)
            return true;

        for (int j = s1.size(), i = 0; j < s2.size(); ++j, ++i)
        {
            H_S2[s2[i] - 'a']--;
            H_S2[s2[j] - 'a']++;
            if (H_S1 == H_S2)
                return true;
        }
        return false;
    }

    // descp mine
    // bool checkInclusion(string s1, string s2)
    // {
    //     int len1 = s1.size(), len2 = s2.size(), k = 0;
    //     if (len1 > len2)
    //         return false;

    //     vector<int> o(256, -1), temp;
    //     for (auto &&i : s1)
    //     {
    //         if (o[i] == -1)
    //             o[i] = 1;
    //         else
    //             o[i]++;
    //     }

    //     for (int i = 0; i <= len2 - len1; i++)
    //     {
    //         temp = o;
    //         for (k = i; k < len1 + i; k++)
    //         {
    //             if (temp[s2[k]] < 1)
    //                 break;
    //             else
    //                 temp[s2[k]]--;
    //         }
    //         if (k == (len1 + i))
    //             return true;
    //     }
    //     return false;
    // }
};
// @lc code=end
