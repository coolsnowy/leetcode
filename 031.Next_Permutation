/**
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1


 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>

using std::priority_queue;
using std::list;
using std::map;
using std::unordered_map;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    // see the detail https://leetcode.com/problems/next-permutation/solution/
    // great algotithm, smart
    // brute dorce is time limited
    void nextPermutation(std::vector<int>& nums) {
        if(nums.size() <2) return;
        // int 和size_t之间 不能乱用，后面有i--！！！！，如果是unsigned，将会导致i变成INT_MAX
        int i = nums.size() - 2;
        // 全排列中后面数字是递减的
        // such as
        /*
         * 1 2 3 4
         * 1 2 4 3
         * 1 3 2 4
         * 1 3 4 2
         * 1 4 2 3
         * 1 4 3 2
         * 2 1 3 4
         * 2 1 4 3
         */
        // i 指向从尾部开始第一个不是递增的数字
        while(i >= 0 && nums[i+1] <= nums[i]) {
            i--;
        }
        if(i >= 0) {
            // j指向刚刚好比i大的数字
            int j = nums.size() - 1;
            while(j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i+1);

    }

private:
    void reverse(std::vector<int>& nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main() {
    Solution s;
    std::vector<int> vec{1,2};
    s.nextPermutation(vec);
    for(auto i : vec) {
        cout<<i<<'\t';
    }
}
