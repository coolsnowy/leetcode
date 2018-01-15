/**
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

    For example,
    Given the following matrix:

    [
     [ 1, 2, 3 ],
     [ 4, 5, 6 ],
     [ 7, 8, 9 ]
    ]
    You should return [1,2,3,6,9,8,7,4,5].
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
    // my accepted solution, need about 3ms
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        if(matrix.empty()) return std::vector<int>();
        int rowBegin = 0, colBegin = 0, rowEnd = matrix.size() - 1, colEnd = matrix[0].size() - 1;
        std::vector<int> result;
        while(rowBegin <= rowEnd && colBegin <= colEnd) {
            for(int i = colBegin; i <= colEnd; i++) {
                result.push_back(matrix[rowBegin][i]);
            }
            rowBegin++;
            for(int i = rowBegin; i <= rowEnd; i++) {
                result.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            // 没有这句判断条件的话，输入为{1，2，3}会出错
            if(rowBegin > rowEnd) break;
            for(int i = colEnd; i >= colBegin; i--) {
                result.push_back(matrix[rowEnd][i]);
            }
            rowEnd--;
            //没有这句判断条件的话，输入为{{1}，{2}，{3}}会出错
            if(colBegin > colEnd) break;
            for(int i = rowEnd; i >= rowBegin; i--) {
                result.push_back(matrix[i][colBegin]);
            }
            colBegin++;
        }
        return result;
    }
    //简洁一些，short is better
    //You should use an array of direction offsets
    // And you don’t need to check the border because rows and cols always decrease. Here is my C++ code:

    std::vector<int> spiralOrder1(std::vector<std::vector<int>> &matrix) {
        std::vector<int> result;
        if (matrix.empty()) return result;
        result = matrix[0];  // first row, no need to check the first row
        int dirs[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};  // direction offsets
        int d = 0;  // direction index
        int m = matrix.size();
        int n = matrix[0].size();
        // pos[0] represent the row, pos[1] represent column
        int pos[2] = {0, n - 1};  // start from the top right corner
        int i = (m - 1) * n;  // number of the rest numbers
        while (i > 0) {
            for (int j = 1; j < m; j++) {
                i--; // 减少一个元素
                pos[0] += dirs[d][0]; pos[1] += dirs[d][1];
                result.push_back(matrix[pos[0]][pos[1]]);
            }
            m--;  // decrease the size of row or column
            std::swap(m, n);  // switch between horizontal and vertical mode
            d = (d + 1) % 4;  // loop between direction offsets
        }
        return result;
    }
};


int main() {
    Solution s;
    std::vector<std::vector<int>> matrix {{1}, {2}, {3}};
    auto result = s.spiralOrder1(matrix);
    for(auto i : result) {
        cout<<i<<'\t';
    }
}