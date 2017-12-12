/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

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
    // don't know how to resolve it, fuck
    
    // see the solution 1, backtracking solution
    // crazing, 0ms
    // algorithm The idea here is to only add '(' and ')' that we know will guarantee us a solution (instead of adding 1 too many close).
    // Once we add a '(' we will then discard it and try a ')' which can only close a valid '('. Each of these steps are recursively called.
    std::vector<string> generateParenthesis(int n) {
        std::vector<string> vec;
        backtrack(vec,"",0,0,n);
        return vec;
    }
    // 这个递归相当于二叉树往下伸展出所有的结果，然后最终所有的结果回溯回来
    void backtrack(std::vector<string> &vec, string str, int open, int close, int max) {
        if(str.size() == max*2) {
            vec.push_back(str);
            return;
        }
        if(open < max) {
            backtrack(vec, str+"(", open+1, close, max);
        }
        if(close < open) {
            backtrack(vec, str+")", open, close+1, max);
        }
    }

    // Solution 2, 3ms
    // Algorithm: The idea is intuitive. Use two integers to count the remaining left parenthesis (n) and the right parenthesis (m) to be added.
    // At each function call add a left parenthesis if n >0 and add a right parenthesis if m>0.
    // Append the result and terminate recursive calls when both m and n are zero.
    std::vector<string> generateParenthesis2(int n) {
        std::vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(std::vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }

};

int main() {
    Solution s;
    auto result = s.generateParenthesis2(3);
    for(auto i : result) {
        cout<<i<<endl;
    }
    cout<<endl;
    return 0;
}