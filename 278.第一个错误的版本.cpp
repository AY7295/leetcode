/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */
bool isBadVersion(int version);

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    // descp mine
    int firstBadVersion(int n)
    {
        int left = 1, right = n, mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (isBadVersion(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
