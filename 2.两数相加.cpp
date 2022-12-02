/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    //  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    //  {
    //      if (l1 == nullptr and l2 == nullptr)
    //          return nullptr;
    //      else if (l1 == nullptr)
    //          return l2;
    //      else if (l2 == nullptr)
    //          return l1;

    //     int a = l1->val + l2->val;
    //     ListNode *p = new ListNode(a % 10);
    //     p->next = addTwoNumbers(l1->next, l2->next);
    //     if (a >= 10)
    //         p->next = addTwoNumbers(p->next, new ListNode(1));
    //     return p;
    // }

    // descp mine
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr || l2 == nullptr)
        {
            return l1 == nullptr ? l2 : l1;
        }

        int temp = 0;
        auto ans = l1;
        while (l1->next != nullptr && l2->next != nullptr)
        {
            l1->val += l2->val + temp;
            temp = l1->val / 10;
            l1->val = l1->val % 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        l1->val += l2->val + temp;
        temp = l1->val / 10;
        l1->val = l1->val % 10;

        l1->next = l2->next == nullptr ? l1->next : l2->next;
        if (l1->next != nullptr)
        {
            l1 = l1->next;
            while (l1->next != nullptr && temp != 0)
            {
                l1->val += temp;
                temp = l1->val / 10;
                l1->val = l1->val % 10;
                l1 = l1->next;
            }
            l1->val += temp;
            temp = l1->val / 10;
            l1->val = l1->val % 10;
        }

        if (temp != 0)
        {
            l1->next = new ListNode(temp);
        }

        return ans;
    }
};
// @lc code=end
