/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include <unordered_map>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> m;
        for (auto x : magazine)
        {
            m[x]++;
        }
        for (auto x : ransomNote)
        {
            if (m[x] == 0)
                return false;

            m[x]--;
        }
        return true;
    }

    // descp mine
    //  bool canConstruct(string s1, string s2)
    //  {
    //      if (s1.size() > s2.size())
    //          return false;

    //     vector<int> v(26, 0);
    //     for (auto &&i : s1)
    //     {
    //         v[i - 'a']++;
    //     }
    //     for (auto &&i : s2)
    //     {
    //         v[i - 'a']--;
    //     }
    //     for (auto &&i : v)
    //     {
    //         if (i > 0)
    //             return false;
    //     }
    //     return true;
    // }
};
// @lc code=end
