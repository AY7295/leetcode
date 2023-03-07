/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 1;
        while (i < n && j < n)
        {
            if (nums[i] % 2 == 0)
            {
                i += 2;
            }
            else if (nums[j] % 2 == 1)
            {
                j += 2;
            }
            else
            {
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }

    // descp mine
    // vector<int> sortArrayByParityII(vector<int> &nums)
    // {
    //     int temp, n = nums.size(), e, o;
    //     queue<int> odd, enven;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (i % 2 == 0)
    //         {
    //             if (nums[i] % 2 != 0)
    //                 enven.emplace(i);
    //         }
    //         else
    //         {
    //             if (nums[i] % 2 == 0)
    //                 odd.emplace(i);
    //         }

    //         if (!odd.empty() && !enven.empty())
    //         {
    //             o = odd.front();
    //             odd.pop();
    //             e = enven.front();
    //             enven.pop();
    //             temp = nums[o];
    //             nums[o] = nums[e];
    //             nums[e] = temp;
    //         }
    //     }
    //     return nums;
    // }
};
// @lc code=end
