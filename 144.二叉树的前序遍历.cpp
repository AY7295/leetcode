/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> nodes;
        stack<TreeNode *> todo;
        while (root != nullptr || !todo.empty())
        {
            if (root != nullptr)
            {
                nodes.push_back(root->val);
                if (root->right)
                {
                    todo.push(root->right);
                }
                root = root->left;
            }
            else
            {
                root = todo.top();
                todo.pop();
            }
        }
        return nodes;
    }
    // descp mine
    // vector<int> preorderTraversal(TreeNode *root)
    // {
    //     vector<decltype(TreeNode::val)> res;
    //     function<void(TreeNode *)> help = [&](TreeNode *r)
    //     {
    //         if (r == nullptr)
    //             return;

    //         res.emplace_back(r->val);
    //         help(r->left);
    //         help(r->right);
    //     };
    //     help(root);
    //     return res;
    // }
};
// @lc code=end
