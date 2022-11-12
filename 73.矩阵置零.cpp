/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size(), col = matrix[0].size();
        unordered_map<int, int> r, c;

        for (size_t i = 0; i < row; i++)
        {
            for (size_t k = 0; k < col; k++)
            {
                if (matrix[i][k] == 0)
                {
                    r[i]++;
                    c[k]++;
                }
            }
        }

        for (auto &&k : r)
        {
            for (size_t i = 0; i < col; i++)
            {
                matrix[k.first][i] = 0;
            }
        }
        for (auto &&k : c)
        {
            for (size_t i = 0; i < row; i++)
            {
                matrix[i][k.first] = 0;
            }
        }
    }
};
// @lc code=end
