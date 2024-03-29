/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp official
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        unordered_map<int, int> cnt;

        int left = 0, ans = 0;
        for (int right = 0; right < n; ++right)
        {
            ++cnt[fruits[right]];
            while (cnt.size() > 2)
            {
                auto it = cnt.find(fruits[left]);
                --it->second;
                if (it->second == 0)
                {
                    cnt.erase(it);
                }
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end
