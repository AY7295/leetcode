/*
 * @lc app=leetcode.cn id=1832 lang=cpp
 *
 * [1832] 判断句子是否为全字母句
 */
#include <unordered_map>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp official
    bool checkIfPangram(string sentence)
    {
        int state = 0;
        for (auto c : sentence)
        {
            state |= 1 << (c - 'a');
        }
        return state == (1 << 26) - 1;
    }

    // descp mine
    bool checkIfPangram(string sentence)
    {
        if (sentence.size() < 26)
        {
            return false;
        }

        unordered_map<int, int> mp;
        for (auto &&i : sentence)
        {
            mp[i]++;
            if (mp.size() == 26)
            {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end
