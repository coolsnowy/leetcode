// leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using  std::unordered_map;
using  std::vector;

class Solution {
public:
		vector<int> twoSum(vector<int>& nums, int target) {
		auto it1 = nums.cbegin();
		auto it2 = it1 + 1;
		for (; it1 != nums.cend() - 1; it1++){
			for (it2 = it1 + 1; it2 != nums.cend(); it2++){
				if (*it1 + *it2 == target)
					return vector<int>{it1 - nums.cbegin(), it2 - nums.cbegin()};
			}
		}
		}
	};

//N^2
/*
Accepted C++ O(N) Solution
*/
vector<int> twosun(vector<int> &numbers, int target) {
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];
		if (hash.find(numberToFind) != hash.cend()) {
			//indices begin from 1
			result.push_back(hash[numberToFind] + 1);
			result.push_back(i + 1);
			return result;
		}
		//not found,put it in the map
		hash[numbers[i]] = i;
	}
	return result;

}