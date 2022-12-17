/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size(), i = 0, j = 0, l = 0, r = 0;
        for (int x = 0; x <= (m + n) / 2; x++)
        {
            l = r;
            r = (i < m && (j >= n || nums1[i] < nums2[j])) ? nums1[i++] : nums2[j++];
        }
        return (m + n) & 1 ? r : (l + r) / 2.0;
    }
};
// @lc code=end
