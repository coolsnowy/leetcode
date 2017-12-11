/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or
minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no
conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
// my accepted answer
int myAtoi1(string str) {	
	string s;
	int flag = 0;
	for (auto i : str) {
		if ((i == '+' || i == '-' )&& flag == 0) {
			s += i;
			flag = 1;
			continue;
		}
		if (flag == 0 && i != ' ' && (i < '0' || i>'9'))
			return 0;
		if ( i >= '0' && i <= '9') {
			flag = 1;
			s += i;
			continue;
		}
		if (flag == 1 && (i<'0' || i > '9')) {
			break;
		}
	}
	if (s.empty())
		return 0;
	int num = 0,temp_num;
	size_t len = s.length();
	cout << len << '\t';
	for (int i = 0; i < len;i++ ) {
		if (s[i] == '-' || s[i] == '+') {
			continue;
		}
		if (num > (pow(2, 31) - 1 - (s[i] - '0')) / 10.0 && s[0] != '-')
			return pow(2, 31) - 1;
		if (num > (pow(2, 31)  - (s[i] - '0')) / 10.0 && s[0] == '-')
			return -pow(2, 31) ;
		temp_num = num * 10 + (s[i] - '0');
		num = temp_num;
	}
	if ((s[0] == '-') && num != 0) num = -num;
	else if (num == 0) return 0;
	return num;
}
//no better answer ,shitty problem!!
int main() {
	string s;
	while (1) {
		cin >> s;
		cout << myAtoi(s) << endl<<endl;
	}
}