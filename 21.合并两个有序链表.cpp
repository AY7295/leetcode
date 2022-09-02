/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include <algorithm>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start

//  Definition for singly-linked list.

class Solution
{
public:
    // descp most voted solution
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        if (!a || b && a->val > b->val)
            std::swap(a, b);
        if (a)
            a->next = mergeTwoLists(a->next, b);
        return a;
    }

    // descp mine
    // ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    // {
    //     auto result = new ListNode(-1);
    //     auto *head = result;

    //     for (; nullptr != a && nullptr != b;)
    //     {
    //         if (a->val < b->val)
    //         {
    //             head->next = a;
    //             a = a->next;
    //         }
    //         else
    //         {
    //             head->next = b;
    //             b = b->next;
    //         }
    //         head = head->next;
    //     }

    //     head->next = a != nullptr ? a : b;

    //     return result->next;
    // }
};
// @lc code=end
