/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
#include <algorithm>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start

class Solution
{

public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return root;

        function<void(Node *, Node *, Node *)> help = [&](Node *root, Node *right, Node *left)
        {
            if (right == nullptr)
                return;

            left->next = right;
            right->next = root->next == nullptr ? nullptr : root->next->left;

            help(right, right->right, right->left);
            help(left, left->right, left->left);
            return;
        };

        root->next = nullptr;
        help(root, root->right, root->left);

        return root;
    }
};
// @lc code=end
