/*
 * @lc app=leetcode.cn id=1764 lang=cpp
 *
 * [1764] 通过连接另一个数组的子数组得到一个数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    bool canChoose(vector<vector<int>> &groups, vector<int> &nums)
    {
        int idx = 0, i = 0;
        while (idx < groups.size() and i < nums.size())
        {
            if (groups[idx][0] == nums[i])
            {
                int j = 0, k = i;
                for (; k < nums.size() and j < groups[idx].size(); k++)
                {
                    if (groups[idx][j] == nums[k])
                        j++;
                    else
                        break;
                }
                if (j == groups[idx].size())
                    idx++, i = k;
                else
                    i++;
            }
            else
                i++;
        }
        return idx == groups.size();
    }
};
// @lc code=end
