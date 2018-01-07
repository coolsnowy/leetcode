/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 see the diagram in https://leetcode.com/problems/trapping-rain-water/description/
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
    // my solution failure,调试了很久，还是无法通过所有的案例，例如9,2,9,3,2,2,1,4,8
    // 放弃了，看solution in https://leetcode.com/problems/trapping-rain-water/solution/
    // 下面写的很乱，直接去网页
    // 还没有看三四种的办法
    int trap(std::vector<int>& height) {
        std::vector<int> max;
        if(height.size() == 1 || height.empty()) return 0;
        // 找到所有的局部最大点
        for(int i = 0; i < height.size(); i++) {
            if(i == 0 && height[i] >= height[i + 1]) max.push_back(i);
            else if(i == height.size() - 1 && height[i] >= height[i - 1]) max.push_back(i);
            if(i > 0 && i < height.size() - 1 && height[i] >= height[i - 1] && height[i] >= height[i+1])
                max.push_back(i);
        }
        if(max.empty()) return 0;
        for(auto e : max)
            cout<<height[e]<<'\t';
        cout<<endl;

        // 为了滤除无用的局部点，类似于5，2，5，要去掉无用的2
        int maxValue = 0, maxIndex = 0;
        for(int i = 0; i < max.size(); i++) {
            if(height[max[i]] >= maxValue) {
                maxIndex = i;
                maxValue = height[max[i]];
            }

        }
        //cout<<maxIndex<<endl;
        std::vector<int> bar{max[0]};
        for(int i = 1; i < max.size(); i++) {
            if(i == maxIndex) bar.push_back(max[i]);
            if(height[max[i]] > height[bar[bar.size() - 1]] && i < maxIndex) bar.push_back(max[i]);
            if(height[max[i]] < height[bar[bar.size() - 1]] && i > maxIndex) bar.push_back(max[i]);
        }

        for(auto e : bar)
            cout<<height[e]<<'\t';
        cout<<endl;

        if(bar.empty() || bar.size() == 1) return 0;
        int capacity = 0;
        for(int begin = 0; begin < bar.size() - 1; begin++) {
            int end = begin + 1;
            for(int i = bar[begin] + 1; i < bar[end]; i++) {
                int minHeight = (height[bar[begin]] > height[bar[end]] ? height[bar[end]] : height[bar[begin]]);
                if(height[i] < minHeight)
                    capacity += minHeight - height[i];
            }
        }
        return capacity;
    }

    /*
     * Approach #1 Brute force [Accepted]
Intuition

    Do as directed in question. For each element in the array, we find the maximum level of water it can trap after the rain,
     which is equal to the minimum of maximum height of bars on both the sides minus its own height.

Algorithm

    Initialize ans=0
    Iterate the array from left to right:
    Initialize max_left=0 and max_right=0
    Iterate from the current element to the beginning of array updating: max_left=max(max_left,height[j])
    Iterate from the current element to the end of array updating: max_right=max(max_right,height[j])
    Add min(max_left,max_right)−height[i] to ans

     Complexity Analysis

    Time complexity: O(n^2) For each element of array, we iterate the left and right parts.

    Space complexity: O(1) extra space.

     spend 625ms
     */
    int trap1(std::vector<int>& height)
    {
        int ans = 0;
        int size = height.size();
        for (int i = 1; i < size - 1; i++) {
            int max_left = 0, max_right = 0;
            for (int j = i; j >= 0; j--) { //Search the left part for max bar size
                max_left = std::max(max_left, height[j]);
            }
            for (int j = i; j < size; j++) { //Search the right part for max bar size
                max_right = std::max(max_right, height[j]);
            }
            ans += std::min(max_left, max_right) - height[i];
        }
        return ans;
    }

    /*
     * Approach #2 Dynamic Programming [Accepted]
Intuition

    In brute force, we iterate over the left and right parts again and again just to find the highest bar size upto that index.
     But, this could be stored. Voila, dynamic programming.

    The concept is illustrated as shown: in https://leetcode.com/problems/trapping-rain-water/solution/

     Algorithm

        Find maximum height of bar from the left end upto an index i in the array left_max
        Find maximum height of bar from the right end upto an index i in the array right_max
        Iterate over the height array and update ans:
        Add min(max_left[i],max_right[i])−height[i] to ans

    Complexity analysis

        Time complexity: O(n).
        We store the maximum heights upto a point using 2 iterations of O(n) each.
        We finally update ans using the stored values in O(n).

        Space complexity: O(n) extra space.

        Additional O(n) space for left_max and right_max arrays than in Approach #1.
        only need 17ms
     */
    int trap2(std::vector<int>& height)
    {
        if(height.empty())
            return 0;
        int ans = 0;
        int size = height.size();
        std::vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = std::max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = std::max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < size - 1; i++) {
            ans += std::min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
    /*
     * Approach #3 Using stacks [Accepted]
Intuition
    Instead of storing the largest bar upto an index as in Approach #2,
     we can use stack to keep track of the bars that are bounded by longer bars and hence, may store water.
     Using the stack, we can do the calculations in only one iteration.

    We keep a stack and iterate over the array.
     We add the index of the bar to the stack if bar is smaller than or equal to the bar at top of stack,
     which means that the current bar is bounded by the previous bar in the stack.
     If we found a bar longer than that at the top, we are sure that the bar at the top of the stack is bounded by the current bar
     and a previous bar in the stack, hence, we can pop it and add resulting trapped water to ans.

Algorithm

    Use stack to store the indices of the bars.
    Iterate the array:
        While stack is not empty and height[current]>height[st.top()]
            It means that the stack element can be popped. Pop the top element as top.
            Find the distance between the current element and the element at top of stack, which is to be filled. distance=current−st.top()−1
            Find the bounded height
                bounded_height= min(height[current], height[st.top()]) − height[top]
            Add resulting trapped water to answer ans+=distance∗bounded_heightans+=distance∗bounded_height
        Push current index to top of the stack
        Move \text{current}current to the next position

        Complexity analysis

            Time complexity: O(n).
            Single iteration of O(n) in which each bar can be touched at most twice(due to insertion and deletion from stack)
             and insertion and deletion from stack takes O(1) time.
            Space complexity: O(n). Stack can take upto O(n) space in case of stairs-like or flat structure.
         need 12 ms
     */

    int trap3(vector<int>& height)
    {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = current - st.top() - 1;
                int bounded_height = std::min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }

    /*
     * Approach #4 Using 2 pointers [Accepted]
Intuition As in Approach #2, instead of computing the left and right parts seperately, we may think of some way to do it in one iteration. From the figure in dynamic programming approach, notice that as long as right_max[i]>left_max[i]right_max[i]>left_max[i](from element 0 to 6), the water trapped depends upon the left_max, and similar is the case when left_max[i]>right_max[i]left_max[i]>right_max[i](from element 8 to 11). So, we can say that if there is a larger bar at one end(say right), we are assured that the water trapped would be dependant on height of bar in current direction(from left to right). As soon as we find the bar at other end(right) is smaller, we start iterating in opposite direction(from right to left). We must maintain left_maxleft_max and right_maxright_max during the iteration, but now we can do it in one iteration using 2 pointers, switching between the two.

Algorithm

Initialize \text{left}left pointer to 0 and \text{right}right pointer to size-1
While \text{left}< \text{right}left<right, do:
If \text{height[left]}height[left] is smaller than \text{height[right]}height[right]
If height[left]>=left_maxheight[left]>=left_max, update left_maxleft_max
Else add left_max−height[left]left_max−height[left] to \text{ans}ans
Add 1 to \text{left}left.
Else
If height[right]>=right_maxheight[right]>=right_max, update right_maxright_max
Else add right_max−height[right]right_max−height[right] to \text{ans}ans
Subtract 1 from \text{right}right.
     */

    int trap4(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::vector<int> height {9,2,9,3,2,2,1,4,8};
    cout<<s.trap2(height)<<endl;
}