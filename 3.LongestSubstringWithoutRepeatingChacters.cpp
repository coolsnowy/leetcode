/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string result;
        if(s.size() != 0) {
            result += *(s.begin());
        }
        auto iBegin = s.begin();
        auto iNext = iBegin + 1;
        unsigned int length = 1;
        auto maxLength = result.length();
        while(iBegin != s.end()) {
            std::vector<char> v{};
            v.push_back(*iBegin);
            while(iNext != s.end()) {
                
                if(find(v.begin(),v.end(),*iNext) == v.end()) {
                    v.push_back(*iNext);
                } else {
                    v.clear();
                    break;
                }
                length++;
                if(length > maxLength) {
                    result = "";
                    maxLength = length;
                    result = s.substr(iBegin - s.begin(),length);
                }
                iNext++;
            }
            length = 1;
            iBegin++;
            iNext = iBegin + 1;
        }
        std::cout<<result<<std::endl;
        return maxLength;
    }
};
*/
//c++ answer
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);//初始化位256个-1
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)//用字母表示为索引例如a代表97，如果if成立说明这个字母之前出现过，则设置该值为起始位置，i为当前位置，相减即为距离
                start = dict[s[i]];// 每次更新，容器里的值即代表字母在字符串里的位置
            dict[s[i]] = i;
            maxLen = std::max(maxLen, i - start);
        }
        return maxLen;
    }
};
int main() {
    Solution s;
    string str = "abcabcbb";
    std::cout<<"result = "<<s.lengthOfLongestSubstring(str)<<std::endl;
}













