/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int pivotIndex(vector<int> &nums)
    {
        long long int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        long long int lsum = 0;
        long long int rsum = sum;

        for (int i = 0; i < nums.size(); i++)
        {
            rsum = rsum - nums[i];

            if (lsum == rsum)
            {
                return i;
            }

            lsum += nums[i];
        }
        return -1;
    }

    // descp mine
    int pivotIndex(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return 0;
        }

        auto l = nums, r = nums;
        int len = nums.size() - 1;
        for (int i = 1, j = len - 1; i <= len; i++, j--)
        {
            l[i] += l[i - 1];
            r[j] += r[j + 1];
        }

        if (r[1] == 0)
        {
            return 0;
        }

        for (int i = 0; i <= len - 2; i++)
        {
            if (l[i] == r[i + 2])
            {
                return i + 1;
            }
        }

        if (l[len - 1] == 0)
        {
            return len;
        }

        return -1;
    }
};
// @lc code=end
