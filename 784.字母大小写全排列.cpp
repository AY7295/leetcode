/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    vector<string> letterCasePermutation(string s)
    {
        vector<string> res;
        int gap = 'a' - 'A';

        function<void(int, string)> help = [&](int now, string target)
        {
            if (now == target.size())
            {
                res.push_back(target);
                return;
            }

            if (isalpha(target[now]))
            {
                help(now + 1, target);
                auto ch = target[now];
                target[now] = ch >= 'a' ? ch - gap : ch + gap;
                help(now + 1, target);
            }
            else
            {
                help(now + 1, target);
            }
        };
        help(0, s);

        return res;
    }

    // descp official
    // vector<string> letterCasePermutation(string s)
    // {
    //     int n = s.size();
    //     int m = 0;
    //     for (auto c : s)
    //     {
    //         if (isalpha(c))
    //         {
    //             m++;
    //         }
    //     }
    //     vector<string> ans;
    //     for (int mask = 0; mask < (1 << m); mask++)
    //     {
    //         string str;
    //         for (int j = 0, k = 0; j < n; j++)
    //         {
    //             if (isalpha(s[j]) && (mask & (1 << k++)))
    //             {
    //                 str.push_back(toupper(s[j]));
    //             }
    //             else
    //             {
    //                 str.push_back(tolower(s[j]));
    //             }
    //         }
    //         ans.emplace_back(str);
    //     }
    //     return ans;
    // }
};
// @lc code=end
