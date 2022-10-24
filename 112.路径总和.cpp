/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

#include <algorithm>
#include <queue>
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
    // descp official solution
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return false;
        }
        std::queue<TreeNode *> que_node;
        std::queue<int> que_val;
        que_node.push(root);
        que_val.push(root->val);
        while (!que_node.empty())
        {
            TreeNode *now = que_node.front();
            int temp = que_val.front();
            que_node.pop();
            que_val.pop();
            if (now->left == nullptr && now->right == nullptr)
            {
                if (temp == sum)
                {
                    return true;
                }
                continue;
            }
            if (now->left != nullptr)
            {
                que_node.push(now->left);
                que_val.push(now->left->val + temp);
            }
            if (now->right != nullptr)
            {
                que_node.push(now->right);
                que_val.push(now->right->val + temp);
            }
        }
        return false;
    }

    // descp mine
    // bool hasPathSum(TreeNode *root, int targetSum)
    // {
    //     if (root == nullptr)
    //         return false;
    //     if (root->left == nullptr && root->right == nullptr)
    //         return root->val == targetSum;
    //     return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    // }
};
// @lc code=end
