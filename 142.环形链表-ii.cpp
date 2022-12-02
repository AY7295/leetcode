/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

#include <unordered_map>
using namespace std;
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
    ListNode *detectCycle(ListNode *head)
    {
        // edge case - empty list
        if (!head || !head->next || !head->next->next)
            return nullptr;
        // support animals
        ListNode *turtle = head, *hare = head;
        // checking if we loop or not
        while (hare->next && hare->next->next)
        {
            hare = hare->next->next;
            turtle = turtle->next;
            if (hare == turtle)
                break;
        }
        // exiting if we do not find a loop
        if (hare != turtle)
            return nullptr;
        // finding the start of the loop
        turtle = head;
        while (turtle != hare)
        {
            hare = hare->next;
            turtle = turtle->next;
        }
        return turtle;
    }
};
// @lc code=end
