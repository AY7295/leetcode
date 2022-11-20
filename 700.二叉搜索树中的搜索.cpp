/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
 */
#include <algorithm>
#include <queue>
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
    // descp official
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root)
        {
            if (val == root->val)
            {
                return root;
            }
            root = val < root->val ? root->left : root->right;
        }
        return nullptr;
    }

    // descp mine
    // TreeNode *searchBST(TreeNode *root, int val)
    // {
    //     if (root == nullptr)
    //     {
    //         return nullptr;
    //     }
    //     queue<decltype(root)> q;
    //     q.emplace(root);
    //     auto now = root;
    //     while (!q.empty())
    //     {
    //         now = q.front();
    //         q.pop();
    //         if (now->val == val)
    //         {
    //             return now;
    //         }
    //         if (now->left != nullptr)
    //         {
    //             q.emplace(now->left);
    //         }
    //         if (now->right != nullptr)
    //         {
    //             q.emplace(now->right);
    //         }
    //     }
    //     return nullptr;
    // }
};
// @lc code=end
