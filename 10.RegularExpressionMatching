/*
 * Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
 注意：这里的a*表示a可以重复0次或者多次，不是a和*分开的。!!!!!!!!
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

using std::list;
using std::map;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    //don't know how to work out this problem
    // see the answer

    // approach 1
    // 和下面方法1相同，通过递归，不过这这个效率更高，time complexity更低
    /*
     * Intuition

        If there were no Kleene stars (the * wildcard character for regular expressions),
     the problem would be easier - we simply check from left to right if each character of the text matches the pattern.

        When a star is present, we may need to check many different suffixes of the text and see if they match the rest of the pattern.
     A recursive solution is a straightforward way to represent this relationship.
     */
    // *是重复前面的字符，所以*的位置至少是1
    bool isMatch3(string s, string p) {
        //if p is empty ,then return 1 if s is also empty
        if (p.empty()) return s.empty();
        // if not empty, judge the first char ,if equal of '.', result is true
        bool first_match = (!s.empty() &&
                            (p.at(0) == s.at(0) || p.at(0) == '.'));
        // if p[1] == '*'
        /*
         * If a star is present in the pattern, it will be in the second position pattern[1].
         * Then, we may ignore this part of the pattern, or delete a matching character in the text.
         * If we have a match on the remaining strings after any of these operations, then the initial inputs matched.
         */
        if (p.length() >= 2 && p.at(1) == '*') {
            // p[1] == '*'
            //return first_match && ismatch()
            // *一次也没有重复，直接跳过*和*前面的字符p.substr(2)  a*cd ，cd
            // *重复了   a*cd aaacd
            return (isMatch(s, p.substr(2)) ||
                    (first_match && isMatch(s.substr(1), p)));
        } else {
            // p[1] != '*', return first_match && ismatch
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }

    /*
    * 这个题目比较常见，但是难度还是比较大的。我们先来看看brute force怎么解决。
    * 基本思路就是先看字符串s和p的从i和j开始的子串是否匹配，用递归的方法直到串的最后，最后回溯回来得到结果。
    * 假设现在走到s的i位置，p的j位置，情况分为下列两种：
   (1)p[j+1]不是'*'。情况比较简单，只要判断当前s的i和p的j上的字符是否一样（如果有p在j上的字符是'.',也是相同），如果不同，返回false，否则，递归下一层i+1，j+1;
   (2)p[j+1]是'*'。那么此时看从s[i]开始的子串，假设s[i],s[i+1],...s[i+k]都等于p[j]那么意味着这些都有可能是合适的匹配，
    那么递归对于剩下的(i,j+2),(i+1,j+2),...,(i+k,j+2)都要尝试（j+2是因为跳过当前和下一个'*'字符）。
    */

    bool isMatch(string s, string p) {
        return helper(s,p,0,0);
    }
    bool helper(string s, string p, int i, int j) {
        //p 和 s都到了the one past the last, 前面的都匹配的情况
        if(j==p.length())
            return i==s.length();
        // situation 1
        // 一直递归，需要个结束条件，p先到达，s还没到肯定返回false，即上面
        // 或者p还没到达the one past the last， s就先到达文件尾，而且p的下一个不是*，也是返回false
        if(j==p.length()-1 || p.at(j+1)!='*')
        {
            //i and j 长度不等，而且下一个不是*（*可以代表为空），则也是不匹配的
            if(i==s.length()|| s.at(i)!=p.at(j) && p.at(j)!='.')
                return false;
            else
                return helper(s,p,i+1,j+1);
        }
        // p.charAt(j+1)=='*'
        // 如果上面的情况一满足，直接递归调用下一个，根本不会进入while循环
        // 即s[i] p[j] match
        while(i<s.length() && (p.at(j)=='.' || s.at(i)==p.at(j)))
        {
            if(helper(s,p,i,j+2))
                return true;
            i++;
        }
        return helper(s,p,i,j+2);
    }


    /*
     * Approach #2: Dynamic Programming [Accepted]

    Intuition

    As the problem has an optimal substructure, it is natural to cache intermediate results.
     We ask the questiondp(i, j): does text[i:] and pattern[j:] match? We can describe our answer in terms of answers to questions involving smaller strings.

     Algorithm

    We proceed with the same recursion as in Approach #1, except because calls will only ever be made to match(text[i:], pattern[j:]),
     we use dp(i, j) to handle those calls instead, saving us expensive string-building operations and allowing us to cache the intermediate results.

     */
    // time complexity is very low, the procedure is optimal
    //the detail complexity analyis see the https://leetcode.com/problems/regular-expression-matching/solution/
    // amazing， only need 9 ms
    bool isMatch1(string s, string p) {
        /**
         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
         */
        size_t m = s.size(), n = p.size();
        std::vector<std::vector<bool>> f(m + 1, std::vector<bool>(n + 1, false));
        //把前面的值都设定好初值，方便后面根据前面的数值进行推导计算
        f[0][0] = true;
        for (int i = 1; i <= m; i++)
            f[i][0] = false;
        // p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
        // such as a*, a*b*c* match empty
        for (int j = 1; j <= n; j++)
            f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                //&& 的巧用，第一个值是前面的值0或1，后面都是判断条件bool，只有都是一，所有相与的结果才是第一个的值，否则为0
                if (p[j - 1] != '*')
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                else
                    // p[0] cannot be '*' so no need to check "j > 1" here
                    f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];

        return f[m][n];
    }


    /*
     * 接下来我们考虑如何优化brute force算法，熟悉动态规划的朋友可能发现了，其实这个思路已经很接近动态规划了。
     * 动态规划基本思想就是把我们计算过的历史信息记录下来，等到要用到的时候就直接使用，不用重新计算。
     * 在这个题里面，假设我们维护一个布尔数组res[i][j],代表s的前i个字符和p的前j个字符是否匹配(注意这里res的维度是s.length()+1,p.length()+1)。递推公式跟上面类似，分三种种情况：
     * (1)p[j+1]不是'*'。情况比较简单，只要判断如果当前s的i和p的j上的字符一样（如果有p在j上的字符是'.',也是相同），
     *      并且res[i][j]==true，则res[i+1][j+1]也为true，res[i+1][j+1]=false;
     *
     * (2)p[j+1]是'*'，但是p[j]!='.'，p[j]是一个字母。那么只要以下条件有一个满足即可对res[i+1][j+1]赋值为true：
     *      1)res[i+1][j]为真（'*'只取前面字符一次）;
            2)res[i+1][j-1]为真（'*'前面字符一次都不取，也就是忽略这两个字符）;
            3)res[i][j+1] && s[i]==s[i-1] && s[i-1]==p[j-1](这种情况是相当于i从0到s.length()扫过来，如果p[j+1]对应的字符是‘*’那就意味着接下来的串就可以依次匹配下来，
                如果下面的字符一直重复，并且就是‘*’前面的那个字符）。

      (3)p[j+1]是'*'，并且p[j]=='.'。因为".*"可以匹配任意字符串，所以在前面的res[i+1][j-1]或者res[i+1][j]中只要有i+1是true，
            那么剩下的res[i+1][j+1],res[i+2][j+1],...,res[s.length()][j+1]就都是true了。
            这道题有个很重要的点，就是实现的时候外层循环应该是p,然后待匹配串s内层循环扫过来
     */
