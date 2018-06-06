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
 * Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent,
 * with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's,
 then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?

 */
class Solution {
public:
	// my accepted solution, beats 100%
	void sortColors(vector<int>& nums) {
		if(nums.empty()) return;
		// firstIndex point to the first element not 0
		// secondIndex point to the element one before 2
		int size = nums.size();
		int firstIndex = 0, secondIndex = size - 1;
		while(firstIndex < nums.size() && nums[firstIndex] == 0)
			firstIndex++;
		while(secondIndex >= 0 && nums[secondIndex] == 2)
			secondIndex--;
		int i = firstIndex;
		while(i <= secondIndex && i < size) {
			if(nums[i] == 0) {
				nums[i] = nums[firstIndex];
				nums[firstIndex] = 0;
				firstIndex++;
			} else if(nums[i] == 2) {
				nums[i] = nums[secondIndex];
				nums[secondIndex] = 2;
				while(secondIndex >= 0 && nums[secondIndex] == 2)
					secondIndex--;
				// be caution here, because after execution, we will increment i
				// but if i now point to zero, it need to be processed to swap to the first part
				if(nums[i] == 0) {
					nums[i] = nums[firstIndex];
					nums[firstIndex] = 0;
					firstIndex++;
				}
			}
			i++;
		}
	}

	// offical solution, have same compexity as mine, but seem shorter
	void sortColors1(vector<int> &A) {
		int n = A.size();
		int second = n - 1, zero = 0;
		for (int i = 0; i <= second; i++) {
			while (A[i] == 2 && i < second)
				std::swap(A[i], A[second--]);
			while (A[i] == 0 && i > zero)
				std::swap(A[i], A[zero++]);
		}
	}
};

int main (int argc, char *argv[]) {
	vector<int> nums{1, 2, 0};
	Solution s;
	s.sortColors1(nums);
	for(auto i: nums) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}