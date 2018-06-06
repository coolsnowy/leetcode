/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.

    Each element in the array represents your maximum jump length at that position.

    Your goal is to reach the last index in the minimum number of jumps.

    For example:
    Given array A = [2,3,1,1,4]

    The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

    Note:
    You can assume that you can always reach the last index.


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
    // difficult question, the solution is quite elegant and concise, smart!
    // see the asnwer, code by myself, need 15ms
    int jump(std::vector<int>& nums) {
        if(nums.size() <= 1 ) return 0;
        int index = 1, size = nums.size() - 1, level = 0, levelIndex = nums[0], max = nums[0];
        while(1) {
            level++;
            if (max >= size) return level;
            while (index <= levelIndex && index < size) {
                if ((nums[index] + index) > max) {
                    max = nums[index] + index;
                }
                index++;
            }
            levelIndex = max;
        }

    }

    // 另一种写法，看起来更简洁，运行效率是一样的
    int jump1(std::vector<int>& A) {
        int step_count = 0;
        int last_jump_max = 0;
        int current_jump_max = 0;
        for(int i=0; i<A.size()-1; i++) {
            current_jump_max = std::max(current_jump_max, i+A[i]);
            if( i == last_jump_max ) {
                step_count++;
                last_jump_max = current_jump_max;
            }
        }
        return step_count;
    }
};

int main() {
    Solution s;
    std::vector<int> nums{2, 2, 3};
    cout<<s.jump1(nums);
}