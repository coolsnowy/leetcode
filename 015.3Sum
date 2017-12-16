
/**
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

    Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

 */


#include <iostream>
#include <string>
#include <vector>;
#include <set>

using std::set;
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Solution {
public:
    //brute force
    // 对于比较小规模的问题，可以得到结果，submission 提示time limited
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 为了防止相同的元素，所以使用了set，去除重复，之后insert之前先进行排序，否则，set仍无法识别
        set<vector<int>> v;
        vector<vector<int>> vec;
        for(int i = 0;i < nums.size()-2;i++) {
            for(int j = i+1;j<nums.size() - 1;j++) {
                for(int k = j+1;k<nums.size();k++) {
                    if((nums[i] + nums[j] + nums[k]) == 0 ) {
                        vector<int> temp{nums[i],nums[j],nums[k]};
                        // 防止出现只是元素顺序不同， 但是其实元素相同的容器，所以先进行排序
                        std::sort(temp.begin(),temp.end());
                        v.insert(temp);
                    }
                }
            }
        }
        for(auto i: v)
            vec.push_back(i);
        return vec;
    }
    // see answer, 1 and 2 is similar,but I think 2 is better than 1，can see solution 2 directly
    /* I think the second function is more brief
     * the key idea is the same as the TwoSum problem. When we fix the 1st number, the 2nd and 3rd number can be found following the same reasoning as TwoSum.

    The only difference is that, the TwoSum problem of LEETCODE has a unique solution. However, in ThreeSum, we have multiple duplicate solutions
        that can be found. Most of the OLE errors happened here because you could've ended up with a solution with so many duplicates.

    The naive solution for the duplicates will be using the STL methods like below :
    貌似比我自己做的用set还好一点。。。
    std::sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

     But according to my submissions, this way will cause you double your time consuming almostly.
    A better approach is that, to jump over the number which has been scanned, no matter it is part of some solution or not.
    If the three numbers formed a solution, we can safely ignore all the duplicates of them.
    We can do this to all the three numbers such that we can remove the duplicates.
     */
    vector<vector<int> > threeSum1(vector<int> &num) {
        vector<vector<int> > res;
        std::sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            int target = -num[i];
            // this manner is very clear
            if(target < 0)
            {
                break;
            }
            int front = i + 1;
            int back = num.size() - 1;
            while (front < back) {
                int sum = num[front] + num[back];
                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = num[i];
                    triplet[1] = num[front];
                    triplet[2] = num[back];
                    res.push_back(triplet);
                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && num[front] == triplet[1]) front++;
                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && num[back] == triplet[2]) back--;
                }
            }
            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i])
                i++;
        }
        return res;
    }
    /*
     * The idea is to sort an input array and then run through all indices of a possible first element of a triplet.
     * For each possible first element we make a standard bi-directional 2Sum sweep of the remaining part of the array.
     * Also we want to skip equal elements to avoid duplicates in the answer without making a set or smth like that.
     */
    vector<vector<int>> threeSum2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> vec;
        // if size < 3 ,should return a null vector<vector<int>>
        if(nums.size() < 3) {
            return vector<vector<int>> ();
        }
        for(int i= 0;i < nums.size() - 2;i++) {
            if(i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int lo = i+1, hi = nums.size()-1, sum = 0-nums[i];
                //this manner is very clear
                if(sum < 0) break;

                // transfer 3-sum question to 2-sum question, so smart
                while(lo < hi) {
                    if(nums[lo] + nums[hi] == sum) {
                        vec.push_back(vector<int> {nums[i], nums[lo], nums[hi]});
                        // because the vector has been sorted, so we should skip the same element
                        while (lo < hi && nums[lo] == nums[lo+1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi-1]) hi--;
                        lo++; hi--;
                    } else if (nums[lo] + nums[hi] < sum) {
                        lo++;
                    } else {
                        hi--;
                    }
                }
            }
        }
        return vec;
    }

};
int main() {
    vector<int> v{-1, 0, 1, 2,  -1, -4};
    Solution s;
    vector<vector<int>>  result = s.threeSum2(v);
    for(auto i:result) {
        for(auto j : i) {
            cout<<j<<'\t';
        }
        cout<<endl;
    }

}