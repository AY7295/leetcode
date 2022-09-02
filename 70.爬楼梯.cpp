/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int climbStairs(int n)
    {
        int StepOne = 1;
        int StepTwo = 0;
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            ret = StepOne + StepTwo;
            StepTwo = StepOne;
            StepOne = ret;
        }
        return ret;
    }

    // descp mine
    //  int climbStairs(int n)
    //  {
    //      int dp[n + 1];
    //      dp[0] = 1;
    //      dp[1] = 1;
    //      for (int i = 2; i < n + 1; i++)
    //      {
    //          dp[i] = dp[i - 2] + dp[i - 1];
    //      }
    //      return dp[n];
    //  }

    // tip 递归超时
    // int climbStairs(int n)
    // {
    //     if (n == 1 || n == 0)
    //     {
    //         return 1;
    //     }
    //     return climbStairs(n - 1) + climbStairs(n - 2);
    // }
};
// @lc code=end
