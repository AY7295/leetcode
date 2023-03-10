/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int num = 1, max = n * n, x, y, x0 = 0, y0 = 0;
        while (num <= max)
        {
            x = x0, y = y0;
            while (y < n + y0)
            {
                ret[x][y++] = num++;
            }

            x++, y--;
            while (x < n + x0)
            {
                ret[x++][y] = num++;
            }

            x--, y--;
            while (y >= y0)
            {
                ret[x][y--] = num++;
            }

            x--, y++;
            while (x > x0)
            {
                ret[x--][y] = num++;
            }

            n -= 2;
            x0++;
            y0++;
        }

        return ret;
    }
};
// @lc code=end
