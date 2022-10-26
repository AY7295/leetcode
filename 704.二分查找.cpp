/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int search(vector<int> &nums, int target)
    {
        vector<int>::iterator it2 = nums.begin();
        vector<int>::iterator it = std::lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || *it != target)
            return -1;
        else
            return (it - it2);
    }
    // descp mine
    // int search(vector<int> &nums, int target)
    // {
    //     int left = 0, right = nums.size() - 1, mid;
    //     while (left <= right)
    //     {
    //         mid = (left + right) / 2;
    //         if (nums[mid] == target)
    //             return mid;
    //         else if (nums[mid] < target)
    //             left = mid + 1;
    //         else
    //             right = mid - 1;
    //     }
    //     return -1;
    // }
};
// @lc code=end
