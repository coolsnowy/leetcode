/**
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

        You may assume that the intervals were initially sorted according to their start times.

        Example 1:
        Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

        Example 2:
        Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

        This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}

};

class Solution {
public:
    // my accepted solution, need about 16ms
    std::vector<Interval> insert(std::vector<Interval>& intervalBefore, Interval newInterval) {
        if(intervalBefore.empty()) return std::vector<Interval> {newInterval};
        std::vector<Interval> intervals;
        for(int i = 0; i < intervalBefore.size(); i++) {
            if(intervalBefore[i].start >= newInterval.start)
                intervals.push_back(newInterval);
            intervals.push_back(intervalBefore[i]);
        }
        if(intervals[intervals.size() - 1].start < newInterval.start) {
            intervals.push_back(newInterval);
        }
        std::vector<Interval> result;
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

    //discuss solution
    // also need 16ms, but more concise and elegant
    std::vector<Interval> insert1(std::vector<Interval> intervals, Interval newInterval) {
        std::vector<Interval> result;
        int i = 0;
        // add all the intervals ending before newInterval starts
        while (i < intervals.size() && intervals[i].end < newInterval.start)
            result.push_back(intervals[i++]);
        // merge all overlapping intervals to one considering newInterval
        while (i < intervals.size() && intervals[i].start <= newInterval.end) {
            newInterval = Interval( // we could mutate newInterval here also
                    std::min(newInterval.start, intervals[i].start),
                    std::max(newInterval.end, intervals[i].end));
            i++;
        }
        result.push_back(newInterval); // add the union of intervals we got
        // add all the rest
        while (i < intervals.size()) result.push_back(intervals[i++]);
        return result;
    }

    // above solution may not need to use additional memory, in place solution with a little change
    // but it cost about 109 ms
    // 典型的空间换时间，vector的插入删除操作很慢，换成List可能会好很多
    std::vector<Interval> insert12(std::vector<Interval> intervals, Interval newInterval) {
        int i = 0;
        while (i < intervals.size() && intervals[i].end < newInterval.start)
            i++;
        // merge all overlapping intervals to one considering newInterval
        while (i < intervals.size() && intervals[i].start <= newInterval.end) {
            newInterval = Interval( // we could mutate newInterval here also
                    std::min(newInterval.start, intervals[i].start),
                    std::max(newInterval.end, intervals[i].end));
            intervals.erase(intervals.begin() + i);
        }
        intervals.insert(intervals.begin() + i,newInterval);
        return intervals;
    }
};

int main() {
    Solution s;
    std::vector<Interval> intervals{Interval(1, 5)};
    Interval temp(2, 7);
    auto result = s.insert1(intervals, temp);
    for(auto i : result) {
        cout<<i.start<<'\t'<<i.end<<endl;
    }
}