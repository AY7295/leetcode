/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 *
 * [1000] 合并石头的最低成本
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp 灵茶山艾府
    int mergeStones(vector<int> &stones, int k)
    {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) // 无法合并成一堆
            return -1;

        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; i++)
            s[i + 1] = s[i] + stones[i]; // 前缀和

        int f[n][n];
        for (int i = n - 1; i >= 0; --i)
        {
            f[i][i] = 0;
            for (int j = i + 1; j < n; ++j)
            {
                f[i][j] = INT_MAX;
                for (int m = i; m < j; m += k - 1)
                    f[i][j] = min(f[i][j], f[i][m] + f[m + 1][j]);
                if ((j - i) % (k - 1) == 0) // 可以合并成一堆
                    f[i][j] += s[j + 1] - s[i];
            }
        }
        return f[0][n - 1];
    }
};
// @lc code=end
