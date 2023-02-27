/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{

    // descp copilot dfs
private:
    bool dfs(vector<vector<int>> &courses, vector<int> &visited, int i, vector<int> &ans)
    {
        if (visited[i] == 1)
            return false;
        if (visited[i] == 2)
            return true;
        visited[i] = 1;
        for (int j = 0; j < courses.size(); j++)
        {
            if (courses[i][j] == 1)
            {
                if (!dfs(courses, visited, j, ans))
                    return false;
            }
        }
        visited[i] = 2;
        ans.push_back(i);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> courses(numCourses, vector<int>(numCourses, 0));
        for (auto &&v : prerequisites)
        {
            courses[v[0]][v[1]] = 1;
        }
        vector<int> ans;
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(courses, visited, i, ans))
                return {};
        }
        return ans;
    }
};
// @lc code=end
