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
/*
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 */

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		// can't resolve, see the thought, it is easy to store the condition in the m + n  space
		// this problem prohibit the storage, so we need to store the condition in first row and first column
		// the only tricky thing is that matrix[0][0] can't represent the two line, so we need a flag
		if(matrix.empty()) return ;
		bool firstRowHasZero = false;
		int colSize = matrix[0].size();
		for(int i = 0; i < colSize; i++) {
			if(matrix[0][i] == 0) {
				firstRowHasZero = true;
				break;
			}
		}
		int rowSize = matrix.size();
		// not include i = 0, we use bool value to indicate that
		for(int i = 1; i < rowSize; i++) {
			for(int j = 0; j < colSize; j++) {
				if(matrix[i][j] == 0) {
					matrix[0][j] = 0; // represent j col has zero
					matrix[i][0] = 0; // represent i row has zero(not include i = 0)
				}
			}
		}
		// here must be caution, we must decrease j from colSize - 1 to 0
		// because wo set value depend on the first row or first column,
		// we can't destroy the value of matrix [i][0] until we have processed the entire row line
		// i is arbitrary because we process form i = 1
		for(int i = rowSize - 1; i >= 1; i--) {
			for(int j = colSize - 1; j >= 0; j--) {
				if(matrix[i][0] == 0 || matrix[0][j] == 0) {
						matrix[i][j] = 0;
				}
			}
		}
		// used to process the first row with bool indicator
		if(firstRowHasZero) {
			for(int i = 0; i < colSize; i++) {
				matrix[0][i] = 0;
			}
		}
	}
};

int main (int argc, char *argv[]) {
	vector<vector<int>> matrix = {{1, 1, 2, 1},
								  {0, 4, 0, 2},
								  {1, 3, 1, 5}};
	Solution s;
	s.setZeroes(matrix);
	for(auto i : matrix) {
		for(auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}