/**
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

    If the last word does not exist, return 0.

    Note: A word is defined as a character sequence consists of non-space characters only.

    Example:

    Input: "Hello World"
    Output: 5
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
    int lengthOfLastWord(string s) {
        int len = s.size() - 1;
        while(len >= 0 && s[len] == ' ') {
            len--;
        }
        int result = 0;
        while(len >= 0 && s[len] != ' ') {
            len--;
            result++;
        }
        return result;
    }
};

int main() {
    Solution s;
    string str = "Hello _World  ";
    auto result = s.lengthOfLastWord(str);
    cout<<result;
}