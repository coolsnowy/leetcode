/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

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
    // my accepted solution, need 3ms
    int findMin(std::vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        int mid = (lo + hi) / 2;
        while(lo < hi) {
            //不能是<= ,否则数组为【1】时，无限循环
            mid = (lo + hi) / 2;
            if(nums[mid] < nums[hi]) hi = mid;
            else if(nums[mid] > nums[hi]) lo = mid + 1;
        }
        return nums[lo];
    }
    // a promotion, if a[o] < a[last], need not search ,the minist num is a[0]
    int findMin1(std::vector<int>& nums) {
        if(nums[0] <= nums[nums.size() - 1])
            return nums[0];
        int lo = 0, hi = nums.size() - 1;
        int mid = (lo + hi) / 2;
        while(lo < hi) {
            //不能是<= ,否则数组为【1】时，无限循环
            mid = (lo + hi) / 2;
            if(nums[mid] < nums[hi]) hi = mid;
            else if(nums[mid] > nums[hi]) lo = mid + 1;
        }
        return nums[lo];
    }
};

int main() {
    Solution s;
    std::vector<int> a = {4, 5};
    cout << s.findMin(a);


}