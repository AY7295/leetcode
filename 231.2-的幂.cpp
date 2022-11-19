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
        return n <= 0 ? false : (n & (n - 1)) == 0;
    }

    // descp mine
    // bool isPowerOfTwo(int n)
    // {
    //     if (n == 1)
    //         return true;
    //     return n <= 0 ? false : !(n & (n + ~1));
    // }
};
// @lc code=end
