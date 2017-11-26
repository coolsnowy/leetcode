/**
  *  Given a roman numeral, convert it to an integer.
  *
  *  Input is guaranteed to be within the range from 1 to 3999.
  **/
/**
 * 首先简单介绍一下罗马数字，一下摘自维基百科

罗马数字共有7个，即I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）。按照下述的规则可以表示任意正整数。需要注意的是罗马数字中没有“0”，与进位制无关。一般认为罗马数字只用来记数，
而不作演算。

重复数次：一个罗马数字重复几次，就表示这个数的几倍。
右加左减：
在较大的罗马数字的右边记上较小的罗马数字，表示大数字加小数字。
在较大的罗马数字的左边记上较小的罗马数字，表示大数字减小数字。
左减的数字有限制，仅限于I、X、C。比如45不可以写成VL，只能是XLV
但是，左减时不可跨越一个位数。比如，99不可以用IC（100 - 1）表示，而是用XCIX（[100 - 10] + [10 - 1]）表示。（等同于阿拉伯数字每位数字分别表示。）
左减数字必须为一位，比如8写成VIII，而非IIX。
右加数字不可连续超过三位，比如14写成XIV，而非XIIII。（见下方“数码限制”一项。）
加线乘千：
在罗马数字的上方加上一条横线或者加上下标的Ⅿ，表示将这个数乘以1000，即是原数的1000倍。
同理，如果上方有两条横线，即是原数的1000000（1000^{2}）倍。
数码限制：
同一数码最多只能出现三次，如40不可表示为XXXX，而要表示为XL。
3999范围内的罗马数字不会用到加上划线的字母
 */

#include <iostream>
#include <string>
#include <vector>;
#include <unordered_map>

using std::unordered_map;
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
//一次通过，beat78%
class Solution {
public:
    // 将罗马转化成真实数字，否则不好进行计算
    vector<int> romanString(const string &s) {
        vector<int> romanS;
        for (auto i:s) {
            switch (i) {
                case 'i' :
                case 'I' : {
                    romanS.push_back(1);
                    break;
                }
                case 'v':
                case 'V' : {
                    romanS.push_back(5);
                    break;
                }
                case 'x':
                case 'X' : {
                    romanS.push_back(10);
                    break;
                }
                case 'l':
                case 'L' : {
                    romanS.push_back(50);
                    break;
                }
                case 'c':
                case 'C' : {
                    romanS.push_back(100);
                    break;
                }
                case 'd':
                case 'D' : {
                    romanS.push_back(500);
                    break;
                }
                case'm':
                case 'M' : {
                    romanS.push_back(1000);
                    break;
                }
                default: cout<<"no this Roman "<<endl;
            }
        }
        return romanS;
    }
    int romanToInt(string s) {
        int sum = 0;
        vector<int> vString = romanString(s);
        // 先计算出所有数字相加，上面给了很多罗马数字的限制，但是那是罗马数字命名规范，和程序计算数字无关
        // 其中最重要的一句是，左减数字只能有一位，所以只需要从0到size-1 判断这个数字是否小于他右边的数字，如果是的话，减去两倍他，因为刚才算总和将他加了上去
        // 至于比大数字小的右边数字不需要处理，因为反正也要加上去的， 我们程序只需要处理需要减的
        for(auto i: vString) {
            sum += i;
        }
        for(int i =0;i < vString.size() - 1 ;i++)
        {
            if(vString[i] < vString[i+1]) {
                sum -= 2*vString[i];
            }
        }
        return sum;
    }
    // 和我想的一模一样，但是写法上使用了unorder_map，值得学习
    // better answer
    int romanToInt1(string s)
    {
        unordered_map<char, int> T = { { 'I' , 1 },
                                       { 'V' , 5 },
                                       { 'X' , 10 },
                                       { 'L' , 50 },
                                       { 'C' , 100 },
                                       { 'D' , 500 },
                                       { 'M' , 1000 } };
        // 从后往前依次处理

        int sum = T[s.back()];
        for (int i = s.length() - 2; i >= 0; --i)
        {
            if (T[s[i]] < T[s[i + 1]])
            {
                sum -= T[s[i]];
            }
            else
            {
                sum += T[s[i]];
            }
        }

        return sum;
    }
};

int main() {
    Solution s;
    string roman = "XCIX";
    cout<<s.romanToInt1(roman)<<endl;
    return 0;

}