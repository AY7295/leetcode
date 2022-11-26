/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        int fromBegin = 1;
        int fromLast = 1;
        vector<int> res(n, 1);

        for (int i = 0; i < n; i++)
        {
            res[i] *= fromBegin;
            fromBegin *= nums[i];
            res[n - 1 - i] *= fromLast;
            fromLast *= nums[n - 1 - i];
        }
        return res;
    }

    // descp mine
    //  vector<int> productExceptSelf(vector<int> &nums)
    //  {
    //      long long int total = 1;
    //      int count0 = 0, index0 = -1, n = nums.size();
    //      vector<int> ans(n, 0);
    //      for (int i = 0; i < n; i++)
    //      {
    //          if (nums[i] == 0)
    //          {
    //              count0++;
    //              if (count0 > 1)
    //              {
    //                  return ans;
    //              }
    //              index0 = i;
    //              continue;
    //          }
    //          total *= nums[i];
    //      }
    //      if (count0 != 0)
    //      {
    //          ans[index0] = total;
    //          return ans;
    //      }
    //      for (int i = 0; i < n; i++)
    //      {
    //          ans[i] = total / nums[i];
    //      }

    //     return ans;
    // }
};
// @lc code=end
