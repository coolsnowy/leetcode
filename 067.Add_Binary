/**
 * Given two binary strings, return their sum (also a binary string).

        For example,
        a = "11"
        b = "1"
        Return "100".
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
    // my accepted solution, need 5ms
    // cost too much time for the detail about the problem
    string addBinary(string a, string b) {
        if(a.empty()) return b;
        if(b.empty()) return a;
        if(a.length() < b.length()) std::swap(a, b);
        int aSize = a.length(), bSize = b.length();
        int carry = 0, i = 1;
        for(i = 1; i <= bSize; i++) {
            if(carry == 1 && a[aSize - i] == '1' && b[bSize - i] == '1') {
                a[aSize - i] = '1';
            } else if((a[aSize - i] == '1' && b[bSize - i] == '1')|| (carry == 1 && (a[aSize - i] == '1' || b[bSize - i] == '1'))) {
                a[aSize - i] = '0';
                carry = 1;
            } else {
                a[aSize - i] = a[aSize - i] + b[bSize - i] + carry - 48;
                carry = 0;
            }
        }
        if(carry == 1) {
            if(a[aSize - i] == '0') {
                a[aSize - i] = '1';
            } else {
                while (a[aSize - i] == '1' && i <= aSize) {
                    a[aSize - i] = '0';
                    i++;
                }
                if (i > aSize) a.insert(a.begin(), 1, '1');
                else a[aSize - i] = '1';
            }
        }
        return a;
    }
    // discuss solution, concise , need about 4ms
    string addBinary1(string a, string b)
    {
        string s = "";
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            // >= 优先级高于 ？：高于 +=
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s; // 相当于插入在前面
            c /= 2;
        }

        return s;
    }
};
int main() {
    Solution s;
    string a = "101111";
    string b = "10";
    auto result = s.addBinary1(a, b);
    cout<<result;
}