/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

//  Definition for singly-linked list.
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr, *now = head;

        while (head != nullptr)
        {
            now = head;
            head = head->next;
            now->next = pre;
            pre = now;
        }

        return now;
    }
};
// @lc code=end
