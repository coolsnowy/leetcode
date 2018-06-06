/**
 * Given a collection of distinct numbers, return all possible permutations.

    For example,
    [1,2,3] have the following permutations:
    [
      [1,2,3],
      [1,3,2],
      [2,1,3],
      [2,3,1],
      [3,1,2],
      [3,2,1]
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
    // see the solution, do it by backtrack method
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> item;
        backtrack(nums, result, item, 0);
        return result;
    }
    void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& result, std::vector<int>& item, int len) {
        if(len == nums.size()) {
            result.push_back(item);
        }
        for(int i = 0; i < nums.size(); i++) {
            if(std::find(item.begin(), item.end(), nums[i]) != item.end()) continue;
            item.push_back(nums[i]);
            backtrack(nums, result, item, len + 1);
            item.pop_back();
        }
    }
};

int main() {
    Solution s;
    std::vector<int> nums {1,2,3};
    auto result = s.permute(nums);
    for(auto i : result) {
        for(auto elem : i) {
            cout<<elem<<'\t';
        }
        cout<<endl;
    }
}