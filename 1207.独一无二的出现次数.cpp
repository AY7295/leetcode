/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> count;
        for (auto &&i : arr)
        {
            count[i]++;
        }

        unordered_set<int> us;
        for (auto &&i : count)
        {
            if (us.find(i.second) == us.end())
            {
                us.insert(i.second);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
