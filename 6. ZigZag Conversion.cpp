/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

/*
my accepted answer: �����������飬����numRowsΪ3�����Ϊ012101210121012��Ȼ��0  1  2�ֱ���ѡ������Ϊ����
����ֻ���㱩���㷨�����Ҷ���ռ�
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
string convert(string s, int numRows) {
	size_t len = s.length();
	int *p = new int[len];
	bool flag = 1;
	int row = 0;
	for (int i = 0; i < len; i++) {
		if (numRows == 1) {
			p[i] = 0;
			continue;
		}
		if (flag) {
			p[i] = row;
			row += 1;
			if (row == numRows) {
				row = numRows - 2;
				flag = 0;
			}
		}
		else {
			p[i] = row;
			row -= 1;
			if (row == -1) {
				row = 1;
				flag = 1;
			}
		}
	}
	string s1;
	for (int rowi = 0; rowi < numRows; rowi++) {
		for (int i = 0; i < len; i++) {
			if (p[i] == rowi)
				s1 += s[i];
		}
	}
	delete[]p;
	return s1;
}
*/

/* better solution,˼·��ʵ���񣬸���û�ж���ѭ����ֻ���������˸���Ŀռ䣡string����ֱ��Ӧ��0 1 2��*/

string convert(string s, int numRows) {
	int len = s.length();
	//���������Ҫ������ û��������ᱨ��reference binding to null pointer of type 'struct value_type'
	//����ȷ������ok�ڴ���vector��
	if (len <= 0)
		return string("");
	vector<string> sb(len);
	int i = 0;
	while (i < len) {
		for (int idx = 0; idx < numRows && i < len; idx++) {
			sb[idx] += (s[i++]);
		}
		for (int idx = numRows - 2; idx >= 1 && i < len; idx--) {
			sb[idx] += (s[i++]);
		}
	}
	for (int idx = 1; idx < sb.size(); idx++) {
		sb[0] += sb[idx];
	}
	return sb[0];
}
int main() { 
	string s = "abcdefg";
	cout<<convert(s, 3)<<endl;
}