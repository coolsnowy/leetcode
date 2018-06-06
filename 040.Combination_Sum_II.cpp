/**
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
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
#include <algorithm>

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
    // 39 see the answer, this problem I can do it by myself, haha!

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        combinationSum(candidates, target, result, combination, 0);

        // use cpp unique and erase algorithm to cut the duplicate result
        std::sort(result.begin(), result.end());
        auto iter = std::unique(result.begin(), result.end());
        result.erase(iter, result.end());
        return result;
    }
    void combinationSum(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& result, std::vector<int>& combination, int begin) {
        // Note all element is positive
        // if target is zero, it is the vector we want to get
        if(!target) {
            result.push_back(combination);
            return;
        }
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], result, combination, i + 1);
            combination.pop_back();
        }

    }

    // better discuss solution
    std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum2(candidates, target, res, combination, 0);
        return res;
    }
    void combinationSum2(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
            // important process
            if (i == begin || candidates[i] != candidates[i - 1]) {
                combination.push_back(candidates[i]);
                combinationSum2(candidates, target - candidates[i], res, combination, i + 1);
                combination.pop_back();
            }
    }
};

int main() {
    Solution s;
    std::vector<int> candidates {1,1,7};// sort 1,1,2,5,6,7,10
    /* for example 1,1,7
     *    1  -  1  -  7   // 最大的for循环从左遍历到右边， 下面的分支由回溯来决定，其实类似于图论中的dfs深度优先搜索
     *   / \    \
     *  1  7    7
     * /   ok   ok    // 重复结果，所以加个判断条件，因为排序过，所以重复结果一定出现在相邻
     *7
     *ok
     */
    int target = 8;
    auto result = s.combinationSum2(candidates, target);
    for(auto i: result) {
        for(auto j : i) {
            cout << j << '\t';
        }cout << '\n';
    }
}