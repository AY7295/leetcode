/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    // descp most voted solution
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<char, int> row[9], col[9], blk[9];
        char c;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                c = board[i][j];
                if ((c != '.') && (0 < row[i][c]++ || 0 < col[j][c]++ || 0 < blk[i / 3 * 3 + j / 3][c]++))
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
