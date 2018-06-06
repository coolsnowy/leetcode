/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>

using std::list;
using std::map;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::stack;
using std::vector;

class Solution {
public:
    // my accepted answer 3ms
    // I think it too complexity, the string is only consisted of symobol, no digits or alphabet
    bool isValid(string s) {
        std::vector<char> vec;
        std::vector<char>::size_type i = 0;
        for(size_t num = 0; num<s.size(); num++) {
            if(s[num] == '(' || s[num] =='[' || s[num] == '{' ) {
                vec.push_back(s[num]);
                i++;
            }
                //first time, I ignore this case, lead to the runtime error
            else if((s[num] == ']' || s[num] == ')' || s[num] == '}' )&& vec.empty()) {
                return false;
            } else if(s[num] == ')') {
                if(vec[--i] == '(')
                    vec.pop_back();
            } else if(s[num] == ']') {
                if(vec[--i] == '[')
                    vec.pop_back();
            } else if(s[num] == '}') {
                if(vec[--i] == '{')
                    vec.pop_back();
            }
        }
        if(vec.empty()) {
            return true;
        } else
            return false;
    }
    // solution, alse need 3 ms, only take acount to the symbol, no alphabet or digit
    bool isValid1(string s) {
        std::stack<char> st;
        for (auto c : s) {
            if (c == '(')
                st.push(')');
            else if (c == '{')
                st.push('}');
            else if (c == '[')
                st.push(']');
            else if(!st.empty() && st.top() == c) {
                st.pop();
            }
            else if (st.empty() || st.top() != c) {
                return false;
            }
        }
        return st.empty();

    }
};

int main() {
    Solution s;
    string str = "[]({})";
    cout<<s.isValid1(str);
}