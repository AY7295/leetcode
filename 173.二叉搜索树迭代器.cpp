/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */
#include <vector>
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
// descp most voted solution
class BSTIterator
{
    stack<TreeNode *> myStack;

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node)
    {
        for (; node != NULL; myStack.push(node), node = node->left)
            ;
    }
};

// descp mine
//  class BSTIterator
//  {
//      vector<int> *bst;
//      int cur = 0, max;
//      void help(TreeNode *root)
//      {
//          if (root == nullptr)
//              return;
//          help(root->left);
//          bst->emplace_back(root->val);
//          help(root->right);
//      }
//  public:
//      BSTIterator(TreeNode *root)
//      {
//          bst = new vector<int>;
//          help(root);
//          this->max = this->bst->size();
//      }
//      int next()
//      {
//          return this->bst->at(cur++);
//      }
//      bool hasNext()
//      {
//          return cur != max;
//      }
//  };
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
