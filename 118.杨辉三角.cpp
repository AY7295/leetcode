/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i)
        {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j)
            {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }

    // descp mine
    // vector<vector<int>> generate(int numRows)
    // {
    //     auto res = vector<vector<int>>{};
    //     res.reserve(numRows);
    //     res.push_back(vector<int>{1});

    //     for (int i = 1; i < numRows; i++)
    //     {
    //         auto temp = vector<int>{1};
    //         temp.reserve(1 + i);

    //         for (int k = 1; k < i; k++)
    //         {
    //             temp.push_back(res[i - 1][k - 1] + res[i - 1][k]);
    //         }

    //         temp.push_back(1);
    //         res.push_back(temp);
    //     }
    //     return res;
    // }
};
// @lc code=end
