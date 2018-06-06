/**
 * Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
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
    //my accepted solution, need 9 ms
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, size = nums.size() - 1, find = 0;
        std::vector<int> result{-1, -1};
        if(nums.empty()) return result;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(nums[mid] > target) {
                hi = mid - 1;
            } else if(nums[mid] < target) {
                lo = mid + 1;
            } else {
                find = 1;
                hi--;
            }
        }
        if(find == 0) return result;
        result.clear();
        result.push_back(lo);
        lo =0;
        hi = size;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(nums[mid] > target) {
                hi = mid - 1;
            } else if(nums[mid] < target) {
                lo = mid + 1;
            } else {
                lo++;
            }
        }
        result.push_back(hi);
        return result;
    }

    // offical solution, need 9 ms too
    /*
     * The overall algorithm works fairly similarly to the linear scan approach,
     * except for the subroutine used to find the left and rightmost indices themselves.
     * Here, we use a modified binary search to search a sorted array, with a few minor adjustments.
     * First, because we are locating the leftmost (or rightmost) index containing target
     * (rather than returning true iff we find target), the algorithm does not terminate as soon as we find a match.
     * Instead, we continue to search until lo == hi and they contain some index at which target can be found.

     *The other change is the introduction of the left parameter,
     * which is a boolean indicating what to do in the event that target == nums[mid];
     * if left is true, then we "recurse" on the left subarray on ties. Otherwise, we go right.
     * To see why this is correct, consider the situation where we find target at index i.
     * The leftmost target cannot occur at any index greater than i, so we never need to consider the right subarray.
     * The same argument applies to the rightmost index.
     * Complexity Analysis
        Time complexity : O(lgn)
        Because binary search cuts the search space roughly in half on each iteration, there can be at most \lceil lgn \rceil⌈lgn⌉ iterations. Binary search is invoked twice, so the overall complexity is logarithmic.
        Space complexity : O(1)
        All work is done in place, so the overall memory usage is constant.
     */
    int extremeInsertionIndex(std::vector<int> nums, int target, bool left) {
        int lo = 0;
        int hi = nums.size();
        while (lo < hi) { // because hi is not size() - 1 , so < here
            int mid = (lo+hi)/2;
            if (nums[mid] > target || (left && target == nums[mid])) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }

    std::vector<int> searchRange1(std::vector<int> nums, int target) {
        std::vector<int> targetRange = {-1, -1};
        int leftIdx = extremeInsertionIndex(nums, target, true);
        // assert that `leftIdx` is within the array bounds and that `target`
        // is actually in `nums`.
        if (leftIdx == nums.size() || nums[leftIdx] != target) {
            return targetRange;
        }
        targetRange[0] = leftIdx;
        targetRange[1] = extremeInsertionIndex(nums, target, false)-1;
        return targetRange;
    }
};

int main() {
    Solution s;
    std::vector<int> a = {2, 2};
    int target  = 1;
    auto result = s.searchRange1(a, target);
    for(auto i : result) {
        cout<<i<<'\t';
    }



}