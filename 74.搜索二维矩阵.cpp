/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][n - 1] >= target)
            {
                for (int k = 0; k < n; k++)
                {
                    int l = 0, r = n - 1, mid = l + (r - l + 1) / 2;
                    while (l <= r)
                    {
                        if (target < matrix[i][mid])
                            r = mid - 1;
                        else if (target > matrix[i][mid])
                            l = mid + 1;
                        else
                            return true;
                        mid = l + (r - l + 1) / 2;
                    }
                }
                return false;
            }
        }
        return false;
    }
};
// @lc code=end
