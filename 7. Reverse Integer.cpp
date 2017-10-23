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
		if (abs(b) > (pow(2, 31)/10)) return 0;//����ע����Ŀ�е�note��32λ����������Ҫע������ж�����
		b = b * 10 + a;
		
		x = x / 10;
	}
	if (abs(b) > (pow(2, 31) / 10)) return 0;//����ע����Ŀ�е�note��32λ����������Ҫע������ж�����
	b = b * 10 + x;
	*/
	//���������Ľ� ����ʽ���һ��ѭ�������һλ�����Խ�while�����ĳ�x��= 0������
	while (x != 0) {
		int a = x % 10;
		if (abs(b) > (pow(2, 31) / 10)) return 0;//����ע����Ŀ�е�note��32λ����������Ҫע������ж�����
		b = b * 10 + a;
		x = x / 10;
	}
	return b;
}
// better answer�����ҵĺ��񣬸Ľ������ڲ���Ҫ�����жϣ��������ˣ��ڽ��з����㣬��֮ǰ��ֵ�᲻��ͬ
// note ��Ϊ�漰���˳˳��������ֻ�мӼ��������γɰ�����Ⱥ����ʹ�����Ҳ��õ�ԭ���Ľ�����������test
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
	//test ������Ⱥ
	int a = 0, b = 0, c = 0;
	a = pow(2, 500);
	cout << a << endl;
	b = 123;
	c = a + b;
	b = c - a;
	cout << b;
}