/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

public:
    // descp official
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

    // descp mine
    // void rotate(vector<int> &nums, int k)
    // {
    //     int len = nums.size();
    //     k = k % len;
    //     vector<int> temp;
    //     temp.reserve(k);
    //     for (int i = k; i > 0; i--)
    //     {
    //         temp.push_back(nums[len - i]);
    //     }
    //     for (int i = len - 1; i >= k; i--)
    //     {
    //         nums[i] = nums[i - k];
    //     }
    //     for (int i = 0; i < k; i++)
    //     {
    //         nums[i] = temp[i];
    //     }
    // }
};
// @lc code=end
