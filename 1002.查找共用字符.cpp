/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp mine
    vector<string> commonChars(vector<string> &words)
    {
        vector<int> appear(26, 0);
        vector<int> current(26, 0);
        int n = words.size();
        for (auto &&ch : words[0])
        {
            appear[ch - 'a']++;
        }

        for (int i = 1; i < n; i++)
        {
            for (auto &&ch : words[i])
            {
                current[ch - 'a']++;
            }
            for (int k = 0; k < 26; k++)
            {
                appear[k] = min(appear[k], current[k]);
                current[k] = 0;
            }
        }

        vector<string> ans;
        string temp;
        for (int i = 0; i < 26; i++)
        {
            while (appear[i]--)
            {
                temp = i + 'a';
                ans.emplace_back(temp);
            }
        }

        return ans;
    }
};
// @lc code=end
