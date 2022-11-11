/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int row = mat.size(), col = mat[0].size();
        if ((r == row && c == col) || row * col != r * c)
        {
            return mat;
        }
        vector<vector<int>> res(r, vector<int>(c, -1));
        for (size_t i = 0; i < r * c; i++)
        {
            res[i / c][i % c] = mat[i / col][i % col];
        }
        return res;
    }
};
// @lc code=end
