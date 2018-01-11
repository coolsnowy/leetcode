/**
 * You are given an n x n 2D matrix representing an image.

        Rotate the image by 90 degrees (clockwise).

        Note:
        You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

        Example 1:

        Given input matrix =
        [
          [1,2,3],
          [4,5,6],
          [7,8,9]
        ],

        rotate the input matrix in-place such that it becomes:
        [
          [7,4,1],
          [8,5,2],
          [9,6,3]
        ]
        Example 2:

        Given input matrix =
        [
          [ 5, 1, 9,11],
          [ 2, 4, 8,10],
          [13, 3, 6, 7],
          [15,14,12,16]
        ],

        rotate the input matrix in-place such that it becomes:
        [
          [15,13, 2, 5],
          [14, 3, 4, 1],
          [12, 6, 8, 9],
          [16, 7,10,11]
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
    // my answer need 6ms, BUT!!!!!! 没卵用
    // but it's not accept the requirement because it use extra space
    void rotate(std::vector<std::vector<int>>& matrix1) {
        if(matrix1.empty()) return;
        auto matrix = matrix1;
        int row = matrix.size(), col = matrix[0].size();
        for(int i = 0; i < row;i++) {
            for(int j = 0; j < col; j++) {
                matrix1[j][row - 1 - i] = matrix[i][j];
            }
        }
    }
    // better solution
    /*
     * clockwise rotate
     * first reverse up to down, then swap the symmetry
     * 1 2 3     7 8 9     7 4 1
     * 4 5 6  => 4 5 6  => 8 5 2
     * 7 8 9     1 2 3     9 6 3
    */
    // need 6 ms
    void rotate1(std::vector<std::vector<int> > &matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                std::swap(matrix[i][j], matrix[j][i]);
        }
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.rotate1(matrix);
    for(auto i : matrix) {
        for(auto j : i) {
            cout<<j<<'\t';
        }cout<<'\n';
    }
}