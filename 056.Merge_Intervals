/**
 * Given a collection of intervals, merge all overlapping intervals.

        For example,
        Given [1,3],[2,6],[8,10],[15,18],
        return [1,6],[8,10],[15,18].
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

/**
 * Definition for an interval.
 */
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}

};
// if里面必须是小于，如果是<=, 就会报错！！！ 暂时不知道为什么
bool compare(const Interval& inter1, const Interval& inter2) {
    if(inter1.start < inter2.start) return true;
    else return false;
}

class Solution {
public:
    std::vector<Interval> merge(std::vector<Interval>& intervals) {
        std::vector<Interval> result;
        if(intervals.empty()) return result;
        //std::sort(intervals.begin(), intervals.end(), compare);
        // use lambda， brilliant
        std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        int i = 0;
        for(i = 0; i < intervals.size() - 1; i++) {
            if(intervals[i + 1].start <= intervals[i].end) {
                intervals[i + 1].start = intervals[i].start;
                intervals[i + 1].end = std::max(intervals[i].end, intervals[i + 1].end);
            } else {
                result.push_back(intervals[i]);
            }
        }
        result.push_back(intervals[i]);
        return result;
    }
};
int main() {
    Solution s;
    std::vector<Interval> intervals{Interval(1, 3), Interval(2, 6), Interval(12, 15), Interval(9, 11)};
    auto result = s.merge(intervals);
    for(auto i : result) {
        cout<<i.start<<'\t'<<i.end<<endl;
    }
}