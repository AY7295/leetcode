/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    // void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    // {
    //     int i = m - 1, j = n - 1, tar = m + n - 1;
    //     while (j >= 0)
    //     {
    //         nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    //     }
    // }

    // descp mine
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = m - 1, j = n - 1, k = m + n - 1; k >= 0; k--)
        {
            int a = i >= 0 ? nums1[i] : INT_MIN;
            int b = j >= 0 ? nums2[j] : INT_MIN;

            if (a > b)
            {
                nums1[k] = a;
                i--;
            }
            else
            {
                nums1[k] = b;
                j--;
            }
        }
    }
};
// @lc code=end
