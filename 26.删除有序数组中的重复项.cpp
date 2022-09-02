/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
// #include <algorithm>
#include <vector>

// @lc code=start
class Solution
{
public:
    // descp most voted solution
    // tip 只要前 i 个位置，存的是正确的元素就行
    int removeDuplicates(std::vector<int> &nums)
    {
        int i = !nums.empty();
        for (int n : nums)
            if (n > nums[i - 1])
                nums[i++] = n;
        return i;
    }
};
// @lc code=end
