/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int num : nums)
        {
            map[num]++;
        }

        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int, int>> pq;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > (int)map.size() - k) // answer can be unordered
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }

    // descp mine
    // vector<int> topKFrequent(vector<int> &nums, int k)
    // {
    //     unordered_map<int, int> mp;
    //     for (auto &&i : nums)
    //     {
    //         mp[i]++;
    //     }
    //     vector<pair<int, int>> v;
    //     v.reserve(mp.size());
    //     for (auto &&i : mp)
    //     {
    //         v.emplace_back(i);
    //     }

    //     sort(v.begin(), v.end(), [](pair<int, int> p1, pair<int, int> p2) -> bool
    //          { return p1.second > p2.second; });

    //     vector<int> ans(k, 0);
    //     for (int i = 0; i < k; i++)
    //     {
    //         ans[i] = v[i].first;
    //     }
    //     return ans;
    // }
};
// @lc code=end
