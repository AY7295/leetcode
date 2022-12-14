/*
 * @lc app=leetcode.cn id=1945 lang=cpp
 *
 * [1945] 字符串转化后的各位数字之和
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int getLucky(string s, int k)
    {
        // 12552031545
        // 33
        string num = "";
        int ans = 0;
        for (auto &&i : s)
        {
            num += to_string(i - 'a' + 1);
        }
        for (int i = 0; i < k; i++)
        {
            ans = 0;
            for (auto &&c : num)
            {
                ans += c - '0';
            }
            if (ans < 10)
            {
                return ans;
            }
            num = to_string(ans);
        }
        return ans;
    }
};
// @lc code=end
