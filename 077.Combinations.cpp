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
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
 */

class Solution {
public:
	// don't know how to solve the problem
	// see the thought
	/*
	 * I should study this thought about backtracking
	 * my idea is using backtracking ,every time I push a number into vector,then I push a bigger one into it;
	then i pop the latest one,and push a another bigger one...
	and if I has push k number into vector,I push this into result;
	 */
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > res;
		if(n < k)return res;
		vector<int> temp;
		combine(res, temp, 0, 0, n, k);
		return res;
	}

	void combine(vector<vector<int> > &res,vector<int> &temp, int start, int num, int n, int k){
		if(num == k){
			res.push_back(temp);
			return;
		}
		for(int i = start; i < n; i++){
			temp.push_back(i + 1);
			combine(res,temp, i + 1, num + 1, n, k);
			temp.pop_back();
		}
	}

	// althought quicker, we should still study backtracking method
	// a quicker algorithm, excellent solution
	vector<vector<int>> combine1(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i;
			else if (i == k - 1) result.push_back(p);
			else {
				++i;
				p[i] = p[i - 1];
			}
		}
		return result;
	}

	// explain the upper code
	vector<vector<int>> combine1explain(int n, int k) {
		vector<vector<int>> ans;
		vector<int> c(k, 0); // vector of length k, all 0s
		int i = 0;
		while (i >= 0) {
			// Increment element at index i
			c[i]++;
			cout << "Incremented element at index " << i << endl;
			cout << toString(c) << endl;

			/* Move index to the left if the element
			 * at index i has exceeded n.
			 */
			if (c[i] > n) {
				i--;
				cout << "n exceeded at " << i+1 << ", moving index to the left" << endl;
			}

				/* If the index is at the end of the vector
				 * c, then (because the other conditions are
				 * obeyed), we know we have a valid combination,
				 * so push it to our ans vector<vector<>>
				 */
			else if (i == k - 1) {
				ans.push_back(c);
				cout << "Combination found!" << endl;
				cout << "Added " << toString(c) << " as an answer!" << endl;
				cout << " ************************************************" << endl;
			}

				/* Move index to the right and set the
				 * element at that index equal to the
				 * element at the previous index.
				 *
				 * Because of the increment at the beginning
				 * of this while loop, we ensure that the
				 * element at this index will be at least
				 * one more than its neighbor to the left.
				 */
			else {
				i++;
				c[i] = c[i - 1];
				cout << "Moved index to the right, and copied the value"
					 << " from the left" << endl;
				cout << toString(c) << endl;
			}
		}
		return ans;
	}

	string toString(vector<int> v) {
		string ans = "[";
		for (int i: v) {
			ans += i + '0';
			ans += ", ";
		}
		ans = ans.substr(0, ans.length() - 2) + "]";
		return ans;
	}

	string toString(vector<vector<int>> v) {
		string ans = "[";
		for (vector<int> i: v) {
			ans += toString(i);
			ans += ", ";
		}
		ans = ans.substr(0, ans.length() - 2) + "]";
		return ans;
	}
};

int main (int argc, char *argv[]) {
	Solution s;
	auto result = s.combine2explain(4, 2);
	for(auto i : result) {
		for(auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}