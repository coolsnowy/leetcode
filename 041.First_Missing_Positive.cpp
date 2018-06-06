/**
 * Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
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
#include <cassert>
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
    // my accepted solution, need 6ms, I think this solution is not well,
    // I spend much time to debug the various boundary conditions
    int firstMissingPositive(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int i = 0;
        if(nums.empty()) return 1;
        if(nums.size() == 1) {
            if(nums[0] <=0 || nums[0] > 1) return 1;
            else return nums[0] + 1;
        }
        for(i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) break;
        }
        if(i == nums.size()) return 1;
        for(int index = i; index < nums.size(); index++) {
            if(nums[i] > 1) {
                return 1;
            } else if(index == nums.size() - 1) {
                return nums[index] + 1;
            } else if(index < nums.size() - 1 && nums[index + 1] - 1 > nums[index])
                return nums[index] + 1;
        }
    }

    // discuss solution
    /*
    Put each number in its right place.

    For example:
            When we find 5, then swap it with A[4].
    At last, the first place where its number is not right, return the place + 1.
    */
    // also need 6 ms , but the solution is so concise
    int firstMissingPositive1(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                std::swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }

};

int main() {
    Solution s;
    std::vector<int> nums{1, 2, 2};
    cout<<s.firstMissingPositive1(nums)<<endl;
}