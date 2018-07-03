科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。

输入格式：
每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。

输出格式：
对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。

输入样例1：
+1.23400E-03
输出样例1：
0.00123400
输入样例2：
-1.2E+10
输出样例2：
-12000000000

code:

#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int i = 0;
	while (s[i] != 'E') i++;
	string t = s.substr(1, i - 1);  //substr(pos,len),返回从pos位开始，长度为len的子串
	int n = stoi(s.substr(i + 1));  //stoi()将字符串转化为int型整数
	if (s[0] == '-')cout << '-';
	if (n < 0) {
		cout << "0.";
		for (int j = 0; j < abs(n) - 1; j++) cout << '0'; //也就是输出abs(n)-1个零
		for (int j = 0; j < t.length(); j++)
			if (t[j] != '.') cout << t[j];
	}
	else {
		cout << t[0];
		int cnt, j;
		for (j = 2, cnt = 0; j < t.length() && cnt < n; j++, cnt++) cout << t[j];
		if (j == t.length())
			for (int k = 0; k < n - cnt; k++)cout << '0';
		else {
			cout << '.';
			for (int k = j; k < t.length(); k++) cout << t[j];
		}
	}
	return 0;
}
