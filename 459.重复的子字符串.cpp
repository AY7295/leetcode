/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    bool repeatedSubstringPattern(string s)
    {

        int size = s.size();

        string postfix = s.substr(1, size - 1);
        string prefix = s.substr(0, size - 1);

        string sFold = postfix + prefix;

        return sFold.find(s) != string::npos;
    }

    // descp mine
    // bool repeatedSubstringPattern(string s)
    // {
    //     int n = s.size(), d, k;
    //     bool f;
    //     for (int i = n / 2; i > 0; i--)
    //     {
    //         if (n % i != 0)
    //         {
    //             continue;
    //         }
    //         d = n / i;
    //         f = true;
    //         for (k = 1; k < d; k++)
    //         {
    //             if (s.substr(0, i) != s.substr(k * i, i))
    //             {
    //                 f = false;
    //                 break;
    //             }
    //         }
    //         if (f == true)
    //         {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
};
// @lc code=end
