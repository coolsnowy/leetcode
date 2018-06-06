/**
 * Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>

using std::priority_queue;
using std::list;
using std::map;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::stack;
using std::vector;

class Solution {
public:
    // my accepted answer, need 36ms
    int removeDuplicates(std::vector<int>& nums) {
        //cout<<nums.size()<<endl;
        auto first = nums.begin();
        auto second = nums.begin();
        while (first != nums.end()) {
            if(*first == *(first + 1)) {
                // note the second condition must be accepted
                while (*first == *(first + 1) && (first+1) != nums.end()) {
                    first++;
                }
                *second = *first;
                second++;
            }
            else if(*first != *(first+1)) {
                *second = *first;
                second++;
            }
            first++;
        }
        return second-nums.begin();
    }
    // see the provided solution, method is same as mine, but is used the subscribe,
    // while I use iterator, so the provided answer is much concise
    /*
     * Approach (Two Pointers) [Accepted]
Algorithm

Since the array is already sorted, we can keep two pointers ii and jj,
     where i is the slow-runner while j is the fast-runner.
     As long as nums[i] = nums[j], we increment j to skip the duplicate.

     When we encounter nums[j] != nums[i], the duplicate run has ended so we must copy its value to nums[i + 1]
     i is then incremented and we repeat the same process again until j reaches the end of array.
     */
    /**
     * Complexity analysis

Time complextiy : O(n). Assume that n is the length of array. Each of i and j traverses at most n steps.

Space complexity : O(1).
     */
    int removeDuplicates1(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
int main() {
    Solution s;
    std::vector<int> vec{0,0,0};
    cout<< s.removeDuplicates(vec)<<endl;
}