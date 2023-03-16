/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp official
    string reverseWords(string s)
    {
        // 反转整个字符串
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start)
        {
            if (s[start] != ' ')
            {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (idx != 0)
                    s[idx++] = ' ';

                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ')
                    s[idx++] = s[end++];

                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }

    // descp mine
    // string reverseWords(string s)
    // {
    //     int i, l;
    //     reverse(s.begin(), s.end());
    //     s = ' ' + s + ' ';
    //     for (i = 0; i < s.size(); i++)
    //     {
    //         if (s[i] == ' ')
    //         {
    //             if (i > 0 && s[i - 1] == ' ')
    //             {
    //                 s.erase(s.begin() + i - 1, s.begin() + i);
    //                 i--;
    //                 continue;
    //             }
    //         }
    //         else
    //         {
    //             l = i;
    //             while (i < s.size() && s[i] != ' ')
    //                 i++;
    //             reverse(s.begin() + l, s.begin() + i);
    //         }
    //     }
    //     s.erase(s.end() - 1, s.end());
    //     s.erase(s.begin(), s.begin() + 1);
    //     return s;
    // }
};
// @lc code=end
