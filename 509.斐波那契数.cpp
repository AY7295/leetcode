/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution F(n) = ((1 + sqrt(5)) ^ n - (1 - sqrt(5)) ^ n) / 2 ^ n * sqrt(5)
    int fib(int N)
    {
        float z = sqrt(5);
        long long int t = (pow(2, N) * z);
        long long int a = (pow(1 + z, N));
        long long int b = (pow(1 - z, N));
        return (a - b) / t;
    }

    // descp mine
    int fib(int n)
    {
        if (n == 0)
            return 0;
        int temp = 1, ans = 1, t;
        for (int i = 2; i < n; i++)
        {
            temp += ans;
            t = temp;
            temp = ans;
            ans = t;
        }
        return ans;
    }
};
// @lc code=end
