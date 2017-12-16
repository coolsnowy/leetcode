/*
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number,
 * target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        if(nums.size() < 3) {
            return 0;
        }
        int diff = 1000;
        int result = 0;
        for(int i = 0; i<nums.size()-2; i++) {
            int lo = i+1, hi = nums.size() - 1, sum = nums[i]-target;
            while(lo < hi) {
                // 之前没加下面这段，就是time limited， 但是加了以后就ac了
                // 因为我笨来的三个if没考虑过等于的情况。。。， 当等于以后就进入了死循环。。。
                //加入这个取等条件，极大地优化了算法性能
                // time complexity O(N^2)
                if(nums[lo] + nums[hi] + sum == 0) {
                    result = nums[lo]+nums[hi]+nums[i];
                    return result;
                }
                if(abs(nums[lo] + nums[hi] + sum) < diff) {
                    diff = abs(nums[lo] + nums[hi] + sum);
                    result = nums[lo]+nums[hi]+nums[i];
                }
                if((nums[lo] + nums[hi] + sum)<0 && lo<hi)
                    lo++;
                else if((nums[lo] + nums[hi] + sum)>0 && lo<hi)
                    hi--;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums{-1, 2, 1, -4, -2};
    cout<<s.threeSumClosest(nums, 1)<<endl;
}