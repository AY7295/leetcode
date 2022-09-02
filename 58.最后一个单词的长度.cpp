/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int lengthOfLastWord(string s)
    {
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ')
            tail--;
        while (tail >= 0 && s[tail] != ' ')
        {
            len++;
            tail--;
        }
        return len;
    }

    // descp mine
    // int lengthOfLastWord(string s)
    // {
    //     int start = s.length() - 1;
    //     while (start >= 0 && s[start] == ' ')
    //         start--;

    //     int end = start;
    //     while (end >= 0 && s[end] != ' ')
    //         end--;

    //     return start - end;
    // }
};
// @lc code=end
