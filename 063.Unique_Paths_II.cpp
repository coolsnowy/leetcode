/**
 * Follow up for "Unique Paths":

    Now consider if some obstacles are added to the grids. How many unique paths would there be?

    An obstacle and empty space is marked as 1 and 0 respectively in the grid.

    For example,
    There is one obstacle in the middle of a 3x3 grid as illustrated below.

    [
    [0,0,0],
    [0,1,0],
    [0,0,0]
    ]
    The total number of unique paths is 2.

    Note: m and n will be at most 100.
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
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        // my accepted solution , need about 4 ms
        if(obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        bool indicate = 0;
        if(m > n) {
            std::swap(m, n);
            // indicate whether swap the row and column
            indicate = 1;
        }
        std::vector<std::vector<int>> path(m, std::vector<int> (n, 1));
        // 找出第零行和第零列是否有obstacle
        // 注意，只要有，该位置之后的所有元素都要设置为0！！！
        for(int i = 0; i< m; i++) {
            if((obstacleGrid[i][0] == 1 && indicate == 0) || (indicate == 1 && obstacleGrid[0][i] == 1)) {
                while(i < m)
                    path[i++][0] = 0;
            }
        }
        for(int i = 0; i < n; i++) {
            if((obstacleGrid[0][i] == 1 && indicate == 0) || (indicate == 1 && obstacleGrid[i][0] == 1)) {
                while(i < n)
                    path[0][i++] = 0;
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                path[i][j] = path[i - 1][j] + path[i][j - 1];
                if((obstacleGrid[i][j] == 1 && indicate == 0) || (indicate == 1 && obstacleGrid[j][i] == 1)) {
                    path[i][j] = 0;
                }
            }
        }
        return path[m - 1][n - 1];
    }

    //discuss solution, need about 4 ms,this solution is so concise
    int uniquePathsWithObstacles1(std::vector<std::vector<int>>& obstacleGrid) {
        int width = obstacleGrid[0].size();
        std::vector<int> dp(width, 0);
        dp[0] = 1;
        for (auto row : obstacleGrid) {
            for (int j = 0; j < width; j++) {
                if (row[j] == 1)
                    dp[j] = 0;
                else if (j > 0)
                    dp[j] += dp[j - 1];
            }
        }
        return dp[width - 1];
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> obstacle {{0, 0, 0}, {0, 1, 0}, { 0, 0, 0}};
    auto result = s.uniquePathsWithObstacles1(obstacle);
    cout<<result;
}