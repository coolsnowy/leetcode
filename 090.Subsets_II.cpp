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
#include <functional>


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
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]


 */

class Solution {
public:
	// a important point in the for loop
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int> > res;
	 	if(nums.empty()) return res;

	 	vector<int> temp;
	 	// this step is essential
		std::sort(nums.begin(), nums.end());

	 	const int size = nums.size();
	 	combine(res, temp, nums, size, 0);
	 	return res;
	}
	void combine(vector<vector<int> > &res,vector<int> &temp, const vector<int>& nums, const int size, int start){
		res.push_back(temp);

	 	for(int i = start; i < size; i++){
	 		// this statement is so important, only can use the same element at the first time use it
			// second time use it, skip it
	 		if(i > start && nums[i] == nums[i - 1]) {
	 			continue;
	 		}
			temp.push_back(nums[i]);
			combine(res, temp, nums, size, i + 1);
			temp.pop_back();

	 	}
	}

	// can't understand the following solution
	/*
	 * To solve this problem, it is helpful to first think how many subsets are there.
	 * If there is no duplicate element, the answer is simply 2^n, where n is the number of elements.
	 * This is because you have two choices for each element, either putting it into the subset or not.
	 * So all subsets for this no-duplicate set can be easily constructed:
num of subset

(1 to 2^0) empty set is the first subset
(2^0+1 to 2^1) add the first element into subset from (1)
(2^1+1 to 2^2) add the second element into subset (1 to 2^1)
(2^2+1 to 2^3) add the third element into subset (1 to 2^2)
....
(2^(n-1)+1 to 2^n) add the nth element into subset(1 to 2^(n-1))
Then how many subsets are there if there are duplicate elements?
	 We can treat duplicate element as a spacial element. For example, if we have duplicate elements (5, 5),
	 instead of treating them as two elements that are duplicate, we can treat it as one special element 5,
	 but this element has more than two choices: you can either NOT put it into the subset, or put ONE 5 into the subset,
	 or put TWO 5s into the subset. Therefore, we are given an array (a1, a2, a3, ..., an) with each of them appearing (k1, k2, k3, ..., kn) times,
	 the number of subset is (k1+1)(k2+1)...(kn+1). We can easily see how to write down all the subsets similar to the approach above.
	 */
	vector<vector<int> > subsetsWithDup1(vector<int> &S) {
		vector<vector<int> > totalset = {{}};
		sort(S.begin(), S.end());
		for(int i = 0; i < S.size(); ){
			int count = 0; // num of elements are the same
			while(count + i < S.size() && S[count + i] == S[i])  count++;
			int previousN = totalset.size();
			for(int k = 0; k < previousN; k++){
				vector<int> instance = totalset[k];
				for(int j = 0; j < count; j++){
					instance.push_back(S[i]);
					totalset.push_back(instance);
				}
			}
			i += count;
		}
		return totalset;
	}
};

int main (int argc, char *argv[]) {
	Solution s;
	vector<int> v { 1, 2, 3};
	auto result = s.subsetsWithDup1(v);
	for(auto i : result) {
		for(auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}