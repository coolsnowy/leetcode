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
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

 */


class Solution {
public:
	// do it by myself
	// according the thought of 77th problems, done it easy!
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int> > res;
	 	if(nums.empty()) return res;
	 	vector<int> temp;
	 	const int size = nums.size();
	 	combine(res, temp, nums, size, 0);
	 	return res;
	}
	void combine(vector<vector<int> > &res,vector<int> &temp, const vector<int>& nums, const int size, int start){
		res.push_back(temp);
	 	for(int i = start; i < size; i++){
				temp.push_back(nums[i]);
				combine(res, temp, nums, size, i + 1);
				temp.pop_back();
	 	}
	}
};

int main (int argc, char *argv[]) {
	Solution s;
	vector<int> v { 1, 2, 3};
	auto result = s.subsets(v);
	for(auto i : result) {
		for(auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}