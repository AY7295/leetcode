/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入二叉搜索树
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
    // descp most voted solution
    // bool findTarget(TreeNode *root, int target)
    // {

    //     if (root == nullptr)
    //         return false;

    //     stack<TreeNode *> s1, s2;
    //     TreeNode *temp1 = root;
    //     TreeNode *temp2 = root;

    //     while (true)
    //     {
    //         while (temp1 != nullptr)
    //         {
    //             s1.push(temp1);
    //             temp1 = temp1->left;
    //         }

    //         while (temp2 != nullptr)
    //         {
    //             s2.push(temp2);
    //             temp2 = temp2->right;
    //         }

    //         if (s1.empty() || s2.empty())
    //             break;

    //         temp1 = s1.top();
    //         temp2 = s2.top();

    //         if ((temp1->val + temp2->val) == target)
    //         {
    //             if (temp1 == temp2)
    //                 return false;

    //             return true;
    //         }
    //         else if ((temp1->val + temp2->val) < target)
    //         {
    //             s1.pop();
    //             temp1 = temp1->right;
    //             temp2 = nullptr;
    //         }
    //         else
    //         {
    //             s2.pop();
    //             temp2 = temp2->left;
    //             temp1 = nullptr;
    //         }
    //     }

    //     return false;
    // }

    // descp mine
    bool findTarget(TreeNode *root, int k)
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

        int l = 0, r = ordered.size() - 1;
        while (l < r)
        {
            if (ordered[r] + ordered[l] < k)
            {
                l++;
            }
            else if (ordered[r] + ordered[l] > k)
            {
                r--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
