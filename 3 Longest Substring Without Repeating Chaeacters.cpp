/**
*Given a string, find the length of the longest substring without repeating characters.
*
*Examples:
*
*Given "abcabcbb", the answer is "abc", which the length is 3.
*
*Given "bbbbb", the answer is "b", with the length of 1.
*
*Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*
**/

/*

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
 // look the answer ,donot know how to work out it 
 // still don't know why !!!
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256,-1);
		int maxlen = 0,start = -1;
		for(int i = 0; i != s.length(); i++) {
			if(dict[[s[i]] > start)
				start = dict[s[i]];
			dict[s[i]] = i;
			maxlen = max(maxLen,i-start);
		}
		return maxlen;
    }
};