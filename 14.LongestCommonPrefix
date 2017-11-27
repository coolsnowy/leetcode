
/**
  Write a function to find the longest common prefix string amongst an array of strings.
 */


#include <iostream>
#include <string>
#include <vector>;


using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minSize = 100000;
        if(strs.empty())
            return string();
        for(auto i:strs) {
            if(i.size() < minSize) {
                minSize = i.size();
            }
        }
        string commanPrefix = "";
        for(int i = 0;i<minSize;i++) {
            char s = strs[0][i];
            for(int j = 1;j<strs.size();j++) {
                if(strs[j][i] != s) {
                    return commanPrefix;
                }
            }
            commanPrefix += s;
        }
        return commanPrefix;
    }

    /*
 * see all solution in  https://leetcode.com/problems/longest-common-prefix/solution/
 */

/*
 * approach 1
 * Complexity Analysis

Time complexity : O(S) , where S is the sum of all characters in all strings.
In the worst case all nn strings are the same. The algorithm compares the string S1S1 with the other strings [S_2…S​n]
 There are S character comparisons, where S is the sum of all characters in the input array.

Space complexity : O(1). We only used constant extra space.
 */
    string longestCommonPrefix1(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        return prefix;
    }

    /*
    * approach2
    * Imagine a very short string is at the end of the array. The above approach will still do S comparisons.
    * One way to optimize this case is to do vertical scanning.
    * We compare characters from top to bottom on the same column (same character index of the strings) before moving on to the next column.
    */
    //same as I did
    /*
     * Time complexity : O(S) , where S is the sum of all characters in all strings. In the worst case there will be n equal strings with length m
     * and the algorithm performs S = m*n character comparisons. Even though the worst case is still the same as Approach #1,
     * in the best case there are at most n*minLen comparisons where minLen is the length of the shortest string in the array.
    Space complexity : O(1). We only used constant extra space.
     */


    /*
     * Approach #3 (Divide and conquer)
     * Complexity Analysis
     * In the worst case we have n equal strings with length m
     * Time complexity : O(S), where S is the number of all characters in the array, S=m∗n Time complexity is T(n) = 2 T(n/2) + O(m).
     * Therefore time complexity is O(S)
     * In the best case this algorithm performs O(minLen*n) comparisons, where minLen is the shortest string of the array
     * Space complexity : O(m*log(n))
     * */
    string longestCommonPrefix3(vector<string>& strs) {
        if( strs.empty()) {
            return string();
        }
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }
    string longestCommonPrefix(vector<string> strs, int left, int right) {
        if(left == right)
            return strs[left];
        else {
            int mid = (left + right) / 2;
            string lcpLeft = longestCommonPrefix(strs, left, mid);
            string lcpRight = longestCommonPrefix(strs, mid + 1, right);
            return commonPrefix(lcpLeft, lcpRight);
        }
    }
    string commonPrefix(string lcpLeft, string lcpRight) {
        int minSize = (lcpLeft.size() < lcpRight.size() ? lcpLeft.size() : lcpRight.size());
        for(int i = 0; i < minSize; i++) {
            if(lcpLeft[i] != lcpRight[i]) {
                return lcpLeft.substr(0,i);
            }
        }
        return lcpLeft.substr(0,minSize);
    }

    /*
     * Approach #4 (Binary search)
     *
     *The idea is to apply binary search method to find the string with maximum value L, which is common prefix of all of the strings.
     * The algorithm searches space is the interval(0…minLen), where minLen is minimum string length and the maximum possible common prefix.
     * Each time search space is divided in two equal parts, one of them is discarded, because it is sure that it doesn't contain the solution.
     * There are two possible cases:
     * S[1...mid] is not a common string. This means that for each j > i S[1..j] is not a common string and
     *      we discard the second half of the search space.
     * S[1...mid] is common string. This means that for for each i < j S[1..i] is a common string and
     *      we discard the first half of the search space, because we try to find longer common prefix.
     */
    /*
     * Complexity Analysis

In the worst case we have n equal strings with length m

    Time complexity : O(S∗log(n)), where S is the sum of all characters in all strings.
The algorithm makes log(n) iterations, for each of them there are S = m*n comparisons, which gives in total O(S*log(n)) time complexity.

    Space complexity : O(1).
We only used constant extra space.
     */
    string longestCommonPrefix4(vector<string>& strs) {
        if( strs.empty()) {
            return string();
        }
        int minSize = 100000;
        for(auto i : strs) {
            if(i.size() < minSize)
                minSize = i.size();
        }
        int low = 1, high = minSize;
        while(low <= high) {
            int middle = (low + high) / 2;
            if(isCommonPrefix(strs, middle)) {
                low = middle + 1;
            } else
                high = middle - 1;
        }
        return strs[0].substr(0,(low + high) / 2);
    }
    bool isCommonPrefix(vector<string>& strs, int middle) {
        string s = strs[0].substr(0,middle);
        for(int i = 1;i < strs.size(); i++) {
            // if equal, compare return 0
            if(strs[i].compare(0,s.size(),s, 0, s.size()))
                return false;
        }
        return true;
    }
};



int main() {
    string s1 = "abcskjf";
    string s2 = "abcsjhf";
    string s3 = "abcd";
    Solution s;
    vector<string> v{s1,s2,s3};

    cout<<endl<<s.longestCommonPrefix4(v)<<endl;
}


