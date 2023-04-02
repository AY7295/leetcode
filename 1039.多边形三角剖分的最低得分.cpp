/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] 多边形三角剖分的最低得分
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp by 灵茶山
    int minScoreTriangulation(vector<int> &v)
    {
        int n = v.size(), f[n][n];
        memset(f, 0, sizeof(f));
        for (int i = n - 3; i >= 0; --i)
            for (int j = i + 2; j < n; ++j)
            {
                f[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + v[i] * v[j] * v[k]);
            }
        return f[0][n - 1];
    }
};
// @lc code=end
