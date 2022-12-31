/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// Definition for singly-linked list.
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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // divide the list into two parts
        fast = slow->next;
        slow->next = nullptr;

        return merge(sortList(head), sortList(fast));
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dump(0);
        ListNode *cur = &dump;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }

            cur = cur->next;
        }

        if (l1 != nullptr)
            cur->next = l1;
        else
            cur->next = l2;

        return dump.next;
    }
};
// @lc code=end
