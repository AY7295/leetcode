/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;
        pair<int, int> now;
        int row = grid.size(), col = grid[0].size(), ans = 0, x, y;
        vector<int> around = {1, 0, -1, 0, 1};

        for (size_t i = 0; i < row; i++)
        {
            for (size_t k = 0; k < col; k++)
            {
                if (grid[i][k] == '1')
                {
                    ans++;
                    q.emplace(i, k);
                    while (!q.empty())
                    {
                        now = q.front();
                        q.pop();
                        for (int a = 0; a < 4; a++)
                        {
                            x = around[a] + now.first;
                            y = around[a + 1] + now.second;
                            if (x < row && x >= 0 && y < col && y >= 0 && grid[x][y] == '1')
                            {
                                grid[x][y] = '0';
                                q.emplace(x, y);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
