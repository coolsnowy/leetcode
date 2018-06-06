/**
 * The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:
Input: 1
Output: "1"

Example 2:
Input: 4
Output: "1211"
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
    // my accepted resurcion solution, need 3ms
    string countAndSay1(int n) {
        string result;
        if(n == 1) return "1";
        result = countAndSay1(n - 1);
        string temp = "";
        for(int i = 0; i < result.size(); i++) {
            int num = 1;
            while((i + 1) < result.size() && result[i] == result[i + 1]) {
                i++;
                num++;
            }
            temp += std::to_string(num);
            // temp += '0' + num; // is also right
            temp += result[i];
        }
        return temp;
    }
    // discuss solution, need 3ms
    string countAndSay(int n) {
        if (n == 0) return "";
        string res = "1";
        while (--n) {
            string cur = "";
            for (int i = 0; i < res.size(); i++) {
                int count = 1;
                while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                    count++;
                    i++;
                }
                cur += std::to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
};

int main() {
    Solution s;
    int n = 5;
    cout<<s.countAndSay1(n);
}