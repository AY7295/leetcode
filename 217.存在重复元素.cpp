/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include <algorithm>
#include <set>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    bool containsDuplicate(vector<int> &nums)
    {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
    // descp mine
    //  bool containsDuplicate(vector<int> &nums)
    //  {
    //      unordered_map<int, int> m;
    //      for (auto &&i : nums)
    //      {
    //          m[i]++;
    //          if (m[i] >= 2)
    //              return true;
    //      }
    //      return false;
    //  }
};
// @lc code=end
