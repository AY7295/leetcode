/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    bool isIsomorphic(string s, string t)
    {
        char map_s[128] = {0};
        char map_t[128] = {0};
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            if (map_s[s[i]] != map_t[t[i]])
                return false;
            map_s[s[i]] = i + 1;
            map_t[t[i]] = i + 1;
        }
        return true;
    }

    // descp mine
    bool isIsomorphic(string s, string t)
    {
        unordered_map<int, int> mps, mpt;
        int len = s.size();
        for (size_t i = 0; i < len; i++)
        {
            // s -> t
            if (mps.find(s[i]) == mps.end())
            {
                mps[s[i]] = i;
            }
            else if (t[i] != t[mps[s[i]]])
            {
                return false;
            }

            // t -> s
            if (mpt.find(t[i]) == mpt.end())
            {
                mpt[t[i]] = i;
            }
            else if (s[i] != s[mpt[t[i]]])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
