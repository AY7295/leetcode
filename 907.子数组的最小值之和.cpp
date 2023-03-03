/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
    const int MOD = 1e9 + 7;

public:
    // descp time exceed
    //  int sumSubarrayMins(vector<int> &arr)
    //  {
    //      int n = arr.size(), min, ans = 0;
    //      for (int i = 0; i < n; i++)
    //      {
    //          min = arr[i];
    //          for (int k = i; k < n; k++)
    //          {
    //              min = min > arr[k] ? arr[k] : min;
    //              ans = (ans + min) % MOD;
    //          }
    //      }
    //      return ans;
    //  }

    // descp contribution with monotonous stack
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        // 左边界 left[i] 为左侧严格小于 arr[i] 的最近元素位置（不存在时为 -1）
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop(); // 移除无用数据
            if (!st.empty())
                left[i] = st.top();
            st.push(i);
        }

        // 右边界 right[i] 为右侧小于等于 arr[i] 的最近元素位置（不存在时为 n）
        vector<int> right(n, n);

        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop(); // 移除无用数据
            if (!st.empty())
                right[i] = st.top();
            st.push(i);
        }

        long ans = 0L;
        for (int i = 0; i < n; ++i)
            ans += (long)arr[i] * (i - left[i]) * (right[i] - i); // 累加贡献
        return ans % MOD;
    }
};
// @lc code=end
