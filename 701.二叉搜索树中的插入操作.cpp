/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {

        auto r = root;
        while (r != nullptr)
        {
            if (r->val > val)
            {
                if (r->left == nullptr)
                {
                    r->left = new TreeNode(val);
                    return root;
                }
                r = r->left;
            }
            else
            {
                if (r->right == nullptr)
                {
                    r->right = new TreeNode(val);
                    return root;
                }
                r = r->right;
            }
        }

        return new TreeNode(val);
    }
};
// @lc code=end
