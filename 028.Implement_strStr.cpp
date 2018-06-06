/**
 * Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>

using std::priority_queue;
using std::list;
using std::map;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    // my accepted answer, need 1169 ms, so bad solution
    int strStr(string haystack, string needle) {
        size_t i = 0;
        if(needle.empty()) {
            return 0;
        }
        for(int i = 0; i<haystack.size(); i++) {
            if(haystack[i] == needle[0]) {
                for(int m = i, j = 0; m<haystack.size() && j < needle.size(); m++, j++) {
                    if(haystack[m] != needle[j])
                        break;
                    if(j == needle.size()-1)
                        return i;
                }
            }
        }
        return -1;
    }

    //better solution, only need 6ms
    int strStr1(string haystack, string needle) {
        for (int i = 0; ; i++) {
            for (int j = 0; ; j++) {
                if (j == needle.length()) return i;
                if (i + j == haystack.length()) return -1;
                if (needle.at(j) != haystack.at(i + j)) break;
            }
        }
    }
};

int main() {
    Solution s;
    string s1 = "slczgw";
    string s2 = "czgq";
    cout<<s.strStr(s1, s2);
}