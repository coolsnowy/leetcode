/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

    Note: You can only move either down or right at any point in time.

    Example 1:
    [[1,3,1],
     [1,5,1],
     [4,2,1]]
    Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.
    */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <algorithm>


using std::priority_queue;
using std::vector;
using std::map;
using std::stack;
using std::unordered_map;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    // my accepted solution, cost 10ms, the most important thing is that I use 0 extra space!!!l
    int minPathSum(std::vector<std::vector<int>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size(), col = grid[0].size();
        for(int i = 1; i < row; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for(int i = 1; i < col; i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                grid[i][j] = std::min(grid[i][j] + grid[i - 1][j], grid[i][j] + grid[i][j - 1]);
            }
        }
        return grid[row - 1][col - 1];
    }
    /* discuss solution
        This is a typical DP problem. Suppose the minimum path sum of arriving at point (i, j) is S[i][j],
        then the state equation is S[i][j] = min(S[i - 1][j], S[i][j - 1]) + grid[i][j].

        Well, some boundary conditions need to be handled.
        The boundary conditions happen on the topmost row (S[i - 1][j] does not exist) and the leftmost column (S[i][j - 1] does not exist).
        Suppose grid is like [1, 1, 1, 1], then the minimum sum to arrive at each point is simply an accumulation of previous points
        and the result is [1, 2, 3, 4].

        Now we can write down the following (unoptimized) code.
    */
    // this solution is as same as mine! but actually, needn't the additional m * n space of the sum, just see my code
        int minPathSum1(std::vector<std::vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            std::vector<std::vector<int> > sum(m, std::vector<int>(n, grid[0][0]));
            for (int i = 1; i < m; i++)
                sum[i][0] = sum[i - 1][0] + grid[i][0];
            for (int j = 1; j < n; j++)
                sum[0][j] = sum[0][j - 1] + grid[0][j];
            for (int i = 1; i < m; i++)
                for (int j = 1; j < n; j++)
                    sum[i][j]  = std::min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
            return sum[m - 1][n - 1];
        }
    };
    /*As can be seen, each time when we update sum[i][j], we only need sum[i - 1][j] (at the current column) and sum[i][j - 1] (at the left column).
     * So we need not maintain the full m*n matrix. Maintaining two columns is enough and now we have the following code.
    */

        int minPathSum2(std::vector<std::vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            std::vector<int> pre(m, grid[0][0]);
            std::vector<int> cur(m, 0);
            for (int i = 1; i < m; i++)
                pre[i] = pre[i - 1] + grid[i][0];
            for (int j = 1; j < n; j++) {
                cur[0] = pre[0] + grid[0][j];
                for (int i = 1; i < m; i++)
                    cur[i] = std::min(cur[i - 1], pre[i]) + grid[i][j];
                swap(pre, cur);
            }
            return pre[m - 1];
        }
    /*
    Further inspecting the above code, it can be seen that maintaining pre is for recovering pre[i],
     which is simply cur[i] before its update. So it is enough to use only one vector. Now the space is further optimized and the code also gets shorter.
    */
        // need about 9 ms, but is still cost m extra space, but my solution use 0 extra space!
        int minPathSum3(std::vector<std::vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            std::vector<int> cur(m, grid[0][0]);
            for (int i = 1; i < m; i++)
                cur[i] = cur[i - 1] + grid[i][0];
            for (int j = 1; j < n; j++) {
                cur[0] += grid[0][j];
                for (int i = 1; i < m; i++)
                    cur[i] = std::min(cur[i - 1], cur[i]) + grid[i][j];
            }
            return cur[m - 1];
        }

};

int main() {
    Solution s;
    std::vector<std::vector<int>> grid {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    auto result = s.minPathSum(grid);
    cout<<result;
}