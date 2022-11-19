/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */
#include <algorithm>
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
    TreeNode *invertTree(TreeNode *root)
    {
        TreeNode *temp;
        function<void(TreeNode *)> help = [&](TreeNode *node)
        {
            if (node == nullptr)
            {
                return;
            }
            temp = node->left;
            node->left = node->right;
            node->right = temp;
            help(node->left);
            help(node->right);
        };
        help(root);
        return root;
    }
};
// @lc code=end
