/*
 * @lc app=leetcode.cn id=1785 lang=cpp
 *
 * [1785] 构成特定和需要添加的最少元素
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    int minElements(vector<int> &nums, int limit, int goal)
    {
        long long sum = 0;
        for (auto &&i : nums)
        {
            sum += i;
        }

        long long sub = sum - goal < 0 ? goal - sum : sum - goal;

        int temp = sub % limit == 0 ? 0 : 1;

        return sub / limit + temp;
    }
};
// @lc code=end
