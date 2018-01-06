/**
 * Find all possible combinations of k numbers that add up to a number n,
 * given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

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
#include <cassert>
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
    // according the 39 40problem, my accepted solution, amazing ! need 0 ms
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        std::vector<int> candidates {1, 2, 3, 4, 5, 6, 7, 8, 9};
        combinationSum3(candidates, n, result, combination, 0, 0, k);
        return result;
    }
    void combinationSum3(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& result, std::vector<int>& combination, int begin, int num, int k) {
        // 最终调试通过，不需要自己对num进行判断，质押下面处理了num + 1 ， num - 1,就可以通过递归自动处理combination中的数目！！
        if(!target && num == k) {
            result.push_back(combination);
            return;
        }

        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++) {
            combination.push_back(candidates[i]);
            combinationSum3(candidates, target - candidates[i], result, combination, i + 1, num + 1, k);
            combination.pop_back();
        }
    }

    // better solution1

    std::vector<std::vector<int> > combinationSum4(int k, int n) {
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum4(n, res, combination, 1, k);
        return res;
    }
private:
    void combinationSum4(int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin, int need) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        else if (!need)
            return;
        // 处理的时候，如果need三个数，直接通过target去判断，减少循环次数，代码如下，候选数字是0 - 9
        // 例如 4，5，6，7当前为位置是4
        // need = 3 ， 4+5+6 = 4*3 + 0 + 1 + 2（3）（need * (need - 1) / 2）
        // need = 2 ,  4+5 = 4*2 + 0 + 1（1）
        // need = 1 ， 4 = 4*1 + 0（0）
        for (int i = begin; i != 10 && target >= i * need + need * (need - 1) / 2; ++i) {
            combination.push_back(i);
            combinationSum4(target - i, res, combination, i + 1, need - 1);
            combination.pop_back();
        }
    }

    // better solution2
    std::vector<std::vector<int>> combinationSum(int k, int n) {
        std::vector<std::vector<int>> ans;
        std::vector<int> combinations;
        combination(ans, combinations, k, 1, n);
        return ans;
    }

    void combination(std::vector<std::vector<int>>& ans, std::vector<int>& comb, int k,  int start, int n) {
        if (comb.size() == k && n == 0) {
            ans.push_back(comb);
            return;
        }
        // 直接使用数字1-9，类似于代替了我的combination，并且combinaton【i】和i是一个值，所以再次简化代码
        for (int i = start; i <= 9; i++) {
            comb.push_back(i);
            combination(ans, comb, k, i+1, n-i);
            comb.pop_back();
        }
    }
};

int main() {
    Solution s;
    int k = 3, n = 9;
    auto result = s.combinationSum4(k, n);
    for(auto i: result) {
        for(auto j : i) {
            cout << j << '\t';
        }cout << '\n';
    }
}