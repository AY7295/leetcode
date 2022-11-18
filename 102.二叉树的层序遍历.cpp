/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<vector<decltype(TreeNode::val)>> res;
        vector<decltype(TreeNode::val)> temp;
        queue<decltype(root)> q;
        int qSize = 0;
        q.emplace(root);

        while (!q.empty())
        {
            qSize = q.size();
            temp.resize(qSize);
            for (int i = 0; i < qSize; i++)
            {
                auto now = q.front();
                q.pop();
                temp[i] = now->val;
                if (now->left != nullptr)
                {
                    q.emplace(now->left);
                }
                if (now->right != nullptr)
                {
                    q.emplace(now->right);
                }
            }

            res.emplace_back(temp);
        }
        return res;
    }
};
// @lc code=end
