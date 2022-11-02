/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */
#include <algorithm>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        queue<pair<int, int>> q;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dis(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    q.push({i, j});
                    dis[i][j] = 0;
                }
            }

        vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            for (auto &&x : dir)
            {
                int a = curr.first + x[0];
                int b = curr.second + x[1];
                if (!(a == m || b == n || b < 0 || a < 0) && dis[a][b] == -1)
                {
                    q.push({a, b});
                    dis[a][b] = dis[curr.first][curr.second] + 1;
                }
            }
        }
        return dis;
    }
};
// @lc code=end
