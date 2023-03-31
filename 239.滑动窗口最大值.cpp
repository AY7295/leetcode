/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
    deque<int> de;
    void pop(int v)
    {
        if (!de.empty() && de.front() == v)
        {
            de.pop_front();
        }
    }
    void push(int v)
    {
        while (!de.empty() && de.back() < v)
        {
            de.pop_back();
        }
        de.emplace_back(v);
    }
    int getMax()
    {
        return de.front();
    }

public:
    // descp 代码随想录
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size(), i;
        vector<int> ans;
        ans.reserve(n - k + 1);
        for (i = 0; i < k; i++)
        {
            push(nums[i]);
        }
        ans.emplace_back(getMax());
        for (i = k; i < n; i++)
        {
            push(nums[i]);
            pop(nums[i - k]);
            ans.emplace_back(getMax());
        }
        return ans;
    }

    // descp most vited solution
    // vector<int> maxSlidingWindow(vector<int> &nums, int k)
    // {
    //     if (k == 1)
    //         return nums;
    //     vector<int> result;
    //     deque<int> w;
    //     for (int i = 0, n = (int)nums.size(); i < n; i++)
    //     {
    //         while (!w.empty() && w.front() <= i - k)
    //             w.pop_front();
    //         while (!w.empty() && nums[w.back()] <= nums[i])
    //             w.pop_back();
    //         w.push_back(i);
    //         if (i >= k - 1)
    //             result.push_back(nums[w.front()]);
    //     }
    //     return result;
    // }
};
// @lc code=end
