/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    // int evalRPN(vector<string> &tokens)
    // {
    //     unordered_map<string, function<int(int, int)>> map = {
    //         {"+", [](int a, int b)
    //          { return a + b; }},
    //         {"-", [](int a, int b)
    //          { return a - b; }},
    //         {"*", [](int a, int b)
    //          { return a * b; }},
    //         {"/", [](int a, int b)
    //          { return a / b; }}};
    //     std::stack<int> stack;
    //     for (string &s : tokens)
    //     {
    //         if (map.count(s) == 0)
    //         {
    //             stack.push(stoi(s));
    //         }
    //         else
    //         {
    //             int op1 = stack.top();
    //             stack.pop();
    //             int op2 = stack.top();
    //             stack.pop();
    //             stack.push(map[s](op2, op1));
    //         }
    //     }
    //     return stack.top();
    // }

    // descp official
    int evalRPN(vector<string> &tokens)
    {
        vector<int> stk((tokens.size() + 1) / 2);
        int index = -1;
        for (auto &&token : tokens)
        {
            if (token.length() > 1 || isdigit(token[0]))
            {
                index++;
                stk[index] = atoi(token.c_str());
            }
            else
            {
                index--;
                switch (token[0])
                {
                case '+':
                    stk[index] += stk[index + 1];
                    break;
                case '-':
                    stk[index] -= stk[index + 1];
                    break;
                case '*':
                    stk[index] *= stk[index + 1];
                    break;
                case '/':
                    stk[index] /= stk[index + 1];
                    break;
                }
            }
        }
        return stk[0];
    }
};
// @lc code=end
