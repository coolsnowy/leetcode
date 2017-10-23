/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.


*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
//my accepted answer
int reverse1(int x) {
	int b = 0;
	/*
	while (x / 10) {
		int a = x % 10;
		if (abs(b) > (pow(2, 31)/10)) return 0;//额外注意题目中的note，32位机器机器上要注意这个判断条件
		b = b * 10 + a;
		
		x = x / 10;
	}
	if (abs(b) > (pow(2, 31) / 10)) return 0;//额外注意题目中的note，32位机器机器上要注意这个判断条件
	b = b * 10 + x;
	*/
	//对上面程序改进 ，上式最后一次循环处理第一位，可以将while条件改成x！= 0，即可
	while (x != 0) {
		int a = x % 10;
		if (abs(b) > (pow(2, 31) / 10)) return 0;//额外注意题目中的note，32位机器机器上要注意这个判断条件
		b = b * 10 + a;
		x = x / 10;
	}
	return b;
}
// better answer，和我的很像，改进点在于不需要进行判断，如果溢出了，在进行反运算，和之前的值会不相同
// note 因为涉及到了乘除法，如果只有加减法，会形成阿贝尔群，即使溢出，也会得到原来的结果，见下面的test
int reverse(int x)
{
	int result = 0;
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

	return result;
}
int main() { 
	int x = 0;
	cin >> x;
	cout << reverse(x) << endl;
	//test 阿贝尔群
	int a = 0, b = 0, c = 0;
	a = pow(2, 500);
	cout << a << endl;
	b = 123;
	c = a + b;
	b = c - a;
	cout << b;
}