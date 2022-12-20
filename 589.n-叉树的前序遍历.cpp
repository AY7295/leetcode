/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */
#include <vector>
#include <stack>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
// @lc code=start
class Solution
{
public:
    // descp official
    vector<int> preorder(Node *root)
    {
        if (root == nullptr)
            return {};

        vector<int> res;
        stack<Node *> st;
        st.emplace(root);
        while (!st.empty())
        {
            root = st.top();
            st.pop();
            res.emplace_back(root->val);
            for (auto it = root->children.rbegin(); it != root->children.rend(); it++)
            {
                st.emplace(*it);
            }
        }
        return res;
    }

    // descp mine
    // vector<int> preorder(Node *root)
    // {

    //     if (root != nullptr)
    //         return {};

    //     vector<int> ans;
    //     function<void(Node *)> help = [&](Node *r)
    //     {
    //         ans.emplace_back(r->val);
    //         for (auto &&child : r->children)
    //         {
    //             help(child);
    //         }
    //     };
    //     help(root);

    //     return ans;
    // }
};
// @lc code=end
