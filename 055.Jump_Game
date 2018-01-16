/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.

    Each element in the array represents your maximum jump length at that position.

    Determine if you are able to reach the last index.

    For example:
    A = [2,3,1,1,4], return true.

    A = [3,2,1,0,4], return false.
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
    // there are many solution in the offical answer, include the backtrack and the dyanmic programming
    // I haven't see the offical solution, but it is worth to see it, the page is  https://leetcode.com/problems/jump-game/solution/

    // my accepted solution, need 14ms
    bool canJump(std::vector<int>& nums) {
        if(nums.empty() || nums.size() == 1) return true;
        int start = 1, lastMax = nums[0], max = nums[0];
        while(start <= lastMax) {
            max = std::max(max, start + nums[start]);
            if(max >= nums.size() - 1) return true;
            if(start == lastMax) {
                if(lastMax == max) return false;
                lastMax = std::max(max, lastMax);
            }
            start++;
        }
        return false;
    }

    // another solution, the complexity is same as mine, maybe more concise
    bool canJump1(std::vector<int>& nums) {
        int n = nums.size(), reachableSofar = 0;
        for(int i = 0; i < n; i++){
            if(reachableSofar < i) return false;
            reachableSofar = std::max(reachableSofar, i + nums[i]);
            if(reachableSofar >= n - 1) return true;
        }
    }
};

int main() {
    Solution s;
    std::vector<int> nums {1, 1, 1, 0};
    auto result = s.canJump(nums);
    cout<<result;
}