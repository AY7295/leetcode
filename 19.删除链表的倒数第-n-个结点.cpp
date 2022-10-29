/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */
#include <algorithm>
using namespace std;
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
    // descp most voted solution
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode new_head(-1);
        new_head.next = head;

        ListNode *slow = &new_head, *fast = &new_head;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *to_be_deleted = slow->next;
        slow->next = slow->next->next;

        delete to_be_deleted;

        return new_head.next;
    }

    // descp mine
    // ListNode *removeNthFromEnd(ListNode *head, int n)
    // {
    //     ListNode *target = head, *tail = head, *pre = head;
    //     while (tail != nullptr)
    //     {
    //         tail = tail->next;
    //         n--;
    //         if (n < 0)
    //         {
    //             pre = target;
    //             target = target->next;
    //         }
    //     }
    //     if (pre == target)
    //     {
    //         return head->next;
    //     }

    //     pre->next = target->next;

    //     return head;
    // }
};
// @lc code=end
