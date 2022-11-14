/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
#include <algorithm>
using namespace std;
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start

class Solution
{
public:
    // descp most voted solution
    bool hasCycle(ListNode *head)
    {
        ListNode *h = head, *prev = nullptr, *follow = nullptr;
        while (head) // reverse the list
        {
            follow = head->next;
            head->next = prev;
            prev = head;
            head = follow;
        }

        return h && h->next && prev == h;
    }

    // descp mine
    // bool hasCycle(ListNode *head)
    // {
    //     unordered_map<decltype(head), bool> mp;
    //     while (head != nullptr)
    //     {
    //         if (mp.find(head) != mp.end())
    //         {
    //             return true;
    //         }
    //         mp[head] = true;
    //         head = head->next;
    //     }
    //     return false;
    // }
};
// @lc code=end
