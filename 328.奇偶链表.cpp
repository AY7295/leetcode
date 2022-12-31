/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *even_start = head->next;

        while (odd->next && even->next)
        {
            odd->next = even->next;       // Connect all odds
            even->next = odd->next->next; // Connect all evens
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_start; // Place the first even node after the last odd node.
        return head;
    }

    // descp mine
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        decltype(head) h = head->next->next, odd = head, even = head->next, evenHead = even;

        int temp = 1;
        while (h != nullptr)
        {
            if (temp++ % 2 == 0)
            {
                even->next = h;
                even = even->next;
            }
            else
            {
                odd->next = h;
                odd = odd->next;
            }
            h = h->next;
        }

        even->next = nullptr;
        odd->next = evenHead;
        return head;
    }
};
// @lc code=end
