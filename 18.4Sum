/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
 Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

using std::list;
using std::map;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    // my accepted answer,26 ms ,过程中参考3sum，很多地方类似，sum<0 就break，nums[j] == nums[j-1]就continue是不对的，在这里不能照搬
    // 为了不能重复答案，我的操作是find，有更好的方法
    // better answer follow 加了更多的限制条件
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        if(nums.size() < 4)
            return result;
        std::sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size()-3; i++) {
            for(int j = i+1; j<nums.size()-2;j++) {
                if(j == 1 || j>1  ) {
                    int lo = j+1, hi = nums.size()-1, sum = target-(nums[i]+nums[j]);
                    while(lo<hi) {
                        if(nums[lo] + nums[hi] == sum) {
                            if(result.empty() || std::find(result.begin(), result.end(), std::vector<int>{nums[i], nums[j], nums[lo], nums[hi]}) == result.end())
                            result.push_back(std::vector<int>{nums[i], nums[j], nums[lo], nums[hi]});
                            while(lo<hi && nums[lo] == nums[lo+1]) lo++;
                            while(lo<hi && nums[hi] == nums[hi-1]) hi--;
                            lo++;hi--;
                        } else if(nums[lo] + nums[hi] < sum) {
                            lo++;
                        } else {
                            hi--;
                        }
                    }
                }

            }
        }
        return result;
    }
    // better c++ answer need 22ms
    // 思路和上面基本相同，只是相关的限制条件更加好
    std::vector<std::vector<int>> fourSum1(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            // 下个i相同和上个i相同就可以直接跳过继续下一次循环
            if(i>0&&nums[i]==nums[i-1]) continue;
            // 最小的四个都比target大，直接结束程序返回空了
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            // 第一个和最大的三个都小，这个就不用算了，继续下一次循环
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1;j<n-2;j++)
            {
                //注意是j和i+1比较
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
    }
};

int main() {
    Solution s;
    std::vector<int> nums {-1,0,1,2,-1,-4};
    auto result = s.fourSum1(nums,-1);
    for(auto i:result) {
        for(auto j:i){
            cout<<j<<'\t';
        }
        cout<<endl;
    }
    return 0;
}