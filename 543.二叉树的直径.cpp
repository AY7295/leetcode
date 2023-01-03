/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    // descp most voted solution
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        int ans = 0;
        function<int(TreeNode *)> height = [&](TreeNode *root)
        {
            if (!root)
                return 0;

            int lHeight = height(root->left);
            int rHeight = height(root->right);

            ans = max(ans, 1 + lHeight + rHeight);
            return 1 + max(lHeight, rHeight);
        };
        height(root);

        return ans - 1;
    }
};
// @lc code=end
