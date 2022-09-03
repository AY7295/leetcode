/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */
#include <algorithm>
#include <queue>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution
{
public:
    // descp most voted solution
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> Queue;
        Queue.push(p);
        Queue.push(q);
        while (Queue.size() != 0)
        {
            TreeNode *q2 = Queue.front();
            Queue.pop();
            TreeNode *q1 = Queue.front();
            Queue.pop();
            if (q1 == nullptr && q2 == nullptr)
                continue;
            if (q1 == nullptr || q2 == nullptr)
                return false;
            if (q1->val != q2->val)
                return false;
            Queue.push(q1->left);
            Queue.push(q2->left);
            Queue.push(q1->right);
            Queue.push(q2->right);
        }
        return true;
    }

    // descp mine
    //  bool isSameTree(TreeNode *p, TreeNode *q)
    //  {
    //      if (p == nullptr && q == nullptr)
    //          return true;
    //      if (p == nullptr || q == nullptr)
    //          return false;
    //      if (p->val != q->val)
    //          return false;
    //      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    //  }
};
// @lc code=end
