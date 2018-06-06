/**
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

    Given an integer n, return all distinct solutions to the n-queens puzzle.

    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.'
    both indicate a queen and an empty space respectively.

    For example,
    There exist two distinct solutions to the 4-queens puzzle:

    [
     [".Q..",  // Solution 1
      "...Q",
      "Q...",
      "..Q."],

     ["..Q.",  // Solution 2
      "Q...",
      "...Q",
      ".Q.."]
    ]
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
    // difficult problem, see the solution and then code it
    // need 8 ms
    std::vector<std::vector<string>> solveNQueens(int n) {
        std::vector<string> vec(n, std::string(n, '.'));
        std::vector<std::vector<string>> result;
        int row = 0;
        nQueens(vec, result, row, n);
        return result;
    }

    void nQueens(std::vector<string> &vec, std::vector<std::vector<string>> &result, int row, int n) {
        if (row == n) {
            result.push_back(vec);
            return;
        }

        for (int col = 0; col < n; col++)
            if (isValid(vec, row, col, n)) {
                vec[row][col] = 'Q';
                nQueens(vec, result, row + 1, n);
                vec[row][col] = '.';
            }
    }

    bool isValid(std::vector<string> &vec, int row, int col, int n) {
        // judge the column whether exist the queen
        for (int i = 0; i < n; i++) {
            if (vec[i][col] == 'Q')
                return false;
        }
        // judge the 45 whether exist the queen
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (vec[i][j] == 'Q')
                return false;
        }
        // judge the 135 whether exist the queen
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (vec[i][j] == 'Q')
                return false;
        }
        return true;
    }
}
    /*
    Solution B: Use flag vectors as bitmask, 4ms:

    The number of columns is n, the number of 45 diagonals is 2 * n - 1,
     the number of 135 diagonals is also 2 * n - 1.
     When reach [row, col], the column No. is col, the 45 diagonal No. is row + col and the 135\xb0 diagonal No. is n - 1 + col - row.
     We can use three arrays to indicate if the column or the diagonal had a queen before,
     if not, we can put a queen in this position and continue.

    NOTE: Please don’t use vector<bool> flag to replace vector<int> flag in the following C++ code.
     In fact, vector<bool> is not a STL container. You should avoid to use it. You can also get the knowledge from here and here.
    */
/**    | | |                / / /             \\ \\ \\
  *    O O O               O O O               O O O
  *    | | |              / / / /             \\ \\ \\ \\
  *    O O O               O O O               O O O
  *    | | |              / / / /             \\ \\ \\ \\
  *    O O O               O O O               O O O
  *    | | |              / / /                 \\ \\ \\
  *   3 columns        5 45 diagonals     5 135 diagonals    (when n is 3)
  */
class Solution1 {
    public:
        std::vector<std::vector<std::string> > solveNQueens(int n) {
            std::vector<std::vector<std::string> > res;
            std::vector<std::string> nQueens(n, std::string(n, '.'));
            std::vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
            solveNQueens(res, nQueens, flag_col, flag_45, flag_135, 0, n);
            return res;
        }
    private:
        void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag_col, std::vector<int> &flag_45, std::vector<int> &flag_135, int row, int &n) {
            if (row == n) {
                res.push_back(nQueens);
                return;
            }
            for (int col = 0; col != n; ++col)
                if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
                    flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
                    nQueens[row][col] = 'Q';
                    solveNQueens(res, nQueens, flag_col, flag_45, flag_135, row + 1, n);
                    nQueens[row][col] = '.';
                    flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
                }
        }
};
/*  把上面的三个合并在一个里面，相对于上一个代码简介了一些，但其实并没有什么改进
    But we actually do not need to use three arrays, we just need one.
    Now, when reach [row, col], the subscript of column is col, the subscript of 45\xb0 diagonal is n + row + col
    and the subscript of 135\xb0 diagonal is n + 2 * n - 1 + n - 1 + col - row.
*/
class Solution2 {
    public:
        std::vector<std::vector<std::string> > solveNQueens(int n) {
            std::vector<std::vector<std::string> > res;
            std::vector<std::string> nQueens(n, std::string(n, '.'));
            /*
            flag[0] to flag[n - 1] to indicate if the column had a queen before.
            flag[n] to flag[3 * n - 2] to indicate if the 45\xb0 diagonal had a queen before.
            flag[3 * n - 1] to flag[5 * n - 3] to indicate if the 135\xb0 diagonal had a queen before.
            */
            std::vector<int> flag(5 * n - 2, 1);
            solveNQueens(res, nQueens, flag, 0, n);
            return res;
        }
    private:
        void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag, int row, int &n) {
            if (row == n) {
                res.push_back(nQueens);
                return;
            }
            for (int col = 0; col != n; ++col)
                if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row]) {
                    flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0;
                    nQueens[row][col] = 'Q';
                    solveNQueens(res, nQueens, flag, row + 1, n);
                    nQueens[row][col] = '.';
                    flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1;
                }
        }
};


int main() {
    Solution s;
    int n = 4;
    auto result = s.solveNQueens(n);
    for(auto i : result) {
        for(auto j : i)
            cout<<j<<endl;
        cout<<endl;
    }
}