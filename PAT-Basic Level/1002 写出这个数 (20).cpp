读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10^100^。
输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu

code:
#include <iostream>
#include<string>
using namespace std;
string p[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main() {
	string n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n.length(); i++) {
		sum = sum + n[i]-'0';
	}
	string r = to_string(sum);
	cout << p[r[0] - '0'];
	for (int i = 1; i < r.length(); i++) {
		cout << ' ' << p[r[i] - '0'];
	}
	return 0;
}
