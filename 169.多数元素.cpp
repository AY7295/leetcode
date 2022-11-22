/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include <algorithm>
#include <time.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size(), candidate, counter;
        srand(unsigned(time(nullptr)));
        while (true)
        {
            candidate = nums[rand() % n], counter = 0;
            for (int num : nums)
            {
                if (num == candidate)
                {
                    counter++;
                }
            }
            if (counter > n / 2)
            {
                break;
            }
        }
        return candidate;
    }

    // descp mine
    // int majorityElement(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     unordered_map<int, int> mp(n / 2);
    //     for (auto &&i : nums)
    //     {
    //         mp[i]++;
    //         if (mp[i] * 2 >= n)
    //         {
    //             return i;
    //         }
    //     }
    //     return 0;
    // }
};
// @lc code=end
