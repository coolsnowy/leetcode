/**
 * Given an absolute path for a file (Unix-style), simplify it.

    For example,
    path = "/home/", => "/home"
    path = "/a/./b/../../c/", => "/c"

    Corner Cases:
        Did you consider the case where path = "/../"?
        In this case, you should return "/".
        Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
        In this case, you should ignore redundant slashes and return "/home/foo".

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

/*
 * This is a classic problem of Dynamic Programming. We define the state dp[i][j] to be the minimum number of operations to convert word1[0..i - 1] to word2[0..j - 1]. The state equations have two cases: the boundary case and the general case. Note that in the above notations, both i and j take values starting from 1.

        For the boundary case, that is, to convert a string to an empty string, it is easy to see that the mininum number of operations to convert word1[0..i - 1] to "" requires at least i operations (deletions). In fact, the boundary case is simply:

        dp[i][0] = i;
        dp[0][j] = j.
        Now let’s move on to the general case, that is, convert a non-empty word1[0..i - 1] to another non-empty word2[0..j - 1]. Well, let’s try to break this problem down into smaller problems (sub-problems). Suppose we have already known how to convert word1[0..i - 2] to word2[0..j - 2], which is dp[i - 1][j - 1]. Now let’s consider word[i - 1] and word2[j - 1]. If they are euqal, then no more operation is needed and dp[i][j] = dp[i - 1][j - 1]. Well, what if they are not equal?

        If they are not equal, we need to consider three cases:

        Replace word1[i - 1] by word2[j - 1] (dp[i][j] = dp[i - 1][j - 1] + 1 (for replacement));
        Delete word1[i - 1] and word1[0..i - 2] = word2[0..j - 1] (dp[i][j] = dp[i - 1][j] + 1 (for deletion));
        Insert word2[j - 1] to word1[0..i - 1] and word1[0..i - 1] + word2[j - 1] = word2[0..j - 1] (dp[i][j] = dp[i][j - 1] + 1 (for insertion)).
        Make sure you understand the subtle differences between the equations for deletion and insertion. For deletion, we are actually converting word1[0..i - 2] to word2[0..j - 1], which costs dp[i - 1][j], and then deleting the word1[i - 1], which costs 1. The case is similar for insertion.

        Putting these together, we now have:

        dp[i][0] = i;
        dp[0][j] = j;
        dp[i][j] = dp[i - 1][j - 1], if word1[i - 1] = word2[j - 1];
        dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1), otherwise.
        The above state equations can be turned into the following code directly.
 */
class Solution {
public:
    // so difficult question, see the discuss proble,
    // need about 22 ms
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        std::vector<std::vector<int> > dp(m + 1, std::vector<int> (n + 1, 0));
        for (int i = 1; i <= m; i++)
            dp[i][0] = i;
        for (int j = 1; j <= n; j++)
            dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                // min 只能比较两个数字之间的较小值
                else dp[i][j] = std::min(dp[i - 1][j - 1] + 1, std::min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));

            }
        }
        return dp[m][n];
    }
    /*
        Well, you may have noticed that each time when we update dp[i][j], we only need dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j].
        In fact, we need not maintain the full m*n matrix. Instead, maintaining one column is enough.
        The code can be optimized to O(m) or O(n) space, depending on whether you maintain a row or a column of the original matrix.
        The optimized code is as follows.
    */
    // need about 10ms, optimized!
    int minDistance2(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        std::vector<int> cur(m + 1, 0);
        for (int i = 1; i <= m; i++)
            cur[i] = i;
        //一列一列的更新
        for (int j = 1; j <= n; j++) {
            int pre = cur[0];
            // cur[0] 就相当于是之前的cur[0][j]
            cur[0] = j;
            for (int i = 1; i <= m; i++) {
                // 每次循环更新pre值，pre值指向上一行的值，由于是默认一列一列更新，所以隐含指向上一列
                int temp = cur[i];
                if (word1[i - 1] == word2[j - 1])
                    cur[i] = pre;
                    // 当前在执行cur[i]的计算，所以右边的cur【i】隐含是dp[i][j-1]，
                    // cur[i-1]是上次计算过的，已经更新了，所以cur[i-1]隐含是dp[i-1][j]
                else cur[i] = std::min(pre + 1, std::min(cur[i] + 1, cur[i - 1] + 1));
                pre = temp;
            }
        }
        return cur[m];
    }

};

int main() {
    Solution s;
    string word1 = "";
    string word2 = "";
    auto result = s.minDistance(word1, word2);
    cout<<result;

}