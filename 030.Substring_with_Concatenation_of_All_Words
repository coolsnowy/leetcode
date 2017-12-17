/**
 * You are given a string, s, and a list of words, words, that are all of the same length.
 * Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).


 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>

using std::priority_queue;
using std::list;
using std::map;
using std::unordered_map;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    // okay, don't know how to resolve it!
    /*
     * I think the following code is self-explanatory enough.
     * We use an unordered_map<string, int> counts to record the expected times of each word and
     * another unordered_map<string, int> seen to record the times we have seen. Then we check for every possible position of i.
     * Once we meet an unexpected word or the times of some word is larger than its expected times, we stop the check.
     * If we finish the check successfully, push i to the result indexes.
     */
    // easy understand, but it time cost need 192 ms
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (string word : words)
            counts[word]++;
        int n = s.length(), num = words.size(), len = words[0].length();
        vector<int> indexes;
        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                }
                else break;
            }
            if (j == num) indexes.push_back(i);
        }
        return indexes;
    }
    // this solution is more effiency
    // travel all the words combinations to maintain a window
    // there are wl(word len) times travel
    // each time, n/wl words, mostly 2 times travel for each word
    // one left side of the window, the other right side of the window
    // so, time complexity O(wl * 2 * N/wl) = O(2N)
    std::vector<int> findSubstring1(string S, std::vector<string> &L) {
        std::vector<int> index;
        int n = S.size(), num = L.size();
        if (n <= 0 || num <= 0) return index;
        // init word occurence
        unordered_map<string, int> dict;
        for(auto word : L)
            dict[word]++;
        // travel all sub string combinations
        int len = L[0].size();
        //内层for循环中，每次递增len，所以外层for循环，只需要递增单词长度次数，即可便历完全部情况
        for (int i = 0; i < len; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> tdict;
            for (int j = i; j <= n - len ; j += len) {
                string str = S.substr(j, len);
                // a valid word, accumulate results
                if (dict.count(str)) {
                    tdict[str]++;
                    if (tdict[str] <= dict[str])
                        count++;
                    else {
                        // a more word, advance the window left side possiablly
                        while (tdict[str] > dict[str]) {
                            string str1 = S.substr(left, len);
                            tdict[str1]--;
                            if (tdict[str1] < dict[str1]) count--;
                            left += len;
                        }
                    }
                    // come to a result
                    if (count == num) {
                        index.push_back(left);
                        // advance one word
                        tdict[S.substr(left, len)]--;
                        count--;
                        left += len;
                    }
                }
                    // not a valid word, reset all vars
                else {
                    tdict.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }

        return index;
    }
};

int main() {
    Solution s;
    int a = 15;
    int b = 4;
    vector<string> vec{"ab"};
    string str = "cabcabcababab";

    auto result = s.findSubstring1(str,vec);
    for(auto i : result) {
        cout<<i<<'\t';
    }cout<<endl;
}
