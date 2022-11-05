/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    vector<vector<int>> res;
    vector<int> cur;
    void help(int n, int k, int start)
    {
        if (k == 0)
        {
            res.push_back(cur);
            return;
        }
        if (start + k > n + 1)
        {
            return;
        }
        for (int i = start; i <= n; i++)
        {
            cur.emplace_back(i);
            help(n, k - 1, i + 1);
            cur.pop_back();
        }
    }

public:
    // descp official
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        // 初始化
        // 将 temp 中 [0, k - 1] 每个位置 i 设置为 i + 1，即 [0, k - 1] 存 [1, k]
        // 末尾加一位 n + 1 作为哨兵
        for (int i = 1; i <= k; ++i)
        {
            temp.push_back(i);
        }
        temp.push_back(n + 1);

        int j = 0;
        while (j < k)
        {
            ans.emplace_back(temp.begin(), temp.begin() + k);
            j = 0;
            // 寻找第一个 temp[j] + 1 != temp[j + 1] 的位置 t
            // 我们需要把 [0, t - 1] 区间内的每个位置重置成 [1, t]
            while (j < k && temp[j] + 1 == temp[j + 1])
            {
                temp[j] = j + 1;
                ++j;
            }
            // j 是第一个 temp[j] + 1 != temp[j + 1] 的位置
            ++temp[j];
        }
        return ans;
    }

    // descp most voted solution
    // vector<vector<int>>
    // combine(int n, int k)
    // {
    //     help(n, k, 1);

    //     return res;
    // }
};
// @lc code=end
