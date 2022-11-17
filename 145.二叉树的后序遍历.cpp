/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<decltype(TreeNode::val)> res;
        function<void(TreeNode *)> help = [&](TreeNode *r)
        {
            if (r == nullptr)
                return;

            help(r->left);
            help(r->right);
            res.emplace_back(r->val);
        };
        help(root);
        return res;
    }
};
// @lc code=end
