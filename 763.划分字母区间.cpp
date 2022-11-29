/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    vector<int> partitionLabels(string s)
    {
        int M[256]{0};
        vector<int> out;

        for (int i{0}; i < size(s); ++i)
            M[s[i]] = i;

        for (int i{0}, j{-1}, MM{0}; i < size(s); ++i)
            if ((MM = max(MM, M[s[i]])) == i)
                out.push_back(i - j), j = i;

        return out;
    }
};
// @lc code=end
