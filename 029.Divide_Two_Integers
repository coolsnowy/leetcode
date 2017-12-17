/**
 * Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.



 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>

using std::priority_queue;
using std::list;
using std::map;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;
class Solution {
public:
    // My solution, but didnot be accepted, because of the time limited
    // 一个一个减太慢了
    int divide1(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        // 要考虑这种极端情况，因为负数的最小值是-2^n,正数最大值是2^n - 1，所以有了下面这种特殊情况
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        int a = abs(dividend);
        int b = abs(divisor);
        int diff = a - b;
        int result = 0;
        while(diff >=0) {
            result += 1;
            a -= b;
            diff = a - b;
        }
        if((dividend <0 && divisor >0) || (dividend>0 && divisor <0))
            result = -result;
        return result;
    }
    /*
     * In this problem, we are asked to divide two integers. However, we are not allowed to use division, multiplication and mod operations.
     * So, what else can we use? Yeah, bit manipulations.
     * Let's do an example and see how bit manipulations work.

Suppose we want to divide 15 by 3, so 15 is dividend and 3 is divisor.
     Well, division simply requires us to find how many times we can subtract the divisor from the the dividend
     without making the dividend negative.

Let's get started. We subtract 3 from 15 and we get 12, which is positive. Let's try to subtract more.
     Well, we shift 3 to the left by 1 bit and we get 6. Subtracting 6 from 15 still gives a positive result.
     Well, we shift again and get 12. We subtract 12 from 15 and it is still positive.
     We shift again, obtaining 24 and we know we can at most subtract 12. Well, since 12 is obtained by shifting 3 to left twice,
     we know it is 4 times of 3. How do we obtain this 4? Well, we start from 1 and shift it to left twice at the same time.
     We add 4 to an answer (initialized to be 0). In fact, the above process is like 15 = 3 * 4 + 3.
     We now get part of the quotient (4), with a remainder 3.

Then we repeat the above process again. We subtract divisor = 3 from the remaining dividend = 3 and obtain 0.
     We know we are done. No shift happens, so we simply add 1 << 0 to the answer.

Now we have the full algorithm to perform division.

According to the problem statement, we need to handle some exceptions, such as overflow.

Well, two cases may cause overflow:

divisor = 0;
dividend = INT_MIN and divisor = -1 (because abs(INT_MIN) = INT_MAX + 1).
Of course, we also need to take the sign into considerations, which is relatively easy.
     */
        int divide(int dividend, int divisor) {
            if (!divisor || (dividend == INT_MIN && divisor == -1))
                return INT_MAX;
            int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

            /*
             * Returns the absolute value of parameter n ( /n/ ).
                This is the long int version of abs.
            */
            long long dvd = labs(dividend);
            long long dvs = labs(divisor);
            int res = 0;
            while (dvd >= dvs) {
                // 外层循环用来判断2的指数倍除数之外的除数结果
                long long temp = dvs, multiple = 1;
                // 计算2的指数倍的除数， 算法速度大大加快
                while (dvd >= (temp << 1)) {
                    temp <<= 1;
                    multiple <<= 1;
                }
                dvd -= temp;
                res += multiple;
            }
            return sign == 1 ? res : -res;
        }
};

int main() {
    Solution s;
    int a = 15;
    int b = 4;
    cout<<s.divide(a,b);
}