/**
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

    For example,
    Given n = 3,

    You should return the following matrix:
    [
     [ 1, 2, 3 ],
     [ 8, 9, 4 ],
     [ 7, 6, 5 ]
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
    // my accepted solution, need 4 ms, and the discuss solution is also like this
    // Be careful, in spiral Matrix I, I add the condition if rowBegin <= rowEnd and colBegin <= colEnd
    // otherwise some element will be printed over one times, but here we don't need the judge condition
    //because in Spiral Matrix I, the matrix is m*n, but here is n*n, the situation will not occur
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> result(n, std::vector<int> (n, 0));
        if(n == 0) return result;
        int rowBegin = 0, rowEnd = n - 1, colBegin = 0, colEnd = n - 1, num = 0;
        while(num <= n * n && rowBegin <= rowEnd && colBegin <= colEnd) {
            for(int i = colBegin; i <= rowEnd; i++)
                result[rowBegin][i] = ++num;
            rowBegin++;
            for(int i = rowBegin; i <= colEnd; i++)
                result[i][colEnd] = ++num;
            colEnd--;
            for(int i = colEnd; i >= colBegin; i--)
                result[rowEnd][i] = ++num;
            rowEnd--;
            for(int i = rowEnd; i >= rowBegin; i--)
                result[i][colBegin] = ++num;
            colBegin++;
        }
        return result;
    }
};

int main() {
    Solution s;
    auto result = s.generateMatrix(9);
    for(auto i : result) {
        for(auto j : i)
            cout<<j<<'\t';
        cout<<'\n';
    }
}