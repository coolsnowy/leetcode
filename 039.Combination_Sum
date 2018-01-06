/**
 * Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
  [7],
  [2, 2, 3]
]

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
#include <cassert>

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
    //  see the discuss soluiton, backtrack solution
    // need 23 ms
    // can see the details about this soultion in  http://blog.csdn.net/u012501459/article/details/46779021
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        combinationSum(candidates, target, result, combination, 0);
        return result;
    }
    void combinationSum(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& result, std::vector<int>& combination, int begin) {
        if(!target) {
            result.push_back(combination);
            return;
        }
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], result, combination, i);
            combination.pop_back();
        }
    }
};

int main() {
    Solution s;
    std::vector<int> candidates {2, 3, 6, 7};
    int target = 7;
    auto result = s.combinationSum(candidates, target);
    for(auto i: result) {
        for(auto j : i) {
            cout << j << '\t';
        }cout << '\n';
    }
}