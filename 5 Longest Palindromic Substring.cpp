/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

see tha solution approach#3,4,understand the answer
https://leetcode.com/problems/longest-palindromic-substring/solution/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int expandAroundCenter(string s, int left, int right) {
	// it is important that left can equal zero but right can't equal size()
	while (left >= 0 && right < s.size() && s[left] == s[right]) {
		left--;
		right++;
	}
	return right - left - 1;//jump the while loop when left != right ,so lendth = left-right + 1 - 2;
}

string longestPalindrome(string s) {
	int len = 0, start = 0, end = 0;
	for (int i = 0; i < s.size(); i++) {
		//the palindromic string only have two situation ,such as "aba" or "abba",so expand the result by i,i and i,i+1
		int len1 = expandAroundCenter(s, i, i);
		int len2 = expandAroundCenter(s, i, i + 1);
		len = len1 > len2 ? len1 : len2;
		if (len > end - start) {
			//use bab and baab ,judge why minus one
			start = i - (len - 1) / 2;
			end = i + len / 2;// the last one
			//end = start + len - 1;
		}
	}
	return s.substr(start, end-start+1);
}

int main()
{
	string s = "abcber";
	cout << longestPalindrome(s) << endl;
}