/*
public boolean isMatch(String s, String p) {
        if(s.length()==0 && p.length()==0)
            return true;
        if(p.length()==0)
            return false;
        boolean[][] res = new boolean[s.length()+1][p.length()+1];
        res[0][0] = true;
        for(int j=0;j<p.length();j++)
        {
            if(p.charAt(j)=='*')
            {
                if(j>0 && res[0][j-1]) res[0][j+1]=true;
                if(j<1) continue;
                if(p.charAt(j-1)!='.')
                {
                    for(int i=0;i<s.length();i++)
                    {
                        if(res[i+1][j] || j>0&&res[i+1][j-1]
                           || i>0 && j>0 && res[i][j+1]&&s.charAt(i)==s.charAt(i-1)&&s.charAt(i-1)==p.charAt(j-1))
                            res[i+1][j+1] = true;
                    }
                }
                else
                {
                    int i=0;
                    while(j>0 && i<s.length() && !res[i+1][j-1] && !res[i+1][j])
                        i++;
                    for(;i<s.length();i++)
                    {
                        res[i+1][j+1] = true;
                    }
                }
            }
            else
            {
                for(int i=0;i<s.length();i++)
                {
                    if(s.charAt(i)==p.charAt(j) || p.charAt(j)=='.')
                        res[i+1][j+1] = res[i][j];
                }
            }
        }
        return res[s.length()][p.length()];
    }

*/






};

int main() {
    Solution s;
    string s1,s2;
    int a = 0, b=1;
    a =1 && b <2&&2>1;
    cout<<a<<endl;
    return 0;
}