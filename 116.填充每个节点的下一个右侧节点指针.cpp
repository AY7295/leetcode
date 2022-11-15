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
    // descp mine
    Node *connect(Node *root)
    {
        if (root == nullptr)
        {
            return root;
        }
        Node *start = root, *end;
        while (start->left != nullptr)
        {
            end = start;
            while (end->next != nullptr)
            {
                end->left->next = end->right;
                end->right->next = end->next->left;
                end = end->next;
            }
            end->left->next = end->right;
            start = start->left;
        }

        return root;
    }
};
// @lc code=end
