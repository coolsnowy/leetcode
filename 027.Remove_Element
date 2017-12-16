/**
 * Given an array and a value, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.
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
using std::vector;
class Solution {
public:
    // fuck! pretty simple problem， but I haven't resolve it.
    // 提交时各种边界情况没有考虑到，放弃了！看solution2 ，是我想要的效果
    // 解法2，就不需要频繁的判断最后一个元素的值
    // my wrong solution follow
    int removeElement(vector<int> &nums, int val) {
        size_t i = 0, j = nums.size();
        if(j == -1) return 0;
        while(nums[j-1] == val) {
            j--;
            if(j == 0)
                return nums[0] == val ? 0 : 1;
            if(j == -1)
                return 0;
        }
        while(i < j) {
            if(nums[i] == val) {
                nums[i] = nums[j-1];
                j--;
            } else
                i++;
        }
        return j;
    }
    // provided solution
    /*need 9 ms
     * When nums[j] equals to the given value, skip this element by incrementing j.
     * As long as nums[j]≠val, we copy nums[j] to nums[i] and increment both indexes at the same time.
     * Repeat the process until j reaches the end of the array and the new length is i.
     */
    /**
     * Complexity analysis

Time complexity : O(n). Assume the array has a total of nn elements, both i and jtraverse at most 2n2n steps.

Space complexity : O(1).
     */

    int removeElement1(vector<int> &nums, int val) {
        size_t i = 0, j = 0;
        for(;j < nums.size(); j++) {
            if(nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }

    // solution 2, need 3ms
    /*
     * Intuition

Now consider cases where the array contains few elements to remove.
     For example, nums = [1,2,3,5,4], val = 4 The previous algorithm will do unnecessary copy operation of the first four elements.
     Another example is nums = [4,1,2,3,5], val = 4
     It seems unnecessary to move elements [1,2,3,5] one step left as the problem description mentions
     that the order of elements could be changed.

Algorithm

When we encounter nums[i] = val, we can swap the current element out with the last element and dispose the last one.
     This essentially reduces the array's size by 1.

Note that the last element that was swapped in could be the value you want to remove itself.
     But don't worry, in the next iteration we will still check this element.
     */
    int removeElement2(vector<int> &nums, int val) {
        size_t i = 0, j = nums.size();
        while(i < j) {
            if(nums[i] == val) {
                nums[i] = nums[j-1];
                // reduce array size by one
                // 不需要像我那样考虑那么多复杂条件，将最后一个拷贝过来，即使是要除去的值也不要紧，因为i并没有增加，下一次还会检查这个元素，perfect！
                j--;
            } else
                i++;
        }
        return j;
    }
};
int main() {
    Solution s;
    std::vector<int> vec{3,2,2,3};

    cout<<s.removeElement(vec,3)<<endl;
    for(auto i:vec) {
        cout<<i<<'\t';
    }cout<<endl;
}