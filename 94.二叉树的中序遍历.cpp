/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
#include <algorithm>
#include <stack>
using namespace std;

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
    // descp Morris traversal
    // vector<int> inorderTraversal(TreeNode *root)
    // {
    //     vector<int> nodes;
    //     while (root)
    //     {
    //         if (root->left)
    //         {
    //             TreeNode *pre = root->left;
    //             while (pre->right && pre->right != root)
    //             {
    //                 pre = pre->right;
    //             }
    //             if (!pre->right)
    //             {
    //                 pre->right = root;
    //                 root = root->left;
    //             }
    //             else
    //             {
    //                 pre->right = NULL;
    //                 nodes.push_back(root->val);
    //                 root = root->right;
    //             }
    //         }
    //         else
    //         {
    //             nodes.push_back(root->val);
    //             root = root->right;
    //         }
    //     }
    //     return nodes;
    // }

    // descp mine
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<decltype(TreeNode::val)> res;
        function<void(TreeNode *)> help = [&](TreeNode *r)
        {
            if (r == nullptr)
                return;

            help(r->left);
            res.emplace_back(r->val);
            help(r->right);
        };
        help(root);
        return res;
    }

    // descp Iterative
    // vector<int> inorderTraversal(TreeNode *root)
    // {
    //     vector<int> nodes;
    //     stack<TreeNode *> Stack;
    //     while (root || !Stack.empty())
    //     {
    //         while (root)
    //         {
    //             Stack.push(root);
    //             root = root->left;
    //         }
    //         root = Stack.top();
    //         Stack.pop();
    //         nodes.push_back(root->val);
    //         root = root->right;
    //     }
    //     return nodes;
    // }
};
// @lc code=end
