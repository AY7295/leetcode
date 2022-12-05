/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
//  * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution
{
public:
    // descp mine
    ListNode *swapPairs(ListNode *head)
    {
        auto root = new ListNode(-1, head);
        auto now = root->next, pre = root, last = root;

        while (now != nullptr && now->next != nullptr)
        {
            last = now->next->next;
            pre->next = now->next;
            now->next = last;
            pre->next->next = now;
            pre = now;
            now = pre->next;
        }
        return root->next;
    }
};
// @lc code=end
