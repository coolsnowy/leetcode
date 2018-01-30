/**
 * Implement int sqrt(int x).

        Compute and return the square root of x.

        x is guaranteed to be a non-negative integer.


        Example 1:

        Input: 4
        Output: 2
        Example 2:

        Input: 8
        Output: 2
        Explanation: The square root of 8 is 2.82842..., and since we want to return an integer, the decimal part will be truncated.
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
    // need 17 ms
    int mySqrt(int x) {
        int lo = 1, hi = x / 2 + 1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            // here is important! we cannot use mid * mid < x, because the value of x maybe is 2147395599, which means x * x will over the boundary
            if(mid  < x / mid) {
                lo = mid + 1 ;
                // 借鉴了下面的思想，对算法提出了改进，可以尽快结束这个循环
                if(mid + 1 > x / (mid + 1))
                    return mid;
            }
            else if (mid  > x / mid) hi = mid - 1;
            else return mid;
        }
        return hi;
    }
    // discuss solution, also need 16ms
    int mySqrt1(int x) {
        if (x == 0)
            return 0;
        int left = 1, right = x / 2 + 1;
        while (true) {
            int mid = left + (right - left) / 2;
            if (mid > x / mid) {
                right = mid - 1;
            } else {
                if (mid + 1 > x / (mid + 1))
                    return mid;
                left = mid + 1;
            }
        }
    }
};

int main() {
    Solution s;
    int x = 2147395599;
    //int x = 10;
    auto result = s.mySqrt1(x);
    cout<<result;
}