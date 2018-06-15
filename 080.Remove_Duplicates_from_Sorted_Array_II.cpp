#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
 * Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
	Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
	Given nums = [1,1,1,2,2,3],
	Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
	It doesn't matter what you leave beyond the returned length.
Example 2:
	Given nums = [0,0,1,1,1,1,2,3,3],
	Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
	It doesn't matter what values are set beyond the returned length.
Clarification:

	Confused why the returned value is an integer but your answer is an array?
	Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

	Internally you can think of this:
	// nums is passed in by reference. (i.e., without making a copy)
	int len = removeDuplicates(nums);
	// any modification to nums in your function would be known by the caller.
	// using the length returned by your function, it prints the first len elements.
	for (int i = 0; i < len; i++) {
    	print(nums[i]);
	}
 */
class Solution {
public:

	// my accepted solution, beats 85%
	int removeDuplicates(vector<int>& nums) {
		auto first = 0, second = 0;
		// first pointer point to the position be inserted
		// second pointer point to the position searched now
		auto last = nums.size();
		int num = 0;
		while(second < last) {
			if(second > 0 && nums[second] == nums[second - 1]) {
				num++;
				if(num <= 2) {
					nums[first++] = nums[second++];
				} else {
					while(nums[second] == nums[second - 1]) {
						second++;
					}
					num = 1;
				}
			} else {
				num = 1;
				nums[first++] =  nums[second++];
			}
		}
		return first;
	}

	// offical easiest solution
	int removeDuplicates1(vector<int>& nums) {
		int i = 0;
		for (auto n : nums)
			if (i < 2 || n > nums[i-2])
				nums[i++] = n;
		return i;
	}
};


int main() {
	vector<int> vec{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	Solution solution;
	auto result = solution.removeDuplicates1(vec);
	for(int i = 0; i < result; i++) {
		cout << vec[i] << '\t';
	}
	cout << endl;
}