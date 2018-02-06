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

class Solution {
public:
    // my 7 ms accepted solution, but it cost me so long time beacuse of the various input and corner case
    string simplifyPath(string path) {
        std::stack<string> st;
        size_t prePos = 0, pos = path.find('/', 1);
        while(prePos <= path.size()) {
            string str = path.substr(prePos, (pos > path.size() ? path.size() - prePos : pos - prePos));
            prePos = pos;
            pos = path.find('/', prePos + 1);

            if(str == "/" || str == "/."){
                continue;
            } else if(str == "/..") {
                if(!st.empty())
                    st.pop();
            } else {
                st.push(str);
            }
        }
        if(st.empty()) st.push("/");
        string result;
        while(!st.empty()) {
            result.insert(0,st.top());
            st.pop();
        }
        return result;
    }

    // discuss solution, 8 ms
    string simplifyPath1(string path) {
        string res, tmp;
        std::vector<string> stk;
        // 使用stringstream 非常灵活
        std::stringstream ss(path);
        // getline 不会存储/， 会丢弃掉，之后就从/后面开始读
        while(getline(ss,tmp,'/')) {
            if (tmp == "" || tmp == ".") continue;
            if (tmp == ".." && !stk.empty()) stk.pop_back();
            else if (tmp != "..") stk.push_back(tmp);
        }
        for(auto str : stk) res += "/"+str;
        return res.empty() ? "/" : res;
    }
};

int main() {
    Solution s;
    string str = "/a/./..";
    //string str = "/a/./b/../../c";
    auto result = s.simplifyPath1(str);
    cout<<result;

}