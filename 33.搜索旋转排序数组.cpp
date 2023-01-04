/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int search(vector<int> &nums, int target)
    {
        int lo = 0, hi = int(nums.size()) - 1;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }

    // descp mine
    // int search(vector<int> &nums, int target)
    // {
    //     int n = nums.size();
    //     if (n == 1)
    //     {
    //         return target == nums[0] ? 0 : -1;
    //     }

    //     int pre = nums[0];
    //     if (target > pre)
    //     {
    //         for (int i = 1; i < n; i++)
    //         {
    //             if (nums[i] < pre)
    //             {
    //                 return -1;
    //             }
    //             if (nums[i] == target)
    //             {
    //                 return i;
    //             }
    //             pre = nums[i];
    //         }
    //     }
    //     else if (target == pre)
    //     {
    //         return 0;
    //     }
    //     else
    //     {
    //         for (int i = n - 1; i >= 0; i--)
    //         {
    //             if (nums[i] > pre)
    //             {
    //                 return -1;
    //             }
    //             if (nums[i] == target)
    //             {
    //                 return i;
    //             }
    //             pre = nums[i];
    //         }
    //     }
    //     return -1;
    // }
};
// @lc code=end
