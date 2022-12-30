/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */
#include <vector>
using namespace std;
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
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        return slow;
    }
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head, *temp = NULL;
        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    bool compareList(ListNode *head1, ListNode *head2)
    {
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->val != head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *h = head;
        ListNode *mid = findMid(h);
        ListNode *h2 = reverseList(mid);
        return compareList(head, h2);
    }

    // descp mine
    // bool isPalindrome(ListNode *head)
    // {
    //     vector<int> half;
    //     auto fast = head, slow = head;
    //     while (fast != nullptr && fast->next != nullptr)
    //     {
    //         half.emplace_back(slow->val);
    //         fast = fast->next->next;
    //         slow = slow->next;
    //     }
    //     int n = half.size() - 1;
    //     if (fast != nullptr)
    //     {
    //         slow = slow->next;
    //     }
    //     while (slow != nullptr)
    //     {
    //         if (slow->val != half[n--])
    //         {
    //             return false;
    //         }
    //         slow = slow->next;
    //     }

    //     return true;
    // }
};
// @lc code=end
