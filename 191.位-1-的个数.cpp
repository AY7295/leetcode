/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
#include <algorithm>
#include <stdint.h>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp official
    // int hammingWeight(uint32_t n)
    // {
    //     int ret = 0;
    //     for (int i = 0; i < 32; i++)
    //     {
    //         if (n & (1 << i))
    //         {
    //             ret++;
    //         }
    //     }
    //     return ret;
    // }

    // descp most voted solution
    int hammingWeight(uint32_t n)
    {
        int count = 0;

        while (n)
        {
            n &= (n - 1);
            count++;
        }

        return count;
    }
};
// @lc code=end
