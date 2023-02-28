/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        unordered_map<int, int> m;
        vector<int> vec = nums;
        int n = nums.size();

        // Sort vec in ascending order
        // T.C = O(nlogn)
        sort(vec.begin(), vec.end());

        // Put the values in hash-map according to their values corresponding to their places in nums
        // T.C = O(n)
        for (int i = n - 1; i >= 0; i--)
        {
            m[vec[i]] = i;
        }

        // Saving the result again in nums, b'cos space complexity matters XD
        // T.C = O(n)
        for (int i = 0; i < n; i++)
        {
            nums[i] = m[nums[i]];
        }

        return nums;
    }

    // descp mine
    //  vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    //  {
    //      vector<int> ans(nums.size(), 0);
    //      int count = 0, i, j;
    //      for (i = 0; i < nums.size(); i++, count = 0)
    //      {
    //          for (j = 0; j < nums.size(); j++)
    //          {
    //              if (nums[i] > nums[j])
    //                  count++;
    //          }
    //          ans[i] = count;
    //      }
    //      return ans;
    //  }
};
// @lc code=end
