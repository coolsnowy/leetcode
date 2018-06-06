/**
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.
    For example,

    Consider the following matrix:

    [
      [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]
    ]
    Given target = 3, return true.
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
    // my accepted solution, need about 12 ms
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if(matrix.empty()) return 0;
        int lo = 0, hi = matrix.size() - 1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(mid == matrix.size() - 1) {
                lo = mid;
                break;
            }
            if(matrix[mid][0] > target) hi = mid - 1;
            else if(matrix[mid][0] < target) {
                if (matrix[mid + 1][0] > target)
                {
                    lo = mid;
                    break;
                }
                else {
                    lo = mid + 1;
                }
            }
            else return true;
        }
        int row = lo;
        lo = 0; hi = matrix[row].size() - 1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(matrix[row][mid] > target) hi = mid - 1;
            else if(matrix[row][mid] < target) lo = mid + 1;
            else return true;
        }
        return false;
    }
    /*
     * discuss solution， also need 12 ms, but shorter is better, actuall maybe my solution is better, reason is follow!
     * the disadvantage is that the m*n maybe overflow where my solution is not
     * Use binary search.
     * n * m matrix convert to an array => matrix[x][y] => a[x * m + y]
     * an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];
    */
    bool searchMatrix1(std::vector<std::vector<int> > &matrix, int target) {
        if(matrix.empty()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r){
            int mid = (l + r) / 2;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else if (matrix[mid / m][mid % m] > target)
                r = mid - 1;
            else return true;
        }
        return false;
    }

};

int main() {
    Solution s;
    std::vector<std::vector<int>> matrix {  {1,   3,  5,  7},
                                            {10, 11, 16, 20},
                                            {23, 30, 34, 50} };
    auto result = s.searchMatrix1(matrix, 50);
    cout<<result;

}