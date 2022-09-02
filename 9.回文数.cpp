/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include <string>
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    bool isPalindrome(int x)
    {
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;
        int sum = 0;
        while (x > sum)
        {
            sum = sum * 10 + x % 10;
            x = x / 10;
        }
        return (x == sum) || (x == sum / 10);
    }

    // descp mine
    // bool isPalindrome(int x)
    // {
    //     if (x < 0)
    //         return false;

    //     if (x >= 0 && x < 10)
    //         return true;

    //     std::string s = std::to_string(x);
    //     int num = s.size();
    //     for (int i = 0; i < num / 2; i++)
    //     {
    //         if (s[i] != s[num - i - 1])
    //             return false;
    //     }

    //     return true;
    // }
};
// @lc code=end
