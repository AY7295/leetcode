/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    vector<string> findRepeatedDnaSequences(string s)
    {

        unordered_map<size_t, int> MP;
        hash<string> hash_fn;
        vector<string> ret;

        for (int i = 0; i < int(s.size()) - 9; ++i)
            if (MP[hash_fn(s.substr(i, 10))]++ == 1)
                ret.push_back(s.substr(i, 10));

        return ret;
    }

    // descp mine
    // vector<string> findRepeatedDnaSequences(string s)
    // {
    //     int n = s.size();
    //     if (n < 10)
    //     {
    //         return {};
    //     }

    //     unordered_map<string, int> mp;

    //     string temp = "";
    //     for (int i = 0; i < 10; i++)
    //     {
    //         temp += s[i];
    //     }
    //     mp[temp]++;

    //     for (int i = 10; i < n; i++)
    //     {
    //         temp.erase(temp.begin());
    //         temp += s[i];
    //         mp[temp]++;
    //     }

    //     vector<string> ret;
    //     for (auto &&i : mp)
    //     {
    //         if (i.second > 1)
    //         {
    //             ret.emplace_back(i.first);
    //         }
    //     }

    //     return ret;
    // }
};
// @lc code=end
