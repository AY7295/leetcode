/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
class Solution
{
public:
    // descp most voted solution
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        return ((n & (n - 1)) == 0);
    }

    // descp mine
    // bool isPowerOfTwo(int n)
    // {
    //     if (n <= 0)
    //         return false;

    //     long int m = 1;
    //     for (int i = 0; i < 31; i++)
    //     {
    //         if (n == m)
    //             return true;
    //         else if (m > n)
    //             return false;
    //         m *= 2;
    //     }

    //     return false;
    // }
};
// @lc code=end
