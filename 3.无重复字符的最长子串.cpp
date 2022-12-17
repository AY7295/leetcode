/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int lengthOfLongestSubstring(string s)
    {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++)
        {
            if (dict[s[i]] > start)
            {
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }

    // descp hash-map
    // int lengthOfLongestSubstring(string s)
    // {
    //     // s[start,end) 前面包含 后面不包含
    //     int start(0), end(0), length(0), result(0);
    //     int sSize = int(s.size());
    //     unordered_map<char, int> hash;
    //     while (end < sSize)
    //     {
    //         char tmpChar = s[end];
    //         //仅当s[start,end) 中存在s[end]时更新start
    //         if (hash.find(tmpChar) != hash.end() && hash[tmpChar] >= start)
    //         {
    //             start = hash[tmpChar] + 1;
    //             length = end - start;
    //         }
    //         hash[tmpChar] = end;

    //         end++;
    //         length++;
    //         result = max(result, length);
    //     }
    //     return result;
    // }
};
// @lc code=end
