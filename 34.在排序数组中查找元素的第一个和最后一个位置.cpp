/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
        {
            return {-1, -1};
        }
        int l = 0, r = n - 1, mid;
        while (l <= r)
        {
            mid = (r - l) / 2 + l;
            if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                l = r = mid;
                while (--l >= 0 && nums[l] == target)
                    ;
                while (++r < n && nums[r] == target)
                    ;
                break;
            }
        }

        return r <= l ? vector<int>{-1, -1} : vector<int>{l + 1, r - 1};
    }

    // descp most voted solution
    // vector<int> searchRange(vector<int> &nums, int target)
    // {
    //     int idx1 = lower_bound(nums, target);
    //     int idx2 = lower_bound(nums, target + 1) - 1;
    //     if (idx1 < nums.size() && nums[idx1] == target)
    //         return {idx1, idx2};
    //     else
    //         return {-1, -1};
    // }

    // int lower_bound(vector<int> &nums, int target)
    // {
    //     int l = 0, r = nums.size() - 1;
    //     while (l <= r)
    //     {
    //         int mid = (r - l) / 2 + l;
    //         if (nums[mid] < target)
    //             l = mid + 1;
    //         else
    //             r = mid - 1;
    //     }
    //     return l;
    // }
};
// @lc code=end
