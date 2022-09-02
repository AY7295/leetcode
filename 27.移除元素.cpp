/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int removeElement(vector<int> &nums, int val)
    {
        int length = nums.size(), index = 0;
        while (index < length)
        {
            if (nums[index] == val)
            {
                nums[index] = nums[length - 1]; // tip 题目有规定顺序是可以变的
                length--;
            }

            else
                ++index;
        }
        return length;
    }

    // descp mine
    //  int removeElement(vector<int> &nums, int val)
    //  {
    //      int i = 0;
    //      for (int n : nums)
    //      {
    //          if (n != val)
    //          {
    //              nums[i] = n;
    //              i++;
    //          }
    //      }
    //      return i;
    //  }
};
// @lc code=end
