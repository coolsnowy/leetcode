#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
	// difficult question, do not know how to solve it
	// see the offical solution
	/*
	 * I will first give the solution then show you the magic template.

		The code of solving this problem is below.
	 */
	string minWindow(string s, string t) {
		vector<int> map(128,0);
		for(auto c: t) map[c]++;
		int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
		while(end < s.size()){
			if(map[s[end++]]-- > 0) counter--; //in t
			while(counter == 0){ //valid
				if(end - begin < d)  d = end - (head = begin);
				if(map[s[begin++]]++ == 0) counter++;  //make it invalid
			}
		}
		return d == INT_MAX? "":s.substr(head, d);
	}
	/*
	 *  Let me explain this algorithm.

	1. Use two pointers: start and end to represent a window.
	2. Move end to find a valid window.
	3. When a valid window is found, move start to find a smaller window.
	To check if a window is valid, we use a map to store (char, count) for chars in t.
		 And use counter for the number of chars of t to be found in s. The key part is m[s[end]]--;.
		 We decrease count for each char in s. If it does not exist in t, the count will be negative.

	To really understand this algorithm, please see my code which is much clearer, because there is no code like if(map[s[end++]]++>0) counter++;.
	 */
	string minWindow1(string s, string t) {
		vector<int> m(128, 0); // 128 ASCII
		// Statistic for count of char in t
		for (auto c : t) m[c]++;
		// counter represents the number of chars of t to be found in s.
		size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
		size_t size = s.size();

		// Move end to find a valid window.
		while (end < size) {
			// If char in s exists in t, decrease counter
			if (m[s[end]] > 0)
				counter--;
			// Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
			m[s[end]]--;
			end++;
			// When we found a valid window, move start to find smaller window.
			while (counter == 0) {
				if (end - start < minLen) {
					minStart = start;
					minLen = end - start;
				}
				// if char doesn't exist,its value in m array should be negative( < 0)
				// When char exists in t, increase counter.
				if (m[s[start]] >= 0)
					counter++;
				m[s[start]]++;
				start++;

			}
		}
		if (minLen != INT_MAX)
			return s.substr(minStart, minLen);
		return "";
	}

	/*
	 * Here comes the template.

		For most substring problem, we are given a string and need to find a substring of it which satisfy some restrictions.
	 	A general way is to use a hashmap assisted with two pointers. The template is given below.
	 */
	/*
	 * todo
	int findSubstring(string s){
		vector<int> map(128,0);
		int counter; // check whether the substring is valid
		int begin=0, end=0; //two pointers, one point to tail and one  head
		int d; //the length of substring

		for() {  initialize the hash map here  }

		while(end<s.size()){

			if(map[s[end++]]-- ?){   modify counter here  }

			while( counter condition ){

				 update d here if finding minimum

				increase begin to make it invalid/valid again

				if(map[s[begin++]]++ ?){ modify counter here }
			}

			update d here if finding maximum
		}
		return d;
	}
	*/

	/*
	 * One thing needs to be mentioned is that when asked to find maximum substring,
	 * we should update maximum after the inner while loop to guarantee that the substring is valid.
	 * On the other hand, when asked to find minimum substring, we should update minimum inside the inner while loop.

		The code of solving Longest Substring with At Most Two Distinct Characters is below:
	 int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> map(128, 0);
        int counter=0, begin=0, end=0, d=0;
        while(end<s.size()){
            if(map[s[end++]]++==0) counter++;
            while(counter>2) if(map[s[begin++]]--==1) counter--;
            d=max(d, end-begin);
        }
        return d;
    }

	The code of solving Longest Substring Without Repeating Characters is below:

	Update 01.04.2016, thanks @weiyi3 for advise.

	int lengthOfLongestSubstring(string s) {
			vector<int> map(128,0);
			int counter=0, begin=0, end=0, d=0;
			while(end<s.size()){
				if(map[s[end++]]++>0) counter++;
				while(counter>0) if(map[s[begin++]]-->1) counter--;
				d=max(d, end-begin); //while valid, update d
			}
			return d;
		}
	 */
};

int main() {
	Solution solution;
	string s = "slc is a good man";
	string t = "sa";
	auto result = solution.minWindow1(s, t);
	cout << result;
}

