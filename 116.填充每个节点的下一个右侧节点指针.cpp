/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
#include <algorithm>
#include <queue>
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
    // descp most voted solution
    Node *connect(Node *root)
    {
        Node *pre = root, *cur;
        while (pre)
        {
            cur = pre;
            while (cur && cur->left)
            {
                cur->left->next = cur->right;
                if (cur->next)
                {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            pre = pre->left;
        }
        return root;
    }

    // descp mine
    // Node *connect(Node *root)
    // {
    //     if (root == nullptr)
    //         return root;

    //     if (root->left)
    //     {
    //         root->left->next = root->right;
    //         if (root->next)
    //         {
    //             root->right->next = root->next->left;
    //         }
    //         connect(root->left);
    //         connect(root->right);
    //     }

    //     return root;
    // }
};
// @lc code=end
