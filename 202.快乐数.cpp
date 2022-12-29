/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include <functional>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    bool isHappy(int n)
    {
        int slow = n, fast = n;
        function<int(int)> solve = [&](int n)
        {
            int sum = 0;
            while (n > 0)
            {
                int r = n % 10;
                sum += r * r;
                n /= 10;
            }
            return sum;
        };

        do
        {
            slow = solve(slow);
            fast = solve(solve(fast));
            if (fast == 1)
                return 1;
        } while (slow != fast);
        return 0;
    }
};
// @lc code=end
