
/**
  Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
  n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container,
  such that the container contains the most water.

Note: You may not slant (倾斜) the container and n is at least 2.
 */

#include <iostream>
#include <string>
#include <vector>;
#include <opencl-c.h>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Solution {
public:
    //Submission Result: Time Limit Exceeded ,must optimize the answer, but I don't how to optimize
    int min(const int &x ,const int &y) {
        return (x < y ? x : y);
    }
    int maxArea1(vector<int>& height) {
        //brute force
        int water = 0;
        int maxWater = 0;
        for(int i = 0;i < height.size();i++) {
            for( int j = i+1; j < height.size();j++) {
                water = (j-i) * min(height[i],height[j]);
                if(water > maxWater) {
                    maxWater = water;
                }
            }
        }
        return maxWater;
    }
    // 2 和 3 的方法其实是一样的，2在里面循环，应该比3速度更快更好一点

    // better c++ solution
    /*
     * Start by evaluating the widest container, using the first and the last line.
     * All other possible containers are less wide, so to hold more water, they need to be higher.
     * Thus, after evaluating that widest container, skip lines at both ends that don't support a higher height.
     * Then evaluate that new container we arrived at. Repeat until there are no more possible containers left.
     */
    int maxArea2(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j ) i++;
            while (height[j] <= h && i < j ) j--;
        }
        return water;
    }

    //O(n) algorithm
    /**
     * Algorithm

    The intuition behind this approach is that the area formed between the lines will always be limited by the height of the shorter line.
     Further, the farther the lines, the more will be the area obtained.

    We take two pointers, one at the beginning and one at the end of the array constituting the length of the lines. Futher,
     we maintain a variable maxareamaxarea to store the maximum area obtained till now. At every step, we find out the area formed between them,
     update maxareamaxarea and move the pointer pointing to the shorter line towards the other end by one step.

     How this approach works?

    Initially we consider the area constituting the exterior most lines. Now, to maximize the area, we need to consider the area between the lines of larger lengths.
     If we try to move the pointer at the longer line inwards, we won't gain any increase in area, since it is limited by the shorter line.
     But moving the shorter line's pointer could turn out to be beneficial, as per the same argument, despite the reduction in the width.
     This is done since a relatively longer line obtained by moving the shorter line's pointer might overcome the reduction in area caused by the width reduction.
     */

    int maxArea3(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            if (height[i] < height[j] )
                i++;
            else
                j--;
        }
        return water;
    }
    /**
     * Here's another way to see what happens in a matrix representation:

Draw a matrix where the row is the first line, and the column is the second line. For example, say n=6.

In the figures below, x means we don't need to compute the volume for that case: (1) On the diagonal, the two lines are overlapped;
     (2) The lower left triangle area of the matrix is symmetric to the upper right area.

We start by computing the volume at (1,6), denoted by o. Now if the left line is shorter than the right line,
     then all the elements left to (1,6) on the first row have smaller volume,
     so we don't need to compute those cases (crossed by ---).
限制在1 ，就算是1 5， 1 4， 高度仍然受限，反倒是宽度降低，不可能提高面积的
  1 2 3 4 5 6
1 x ------- o
2 x x
3 x x x
4 x x x x
5 x x x x x
6 x x x x x x
Next we move the left line and compute (2,6). Now if the right line is shorter, all cases below (2,6) are eliminated.

  1 2 3 4 5 6
1 x ------- o
2 x x       o
3 x x x     |
4 x x x x   |
5 x x x x x |
6 x x x x x x
And no matter how this o path goes, we end up only need to find the max value on this path, which contains n-1 cases. 所以是O(n)算法嘛

  1 2 3 4 5 6
1 x ------- o
2 x x - o o o
3 x x x o | |
4 x x x x | |
5 x x x x x |
6 x x x x x x
Hope this helps. I feel more comfortable seeing things this way.
     */
};