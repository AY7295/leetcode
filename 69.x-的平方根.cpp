/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted Solution
    int mySqrt(int x)
    {
        long r = x;
        while (r * r > x)
            r = (r + x / r) / 2;
        return r;
    }

    // descp mine
    // int mySqrt(int x)
    // {
    //     int end = (x / 2) + 1;
    //     for (unsigned int i = 1; i <= end; i++)
    //     {
    //         if (i * i < x)
    //         {
    //             continue;
    //         }
    //         if (i * i == x)
    //         {
    //             return i;
    //         }
    //         if (i * i > x)
    //         {
    //             return i - 1;
    //         }
    //     }
    //     return x;
    // }
};
// @lc code=end
