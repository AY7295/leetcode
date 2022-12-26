/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    string getHint(string secret, string guess)
    {
        unordered_map<char, int> s_map;
        unordered_map<char, int> g_map;
        int n = secret.size();
        int A = 0, B = 0;
        for (int i = 0; i < n; i++)
        {
            char s = secret[i], g = guess[i];
            if (s == g)
                A++;
            else
            {
                (s_map[g] > 0) ? s_map[g]--, B++ : g_map[g]++;
                (g_map[s] > 0) ? g_map[s]--, B++ : s_map[s]++;
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }

    // descp mine
    // string getHint(string secret, string guess)
    // {
    //     int n = secret.size(), a = 0, b = 0;
    //     unordered_map<int, bool> s;
    //     unordered_map<char, short> t;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (guess[i] == secret[i])
    //         {
    //             a++;
    //         }
    //         else
    //         {
    //             s[i] = true;
    //             t[secret[i]]++;
    //         }
    //     }
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (s[i] == true && t[guess[i]] > 0)
    //         {
    //             t[guess[i]]--;
    //             b++;
    //         }
    //     }

    //     return to_string(a) + "A" + to_string(b) + "B";
    // }
};
// @lc code=end
