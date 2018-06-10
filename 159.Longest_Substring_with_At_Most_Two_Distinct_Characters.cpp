#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "limits.h"

using namespace std;

class Solution {
public:
	/*
	 * Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
		For example, Given s = “eceba”, T is "ece" which its length is 3.
	 */
	int lengthOfLongestSubstringTwoDistinct(string s) {
		vector<int> map(128, 0);
		int start = 0, end = 0, maxLen = 0, maxHead = 0;
		auto size = s.size();
		int count = 0;
		while(end < size) {
//			count represent the count of the distinct word
			if(map[s[end]] == 0) {
				count++;
			}
			map[s[end]]++;
			end++;
			// the count should smaller or equal than 2
			// now is invalid, we need channge the conut until it becomes valid. and then update the maximum length
			while(count > 2) {
				if(map[s[start]] == 1) {
					// follow decrement will make this character deleted in the result string, so count--
					count--;
				}
				map[s[start]]--;
				start++;
			}
			// now satisfy the requirement, so we update the maximum length has at most two distinct character
			if(end - start > maxLen) {
				maxHead = start;
				maxLen = end - start;
			}
		}
		cout << s.substr(maxHead, maxLen) << endl;
		return maxLen;

	}
};

int main() {
	Solution solution;
	string s = "eceba";
	auto result = solution.lengthOfLongestSubstringTwoDistinct(s);
	cout << result;
}

