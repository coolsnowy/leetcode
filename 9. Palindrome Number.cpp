/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1) couldn't

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
// my accepted answer
//根据第8题 reverse Integer，直接修改为本题程序
bool isPalindrome(int x) {
	if (x < 0) return 0;
	int result = 0,x0 = x;
	while (x != 0)
	{
		int tail = x % 10;
		int newResult = result * 10 + tail;
		if ((newResult - tail) / 10 != result)
		{
			return 0;
		}
		result = newResult;
		x = x / 10;
	}
	cout << x0 << "  " << result << "  " << endl;
	if (x0 == result) return 1;
	else return 0;
}
// better answer 和我的其实没有区别，只是缺少的overflow处理，紧缩代码而已
bool isPalindrome(int x) {
	if (x<0 || (x != 0 && x % 10 == 0)) return false;
	int rev = 0;
	while (x>rev) {
		rev = rev * 10 + x % 10;
		x = x / 10;
	}
	return (x == rev || x == rev / 10);
}
int main() {
	int a;
	while (1) {
		cin >> a;
		cout << isPalindrome(a) << endl;
	}
}