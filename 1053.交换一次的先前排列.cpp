/*
 * @lc app=leetcode.cn id=1053 lang=cpp
 *
 * [1053] 交换一次的先前排列
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    vector<int> prevPermOpt1(vector<int> &A)
    {
        int i = A.size() - 2, max_ = -1;
        while (i >= 0 && A[i] <= A[i + 1])
            --i;

        if (i >= 0)
        {
            max_ = i + 1;
            for (int j = max_ + 1; j < A.size(); ++j)
                if (A[max_] < A[j] && A[j] < A[i])
                    max_ = j;

            swap(A[max_], A[i]);
        }
        return A;
    }
};
// @lc code=end
