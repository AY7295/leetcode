/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        for (int i = 2; i < n; i++)
        {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[n - 1], cost[n - 2]);
    }

    // descp mine
    //  int minCostClimbingStairs(vector<int> &cost)
    //  {
    //      int len = cost.size();
    //      vector<int> temp(len + 1, 0);
    //      for (size_t i = 2; i < len + 1; i++)
    //      {
    //          if ((temp[i - 1] + cost[i - 1]) > (temp[i - 2] + cost[i - 2]))
    //          {
    //              temp[i] = temp[i - 2] + cost[i - 2];
    //          }
    //          else
    //          {
    //              temp[i] = temp[i - 1] + cost[i - 1];
    //          }
    //      }
    //      return temp[len];
    //  }
};
// @lc code=end
