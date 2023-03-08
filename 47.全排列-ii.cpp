/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    void recursion(vector<int> num, int i, int j, vector<vector<int>> &res)
    {
        if (i == j - 1)
        {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++)
        {
            if (i != k && num[i] == num[k])
                continue;
            swap(num[i], num[k]);
            recursion(num, i + 1, j, res);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &num)
    {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        recursion(num, 0, num.size(), res);
        return res;
    }

    // descp 代码随想录
    vector<vector<int>> permuteUnique(vector<int> &num)
    {
        int n = num.size();
        sort(num.begin(), num.end());
        vector<vector<int>> ans;
        vector<bool> used(n, false);
        vector<int> path;
        path.reserve(n);

        function<void(vector<bool> &)> help = [&](vector<bool> &used)
        {
            if (path.size() == n)
            {
                ans.emplace_back(path);
            }
            for (int i = 0; i < n; i++)
            {
                if (i > 0 && num[i] == num[i - 1] && used[i - 1] == false)
                {
                    continue;
                }
                if (used[i] == false)
                {
                    used[i] = true;
                    path.emplace_back(num[i]);
                    help(used);
                    used[i] = false;
                    path.pop_back();
                }
            }
        };
        help(used);

        return ans;
    }
};
// @lc code=end
