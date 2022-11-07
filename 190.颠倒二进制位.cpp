/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */
#include <stdint.h>

// @lc code=start
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 1;
        for (int i = 0; i < 32; i++)
        {
            res <<= 1;
            if (n & (1 << i))
            {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
