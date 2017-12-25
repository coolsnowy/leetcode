/**
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

 Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <stack>
#include <queue>

using std::priority_queue;
using std::list;
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
    // don't know how to resolve this question
    // see the offical solution
    // accepted, 19ms
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        int row[9][9] = {0}, col[9][9] = {0}, sub[9][9] = {0};
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == '.') continue;
                int elem = board[i][j] - '0' - 1;
                // sub: row 0-2, col 0-2 ->0
                //      row 0-2, col 3-5 ->1
                //      row 0-2, col 6-8 ->2
                //      row 3-5, col 0-2 ->3
                //      row 6-8, col 0-2 ->6
                //      row 6-8, col 6-8 ->8
                if(row[elem][j] == 1 || col[i][elem] == 1 || sub[i / 3 * 3 + j / 3][elem] == 1) {
                    return false;
                } else {
                    row[elem][j] = 1;
                    col[i][elem] = 1;
                    sub[i / 3 * 3 + j / 3][elem] = 1;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> a {{'.','8','7','6','5','4','3','2','1'},{'2','.','.','.','.','.','.','.','.'},{'3','.','.','.','.','.','.','.','.'},{'4','.','.','.','.','.','.','.','.'},{'5','.','.','.','.','.','.','.','.'},{'6','.','.','.','.','.','.','.','.'},{'7','.','.','.','.','.','.','.','.'},{'8','.','.','.','.','.','.','.','.'},{'9','.','.','.','.','.','.','.','.'}};
    bool result = s.isValidSudoku(a);
    cout<<result<<endl;
}