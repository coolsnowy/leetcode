/*
 * Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.


 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

using std::list;
using std::map;
using std::cout;
using std::string;
using std::endl;
using std::vector;

class Solution {
public:
    // can't resolve this problemn, see the answer
    //看完以后，对本程序进行了修改，才磕磕绊绊写了出来
    // 其中temp和循环部分看了答案才写了出来
    vector<string> letterCombinations(string digits) {
        vector<int> vec;
        vector<string> result;
        result.push_back("");
        if(digits.empty())
            return vector<string> ();
        const string map[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for(auto digit: digits) {
            vec.push_back(digit-'0');
        }
        // 我们想把每个mapping string的每个char都插入到每个结果中，所以最外层循环是mapping string的循环，然后是char字符的循环，最后才是结果的循环
        for(auto e:vec) {
            //每次在这里定义一个新的temp
            //对新的temp进行操作，temp是上次循环后出来的结果
            //每次循环之后，将结果和temp进行交换，然后下次循环对temp进行操作，再讲新的结果换到temp
            //不能直接对result进行操作，否则通过result。size进行循环的次数控制，将会陷入无限循环
            vector<string> temp;
            for(int i = 0;i< map[e].size();i++) {
                for(int j = 0;j<result.size();j++) {
                    temp.push_back(result[j]+map[e][i]);
                }
            }
            result.swap(temp);
        }
        return result;
    }

    //tha answer use FIFO quene
    vector<string> letterCombinations1(string digits) {
        vector<string> result;
        if(digits.empty()) return vector<string>();
        static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        result.push_back("");   // add a seed for the initial case
        for(int i = 0 ; i < digits.size(); ++i) {
            int num = digits[i]-'0';
            if(num < 0 || num > 9) break;
            const string& candidate = v[num];
            if(candidate.empty()) continue;
            vector<string> tmp;
            for(int j = 0 ; j < candidate.size() ; ++j) {
                for(int k = 0 ; k < result.size() ; ++k) {
                    tmp.push_back(result[k] + candidate[j]);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums{-1, 2, 1, -4, -2};
    string str{"234"};
    std::cout<<str<<endl;
    auto result =  s.letterCombinations(str);
    for(auto i: result) {
        cout<<i<<'\t';
    }
    cout<<endl;
    return 0;
}