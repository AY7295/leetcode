/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp double pointer
    // vector<int> sortedSquares(vector<int> &A)
    // {
    //     int k = A.size() - 1;
    //     vector<int> result(A.size(), 0);
    //     for (int i = 0, j = A.size() - 1; i <= j;)
    //     { // 注意这里要i <= j，因为最后要处理两个元素
    //         if (A[i] * A[i] < A[j] * A[j])
    //         {
    //             result[k--] = A[j] * A[j];
    //             j--;
    //         }
    //         else
    //         {
    //             result[k--] = A[i] * A[i];
    //             i++;
    //         }
    //     }
    //     return result;
    // }

    // descp mine
    vector<int> sortedSquares(vector<int> &nums)
    {
        int len = nums.size(), l = 0, r = len - 1;
        vector<int> res(len);
        for (int n = len - 1; l <= r; n--)
        {
            if (nums[r] * nums[r] > nums[l] * nums[l])
            {
                res[n] = nums[r] * nums[r];
                r--;
            }
            else
            {
                res[n] = nums[l] * nums[l];
                l++;
            }
        }
        return res;
    }
};
// @lc code=end
