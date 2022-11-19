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

    // descp mine
    //  int hammingWeight(uint32_t n)
    //  {
    //      int count = 0;

    //     while (n)
    //     {
    //         if (n & 1)
    //         {
    //             count++;
    //         }
    //         n >>= 1;
    //     }

    //     return count;
    // }
};
// @lc code=end
