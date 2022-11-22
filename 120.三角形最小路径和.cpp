/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp form bottom to top
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int row = triangle.size();
        //自下而上遍历
        for (int i = row - 2; i >= 0; --i) // 最后一行作初始值 不参与遍历
        {
            for (int j = 0; j <= i; ++j)
            {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }

    // descp mine
    // int minimumTotal(vector<vector<int>> &triangle)
    // {
    //     int deep = triangle.size(), row;
    //     for (int i = 1; i < deep; i++)
    //     {
    //         row = triangle[i].size();
    //         triangle[i][0] += triangle[i - 1][0];
    //         for (int k = 1; k < row - 1; k++)
    //         {
    //             triangle[i][k] += min(triangle[i - 1][k], triangle[i - 1][k - 1]);
    //         }
    //         triangle[i][row - 1] += triangle[i - 1][row - 2];
    //     }

    //     int ret = INT_MAX;
    //     for (auto &&i : triangle[deep - 1])
    //     {
    //         ret = min(ret, i);
    //     }

    //     return ret;
    // }
};
// @lc code=end
