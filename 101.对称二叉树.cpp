/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */
#include <algorithm>
#include <stack>
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
    bool isTheSame(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        if (left == nullptr || right == nullptr)
        {
            return false;
        }
        if (left->val != right->val)
        {
            return false;
        }
        return isTheSame(left->left, right->right) && isTheSame(right->left, left->right);
    }

public:
    // descp mine
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        return isTheSame(root->left, root->right);
    }

    // descp 迭代
    // bool isSymmetric(TreeNode *root)
    // {
    //     if (root == nullptr)
    //         return true;

    //     stack<TreeNode *> stk;
    //     stk.push(root->left);
    //     stk.push(root->right);
    //     bool ans = true;
    //     while (!stk.empty() && ans)
    //     {
    //         TreeNode *tree1 = nullptr;
    //         TreeNode *tree2 = nullptr;
    //         if (!stk.empty())
    //             tree1 = stk.top();
    //         stk.pop();
    //         if (!stk.empty())
    //             tree2 = stk.top();
    //         stk.pop();

    //         if (!tree1 || !tree2)
    //         {
    //             if (!tree1 && !tree2)
    //                 continue;
    //             else
    //                 return false;
    //         }
    //         ans = tree1->val == tree2->val;
    //         stk.push(tree1->left);
    //         stk.push(tree2->right);
    //         stk.push(tree1->right);
    //         stk.push(tree2->left);
    //     }
    //     return ans;
    // }
};
// @lc code=end
