/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */
#include <algorithm>
//  * Definition for a binary tree node.
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
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left_child = minDepth(root->left);
        int right_child = minDepth(root->right);
        if (left_child == 0)
            return right_child + 1;
        if (right_child == 0)
            return left_child + 1;
        return std::min(left_child, right_child) + 1;
    }
};
// @lc code=end
