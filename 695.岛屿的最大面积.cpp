/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
#include <algorithm>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
    int row, col;
    int findLand(int x, int y, vector<vector<int>> &grid)
    {
        if (!grid[x][y])
        {
            return 0;
        }
        grid[x][y] = 0;
        int res = 1;
        if (x + 1 < row)
        {
            res += findLand(x + 1, y, grid);
        }
        if (x - 1 >= 0)
        {
            res += findLand(x - 1, y, grid);
        }
        if (y + 1 < col)
        {
            res += findLand(x, y + 1, grid);
        }
        if (y - 1 >= 0)
        {
            res += findLand(x, y - 1, grid);
        }

        return res;
    }

public:
    // descp mine
    //  int maxAreaOfIsland(vector<vector<int>> &grid)
    //  {
    //      row = grid.size();
    //      col = grid[0].size();
    //      int res = 0;
    //      for (int r = 0; r < row; r++)
    //      {
    //          for (int c = 0; c < col; c++)
    //          {
    //              if (grid[r][c])
    //                  res = max(res, findLand(r, c, grid));
    //          }
    //      }
    //      return res;
    //  }

    // descp most voted solution
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0, area = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    int a = 1;
                    grid[i][j] = 0;
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty())
                    {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c])
                            {
                                grid[r][c] = 0;
                                a++;
                                todo.push({r, c});
                            }
                        }
                    }
                    area = max(area, a);
                }
            }
        }
        return area;
    }
};
// @lc code=end
