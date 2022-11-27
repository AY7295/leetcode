/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */
#include <algorithm>
#include <stack>
#include <cmath>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    string addStrings(string num1, string num2)
    {
        int idx1 = num1.size() - 1, idx2 = num2.size() - 1;
        int carry(0);
        string ans;

        while (idx1 > -1 || idx2 > -1 || carry)
        {
            int d1 = (idx1 >= 0) ? num1[idx1] - '0' : 0;
            int d2 = (idx2 >= 0) ? num2[idx2] - '0' : 0;
            int sum = d1 + d2 + carry;
            carry = sum / 10;
            ans.insert(ans.begin(), sum % 10 + '0');
            idx1--;
            idx2--;
        }
        return ans;
    }

    // descp mine
    //  string addStrings(string num1, string num2)
    //  {
    //      int len1 = num1.size(), len2 = num2.size(), temp = 0;
    //      int a, b, c;
    //      string ans = "";
    //      for (int i = 0; i < len1 || i < len2 || temp != 0; i++)
    //      {
    //          if (i < len1)
    //          {
    //              a = num1[len1 - i - 1] - 48;
    //          }
    //          else
    //          {
    //              a = 0;
    //          }
    //          if (i < len2)
    //          {
    //              b = num2[len2 - i - 1] - 48;
    //          }
    //          else
    //          {
    //              b = 0;
    //          }
    //          c = a + b + temp;
    //          ans = ans + char(c % 10 + 48);
    //          temp = c / 10;
    //      }

    //     for (a = 0, b = ans.size() - 1; a < b; a++, b--)
    //     {
    //         c = ans[a];
    //         ans[a] = ans[b];
    //         ans[b] = c;
    //     }

    //     return ans;
    // }
};
// @lc code=end
