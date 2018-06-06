/**
 * Validate if a given string is numeric.

        Some examples:
        "0" => true
        " 0.1 " => true
        "abc" => false
        "1 a" => false
        "2e10" => true
        Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

        Cannot agree more and I feel I have a totally different opinion on what can be called a number(cry)

        I will share out the test cases I have in hope to help you understand what OJ define as a “number”.

            test(1, "123", true);
            test(2, " 123 ", true);
            test(3, "0", true);
            test(4, "0123", true);  //Cannot agree
            test(5, "00", true);  //Cannot agree
            test(6, "-10", true);
            test(7, "-0", true);
            test(8, "123.5", true);
            test(9, "123.000000", true);
            test(10, "-500.777", true);
            test(11, "0.0000001", true);
            test(12, "0.00000", true);
            test(13, "0.", true);  //Cannot be more disagree!!!
            test(14, "00.5", true);  //Strongly cannot agree
            test(15, "123e1", true);
            test(16, "1.23e10", true);
            test(17, "0.5e-10", true);
            test(18, "1.0e4.5", false);
            test(19, "0.5e04", true);
            test(20, "12 3", false);
            test(21, "1a3", false);
            test(22, "", false);
            test(23, "     ", false);
            test(24, null, false);
            test(25, ".1", true); //Ok, if you say so
            test(26, ".", false);
            test(27, "2e0", true);  //Really?!
            test(28, "+.8", true);
            test(29, " 005047e+6", true);  //Damn = =|||
        Here is the final Regex I got based on their definition

        Pattern.matches("(\\\\+|-)?(\\\\d+(\\\\.\\\\d*)?|\\\\.\\\\d+)(e(\\\\+|-)?\\\\d+)?", s);
        But I thought my original one should be more rigorous!

        Pattern.matches("-?(([1-9]{1}+\\\\d*|0)(\\\\.\\\\d+)?|\\\\.\\\\d+)(e-?[1-9]{1}+\\\\d*)?", s);
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

#include <boost/algorithm/string.hpp>

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
    // damn question, see the solution
    bool isNumber(string s) {
        // need the support of the boost lib, so we need change the cmakefile
        // add the statement:
        // 添加头文件搜索路径 include_directories(/usr/local/Cellar/boost/1.65.1/include)
        // 添加库文件搜索路径 link_directories(/usr/local/Cellar/boost/1.65.1/lib)

        /*
         * We start with trimming.

        If we see [0-9] we reset the number flags.
        We can only see . if we didn’t see e or .
        We can only see e if we didn’t see e but we did see a number. We reset numberAfterE flag
        We can only see + and - in the beginning and after an e
        any other character break the validation.
        At the and it is only valid if there was at least 1 number and if we did see an e then a number after it as well.

        So basically the number should match this regular expression:

        [-+]?(([0-9]+(.[0-9]*)?)|.[0-9]+)(e[-+]?[0-9]+)?
         */

        boost::trim(s);
        // All we need is to have a couple of flags so we can process the string in linear time:
        bool pointSeen = false;
        bool eSeen = false;
        bool numberSeen = false;
        bool numberAfterE = true;
        for(int i=0; i<s.length(); i++) {
            if('0' <= s.at(i) && s.at(i) <= '9') {
                numberSeen = true;
                numberAfterE = true;
            } else if(s.at(i) == '.') {
                if(eSeen || pointSeen) {
                    return false;
                }
                pointSeen = true;
            } else if(s.at(i) == 'e') {
                if(eSeen || !numberSeen) {
                    return false;
                }
                numberAfterE = false;
                eSeen = true;
            } else if(s.at(i) == '-' || s.at(i) == '+') {
                if(i != 0 && s.at(i-1) != 'e') {
                    return false;
                }
            } else {
                return false;
            }
        }

        return numberSeen && numberAfterE;
    }

};

int main() {
    Solution s;
    string str = "01e-1.2";
    auto result = s.isNumber(str);
    cout<<result<<endl;

}