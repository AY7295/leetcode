/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <algorithm>
#include <stack>
using namespace std;
// @lc code=start
class MyQueue
{
    stack<int> stIn, stOut;

public:
    MyQueue()
    {
        this->stIn = stack<int>();
        this->stOut = stack<int>();
    }

    void push(int x)
    {
        this->stIn.push(x);
    }

    int pop()
    {
        int ret = peek();
        this->stOut.pop();
        return ret;
    }

    int peek()
    {
        if (this->stOut.empty())
        {
            while (!this->stIn.empty())
            {
                this->stOut.push(this->stIn.top());
                this->stIn.pop();
            }
        }
        return this->stOut.top();
    }

    bool empty()
    {
        return this->stIn.empty() && this->stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
