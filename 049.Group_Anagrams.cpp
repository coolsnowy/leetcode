/**
 * Given an array of strings, group anagrams together.

    For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
    Return:

    [
      ["ate", "eat","tea"],
      ["nat","tan"],
      ["bat"]
    ]
    Note: All inputs will be in lower-case.

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
    // my accepted answer, it takea about 58 ms

    // time complexity : O(NKlog(K)), where N is the length of strs, and K is the maximum length of a string in strs.
    //          The outer loop has complexity O(N) as we iterate through each string.
    //          Then, we sort each string in O(KlogK) time.
    // space complexity: O(N∗K), the total information content stored in map.

    std::vector<std::vector<string>> groupAnagrams(std::vector<string>& strs) {
        std::vector<std::vector<string>> result;
        std::map<std::vector<char>, std::vector<string>> map;
        // sort all strings
        for(auto str : strs) {
            std::vector<char> elem;
            for(auto i : str)
                elem.push_back(i);
            std::sort(elem.begin(), elem.end());
            map[elem].push_back(str);
        }
        int index = 0;
        auto it = map.begin();
        while(it != map.end()) {
            // this statement is essential!!!
            // because the lack of this statement, I cost 2 hours!
            result.push_back({});
            for(auto i : it->second) {
               result[index].push_back(i);
            }
            index++;
            it++;
        }
        return result;
    }

    /*
     * Intuition

        Two strings are anagrams if and only if their character counts (respective number of occurrences of each character) are the same.

        Algorithm

        We can transform each string s into a character count, count,
        consisting of 26 non-negative integers representing the number of a's, b's, c's, etc.
        We use these counts as the basis for our hash map.

        In Java, the hashable representation of our count will be a string delimited with '#' characters.
        For example, abbccc will be #1#2#3#0#0#0...#0 where there are 26 entries total.
        In python, the representation will be a tuple of the counts. For example, abbccc will be (1, 2, 3, 0, 0, ..., 0),
        where again there are 26 entries total.
    */
    // need about 40ms!
    /*
     * Time Complexity: O(N * K), where N is the length of strs, and K is the maximum length of a string in strs.
     * Counting each string is linear in the size of the string, and we count every string.
     *
     * Space Complexity: O(N*K), the total information content stored in ans.
     */
    std::vector<std::vector<string>> groupAnagrams1(std::vector<string>& strs) {
        std::vector<std::vector<string>> result;
        if (strs.size() == 0) return result;
        map<string, std::vector<string>> ans;
        int count[26] = {0};
        for (string s : strs) {
            for(int i = 0; i < 26; i++)
                count[i] = 0;
            for (char c : s) count[c - 'a']++;
            string key{""};
            for (int i = 0; i < 26; i++) {
                key += '#';
                key += static_cast<char>(count[i]) - '48';
            }
            ans[key].push_back(s);
        }
        int index = 0;
        auto it = ans.begin();
        while(it != ans.end()) {
            result.push_back({});
            for(auto i : it->second) {
                result[index].push_back(i);
            }
            index++;
            it++;
        }
        return result;
    }

};
bool cmp(char a, char b){
    return a < b;
}
int main() {
    Solution s;
    std::vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = s.groupAnagrams1(strs);
    for(auto i : result) {
        for(auto j : i) {
            cout<<j<<'\t';
        }
        cout<<'\n';
    }


}