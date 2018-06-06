/**
 * Implement wildcard pattern matching with support for '?' and '*'.

        '?' Matches any single character.
        '*' Matches any sequence of characters (including the empty sequence).

        The matching should cover the entire input string (not partial).

        The function prototype should be:
        bool isMatch(const char *s, const char *p)

        Some examples:
        isMatch("aa","a") → false
        isMatch("aa","aa") → true
        isMatch("aaa","aa") → false
        isMatch("aa", "*") → true
        isMatch("aa", "a*") → true
        isMatch("ab", "?*") → true
        isMatch("aab", "c*a*b") → false

 */
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

class Solution {
public:
    // try to solve it use dynamic programming, but not concise
    // the better solution is as follow: see the discuss solution, only need 57 ms
    bool isMatch(string str, string pattern) {
        int s = 0, p = 0, match = 0, starIndex = -1;
        while(s < str.length()) {
            // match! advance p and s
            if(p < pattern.length() && (str[s] == pattern[p] || pattern[p] == '?')) {
                s++;
                p++;
            } else if(p < pattern.length() && pattern[p] == '*') {
                // * find, only advance pattern
                starIndex = p;
                match = s;
                p++;
            } else if(starIndex != -1) {
                //last element is *, advance str only
                p = starIndex + 1;
                match++;
                s = match;
            } else
                //current pattern is not star, last pattern pointer was not *
                // character do not match
                return false;
        }
        while(p < pattern.length() && pattern[p] == '*') {
            p++;
        }
        return p == pattern.length();
    }
};

int main() {
    Solution s;
    string s1 = "bbb";
    string s2 = "?*";
    cout<<s.isMatch(s1, s2);
}