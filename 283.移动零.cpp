/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    void moveZeroes(vector<int> &nums)
    {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[j++] = nums[i];
            }
        }
        for (; j < nums.size(); j++)
        {
            nums[j] = 0;
        }
    }

    // descp  mine
    // void moveZeroes(vector<int> &nums)
    // {
    //     int len = nums.size();
    //     for (int i = 0; i < len;)
    //     {
    //         if (0 == nums[i])
    //         {
    //             for (int k = i; k < len - 1; k++)
    //             {
    //                 nums[k] = nums[k + 1];
    //             }
    //             nums[len - 1] = 0;
    //             len--;
    //         }
    //         else
    //             i++;
    //     }
    // }
};
// @lc code=end
