/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */
#include <algorithm>
#include <stack>
using namespace std;
// Definition for a binary tree node.
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
    // descp mine
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }

    // descp most voted solution
    // TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    // {
    //     TreeNode *cur = root;
    //     while (true)
    //     {
    //         if (p->val < cur->val && q->val < cur->val)
    //         {
    //             cur = cur->left;
    //         }
    //         else if (p->val > cur->val && q->val > cur->val)
    //         {
    //             cur = cur->right;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    //     return cur;
    // }
};
// @lc code=end
