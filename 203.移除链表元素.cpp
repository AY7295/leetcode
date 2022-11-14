/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */
#include <algorithm>

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
    ListNode *removeElements(ListNode *head, int val)
    {
        auto res = new ListNode(val - 1);
        auto h = res, pre = h;
        h->next = head;
        while (h != nullptr)
        {
            if (h->val == val)
                pre->next = h->next;
            else
                pre = h;

            h = h->next;
        }

        return res->next;
    }
};
// @lc code=end
