/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 *
 * [1017] 负二进制转换
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    string baseNeg2(int n)
    {
        string ans = "";
        if (n == 0)
            ans += ('0');
        int r;
        while (n)
        {
            r = n % (-2);
            if (r < 0)
            {
                r += 2;
                n = n / (-2) + 1;
            }
            else
                n /= (-2);
            ans += (r + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
