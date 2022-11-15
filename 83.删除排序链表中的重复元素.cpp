/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        auto s = head;
        while (s != nullptr && s->next != nullptr)
        {
            if (s->val == s->next->val)
                s->next = s->next->next;
            else
                s = s->next;
        }
        return head;
    }
};
// @lc code=end
