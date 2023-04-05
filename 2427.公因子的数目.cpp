/*
 * @lc app=leetcode.cn id=2427 lang=cpp
 *
 * [2427] 公因子的数目
 */
#include <cmath>
// @lc code=start
class Solution
{
public:
    int commonFactors(int a, int b)
    {
        int mi = a > b ? b : a, ma = a > b ? a : b;
        int ans = 0;
        for (int i = 1, t = 0; i <= sqrt(mi); i++)
        {
            if (mi % i == 0)
            {
                if (ma % i == 0)
                {
                    ans++;
                }
                t = mi / i;
                if (ma % t == 0 && t != i)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
