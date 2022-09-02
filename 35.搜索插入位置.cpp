/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int searchInsert(vector<int> &nums, int target)
    {
        auto first = nums.cbegin(), last = nums.cend();
        while (first < last)
        {

            auto mid = first + ((last - first) >> 1);
            if (*mid < target)
            {
                first = mid + 1;
            }
            else
            {
                last = mid;
            }
        }
        return first - nums.begin();
    }

    // descp mine
    // int searchInsert(vector<int> &nums, int target)
    // {
    //     int len = nums.size();
    //     int i;

    //     for (i = 0; i < len; i++)
    //     {
    //         if (nums[i] >= target)
    //         {
    //             return i;
    //         }
    //     }

    //     return i;
    // }
};
// @lc code=end
