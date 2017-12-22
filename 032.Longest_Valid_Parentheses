/**
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <stack>
#include <queue>

using std::priority_queue;
using std::list;
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
    // can't resolve it
    // see the solution, Without extra space [Accepted], the best solution I think, need 6ms
    /*
     * Algorithm

    In this approach, we make use of two counters left and right. First, we start traversing the string from the left towards the right
     and for every '(’ encountered, we increment the left counter and for every ‘)’ encountered, we increment the right counter.
     Whenever left becomes equal to right, we calculate the length of the current valid string and
     keep track of maximum length substring found so far. If right becomes greater than left we reset left and right to 0.

    Next, we start traversing the string from right to left and similar procedure is applied.
Complexity Analysis

    Time complexity : O(n). Two traversals of the string.

    Space complexity : O(1). Only two extra variables left and right are needed.
     */
    int longestValidParentheses(string s) {
        int left = 0, right = 0, longest = 0;
        //from left to right
        for(auto i: s) {
            if(i == '(') left++;
            else if(i == ')')
            {
                right++;
                if(right == left && (left+right)>longest) longest = left + right;
                else if(right > left)  {
                    right = 0;
                    left = 0;
                }
            }
        }
        left = 0;
        right = 0;

        for(int  i = s.size()-1; i>=0; i--) {
            if(s[i] == ')') {
                right++;
            }
            else if(s[i] == '(') {
                left++;
                if (left == right && longest < (left + right)) longest = left + right;
                else if (left > right) {
                    right = 0;
                    left = 0;
                }
            }
        }
        return longest;
    }



    /*
     * Approach #2 Using Dynamic Programming [Accepted], need 9ms
Algorithm

    This problem can be solved by using Dynamic Programming. We make use of a dp array where ith element of dp represents
     the length of the longest valid substring ending at ith index.
     We initialize the complete dp array with 0's. Now, it's obvious that the valid substrings must end with ‘)’.
     This further leads to the conclusion that the substrings ending with ‘(’ will always contain '0' at their corresponding dp indices.
     Thus, we update the dp array only when ‘)’ is encountered.

    To fill dp array we will check every two consecutive characters of the string and if

    1 s[i]=‘)’ and s[i−1]=‘(’, i.e. string looks like ‘‘.......()"⇒

            dp[i]=dp[i−2]+2

    We do so because the ending "()" portion is a valid substring anyhow and leads to an increment of 2 in the length of the
     just previous valid substring's length.

    2 s[i]=‘)’ and s[i−1]=‘)’, i.e. string looks like ‘‘.......))"⇒

    if s[i−dp[i−1]−1]=‘(’ then

        dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2

    The reason behind this is that if the 2nd last ‘)’ was a part of a valid substring (say subs​​ ),
     for the last ‘)’ to be a part of a larger substring, there must be a corresponding starting ‘(’
     which lies before the valid substring of which the 2nd last ‘)’ is a part (i.e. before sub​s​​ ).
     Thus, if the character before sub_s​​​  happens to be ‘(’, we update the dp[i] as an addition of 2 in the length of subs
​​      which is dp[i−1]. To this, we also add the length of the valid substring just before the term "(,sub_s,)" ,
     i.e. dp[i−dp[i−1]−2].
Complexity Analysis

    Time complexity : O(n). Single traversal of string to fill dp array is done.

    Space complexity : O(n). dp array of size n is used.
     */
    int longestValidParentheses1(string s) {
        const size_t len = s.size();
        int* dp = new int[len];
        memset(dp, 0, sizeof(int) * len);
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == '(') dp[i] = 0;
            else if((s[i] == ')' && s[i-1] == '(')) {
                dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
            } else if(s[i] == ')' && s[i-1] == ')' && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i-1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
        }
        int longest = 0;
        for(int i = 0; i<len; i++) {
            if(dp[i]>longest) longest = dp[i];
        }
        delete []dp;
        return longest;
    }



    /*
     * Approach #3 Using Stack [Accepted]， need 9ms
Algorithm

    Instead of finding every possible string and checking its validity,
     we can make use of stack while scanning the given string to check if the string scanned so far is valid,
     and also the length of the longest valid string. In order to do so, we start by pushing −1 onto the stack.

    For every ‘(’ encountered, we push its index onto the stack.

    For every ‘)’ encountered, we pop the topmost element and subtract the current element's index from the top element of the stack,
     which gives the length of the currently encountered valid string of parentheses.
     If while popping the element, the stack becomes empty, we push the current element's index onto the stack.
     In this way, we keep on calculating the lengths of the valid substrings, and return the length of the longest valid string at the end.
Complexity Analysis

    Time complexity : O(n). nn is the length of the given string..

    Space complexity : O(n). The size of stack can go up to n.
     */
    int longestValidParentheses2(string s) {
        std::stack<int> st;
        st.push(-1);
        int longest = 0;
        for(int index = 0; index < s.size(); index++) {
            if(s[index] == '(') {
                st.push(index);
            } else if(s[index] == ')') {
                //始终可以保证stack不空，所以pop之前不需要判断
                st.pop();
                if(st.empty()) st.push(index);
                else {
                    if(longest < index-st.top())
                        longest = index - st.top();
                }
            }
        }
        return longest;
    }
};

int main() {
    Solution s;
    string str = "(()))())(";
    cout<<s.longestValidParentheses2(str)<<endl;

}