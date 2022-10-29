/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // descp mine
    // ListNode *middleNode(ListNode *head)
    // {
    //     vector<ListNode *> v;
    //     while (head != nullptr)
    //     {
    //         v.push_back(head);
    //         head = head->next;
    //     }
    //     return v[v.size() / 2];
    // }
};
// @lc code=end
