/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp official
    // 逆向遍历就可以直接跳过被回退的字符
    bool backspaceCompare(string S, string T)
    {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0)
        {
            while (i >= 0)
            {
                if (S[i] == '#')
                {
                    skipS++, i--;
                }
                else if (skipS > 0)
                {
                    skipS--, i--;
                }
                else
                {
                    break;
                }
            }
            while (j >= 0)
            {
                if (T[j] == '#')
                {
                    skipT++, j--;
                }
                else if (skipT > 0)
                {
                    skipT--, j--;
                }
                else
                {
                    break;
                }
            }
            if (i >= 0 && j >= 0)
            {
                if (S[i] != T[j])
                {
                    return false;
                }
            }
            else
            {
                if (i >= 0 || j >= 0)
                {
                    return false;
                }
            }
            i--, j--;
        }
        return true;
    }
};
// @lc code=end
