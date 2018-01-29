/**
 * Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

    You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
    Pad extra spaces ' ' when necessary so that each line has exactly L characters.

    Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words,
    the empty slots on the left will be assigned more spaces than the slots on the right.

    For the last line of text, it should be left justified and no extra space is inserted between words.

    For example,
    words: ["This", "is", "an", "example", "of", "text", "justification."]
    L: 16.

    Return the formatted lines as:
    [
       "This    is    an",
       "example  of text",
       "justification.  "
    ]
    Note: Each word is guaranteed not to exceed L in length.

    Corner Cases:
        A line other than the last line might contain only one word. What should you do in this case?
        In this case, that line should be left-justified.
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
    // difficult problem, don't know how to solve it
    /*
     * For each line, I first figure out which words can fit in. According to the code, these words are words[i] through words[i+k-1].
     * Then spaces are added between the words. The trick here is to use mod operation to manage the spaces that can’t be evenly distributed:
     * the first (L-l) % (k-1) gaps acquire an additional space.
     */
    std::vector<string> fullJustify(std::vector<string>& words, int L) {
        std::vector<string> res;
        for(int i = 0, k, l; i < words.size(); i += k) {
            // 每行有k个单词，从第i个到i+k-1个，所以i + k < words.size(),同时每行宽度上限为L，l + words[i + k].size() + k(i到i+k有(k + 1）个单词，之间的空格为k)<= L
            for(k = l = 0; i + k < words.size() && l + words[i+k].size() <= L - k; k++) {
                l += words[i+k].size();
            }
            string tmp = words[i];
            for(int j = 0; j < k - 1; j++) {
                if(i + k >= words.size()) tmp += " ";
                else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
                tmp += words[i+j+1];
            }
            // 必须有这句的原因是因为 输入可能是 ""， 2 ，就必须补全为"  "
            tmp += string(L - tmp.size(), ' ');
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
    Solution s;
    std::vector<string> words {"This", "is", "an", "example", "of", "text", "justification."};
    auto result = s.fullJustify(words, 16);
    for(auto i : result) {
        cout<<i<<endl;
    }
}