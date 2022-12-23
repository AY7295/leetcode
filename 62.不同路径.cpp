/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    // int uniquePaths(int m, int n)
    // {
    //     vector<int> cur(n, 1);
    //     for (int i = 1; i < m; i++)
    //     {
    //         for (int j = 1; j < n; j++)
    //         {
    //             cur[j] += cur[j - 1];
    //         }
    //     }
    //     return cur[n - 1];
    // }

    // descp mine
    int uniquePaths(int m, int n)
    {
        if (m > n)
        {
            return uniquePaths(n, m);
        }
        long long ans = 1;
        for (int x = n, y = 1; y < m; x++, y++)
        {
            ans = ans * x / y;
        }
        return ans;
    }
};
// @lc code=end
