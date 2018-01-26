/**
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

    You may assume the integer do not contain any leading zero, except the number 0 itself.

    The digits are stored such that the most significant digit is at the head of the list.


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
    std::vector<int> plusOne(std::vector<int>& digits) {
        int size =  digits.size();
        for(int i = size - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                break;
            }
        }
        if(digits[0] == 0) {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};

int main() {
    Solution s;
    std::vector<int> digits {1, 9, 9, 9};
    auto result = s.plusOne(digits);
    for(auto i : result) {
        cout<<i<<'\t';
    }
}