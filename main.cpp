/**
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 1:

Input: [1,3,5,6], 0
Output: 0

 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <stack>
#include <queue>

using std::priority_queue;
using std::list;
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
    // my accepted solution, 6ms
    //事实上直接二分查找，没找到，返回lo就可以，见offical solution
    int searchInsertt(std::vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(target > nums[mid]) {
                lo = mid + 1;
            } else if(target < nums[mid]) {
                hi = mid;
            } else return mid;
        }
        return lo;
    }

    //offical solution, 6ms
    int searchInsert1(std::vector<int> nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};

int main() {
    Solution s;
    std::vector<int> a = {0, 1, 2, 4};
    int target  = 3;
    auto result = s.searchInsert1(a, target);
    cout<<result<<endl;
}