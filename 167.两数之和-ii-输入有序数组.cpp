/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0, right = numbers.size() - 1, sum;
        while (left < right)
        {
            sum = numbers[left] + numbers[right];
            if (sum > target)
                right--;
            else if (sum < target)
                left++;
            else
                return {left + 1, right + 1};
        }
        return {};
    }
};
// @lc code=end
