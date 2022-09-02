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
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0)
        {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }

    // descp mine
    //  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    //  {

    //     if (!m || !n)
    //     {
    //         nums1 = m == 0 ? nums2 : nums1;
    //         return;
    //     }
    //     nums1.reserve(m + n + n);

    //     int i, k;

    //     /*
    //             for (i = 0, k = 0; i < m + n && k < n; i++)
    //             {
    //                 if (nums2[k] < nums1[i])
    //                 {
    //                     nums1.insert(nums1.begin() + i, nums2[k]);
    //                     k++;
    //                 }
    //                 if ((nums1.size() - i) == n && nums1[i] == 0)
    //                 {
    //                     nums1.insert(nums1.begin() + i, nums2[k]);
    //                     k++;
    //                 }
    //             }
    //      */

    //     for (k = 0; k < n; k++)
    //     {
    //         for (i = 0; i < m + n; i++)
    //         {
    //             if (nums2[k] < nums1[i])
    //             {
    //                 nums1.insert(nums1.begin() + i, nums2[k]);
    //                 break;
    //             }
    //             if ((nums1.size() - i) == n && nums1[i] == 0)
    //             {
    //                 nums1.insert(nums1.begin() + i, nums2[k]);
    //                 break;
    //             }
    //         }
    //     }

    //     nums1.resize(m + n);
    // }
};
// @lc code=end
