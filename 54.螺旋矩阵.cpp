/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), all = m * n;
        int x = 0, y = 0, x0 = 0, y0 = 0;
        vector<int> ans(all, 0);
        for (size_t i = 0; i < all;)
        {
            while (i < all && y < n)
            {
                ans[i++] = matrix[x][y++];
            }
            y--;
            x++;
            while (i < all && x < m)
            {
                ans[i++] = matrix[x++][y];
            }
            y--;
            x--;
            while (i < all && y >= y0)
            {
                ans[i++] = matrix[x][y--];
            }
            y++;
            x--;
            while (i < all && x > x0)
            {
                ans[i++] = matrix[x--][y];
            }
            x = x0 = ++x0;
            y = y0 = ++y0;
            m--;
            n--;
        }

        return ans;
    }
};
// @lc code=end
