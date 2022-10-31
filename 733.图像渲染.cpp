/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    void help(vector<vector<int>> &image, int x, int y, int color, int target)
    {
        image[x][y] = color;
        if (x - 1 >= 0 && image[x - 1][y] == target)
        {
            help(image, x - 1, y, color, target);
        }
        if (x + 1 < image.size() && image[x + 1][y] == target)
        {
            help(image, x + 1, y, color, target);
        }
        if (y - 1 >= 0 && image[x][y - 1] == target)
        {
            help(image, x, y - 1, color, target);
        }
        if (y + 1 < image[0].size() && image[x][y + 1] == target)
        {
            help(image, x, y + 1, color, target);
        }
    }

public:
    // descp mine
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (color != image[sr][sc])
            help(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};
// @lc code=end
