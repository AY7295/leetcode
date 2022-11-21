/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // descp official
    //  bool isValidBST(TreeNode *root)
    //  {
    //      stack<TreeNode *> stack;
    //      long long inorder = (long long)INT_MIN - 1;

    //     while (!stack.empty() || root != nullptr)
    //     {
    //         while (root != nullptr)
    //         {
    //             stack.push(root);
    //             root = root->left;
    //         }
    //         root = stack.top();
    //         stack.pop();
    //         // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
    //         if (root->val <= inorder)
    //         {
    //             return false;
    //         }
    //         inorder = root->val;
    //         root = root->right;
    //     }
    //     return true;
    // }

    // descp mine
    // bool isValidBST(TreeNode *root)
    // {
    //     function<bool(TreeNode *, long, long)> helper = [&](TreeNode *root, long low, long high)
    //     {
    //         // Empty trees are valid BSTs.
    //         if (root == nullptr)
    //         {
    //             return true;
    //         }

    //         // Condition of Binary Search Tree
    //         // left side node values of the root should be less value than the root and right side should be greater
    //         // If that is true check recursivley for the root child's

    //         if ((root->val < high) && (root->val > low))
    //         {
    //             return (helper(root->left, low, root->val) && helper(root->right, root->val, high));
    //         }
    //         else
    //         {
    //             // if this root node violates the min/max constraint
    //             return false;
    //         }
    //     };

    //     return helper(root, LONG_MIN, LONG_MAX);
    // }

    // descp mine
    bool isValidBST(TreeNode *root)
    {
        vector<int> ordered;
        function<void(TreeNode *)> help = [&](TreeNode *r)
        {
            if (r == nullptr)
            {
                return;
            }
            help(r->left);
            ordered.push_back(r->val);
            help(r->right);
        };
        help(root);

        for (size_t i = 1; i < ordered.size(); i++)
        {
            if (ordered[i] <= ordered[i - 1])
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
