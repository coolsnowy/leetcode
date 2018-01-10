/**
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
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
    // can't solve the problem，see the discuss solution

    /* 这是根据java改过来的密码，应该用下面的方法，才是c++！！
     * Remember how we do multiplication?

        Start from right to left, perform multiplication on every pair of digits, and add them together.
        Let’s draw the process! From the following draft, we can immediately conclude:
        see pages :
            https://drscdn.500px.org/photo/130178585/m=2048/300d71f784f679d5e70fadda8ad7d68f
        `num1[i] * num2[j]` will be placed at indices `[i + j`, `i + j + 1]`
     *
     *  need 14ms
     */
     string multiply1(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        std::vector<int> pos(m + n, 0 );
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + pos[p2];

                pos[p1] += sum / 10;
                pos[p2] = (sum) % 10;
            }
        }

        string result = "";
        for(int p : pos) if(!(result.size() == 0 && p == 0)) result += (static_cast<char> (p) + 48);
        return result.size() == 0 ? "0" : result;
    }


    /* 和上面的思路一样，但是使用的是c++版本！包括c++的algorithm，值得学习！
     * This is the standard manual multiplication algorithm.
     * We use two nested for loops, working backward from the end of each input number.
     * We pre-allocate our result and accumulate our partial result in there.
     * One special case to note is when our carry requires us to write to our sum string outside of our for loop.

    At the end, we trim any leading zeros, or return 0 if we computed nothing but zeros.
     */
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');

        for (int i = num1.size() - 1; 0 <= i; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; 0 <= j; --j) {
                int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            sum[i] += carry;
        }

        size_t startpos = sum.find_first_not_of("0");
        if (string::npos != startpos) {
            return sum.substr(startpos);
        }
        
        return "0";
    }
};

int main() {
    Solution s;
    string s1 = "3";
    string s2 = "12";
    string result = s.multiply1(s1, s2);
    cout<<result<<endl;
    cout<<static_cast<char> (49);
}