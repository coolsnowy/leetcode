/**
 * Follow up for N-Queens problem.
    Now, instead outputting board configurations, return the total number of distinct solutions.
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
    // according the last problem, my solution, need 4ms
    int totalNQueens(int n) {
        int result = 0;
        std::vector<int> flagCol(n, 0), flag45(2 * n - 1, 0), flag135(2 * n - 1, 0);
        int row = 0;
        result = Nqueens(result, flagCol, flag45, flag135, row, n);
        return result;
    }
    int Nqueens(int result, std::vector<int>& flagCol, std::vector<int>& flag45, std::vector<int>& flag135, int row, int n) {
        if(row == n) {
            result++;
            return result;
        }
        /*    flagCol             row + col           row - col值唯一（一条斜线上）
          *    | | |                / / /             \ \ \
          *    O O O               O O O               O O O
          *    | | |              / / / /             \ \ \ \
          *    O O O               O O O               O O O
          *    | | |              / / / /             \ \ \ \
          *    O O O               O O O               O O O
          *    | | |              / / /                 \ \ \
          *   3 columns        5 45diagonals     5 135 diagonals    (when n is 3)
          */
        for(int col = 0; col < n; col++) {
            if(!flagCol[col] && !flag45[row + col] && !flag135[n - 1 + col - row]) {
                flagCol[col] = 1;
                flag45[row + col] = 1;
                flag135[n - 1 + col - row] = 1;
                result = Nqueens(result, flagCol, flag45, flag135, row + 1, n);
                flagCol[col] = 0;
                flag45[row + col] = 0;
                flag135[n - 1 + col - row] = 0;
            }
        }
        return result;
    }
};


int main() {
    Solution s;
    int n = 4;
    auto result = s.totalNQueens(n);
    cout<<result;
}