/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    bool validMountainArray(vector<int> &arr)
    {
        if (arr.size() < 3)
        {
            return false;
        }
        int n = arr.size() - 1;
        int l = 0, r = n;

        while (l < n && arr[l] < arr[l + 1])
            l++;
        while (r > 0 && arr[r] < arr[r - 1])
            r--;

        return r == l && r != n && l != 0;
    }
};
// @lc code=end
