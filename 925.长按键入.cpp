/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    bool isLongPressedName(string name, string typed)
    {
        if (name[0] != typed[0])
            return false;
        int i = 0, j = 0;
        while (i < typed.size() || j < name.size())
        {
            if (typed[i] == name[j])
                j++;
            else if (typed[i] != typed[i - 1])
                return false;
            i++;
        }
        return true;
    }

    // descp mine
    // bool isLongPressedName(string name, string typed)
    // {
    //     int n = name.size(), t = typed.size();
    //     if (n >= t)
    //     {
    //         return name == typed;
    //     }
    //     int np = 0, tp = 0, pret = 0, pren = 0;
    //     char temp = name[0];
    //     while (np < n && tp < t)
    //     {
    //         while (np < n && name[np] == temp)
    //             np++;
    //         while (tp < t && typed[tp] == temp)
    //             tp++;
    //         if (np - pren > tp - pret)
    //         {
    //             return false;
    //         }
    //         pret = tp;
    //         pren = np;
    //         temp = name[np];
    //     }
    //     return tp == t && np == n;
    // }
};
// @lc code=end
