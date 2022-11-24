/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted souton
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // first we take transpose of the matrix
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // then we take mirror image about the middle vertical line
        for (int i = 0; i < n; ++i)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    // descp mine
    // void rotate(vector<vector<int>> &matrix)
    // {
    //     int n = matrix.size() - 1;
    //     if (n <= 1)
    //     {
    //         return;
    //     }
    //     function<void(vector<pair<int, int>>, int)> help = [&](vector<pair<int, int>> quator, int n)
    //     {
    //         if (n <= 1)
    //         {
    //             return;
    //         }
    //         int temp = 0;
    //         for (int i = 0; i < n; i++)
    //         {
    //             temp = matrix[quator[0].first][quator[0].second + i];
    //             matrix[quator[0].first][quator[0].second + i] = matrix[quator[3].first - i][quator[3].second];
    //             matrix[quator[3].first - i][quator[3].second] = matrix[quator[2].first][quator[2].second - i];
    //             matrix[quator[2].first][quator[2].second - i] = matrix[quator[1].first + i][quator[1].second];
    //             matrix[quator[1].first + i][quator[1].second] = temp;
    //         }

    //         help({{quator[0].first + 1, quator[0].second + 1},
    //               {quator[1].first + 1, quator[1].second - 1},
    //               {quator[2].first - 1, quator[2].second - 1},
    //               {quator[3].first - 1, quator[3].second + 1}},
    //              n - 2);
    //     };

    //     help({{0, 0}, {0, n}, {n, n}, {n, 0}}, n);
    // }
};
// @lc code=end
