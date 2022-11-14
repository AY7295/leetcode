/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        auto res = new ListNode(-1);
        auto head = res;

        while (a != nullptr && b != nullptr)
        {
            if (a->val < b->val)
            {
                head->next = a;
                a = a->next;
            }
            else
            {
                head->next = b;
                b = b->next;
            }
            head = head->next;
        }
        head->next = a == nullptr ? b : a;

        return res->next;
    }

    // descp most voted solution
    // ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    // {
    //     if (!a || b && a->val > b->val)
    //         std::swap(a, b);
    //     if (a)
    //         a->next = mergeTwoLists(a->next, b);
    //     return a;
    // }
};
// @lc code=end
