/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    vector<int> getRow(int rowIndex)
    {
        vector<int> ret{1}, cur{1};
        for (int i = 1; i <= rowIndex; i++)
        {
            ret.push_back(1);
            for (int j = 1; j < i; j++)
            {
                ret[j] = cur[j] + cur[j - 1];
            }
            cur = ret;
        }
        return ret;
    }

    // descp mine
    // vector<int> getRow(int rowIndex)
    // {
    //     auto res = vector<int>{1};
    //     auto temp = vector<int>{};
    //     for (int i = 1; i < rowIndex + 1; i++)
    //     {
    //         temp.reserve(i + 1);
    //         temp.push_back(1);
    //         for (int k = 1; k < i; k++)
    //         {
    //             temp.push_back(res[k - 1] + res[k]);
    //         }
    //         temp.push_back(1);
    //         res = temp;
    //         temp.clear();
    //     }
    //     return res;
    // }
};
// @lc code=end
