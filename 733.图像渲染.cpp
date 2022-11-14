/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */
#include <algorithm>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int oldColor = image[sr][sc];
        if (oldColor == newColor)
        {
            return image;
        }
        int row = image.size(), col = image[0].size();
        int around[5] = {0, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        q.emplace(sr, sc);
        while (!q.empty())
        {
            auto now = q.front();
            q.pop();
            image[now.first][now.second] = newColor;
            for (int i = 0; i < 4; i++)
            {
                int x = now.first + around[i],
                    y = now.second + around[i + 1];
                if (x >= 0 && y >= 0 && x < row && y < col && image[x][y] == oldColor)
                {
                    image[x][y] = newColor;
                    q.emplace(x, y);
                }
            }
        }

        return image;
    }
};
// @lc code=end
