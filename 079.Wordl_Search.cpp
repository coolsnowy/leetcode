#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
 * 	 Given a 2D board and a word, find if the word exists in the grid.

	 The word can be constructed from letters of sequentially adjacent cell,
	 where "adjacent" cells are those horizontally or vertically neighboring.
	 The same letter cell may not be used more than once.

	Example:
		board =
		[
		  ['A','B','C','E'],
		  ['S','F','C','S'],
		  ['A','D','E','E']
		]
	Given word = "ABCCED", return true.
	Given word = "SEE", return true.
	Given word = "ABCB", return false.
 */

class Solution {
	// difficult solution, see the thought
	// use the recursion and backtracking
public:
	bool exist(vector<vector<char> > &board, string word) {
		m = board.size();
		n = board[0].size();
		for(int x = 0; x < m; x++)
			for(int y = 0; y < n; y++)
			{
				if(isFound(board, word.c_str(), x, y))
					return true;
			}
		return false;
	}
private:
	int m;
	int n;
	bool isFound(vector<vector<char> > &board, const char* w, int x, int y) {
		if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '\0' || *w != board[x][y])
			return false;
		if(*(w+1) == '\0')
			return true;
		char t = board[x][y];
		board[x][y] = '\0';
		if(isFound(board, w + 1, x - 1, y) || isFound(board, w + 1, x + 1, y) || isFound(board, w + 1, x, y-1) || isFound(board, w + 1, x, y + 1))
			return true;
		board[x][y] = t;
		return false;
	}
};

int  main() {
	int m = 3, n = 4;
	vector<vector<char>> board {{'A','B','C','E'},
								{'S','F','C','S'},
								{'A','D','E','E'}};
	string s = "ABCCED";
	Solution soltuion;
	auto result = soltuion.exist(board, s);
	cout << result << endl;
}