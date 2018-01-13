/**
 * Implement pow(x, n).

        Example 1:

        Input: 2.00000, 10
        Output: 1024.00000
        Example 2:

        Input: 2.10000, 3
        Output: 9.26100

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
    // my solution is time limited! when the test input is 0.00012 while n = 2147483647
    double myPow(double x, int n) {
        int sign = 0;
        if(n < 0) {
            sign = 1;
            n = abs(n);
        }
        if(n == 0) return 1;
        int i = 2;
        double result = x;
        while( i <= n) {
            result *= result;
            i = i * 2;
        }
        i = i / 2;
        while(i < n) {
            result = result * x;
            i++;
        }
        if(sign == 1) result = 1 / result;
        return result;
    }

    /*
     * Approach #2 Fast Power Algorithm Recursive [Accepted]
        Intuition

            Assuming we have got the result of x ^ n, how can we get x ^ {2 * n}?
            Obviously we do not need to multiply x for another n times. Using the formula (x ^ n) ^ 2 = x ^ {2 * n}
            we can get x ^ {2 * n} at the cost of only one computation.
            Using this optimization, we can reduce the time complexity of our algorithm.

        Algorithm

            Assume we have got the result of x ^ {n / 2}​​ , and now we want to get the result of x ^ n
            Let A be result of x ^ {n / 2} , we can talk about x ^ n based on the parity of n respectively.
            If n is even, we can use the formula (x ^ n) ^ 2 = x ^ {2 * n}​​  to get x ^ n = A * A
            If n is odd, then A * A = x ^ {n - 1}
            . Intuitively, We need to multiply another x to the result, so x ^ n = A * A * x

             This approach can be easily implemented using recursion. We call this method "Fast Power",
             because we only need at most O(log(n)) computations to get x ^ n
     */
    /*
     * Complexity Analysis

        Time complexity : O(log(n)). Each time we apply the formula (x ^ n) ^ 2 = x ^ {2 * n}​​ ,
            n is reduced by half. Thus we need at most O(log(n)) computations to get the result.

        Space complexity : O(log(n)). For each computation, we need to store the result of x ^ {n / 2}
        ​​    . We need to do the computation for O(log(n)) times, so the space complexity is O(log(n)).
     */
    // need about 14 ms
    double fastPow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
    double myPow1(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }

    /*
     * Intuition

            Using the formula x ^ {a + b} = x ^ a * x ^ b, we can write n as a sum of positive integers, n = ∑​i bi
            ​​  If we can get the result of x ^ {b_i}
            ​​  quickly, the total time for computing x ^ n will be reduced.

        Algorithm

        We can use the binary representation of n to better understand the problem.
        Let the binary representation of n to be b_1, b_2, ..., b_{length\_limit}
        ​​ , from the Least Significant Bit(LSB) to the Most Significant Bit(MSB).
        For the ith bit, if b_i = 1 it means we need to multiply the result by x ^ {2 ^ i}
        It seems to have no improvement with this representation, since ∑i bi∗2^i=n.
        But using the formula (x ^ n) ^ 2 = x ^ {2 * n}​​  we mentioned above, we can see some differences.
        Initially x ^ 1 = x, and for each i > 1, we can use the result of x ^ {2 ^ {i - 1}} to get x ^ {2 ^ i}in one step.
        Since the number of b_i is at most O(log(n)), we can get all x ^ {2 ^ i}in O(log(n)) time.
        
        After that, for all is that satisfy b_i = 1, we can multiply x ^ {2 ^ i}to the result. This also requires O(log(n)) time.

        Using fast power recursively or iteratively are actually taking different paths towards the same goal.
        For more information about fast power algorithm, you can visit its wiki1.
     */
    /*
     * Time complexity : O(log(n)) For each bit of n 's binary representation, we will at most multiply once.
     * So the total time complexity is O(log(n))

    Space complexity : O(1) We only need two variables for the current product and the final result of x.


     */
    //13ms
    double myPow2(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        double current_product = x;
        for (long long i = N; i ; i /= 2) {
            if ((i % 2) == 1) {
                ans = ans * current_product;
            }
            current_product = current_product * current_product;
        }
        return ans;
    }
};

int main() {
    Solution s;
    double x = 34.00515;
    int n = -3;
    cout<<s.myPow(x, n);
}