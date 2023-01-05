/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */
#include <functional>
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
    int kthSmallest(TreeNode *root, int k)
    {
        int ans;
        std::function<void(TreeNode *)> help = [&](TreeNode *root)
        {
            if (root == nullptr || k == 0)
            {
                return;
            }
            help(root->left);
            if (--k == 0)
            {
                ans = root->val;
                return;
            }
            help(root->right);
        };
        help(root);

        return ans;
    }
};
// @lc code=end
