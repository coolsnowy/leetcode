/**
 * You are climbing a stair case. It takes n steps to reach to the top.

            Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

            Note: Given n will be a positive integer.


            Example 1:

            Input: 2
            Output:  2
            Explanation:  There are two ways to climb to the top.

            1. 1 step + 1 step
            2. 2 steps
            Example 2:

            Input: 3
            Output:  3
            Explanation:  There are three ways to climb to the top.

            1. 1 step + 1 step + 1 step
            2. 1 step + 2 steps
            3. 2 steps + 1 step
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
    // time complexity is too high, when the value is 40, the answer is 165580141
    // when the value is 44, prompt the time limited!! Need to find a better solution!
    // Yes! I can use dynamic programming
    int climbStairs(int n) {
        int sum = 0, result = 0;
        result = climb(sum, n, result);
        return result;
    }
    int climb(int sum, int n, int result) {
        if(sum > n) return result;
        if(sum == n) {
            result++;
            return result;
        }

        for(int i = 1; i <= 2; i++) {
            sum += i;
            result = climb(sum, n, result);
            sum -= i;
        }

        return result;
    }

    // dynamic programming version, need 5ms
    // dp[i] = dp[i - 1] + dp[i - 2];
    int climbStairs1(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // below is see the solution
    // last method use O(n) time and  O(n) space
    // instead, we can use only 1 extra space
    /*
     * Now we just have to find nth ​​  number of the fibonacci series having 1 and 2 their first and second term respectively
     * i.e. Fib(1)=1 and Fib(2)=2
     */
    int climbStairs2(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }

    // and there also exist a solution which cost O(logN)time and O(1) space
    // you can see the detail in https://leetcode.com/problems/climbing-stairs/solution/
};

int main() {
    Solution s;
    int n = 40;
    auto result = s.climbStairs1(n);
    cout<<result;
}