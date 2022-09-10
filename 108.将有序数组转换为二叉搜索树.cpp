/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */
#include <algorithm>
#include <cmath>
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
public:
    // descp most voted solution
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int left, int right)
    {

        // base case
        // If the left pointer crosses right return null;
        if (left > right)
        {
            return NULL;
        }

        // as middle of the array will be the root node
        int mid = (left + right) / 2;
        TreeNode *temp = new TreeNode(nums[mid]);

        // left part from middle will be left subtree
        temp->left = helper(nums, left, mid - 1);

        // right part of array will be right subtree
        temp->right = helper(nums, mid + 1, right);
        return temp;
    }
};
// @lc code=end
