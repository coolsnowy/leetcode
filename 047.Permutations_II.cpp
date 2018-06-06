/**
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.

    For example,
    [1,1,2] have the following unique permutations:
    [
      [1,1,2],
      [1,2,1],
      [2,1,1]
    ]
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
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> item;
        std::sort(nums.begin(), nums.end());
        std::vector<int> used(nums.size(), 0);
        backtrack(nums, result, item, used);
        return result;
    }
    void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& result, std::vector<int>& item, std::vector<int>& used) {
        if(item.size() == nums.size())
            result.push_back(item);
        for(int i = 0; i < nums.size(); i++) {
            if(used[i] == 1) continue;
            if(i > 0 && nums[i] == nums[i - 1] && used[i-1] == 0) continue;
            item.push_back(nums[i]);
            used[i] = 1;
            backtrack(nums, result, item, used);
            used[i] = 0;
            item.pop_back();
        }
    }
};

int main() {
    Solution s;
    std::vector<int> nums {1,2,2};
    auto result = s.permuteUnique(nums);
    for(auto i : result) {
        for(auto elem : i) {
            cout<<elem<<'\t';
        }
        cout<<endl;
    }
}